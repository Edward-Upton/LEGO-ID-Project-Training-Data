/*******************************************************************************/
/*                                                                             */
/* LGEO Libray Include File     (C) lgeo@digitalbricks.org (Lutz Uhlmann)      */
/*                                                                             */
/* 20080107 Lutz Uhlmann                                                       */
/* 20080309 Lutz Uhlmann fixed material statement                              */
/*                                                                             */
/* This file is in no way related to the LEGO(tm) Group.                       */
/* It is provided for private non-commercial use only.                         */
/*                                                                             */
/* lg_4182p04: Train Door 1 x 4 x 5 Right with red, white and blue stripe      */
/*             Pattern                                                         */
/*                                                                             */ 
/*******************************************************************************/
#ifdef(lg_4182p04)
#else
#include "lg_4182.inc"
#declare lg_4182p04_decals =
union {
 difference {
  union {
   cylinder {
    <0, 0, -10*LG_PLATE_HEIGHT>,
    <0, 0, -9*LG_PLATE_HEIGHT>,
    LG_BRICK_WIDTH/2+0.0001
    material { texture { lg_red  normal { bumps 0.1 scale 2 } } }
   }
   cylinder {
    <0, 0, -10*LG_PLATE_HEIGHT>,
    <0, 0, -11*LG_PLATE_HEIGHT>,
    LG_BRICK_WIDTH/2+0.0001
    material { texture { lg_white  normal { bumps 0.1 scale 2 } } }
   }
   cylinder {
    <0, 0, -12*LG_PLATE_HEIGHT>,
    <0, 0, -11*LG_PLATE_HEIGHT>,
    LG_BRICK_WIDTH/2+0.0001
    material { texture { lg_blue  normal { bumps 0.1 scale 2 } } }
   }
  }
  union {
   cylinder {
    <0, 0, -3*LG_BRICK_HEIGHT+LG_E>,
    <0, 0, -5*LG_BRICK_HEIGHT>,
    LG_BRICK_WIDTH/2-0.0001
   }
   box {
    <LG_BRICK_WIDTH/2+LG_E, 0, -3*LG_BRICK_HEIGHT+LG_E>,
    <-LG_BRICK_WIDTH/2-LG_E, LG_BRICK_WIDTH/2+LG_E, -5*LG_BRICK_HEIGHT>
   }
   box {
    <0, LG_BRICK_WIDTH/2+LG_E, -3*LG_BRICK_HEIGHT+LG_E>,
    <-LG_BRICK_WIDTH/2-LG_E, LG_BRICK_WIDTH/2-LG_E, -5*LG_BRICK_HEIGHT>
   }
  }
 }
 difference {
  union {
   cylinder {
    <0, 0, -10*LG_PLATE_HEIGHT>,
    <0, 0, -9*LG_PLATE_HEIGHT>,
    LG_BRICK_WIDTH/2+0.0001
    material { texture { lg_red  normal { bumps 0.1 scale 2 } } }
   }
   cylinder {
    <0, 0, -10*LG_PLATE_HEIGHT>,
    <0, 0, -11*LG_PLATE_HEIGHT>,
    LG_BRICK_WIDTH/2+0.0001
    material { texture { lg_white  normal { bumps 0.1 scale 2 } } }
   }
   cylinder {
    <0, 0, -12*LG_PLATE_HEIGHT>,
    <0, 0, -11*LG_PLATE_HEIGHT>,
    LG_BRICK_WIDTH/2+0.0001
    material { texture { lg_blue  normal { bumps 0.1 scale 2 } } }
   }
  }
  union {
   cylinder {
    <0, 0, -3*LG_BRICK_HEIGHT+LG_E>,
    <0, 0, -5*LG_BRICK_HEIGHT>,
    LG_BRICK_WIDTH/2-0.0001
   }
   box {
    <LG_BRICK_WIDTH/2+LG_E, 0, -3*LG_BRICK_HEIGHT+LG_E>,
    <-LG_BRICK_WIDTH/2-LG_E, LG_BRICK_WIDTH/2+LG_E, -5*LG_BRICK_HEIGHT>
   }
   box {
    <0, LG_BRICK_WIDTH/2+LG_E, -3*LG_BRICK_HEIGHT+LG_E>,
    <-LG_BRICK_WIDTH/2-LG_E, LG_BRICK_WIDTH/2-LG_E, -5*LG_BRICK_HEIGHT>
   }
  }
  scale <-1, 0, 0>
  translate <-3*LG_BRICK_WIDTH, 0, 0>
 }
 box {
  <0, -LG_BRICK_WIDTH/2-0.0001, -10*LG_PLATE_HEIGHT>,
  <-3*LG_BRICK_WIDTH, -LG_BRICK_WIDTH/2+0.0001, -9*LG_PLATE_HEIGHT>
  material { texture { lg_red  normal { bumps 0.1 scale 2 } } }
 }
 box {
  <0, -LG_BRICK_WIDTH/2-0.0001, -10*LG_PLATE_HEIGHT>,
  <-3*LG_BRICK_WIDTH, -LG_BRICK_WIDTH/2+0.0001, -11*LG_PLATE_HEIGHT>
  material { texture { lg_white  normal { bumps 0.1 scale 2 } } }
 }
 box {
  <0, -LG_BRICK_WIDTH/2-0.0001, -12*LG_PLATE_HEIGHT>,
  <-3*LG_BRICK_WIDTH, -LG_BRICK_WIDTH/2+0.0001, -11*LG_PLATE_HEIGHT>
  material { texture { lg_blue  normal { bumps 0.1 scale 2 } } }
 }
 scale <1, -1, 1>
}

#declare lg_4182p04 = 
union {
 object { lg_4182 }
 object { lg_4182p04_decals }
}

#declare lg_4182p04_clear = 
union {
 object { lg_4182_clear }
 object { lg_4182p04_decals }
}

#end