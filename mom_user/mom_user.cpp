//////////////////////////////////////////////////////////////////////////////
//
//  mom_user.cpp
//
//  Description:
//      Contains Unigraphics entry points for the application.
//
//////////////////////////////////////////////////////////////////////////////

// #define _CRT_SECURE_NO_DEPRECATE 1

//  Include files
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <uf.h>
#include <uf_exit.h>
#include <uf_ui.h>
#include <uf_mom.h>

#include <uf_vec.h>
#include <uf_obj.h>

#include "mom_user.h"

//----------------------------------------------------------------------------

/*
 * Exported Tcl procedures:
 */
static int sub_10001140
(
  void *client_data,    /* This is the mom object */
  void *interp,         /* Pointer to the TCL interpreter */
  int  argc,            /* Count of the numnber of arguments */
  char **argv           /* Array of arguments where the
                           argv[0] - The TCL extension */
);

//----------------------------------------------------------------------------
//  Activation Methods
//----------------------------------------------------------------------------

//  Explicit Activation
//      This entry point is used to activate the application explicitly, as in
//      "File->Execute UG/Open->User Function..."
//----- (10001010) --------------------------------------------------------
extern "C" DllExport void entry_rtv_mom_cp_part_attr( char *parm, int *returnCode, int rlen )
{
  int errorCode ;
  UF_MOM_id_t mom ;
  void *interp = NULL ;

  if ( !UF_is_initialized() )
  {
    errorCode = UF_initialize();
    *returnCode = errorCode;
  }

  /* Get the TCL interpreter id from the ufusr param */
  // UF_MOM_ask_interp_from_param ( parm, &interp ) ;
  /* Get the MOM id from the ufusr param */
  UF_MOM_ask_mom (parm, &mom) ;
  /*Создаем функции в интепретаторе*/
  UF_MOM_extend_xlator ( mom , "EXTN_rtv_mom_cp_part_attr", sub_10001140 ) ;

  errorCode = UF_terminate();
  *returnCode = errorCode;
}


//----------------------------------------------------------------------------
//  Utilities
//----------------------------------------------------------------------------

// Unload Handler
//     This function specifies when to unload your application from Unigraphics.
//     If your application registers a callback (from a MenuScript item or a
//     User Defined Object for example), this function MUST return
//     "UF_UNLOAD_UG_TERMINATE".
extern "C" int ufusr_ask_unload( void )
{
     /* unload immediately after application exits*/
     //return ( UF_UNLOAD_IMMEDIATELY );

     /*via the unload selection dialog... */
     return ( UF_UNLOAD_SEL_DIALOG );
     /*when UG terminates...              */
     //return ( UF_UNLOAD_UG_TERMINATE );
}


/*-----------------------------------------------------------------------
 * Function Name: sub_10001140
 *
 *
 -----------------------------------------------------------------------*/
static int sub_10001140
(
  void *client_data,    /* This is the mom object */
  void *interp,         /* Pointer to the TCL interpreter */
  int  argc,            /* Count of the numnber of arguments */
  char **argv           /* Array of arguments where the
                           argv[0] - The TCL extension */
)
{
  UF_MOM_id_t mom_id = ( UF_MOM_id_t ) client_data ;

  char    Dest[256] ;
  double  angle1 , angle2 ;
  double  x , y , z , i , j , k ;
  const char *kin_retract_distance ;
  double  retract_distance ;
  const char *kin_reengage_distance;
  double  reengage_distance ;
  double  dx11 , dy12 , dz13 , dx21 , dy22 , dz23 ;
  int  dword_10003334 = 0 ;


    if (0==strcmp(argv[1],"PLANE_hole"))
    {
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "0", &angle1);
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "1", &angle2);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "0", &x);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "1", &y);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "2", &z);
      sprintf(Dest, "MOM_output_literal \"ROT X%.3lf \"", angle2);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"AROT Y%.3lf \"", angle1);
      UF_MOM_execute_command(mom_id, Dest);
    }

    if (0==strcmp(argv[1],"PLANE_UBZ"))
    {
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "0", &angle1);
      UF_MOM_ask_assoc_double_array(mom_id, "out_angle_pos", "1", &angle2);
      sprintf(Dest, "MOM_output_literal \"ROT X%.3lf Z%.3lf \"", angle1, angle2);
      UF_MOM_execute_command(mom_id, Dest);
    }

    if (0==strcmp(argv[1],"PLANE_moving_UBZ"))
    {
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "0", &x);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "1", &y);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "2", &z);
      sprintf(Dest, "MOM_output_literal \"G0 X%.3lf Y%.3lf \"", x, y);
      UF_MOM_execute_command(mom_id, Dest);
      sprintf(Dest, "MOM_output_literal \"G0 Z%.3lf \"", z);
      UF_MOM_execute_command(mom_id, Dest);
    }

    if (0==strcmp(argv[1], "INPUT_ZERO") )
    {
      char ca2[133]="54\0" ;
      int  ir3 ;
      UF_UI_close_listing_window();
      UF_UI_lock_ug_access(UF_UI_FROM_CUSTOM);
      uc1600(":Введите номер нуля программы G", ca2, &ir3);
      UF_MOM_set_string(mom_id, "zero", ca2);
      UF_UI_unlock_ug_access(UF_UI_FROM_CUSTOM);
    }

    if (0==strcmp(argv[1],"INPUT_RETRACT"))
    {
      int  ia4[2]={0,0},
           ip6[2] = {1,1},
           resp;
      double ra5[2] = { 100, 100 } ;
      char   menu[2][16]; //={":Отвод=",":Врезание="};
      strcpy(&menu[0][0], ":Отвод (мм)=");
      strcpy(&menu[1][0], ":Врезание (мм)=");

      UF_UI_close_listing_window();
      UF_UI_lock_ug_access(UF_UI_FROM_CUSTOM);
      resp = uc1608(":Введите значения отвода и врезания инструмента:", menu, 2, ia4, ra5, ip6);
      UF_MOM_set_double(mom_id, "kin_retract_distance", ra5[0]);
      UF_MOM_set_double(mom_id, "kin_reengage_distance", ra5[1]);
      UF_UI_unlock_ug_access(UF_UI_FROM_CUSTOM);
    }

    if (0==strcmp(argv[1],"INPUT_RETRACT_DIST"))
    {
      uc1601(":Ввод дистанций отвода и врезания:", 0);
      UF_MOM_ask_assoc_double_array(mom_id, "prev_mcs_goto", "0", &x);
      UF_MOM_ask_assoc_double_array(mom_id, "prev_mcs_goto", "1", &y);
      UF_MOM_ask_assoc_double_array(mom_id, "prev_mcs_goto", "2", &z);
      UF_MOM_ask_assoc_double_array(mom_id, "prev_tool_axis", "0", &i);
      UF_MOM_ask_assoc_double_array(mom_id, "prev_tool_axis", "1", &j);
      UF_MOM_ask_assoc_double_array(mom_id, "prev_tool_axis", "2", &k);
      UF_MOM_ask_string(mom_id, "kin_retract_distance", &kin_retract_distance);
      UF_MOM_ask_string(mom_id, "kin_reengage_distance", &kin_reengage_distance);
      retract_distance=atof(kin_retract_distance);
      reengage_distance=atof(kin_reengage_distance);
      //UF_free(&kin_retract_distance);
      //UF_free(&kin_reengage_distance);

      dx11=i*retract_distance + x ;
      dy12=j*retract_distance + y ;
      dz13=k*retract_distance + z ;

      dx21=i*reengage_distance + x ;
      dy22=j*reengage_distance + y ;
      dz23=k*reengage_distance + z ;

      UF_MOM_set_assoc_double_array(mom_id, "pos", "0", dx11);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "1", dy12);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "2", dz13);

      UF_MOM_set_assoc_double_array(mom_id, "pos_reen", "0", dx21);
      UF_MOM_set_assoc_double_array(mom_id, "pos_reen", "1", dy22);
      UF_MOM_set_assoc_double_array(mom_id, "pos_reen", "2", dz23);
    }

    if ( 0==strcmp(argv[1], "M128") )
    {
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "0", &x);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "1", &y);
      UF_MOM_ask_assoc_double_array(mom_id, "mcs_goto", "2", &z);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "0", x);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "1", y);
      UF_MOM_set_assoc_double_array(mom_id, "pos", "2", z);
    }

    if ( 0==strcmp(argv[1], "VICE_PBZ") )
    {
        tag_t obj1 = NULL_TAG;
        UF_OBJ_disp_props_t   disp_props;
        double origin0[3] , origin[3] ;
        double dist ;
        int ii ;
        char str[80], skl[20], sind[10];

        uc1601("VICES...", 0);
        UF_OBJ_cycle_by_name("POINT0", &obj1);
        if ( obj1==NULL_TAG )
        {
          uc1601("Базовые клещи (тиски) не найдены!\nРассчет дистанций тисков не может быть произведен", 1);
        }
        else
        {
          UF_OBJ_ask_name_origin(obj1, origin0);
          ii = 1 ;
          do {
              sprintf(sind, "%d", ii);
              sprintf(skl, "POINT%d", ii);
              UF_UI_write_listing_window(skl);
              UF_OBJ_cycle_by_name(skl, &obj1);
              UF_OBJ_ask_display_properties(obj1, &disp_props);
              UF_DISP_set_highlight(obj1, 1);
              if ( obj1==NULL_TAG || disp_props.blank_status==UF_OBJ_NOT_BLANKED )
              {
                uc1601("Not_found or blanked", 0);
                UF_DISP_set_highlight(obj1, 0);
                sprintf(str, "Клещи %s не найдены либо погашены", skl);
                UF_UI_write_listing_window(str);
                UF_MOM_set_assoc_double_array(mom_id, "vice_X_coord", sind, 0.0);
              }
              else
              {
                UF_OBJ_ask_name_origin(obj1, origin);
                UF_VEC3_distance(origin0, origin, &dist);
                sprintf(str, "Дистанция клещей %s = %f %d", skl, dist, ii);
                UF_UI_write_listing_window(str);
                UF_DISP_set_highlight(obj1, 0);
                UF_MOM_set_assoc_double_array(mom_id, "vice_X_coord", sind, origin[0]);
              }
              ii ++ ;
          } while (ii<15);
          UF_MOM_set_assoc_double_array(mom_id, "vice_X_coord", "0", origin0[0]);
       }
    }

    if ( !strcmp(argv[1], "UNLOAD") ) dword_10003334 = 0;

  return ( 0 ) ;
}

