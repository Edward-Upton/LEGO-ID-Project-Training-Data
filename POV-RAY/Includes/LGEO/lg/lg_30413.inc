/*******************************************************************************/
/*                                                                             */
/* LGEO Libray Include File     (C) lgeo@digitalbricks.org (Lutz Uhlmann)      */
/*                                                                             */
/* 20080604 Lutz Uhlmann                                                       */
/*                                                                             */
/* This file is in no way related to the LEGO(tm) Group.                       */
/* It is provided for private non-commercial use only.                         */
/*                                                                             */
/* lg_30413: Panel 1 x 4 x 1                                                  */
/*                                                                             */ 
/*******************************************************************************/
#ifdef(lg_30413)
#else
#declare lg_30413 = 
union {
 #declare MIR = 0;
 #while (MIR < 2)
  union {
   cylinder {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   sphere {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   sphere {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   sphere {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   cylinder {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -0.08>,
    <-0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   torus {
    0.08-LG_CORNER_SPACE,
    LG_CORNER_SPACE
    rotate <0, 0, 90>
    translate <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>
   }
   torus {
    0.08-LG_CORNER_SPACE,
    LG_CORNER_SPACE
    rotate <0, 0, 90>
    translate <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    0.08-LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    0.08
   }
   box {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE-LG_E, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE-LG_E>
   }
   box {
    <-0.5*LG_BRICK_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-0.08-LG_E, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>
   }
   box {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_WALL_WIDTH, -LG_BRICK_HEIGHT+LG_CORNER_SPACE+LG_E>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT>
   }
   box {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_WALL_WIDTH, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>
   }
   object {
    lg_plate_column
    translate <0, LG_BRICK_WIDTH, -LG_BRICK_HEIGHT>
   }
   #if (MIR = 1)
    scale <1, -1, 1>
   #end
  }
  #declare MIR = MIR + 1;
 #end 
 cylinder {
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 box {
  <0.5*LG_BRICK_WIDTH-LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE+LG_E>,
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT>
 }
 box {
  <0.5*LG_BRICK_WIDTH-LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <0.5*LG_BRICK_WIDTH, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>
 }
 box {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE+LG_E>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT>
 }
 box {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-0.08, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE>
 }
 box {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, 0>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE-LG_E>
 }
 box {
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_TOP_HEIGHT>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT>
 }
 object {
  lg_plate_column
  translate <0, 0, -LG_BRICK_HEIGHT>
 }
} 

#declare lg_30413_clear = 
merge {
 #declare MIR = 0;
 #while (MIR < 2)
  merge {
   cylinder {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   sphere {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   sphere {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   sphere {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   cylinder {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -0.08>,
    <-0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    LG_CORNER_SPACE
   }
   torus {
    0.08-LG_CORNER_SPACE,
    LG_CORNER_SPACE
    rotate <0, 0, 90>
    translate <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>
   }
   torus {
    0.08-LG_CORNER_SPACE,
    LG_CORNER_SPACE
    rotate <0, 0, 90>
    translate <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    0.08-LG_CORNER_SPACE
   }
   cylinder {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -0.08>,
    0.08
   }
   box {
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE-LG_E, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE-LG_E>
   }
   box {
    <-0.5*LG_BRICK_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -0.08>,
    <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-0.08-LG_E, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>
   }
   box {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_WALL_WIDTH, -LG_BRICK_HEIGHT+LG_CORNER_SPACE+LG_E>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT>
   }
   box {
    <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_WALL_WIDTH, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
    <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>
   }
   object {
    lg_plate_column_clear
    translate <0, LG_BRICK_WIDTH, -LG_BRICK_HEIGHT>
   }
   #if (MIR = 1)
    scale <1, -1, 1>
   #end
  }
  #declare MIR = MIR + 1;
 #end 
 cylinder {
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, -LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 cylinder {
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
  LG_CORNER_SPACE
 }
 box {
  <0.5*LG_BRICK_WIDTH-LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE+LG_E>,
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT>
 }
 box {
  <0.5*LG_BRICK_WIDTH-LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <0.5*LG_BRICK_WIDTH, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_CORNER_SPACE>
 }
 box {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -LG_BRICK_HEIGHT+LG_CORNER_SPACE+LG_E>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -LG_BRICK_HEIGHT>
 }
 box {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH, 2*LG_BRICK_WIDTH-0.08, -LG_BRICK_HEIGHT+LG_CORNER_SPACE>,
  <-0.5*LG_BRICK_WIDTH, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE>
 }
 box {
  <-0.5*LG_BRICK_WIDTH+LG_WALL_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-0.08, 0>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+0.08, -LG_CORNER_SPACE-LG_E>
 }
 box {
  <0.5*LG_BRICK_WIDTH-LG_CORNER_SPACE, 2*LG_BRICK_WIDTH-LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT-LG_TOP_HEIGHT>,
  <-0.5*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_BRICK_WIDTH+LG_CORNER_SPACE, -2*LG_PLATE_HEIGHT>
 }
 object {
  lg_plate_column_clear
  translate <0, 0, -LG_BRICK_HEIGHT>
 }
} 

#end