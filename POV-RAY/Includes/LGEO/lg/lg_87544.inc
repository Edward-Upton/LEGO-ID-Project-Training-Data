/*******************************************************************************/
/*                                                                             */
/* LGEO Libray Include File     (C) lgeo@digitalbricks.org (Lutz Uhlmann)      */
/*                                                                             */
/* lg_87544: Panel 1 x 2 x 3 Reinforced with Hollow Studs                      */
/*                                                                             */
/* This file is in no way related to the LEGO(tm) Group.                       */
/* It is provided for private non-commercial use only.                         */
/*                                                                             */
/* 2013-01-29 Owen Burgoyne                                                    */
/*                                                                             */
/*******************************************************************************/
#ifdef(lg_87544)
#else
#declare HEIGHT = 3;
#declare WIDTH = 2;
#declare lg_87544 =
union {
  #declare COL_X = 1;
  #while (COL_X < WIDTH)
  object {
    lg_plate_column
    translate <0.5*LG_BRICK_WIDTH, COL_X*LG_BRICK_WIDTH, 0>
    translate <0, WIDTH/2*-LG_BRICK_WIDTH, 0>
  }
  #declare COL_X = COL_X + 1;
  #end
  #declare MIR = 0;
  #while (MIR < 2)
  union {
    sphere {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0, LG_CORNER_SPACE>,
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    sphere {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    sphere {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    sphere {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    // SIDE SUPPORTS
    difference {
      union {
        box {
          <0, 0, LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, 0, LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, LG_PLATE_HEIGHT-LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, 0, 0>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT>
        }
      }
      box {
        <LG_WALL_WIDTH, -LG_E, -LG_E>,
        <LG_BRICK_WIDTH-LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH, LG_PLATE_INNER_HEIGHT>
      }
    }
    box {
      <0, 0, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    box {
      <LG_CORNER_SPACE, 0, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    box {
      <LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    box {
      <LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    cylinder {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>
      LG_CORNER_SPACE
    }
    // SIDE SUPPORT CURVES
    intersection {
      union {
        torus {
          0.08+LG_CORNER_SPACE,
          LG_CORNER_SPACE
          translate <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
        }
        torus {
          0.08+LG_CORNER_SPACE,
          LG_CORNER_SPACE
          translate <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
        }
      }
      box {
        <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_E>
      }
    }
    difference {
      box {
        <LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      }
      cylinder {
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH-LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        0.08
      }
    }
    difference {
      box {
        <LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      }
      cylinder {
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH-LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        0.08+LG_CORNER_SPACE
      }
    }
    // TOP PLATE
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>
      LG_CORNER_SPACE
    }
    torus {
      0.08-LG_CORNER_SPACE,
      LG_CORNER_SPACE
      rotate <90, 0, 0>
      translate <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    torus {
      0.08-LG_CORNER_SPACE,
      LG_CORNER_SPACE
      rotate <90, 0, 0>
      translate <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>
    }
    cylinder {
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      0.08
    }
    cylinder {
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT>,
      0.08-LG_CORNER_SPACE
    }
    difference {
      union {
        box {
          <0, 0, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, -LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH>
        }
      }
      box {
        <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-LG_E>,
        <LG_BRICK_WIDTH+LG_E, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT+LG_E>
      }
    }
    #if (MIR = 1)
    scale <1, -1, 1>
    #end
  }
  #declare MIR = MIR + 1;
  #end
  #declare KNOB_X = 0.5;
  #while (KNOB_X < WIDTH)
  object {
    lg_tech_knob_logo
    translate <0.5*LG_BRICK_WIDTH, KNOB_X*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT>
    translate <0, WIDTH/2*-LG_BRICK_WIDTH, 0>
  }
  #declare KNOB_X = KNOB_X + 1;
  #end
  translate <0.5*-LG_BRICK_WIDTH, 0, HEIGHT*-LG_BRICK_HEIGHT>
}

#declare lg_87544_clear =
merge {
  #declare COL_X = 1;
  #while (COL_X < WIDTH)
  object {
    lg_plate_column_clear
    translate <0.5*LG_BRICK_WIDTH, COL_X*LG_BRICK_WIDTH, 0>
    translate <0, WIDTH/2*-LG_BRICK_WIDTH, 0>
  }
  #declare COL_X = COL_X + 1;
  #end
  #declare MIR = 0;
  #while (MIR < 2)
  merge {
    sphere {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0, LG_CORNER_SPACE>,
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    sphere {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    sphere {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    sphere {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      LG_CORNER_SPACE
    }
    cylinder {
      <2*LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      LG_CORNER_SPACE
    }
    // SIDE SUPPORTS
    difference {
      merge {
        box {
          <0, 0, LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, 0, LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, LG_PLATE_HEIGHT-LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, 0, 0>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, LG_PLATE_HEIGHT>
        }
      }
      box {
        <LG_WALL_WIDTH, -LG_E, -LG_E>,
        <LG_BRICK_WIDTH-LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH, LG_PLATE_INNER_HEIGHT>
      }
    }
    box {
      <0, 0, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    box {
      <LG_CORNER_SPACE, 0, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    box {
      <LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    box {
      <LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH, LG_PLATE_HEIGHT-LG_CORNER_SPACE>,
      <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    cylinder {
      <LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>
      LG_CORNER_SPACE
    }
    // SIDE SUPPORT CURVES
    intersection {
      merge {
        torus {
          0.08+LG_CORNER_SPACE,
          LG_CORNER_SPACE
          translate <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
        }
        torus {
          0.08+LG_CORNER_SPACE,
          LG_CORNER_SPACE
          translate <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
        }
      }
      box {
        <2*LG_WALL_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_E>
      }
    }
    difference {
      box {
        <LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH+LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      }
      cylinder {
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH-LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        0.08
      }
    }
    difference {
      box {
        <LG_WALL_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>
      }
      cylinder {
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH-LG_WALL_WIDTH-LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        <2*LG_WALL_WIDTH+0.08, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-0.08>,
        0.08+LG_CORNER_SPACE
      }
    }
    // TOP PLATE
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
      LG_CORNER_SPACE
    }
    cylinder {
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>
      LG_CORNER_SPACE
    }
    torus {
      0.08-LG_CORNER_SPACE,
      LG_CORNER_SPACE
      rotate <90, 0, 0>
      translate <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
    }
    torus {
      0.08-LG_CORNER_SPACE,
      LG_CORNER_SPACE
      rotate <90, 0, 0>
      translate <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>
    }
    cylinder {
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
      0.08
    }
    cylinder {
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH>,
      <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT>,
      0.08-LG_CORNER_SPACE
    }
    difference {
      merge {
        box {
          <0, 0, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, -LG_E, HEIGHT*LG_BRICK_HEIGHT-LG_CORNER_SPACE>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH+LG_CORNER_SPACE>
        }
        box {
          <LG_CORNER_SPACE, 0, HEIGHT*LG_BRICK_HEIGHT>,
          <LG_BRICK_WIDTH-LG_CORNER_SPACE, 0.5*WIDTH*LG_BRICK_WIDTH-LG_CORNER_SPACE, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH>
        }
      }
      box {
        <LG_BRICK_WIDTH-0.08, 0.5*WIDTH*LG_BRICK_WIDTH-0.08, HEIGHT*LG_BRICK_HEIGHT-LG_WALL_WIDTH-LG_E>,
        <LG_BRICK_WIDTH+LG_E, 0.5*WIDTH*LG_BRICK_WIDTH+LG_E, HEIGHT*LG_BRICK_HEIGHT+LG_E>
      }
    }
    #if (MIR = 1)
    scale <1, -1, 1>
    #end
  }
  #declare MIR = MIR + 1;
  #end
  #declare KNOB_X = 0.5;
  #while (KNOB_X < WIDTH)
  object {
    lg_tech_knob_logo_clear
    translate <0.5*LG_BRICK_WIDTH, KNOB_X*LG_BRICK_WIDTH, HEIGHT*LG_BRICK_HEIGHT>
    translate <0, WIDTH/2*-LG_BRICK_WIDTH, 0>
  }
  #declare KNOB_X = KNOB_X + 1;
  #end
  translate <0.5*-LG_BRICK_WIDTH, 0, HEIGHT*-LG_BRICK_HEIGHT>
}

#end