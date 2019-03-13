// POV Scene File for Part Number = %s                   
// String Input Parameters = (part_number, camera_distance_Int, camera_rotation-x_Int, 
//                            camera_rotate-y_Int, Light_RGB_Vector, Number_Lights-X, 
//                            Number_Lights-Y_Int, Background_RGB_Vector, Brick_Include_Filename, 
//                            Brick_lg_partnum, Rotation_Vector, Translation_Vector, 
//                            Brick_RGB_Vector, Plane_RGB_Vector, Plane_Diffusion_Int)

#include "screen.inc"     
#include "math.inc"   
#include "functions.inc"    
#include "colors.inc"  
  

#version 3.7

#declare LDXQual = 3.000000;	// Quality (0 = Bounding Box; 1 = No Refraction; 2 = Normal; 3 = Stud Logos)
#declare LDXStuds = 1;	// Show studs? (1 = YES; 0 = NO)
#declare LDXRefls = 1;	// Reflections? (1 = YES; 0 = NO)
#declare LDXShads = 1;	// Shadows? (1 = YES; 0 = NO)
#declare LDXFloor = 1;	// Include Floor? (1 = YES; 0 = NO)

// Model bounds information
#declare LDXMinX = -60.000000;
#declare LDXMinY = -28.000000;
#declare LDXMinZ = -60.000000;
#declare LDXMaxX = 80.000000;
#declare LDXMaxY = 0.000000;
#declare LDXMaxZ = 60.000000;
#declare LDXCenterX = 10.000000;
#declare LDXCenterY = -14.000000;
#declare LDXCenterZ = 0.000000;
#declare LDXCenter = <LDXCenterX,LDXCenterY,LDXCenterZ>;
#declare LDXRadius = 186.504684;

#declare LDXFloorLoc = LDXMaxY;	// Floor location. (Dependent on floor axis; MAX_Y is bottom of model)
#declare LDXFloorAxis = y;	// Floor axis (x, y, or z)

#declare LDXAmb = 0.000000;
#declare LDXDif = 0.000000;
#declare LDXRefl = 0.025000;
#declare LDXPhong = 1.000000;
#declare LDXPhongS = 40.000000;
#declare LDXTRefl = 0.015000;
#declare LDXTFilt = 0.750000;
#declare LDXTTransmit = 0.150000;
#declare LDXIoR = 1.250000;
#declare LDXRubberRefl = 0.000000;
#declare LDXRubberPhong = 0.100000;
#declare LDXRubberPhongS = 10.000000;
#declare LDXChromeAmb = 0.250000;
#declare LDXChromeDif = 0.600000;
#declare LDXChromeRefl = 0.500000;
#declare LDXChromeBril = 5.000000;
#declare LDXChromeSpec = 0.700000;
#declare LDXChromeRough = 0.010000;
#declare LDXIPov = 1;	// Use inline POV code from LDraw file? (1 = YES; 0 = NO)
#declare LDXBgR = 1.000000;	// Background Red
#declare LDXBgG = 1.000000;	// Background Green
#declare LDXBgB = 1.000000;	// Background Blue
#declare LDXOrigVer = version;	// DO NOT MODIFY

#declare lg_quality = 3;
#include “rad_def.inc”
global_settings {
   radiosity {
      Rad_Settings(Radiosity_Normal,off,off)
   }
}
global_settings {
	assumed_gamma 1.4
	adc_bailout 0.01/2
	radiosity {
		brightness 0.5
	}
	radiosity {
      Rad_Settings(Radiosity_Normal,off,off)
    }
	max_trace_level 5
}


#local cam_dist = %s;                   //50 ---- 75
#local cam_move = 1/2;
#local cam_area = 2;
#local cam_loca = -z * cam_dist;
#local cam_look = %s;
#local cam_angl = 45;
#local cam_tran = transform
{
	rotate		+x * asind(tand(%s))    //0 ( horizontal ) ---- 45 (vertical)
	rotate		+y * %s                 //can be anything (degress)
	translate	+y * cam_move
}
Set_Camera_Orthographic(false)
Set_Camera_Transform(cam_tran)
Set_Camera(cam_loca, cam_look, cam_angl)

light_source {
    <2, 10, -3>,
    rgb %s                              //RGB Vector with 3 values between 0.8 and 1.0
    area_light <5, 0, 0>, <0, 0, 5>, %s, %s     //How many x lights, and how many y lights (integers)
    adaptive 1
    jitter
  }




background { color rgb %s }             //RGB Vector with 3 values
#include "lg_defs.inc"                  //For stuff to make bricks
#include "%s"                           //LG Brick Include String

#local brick_model = object { 
        %s                              //lg + part num string
        rotate %s                //XYZ Vector (normal rotation = <-90,0,0>
        translate %s     //XYZ Vecotr (Y is 0.96 for normal brick height)
        texture { pigment { color rgb %s }}     // RGB Vector with 3 values
        }
           

 
object {brick_model}



object {
    plane { y, 0}
    texture {
        pigment { color rgb %s }        //RGB Vector with 3 values
        finish { ambient 0 diffuse %s specular %s }     //Diffusion value between 0.4 and 0.8, specular value between 0.1 and 0.5
    }
}              
       
       
 
    
#local Max_X = max_extent(brick_model).x;
#local Max_Y = max_extent(brick_model).y;
#local Max_Z = max_extent(brick_model).z;
#local Min_X = min_extent(brick_model).x;
#local Min_Y = min_extent(brick_model).y;
#local Min_Z = min_extent(brick_model).z;


#local box_vertex_1 = < Max_X, Max_Y, Max_Z >;
#local box_vertex_2 = < Max_X, Min_Y, Max_Z >;
#local box_vertex_3 = < Max_X, Max_Y, Min_Z >; 
#local box_vertex_4 = < Max_X, Min_Y, Min_Z >;
#local box_vertex_5 = < Min_X, Max_Y, Max_Z >;
#local box_vertex_6 = < Min_X, Max_Y, Min_Z >;
#local box_vertex_7 = < Min_X, Min_Y, Max_Z >;
#local box_vertex_8 = < Min_X, Min_Y, Min_Z >;

#local possible_screen_max_XY_1 = Get_Screen_XY(box_vertex_1); 
#local possible_screen_max_XY_2 = Get_Screen_XY(box_vertex_2);
#local possible_screen_max_XY_3 = Get_Screen_XY(box_vertex_3); 
#local possible_screen_max_XY_4 = Get_Screen_XY(box_vertex_4);
#local possible_screen_max_XY_5 = Get_Screen_XY(box_vertex_5);
#local possible_screen_max_XY_6 = Get_Screen_XY(box_vertex_6);
#local possible_screen_max_XY_7 = Get_Screen_XY(box_vertex_7);
#local possible_screen_max_XY_8 = Get_Screen_XY(box_vertex_8);

#debug concat("possible_screen_max_XY_1 = (", vstr(2, possible_screen_max_XY_1, ",", 0, -1), ")\n")
#debug concat("possible_screen_max_XY_2 = (", vstr(2, possible_screen_max_XY_2, ",", 0, -1), ")\n")
#debug concat("possible_screen_max_XY_3 = (", vstr(2, possible_screen_max_XY_3, ",", 0, -1), ")\n")
#debug concat("possible_screen_max_XY_4 = (", vstr(2, possible_screen_max_XY_4, ",", 0, -1), ")\n")
#debug concat("possible_screen_max_XY_5 = (", vstr(2, possible_screen_max_XY_5, ",", 0, -1), ")\n")
#debug concat("possible_screen_max_XY_6 = (", vstr(2, possible_screen_max_XY_6, ",", 0, -1), ")\n")
#debug concat("possible_screen_max_XY_7 = (", vstr(2, possible_screen_max_XY_7, ",", 0, -1), ")\n")
#debug concat("possible_screen_max_XY_8 = (", vstr(2, possible_screen_max_XY_8, ",", 0, -1), ")\n")
