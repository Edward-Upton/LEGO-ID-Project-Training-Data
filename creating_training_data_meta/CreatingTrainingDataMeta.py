import numpy as np
import requests
import json
import os
import subprocess as sp
import time
import threading
import vapory

class creating_training_data_meta():

    def __init__(self, part_cat_id):
        self.current_working_directory = os.path.abspath(os.path.dirname(__file__))
        self.master_files_directory = self.current_working_directory
    
        self.include_lg_directory = "C:\\Users\\edupt\\Documents\\GitHub\\LEGO-ID-Project-Training-Data\\POV-RAY\\Includes\\LGEO\\lg"

        self.temp_pov_path = os.path.join(self.current_working_directory, "temp.pov")
        self.temp_ini_path = os.path.join(self.current_working_directory, "povray.ini")
        self.temp_out_path = os.path.join(self.current_working_directory, "debug.out")
        self.temp_img_path = os.path.join(self.current_working_directory, "temp.jpg")
        self.training_meta_path = os.path.join(self.current_working_directory, "training.meta")
        self.temp_img_dimension = 50
        self.pov_exe = "C:\\Program Files\\POV-Ray\\v3.7\\bin\\pvengine64.exe"
        self.part_cat_id = str(part_cat_id)

        self.master_pov_data = str(open(os.path.join(self.master_files_directory, "master.pov"), "r").read())
        self.master_ini_data = str(open(os.path.join(self.master_files_directory, "master.ini"), "r").read())

        self.part_id_array = self.get_training_part_ids_api()
        #self.part_id_array = self.part_id_array[0:5]
        self.parts_meta_array = np.ndarray((0,3))


    def create_meta_data(self):
        for part_id in self.part_id_array:
            if os.path.exists((self.include_lg_directory + "\\lg_" + part_id + ".inc")):
                part_meta = self.render_size_test(part_id)
                self.parts_meta_array = np.append(self.parts_meta_array, [part_meta], axis=0)
                print(self.parts_meta_array)
            else:
                print("No lg inlcude for : ", part_id)

        return self.parts_meta_array
    
    def get_training_part_ids_api(self):
        url = "http://127.0.0.1:8090/getSQLtable"
        get_request = requests.get(url, params={"table":"parts","where_table_col":"part_category_id", "where_table_val":self.part_cat_id})
        parts_list_id = json.loads(get_request.text)
        part_id_array = np.array([])
        for iter in range(len(parts_list_id)):
            part_id = str(parts_list_id[iter][0])
            part_id_array = np.append(part_id_array, part_id)
        return part_id_array

    def render_size_test(self,part_id):
        lg_part_id = "lg_" + part_id
        part_include_filename = lg_part_id + ".inc"

        new_pov_data = self.master_pov_data % (part_include_filename, lg_part_id)
        new_pov_file = open(self.temp_pov_path, "w")
        new_pov_file.write(new_pov_data)
        new_pov_file.close()

        new_ini_data = self.master_ini_data % (self.include_lg_directory, self.temp_img_path)
        new_ini_file = open(self.temp_ini_path, "w")
        new_ini_file.write(new_ini_data)
        new_ini_file.close()
        print(self.temp_ini_path)
        sp.Popen('C:\\Program Files\\POV-Ray\\v3.7\\bin\\pvengine64.exe /nr /render "povray.ini" /exit', creationflags=0X08000000, cwd=self.current_working_directory).wait()
        #render_cmd = 'pvengine64.exe /nr /render "%s" /exit' % (self.temp_ini_path)
        possible_x_limits = np.array([])
        possible_y_limits = np.array([])
        data_output_file = open(self.temp_out_path, "r")
        data_output_split = data_output_file.read().split("\n")
        data_output_file.close()
        
        data_output_vertex = data_output_split[0:8]


        #Getting Lowest Point of Brick
        vertex_y_values_list = list()
        for line in data_output_vertex:
            XYZ = line[16:(len(line)-1)]
            XYZ_split = XYZ.split(",")
            vertex_y_values_list.append(float(XYZ_split[1]))

        vertex_y_values_list.sort()
        translate_y = vertex_y_values_list[0]

        
        #Setting Camera Distance for Brick
        render_output_Max_Min = data_output_split[8:16]
        possible_x_limits = list()
        possible_y_limits = list()
        for line in render_output_Max_Min:
            XY = line[28:(len(line)-1)]
            XY_split = XY.split(",")
            possible_x_limits.append(float(XY_split[0]))
            possible_y_limits.append(float(XY_split[1]))

        possible_x_limits.sort()
        possible_y_limits.sort()

        X_Min = int(possible_x_limits[0])
        X_Max = int(possible_x_limits[7])
        Y_Min = int(possible_y_limits[0])
        Y_Max = int(possible_y_limits[7])

        X_Diff = X_Max-X_Min
        Y_Diff = Y_Max-Y_Min
        X_Perc = X_Diff / self.temp_img_dimension
        Y_Perc = Y_Diff / self.temp_img_dimension
        Avg_Perc = (X_Perc + Y_Perc)/2

        if Avg_Perc < 0.2:
            render_distance_from_part = 15
            print("Part: ", part_id, " is less than 20%")
        elif Avg_Perc < 0.4:
            render_distance_from_part = 25
            print("Part: ", part_id, " is less than 40%")
        elif Avg_Perc < 0.55:
            render_distance_from_part = 45
            print("Part: ", part_id, " is less than 55%")
        else:
            render_distance_from_part = 70
            print("Part: ", part_id, " is greater than 60%")

        part_training_meta = np.array([])
        part_training_meta = np.append(part_training_meta, part_id)
        part_training_meta = np.append(part_training_meta, translate_y)
        part_training_meta = np.append(part_training_meta, render_distance_from_part)

        return part_training_meta
    
    def create_training_data_meta_file(self, filename):
        meta_data_path = os.path.join(self.current_working_directory, (filename + ".meta"))
        meta_data_file = open(meta_data_path, "w")
        for part_meta_data in self.parts_meta_array:
            string_to_write = "%s,%s,%s\n" % (part_meta_data[0], part_meta_data[1], part_meta_data[2])
            meta_data_file.write(string_to_write)
        meta_data_file.close()

metaData = creating_training_data_meta(11)
training_meta_data = metaData.create_meta_data()
metaData.create_training_data_meta_file("category_brick_1st")
