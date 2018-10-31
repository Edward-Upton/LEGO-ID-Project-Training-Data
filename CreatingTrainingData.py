import numpy as np
from imgaug import augmenters as iaa
import cv2
import os
import subprocess as sp
import requests
import json

CURRENT_WORKING_DIRECTORY = os.path.abspath(os.path.dirname(__file__))

MASTER_FILES_DIRECTORY = os.path.join(CURRENT_WORKING_DIRECTORY, "master")
TRAINING_IMAGES_DIRECTORY = os.path.join(CURRENT_WORKING_DIRECTORY, "TrainingData", "images")
TRAINING_ANNOTATIONS_DIRECTORY = os.path.join(CURRENT_WORKING_DIRECTORY, "TrainingData", "labels")

INCLUDE_LG_DIRECTORY = os.path.join(CURRENT_WORKING_DIRECTORY, "POV-RAY", "Includes", "LGEO", "lg")

TEMP_DIRECTORY = os.path.join(CURRENT_WORKING_DIRECTORY, "temp")
TEMP_POV_PATH = os.path.join(TEMP_DIRECTORY, "temp.pov")
TEMP_INI_PATH = os.path.join(TEMP_DIRECTORY, "povray.ini")
TEMP_OUT_PATH = os.path.join(TEMP_DIRECTORY, "debug.out")
TEMP_IMG_PATH = os.path.join(TEMP_DIRECTORY, "temp.jpg")
TEMP_XML_PATH = os.path.join(TEMP_DIRECTORY, "temp.xml")

TRAINING_IMAGE_DIMENSIONS = [500,500]

def get_training_ids(filename):
    parts_meta_file = open(os.path.join(CURRENT_WORKING_DIRECTORY, "creating_training_data_meta", filename))
    parts_meta_data = parts_meta_file.read()
    part_meta_data_line_split = parts_meta_data.split("\n")
    part_meta_data_line_split = part_meta_data_line_split[0:(len(part_meta_data_line_split)-1)]
    parts_meta_array = np.ndarray((0,3))
    for line in part_meta_data_line_split:
        line_split = line.split(",")
        part_id_temp = str(line_split[0])
        y_translate_temp = str(line_split[1])
        cam_dist_temp = str(line_split[2])
        temp_line_array = np.array([part_id_temp, y_translate_temp, cam_dist_temp])
        parts_meta_array = np.append(parts_meta_array, [temp_line_array], axis=0)
    
    return parts_meta_array


class create_training_data():
    def __init__(self, part_iteration, part_meta):
        self.part_id = part_meta[0]
        self.y_translate = part_meta[1]
        self.camera_distance = part_meta[2]

        self.master_pov_data = (open(os.path.join(MASTER_FILES_DIRECTORY, "master.pov"))).read()
        self.master_ini_data = (open(os.path.join(MASTER_FILES_DIRECTORY, "master.ini"))).read()
        self.master_xml_data = (open(os.path.join(MASTER_FILES_DIRECTORY, "master.xml"))).read()
        self.lg_part_id = "lg_" + self.part_id
        self.part_include_file = self.lg_part_id + ".inc"
        self.part_include_path = os.path.join(INCLUDE_LG_DIRECTORY, self.part_include_file)
        self.part_iteration = str(part_iteration)
        self.unique_render_id = self.part_id + "-" + self.part_iteration
        self.unique_image_id = self.unique_render_id + "-%s.jpg"

    def create_training_data_main(self):
        
        self.create_pov()
        self.create_ini()
        self.render_part()
        self.create_annotations()
        self.augment_images()

    def create_pov(self):
        #Formatting :   part_id, cam_dist, cam_look, cam_x_rot, cam_y_rot, light_rgb,
        #               num_lights_x, num_lights_y, background_rgb, lg_include,
        #               lg_part_id, brick_rot, brick_translate, brick_rgb, pane_rgb, pane_diffuse

        #(self.part_id, cam_dist, cam_look, cam_x_rot, cam_y_rot, light_rgb, number_light_x, number_light_y, background_rgb, self.part_include_file, self.lg_part_id, brick_rotate_vector, brick_translate_vector, brick_rgb, plane_rgb, plane_diffuse, plane_specular)
        
        cam_dist = str(np.random.rand()+float(self.camera_distance))
        cam_look = str("<0,%s,0>" % str(((float(self.y_translate))*-1)/2))
        cam_x_rot = str((np.random.rand()*18)+20)
        cam_y_rot = str(np.random.rand()*360)

        light_rgb = str("<{},{},{}>".format((np.random.rand()*0.2)+0.8,(np.random.rand()*0.2)+0.8, (np.random.rand()*0.2)+0.8))
        number_light_x = str((np.random.rand()*4)+3)
        number_light_y = str((np.random.rand()*4)+3)

        background_rgb = str("<{},{},{}>".format(np.random.rand(),np.random.rand(), np.random.rand()))

        brick_rotate_vector = str("<-90,0,0>")
        brick_translate_vector = str("<0,%s,0>" % str(float(self.y_translate)*-1))
        brick_rgb = str("<{},{},{}>".format(np.random.rand(),np.random.rand(), np.random.rand()))

        plane_rgb = str("<{},{},{}>".format(np.random.rand(),np.random.rand(), np.random.rand()))
        plane_diffuse = str((np.random.rand()*0.4)+0.4)
        plane_specular = str((np.random.rand()*0.4)+0.1)



        new_pov_data = self.master_pov_data % (self.part_id, cam_dist, cam_look, cam_x_rot, cam_y_rot, light_rgb, number_light_x, number_light_y, background_rgb, self.part_include_file, self.lg_part_id, brick_rotate_vector, brick_translate_vector, brick_rgb, plane_rgb, plane_diffuse, plane_specular)

        new_pov_file = open(TEMP_POV_PATH, "w")
        new_pov_file.write(new_pov_data)
        new_pov_file.close()

    def create_ini(self):
        #String Input Parameters = part_number, width, height, lg_include_directory, pov_input_file, image_output_file, data_output_file
        new_ini_data = self.master_ini_data % (self.part_id, TRAINING_IMAGE_DIMENSIONS[0], TRAINING_IMAGE_DIMENSIONS[1], INCLUDE_LG_DIRECTORY, TEMP_POV_PATH, TEMP_IMG_PATH)

        new_ini_file = open(TEMP_INI_PATH, "w")
        new_ini_file.write(new_ini_data)
        new_ini_file.close()

    def render_part(self):
        sp.Popen('pvengine64.exe /nr /render "%s" /exit' % (TEMP_INI_PATH), creationflags=0X08000000).wait()
    def create_annotations(self):
        possible_x_limits = np.array([])
        possible_y_limits = np.array([])
        with open(TEMP_OUT_PATH) as data_output:
            for line in data_output:
                XY_Pair = str(line[28:(len(line)-2)])
                XY_Pair_Split = XY_Pair.split(",")
                X = XY_Pair_Split[0]
                possible_x_limits = np.append(possible_x_limits, X)
                Y = XY_Pair_Split[1]
                possible_y_limits = np.append(possible_y_limits, Y)

        possible_x_limits = np.sort(possible_x_limits)
        possible_y_limits = np.sort(possible_y_limits)

        X_Min = int(float(possible_x_limits[0]))
        X_Max = int(float(possible_x_limits[7]))
        Y_Min = int(float(possible_y_limits[0]))
        Y_Max = int(float(possible_y_limits[7]))

        if X_Min > X_Max:
            print("X labels wrong war around for ", self.part_id, " ", self.part_iteration, ". They have been swapped")
            X_Max_temp = X_Max
            X_Max = X_Min
            X_Min = X_Max_temp
        
        if Y_Min > Y_Max:
            print("Y labels wrong war around for ", self.part_id, " ", self.part_iteration, ". They have been swapped")
            Y_Max_temp = Y_Max
            Y_Max = Y_Min
            Y_Min = Y_Max_temp

        if X_Min == X_Max:
            print("X labels equal for ", self.part_id, " ", self.part_iteration)
        
        if Y_Min == Y_Max:
            print("Y labels equal for ", self.part_id, " ", self.part_iteration)

        if X_Min < 1:
            print("X Coordinate set to 10 with ", self.part_id, " ", self.part_iteration)
            X_Min = 1
        if Y_Min < 1:
            print("Y Coordinate set to 10 with ", self.part_id, " ", self.part_iteration)
            Y_Min = 1
        if X_Max > 499:
            print("X Coordinate set to 490 with ", self.part_id, " ", self.part_iteration)
            X_Max = 499
        if Y_Max > 499:
            print("Y Coordinate set to 490 with ", self.part_id, " ", self.part_iteration)
            Y_Max = 499

        new_xml_data = self.master_xml_data % (self.unique_image_id, TRAINING_IMAGES_DIRECTORY, str(TRAINING_IMAGE_DIMENSIONS[0]), 
                                                str(TRAINING_IMAGE_DIMENSIONS[0]), str(3), str(self.part_id), str(X_Min), str(Y_Min), 
                                                str(X_Max), str(Y_Max))
        
        new_xml_file = open(TEMP_XML_PATH, "w")
        new_xml_file.write(new_xml_data)
        new_xml_file.close()
    
    def augment_images(self):
        
        temp_img_array = cv2.imread(TEMP_IMG_PATH)
        temp_xml_data = str(open(TEMP_XML_PATH, "r").read())


        def add_GaussBlur(img):
            seq = iaa.Sequential([iaa.GaussianBlur(sigma=(2.5, 2.75))])
            img = seq.augment_image(img)
            return img

        def add_Emboss(img):
            seq = iaa.Sequential([iaa.Emboss(alpha=1, strength=(0.35, 0.45))])
            img = seq.augment_image(img)
            return img

        def add_HueAndSaturation(img):
            seq = iaa.Sequential([iaa.AddToHueAndSaturation(value=(-4, 10))])
            img = seq.augment_image(img)
            return img

        def add_GaussNoise(img):
            seq = iaa.Sequential([iaa.Dropout(p=(0.08, 0.10), per_channel=True)])
            img = seq.augment_image(img)
            return img

        def add_ContrastNormalization(img):
            seq = iaa.Sequential([iaa.ContrastNormalization(alpha=(1.5, 2.0))])
            img = seq.augment_image(img)
            return img

        cv2.imwrite(os.path.join(TRAINING_IMAGES_DIRECTORY, "%s-%s-0.jpg" % (self.part_id, self.part_iteration)), temp_img_array)
        cv2.imwrite(os.path.join(TRAINING_IMAGES_DIRECTORY, "%s-%s-1.jpg" % (self.part_id, self.part_iteration)), add_GaussBlur(temp_img_array))
        cv2.imwrite(os.path.join(TRAINING_IMAGES_DIRECTORY, "%s-%s-2.jpg" % (self.part_id, self.part_iteration)), add_Emboss(temp_img_array))
        cv2.imwrite(os.path.join(TRAINING_IMAGES_DIRECTORY, "%s-%s-3.jpg" % (self.part_id, self.part_iteration)), add_HueAndSaturation(temp_img_array))
        cv2.imwrite(os.path.join(TRAINING_IMAGES_DIRECTORY, "%s-%s-4.jpg" % (self.part_id, self.part_iteration)), add_GaussNoise(temp_img_array))
        cv2.imwrite(os.path.join(TRAINING_IMAGES_DIRECTORY, "%s-%s-5.jpg" % (self.part_id, self.part_iteration)), add_ContrastNormalization(temp_img_array))
        for iter in range(6):
            with open(os.path.join(TRAINING_ANNOTATIONS_DIRECTORY, "%s-%s-%s.xml" % (self.part_id, self.part_iteration, iter)), "w") as f:
                f.write(temp_xml_data % iter)


parts_meta_array = get_training_ids("category_brick_1st.meta")

for part_meta in parts_meta_array:
    for iter in range(90):
        print("Creating Training Data for Part: ", part_meta[0], ". Iteration: ", iter)
        create_train_data = create_training_data(iter, part_meta)
        create_train_data.create_training_data_main()
