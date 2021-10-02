//----- (10001140) --------------------------------------------------------
int __cdecl sub_10001140(int a1, int a2, int a3, int a4)
{
  int result; // eax@2
  int v5; // ecx@2
  int v6; // edi@3
  int v7; // esi@4
  int v8; // ecx@17
  int v9; // edx@17
  int v10; // ecx@17
  int v11; // edx@17
  int v12; // eax@18
  unsigned __int8 v13; // cf@19
  unsigned __int8 v14; // cl@21
  int v15; // eax@23
  int v16; // edx@26
  int v17; // ecx@26
  int v18; // edx@34
  int v19; // ecx@34
  unsigned __int8 v20; // zf@36
  char v21; // sf@36
  unsigned __int8 v22; // of@36
  int v23; // ecx@40
  int v24; // [sp+1Ch] [bp-4C4h]@28
  double v25; // [sp+20h] [bp-4C0h]@17
  double v26; // [sp+28h] [bp-4B8h]@7
  double v27; // [sp+30h] [bp-4B0h]@7
  double v28; // [sp+38h] [bp-4A8h]@7
  double v29; // [sp+40h] [bp-4A0h]@17
  char *String; // [sp+48h] [bp-498h]@17
  int v31; // [sp+4Ch] [bp-494h]@1
  int v32; // [sp+50h] [bp-490h]@1
  int v33; // [sp+54h] [bp-48Ch]@1
  int v34; // [sp+58h] [bp-488h]@1
  const char *v35; // [sp+5Ch] [bp-484h]@17
  int v36; // [sp+60h] [bp-480h]@7
  int v37; // [sp+64h] [bp-47Ch]@7
  int v38; // [sp+68h] [bp-478h]@7
  int v39; // [sp+6Ch] [bp-474h]@7
  __int64 v40; // [sp+78h] [bp-468h]@29
  int v41; // [sp+80h] [bp-460h]@29
  int v42; // [sp+84h] [bp-45Ch]@29
  int v43; // [sp+88h] [bp-458h]@29
  int v44; // [sp+8Ch] [bp-454h]@29
  double v45; // [sp+90h] [bp-450h]@17
  double v46; // [sp+98h] [bp-448h]@17
  double v47; // [sp+A0h] [bp-440h]@17
  double v48; // [sp+A8h] [bp-438h]@17
  double v49; // [sp+B0h] [bp-430h]@17
  double v50; // [sp+B8h] [bp-428h]@17
  int v51; // [sp+C0h] [bp-420h]@1
  __int16 v52; // [sp+C4h] [bp-41Ch]@1
  int v53; // [sp+C6h] [bp-41Ah]@1
  int v54; // [sp+CAh] [bp-416h]@1
  __int16 v55; // [sp+CEh] [bp-412h]@1
  int v56; // [sp+D0h] [bp-410h]@1
  int v57; // [sp+D4h] [bp-40Ch]@1
  char v58; // [sp+D8h] [bp-408h]@1
  int v59; // [sp+D9h] [bp-407h]@1
  __int16 v60; // [sp+DDh] [bp-403h]@1
  char v61; // [sp+DFh] [bp-401h]@1
  double v62; // [sp+E0h] [bp-400h]@17
  double v63; // [sp+E8h] [bp-3F8h]@17
  double v64; // [sp+F0h] [bp-3F0h]@17
  int v65; // [sp+F8h] [bp-3E8h]@34
  int v66; // [sp+FCh] [bp-3E4h]@34
  int v67; // [sp+100h] [bp-3E0h]@1
  int v68; // [sp+104h] [bp-3DCh]@1
  int v69; // [sp+108h] [bp-3D8h]@1
  int v70; // [sp+10Ch] [bp-3D4h]@1
  char v71; // [sp+110h] [bp-3D0h]@13
  char v72; // [sp+114h] [bp-3CCh]@32
  int v73; // [sp+11Ch] [bp-3C4h]@32
  char Dest; // [sp+12Ch] [bp-3B4h]@3
  __int64 v75; // [sp+258h] [bp-288h]@1
  int v76; // [sp+260h] [bp-280h]@1
  int v77; // [sp+264h] [bp-27Ch]@1
  int v78; // [sp+268h] [bp-278h]@1
  int v79; // [sp+26Ch] [bp-274h]@29
  __int16 v80; // [sp+348h] [bp-198h]@1
  char v81; // [sp+34Ah] [bp-196h]@1
  char v82; // [sp+34Bh] [bp-195h]@1
  __int16 v83; // [sp+3CBh] [bp-115h]@1
  char v84; // [sp+3D0h] [bp-110h]@40
  char v85; // [sp+3F4h] [bp-ECh]@32

  v75 = 0i64;
  v76 = 0;
  v77 = 0;
  memset(&v78, 0, 0xE0u);
  v51 = dword_1012B5B0;
  v53 = 0;
  v52 = word_1012B5B4;
  v54 = 0;
  v56 = dword_1012B5A4;
  v55 = 0;
  v57 = dword_1012B5A8;
  v59 = 0;
  v58 = byte_1012B5AC;
  v60 = 0;
  v80 = word_1012B5A0;
  v61 = 0;
  v81 = byte_1012B5A2;
  memset(&v82, 0, 0x80u);
  v31 = 0;
  v69 = 1;
  v70 = 1;
  v67 = 1;
  v68 = 1;
  v32 = 1079574528;
  v33 = 0;
  v34 = 1076101120;
  v83 = 0;
  if ( sub_10001CA0() == 1 )
  {
    v6 = a3;
    sprintf(&Dest, "Number of args %ld", a3);
    if ( a3 > 0 )
    {
      v7 = a4;
      do
      {
        sprintf(&Dest, "Arg 0 %s", *(_DWORD *)v7);
        v7 += 4;
        --v6;
      }
      while ( v6 );
    }
    if ( !strcmp(*(const char **)(a4 + 4), "PLANE_hole") )
    {
      UF_MOM_ask_assoc_double_array(a1, "out_angle_pos", L"0", &v36);
      UF_MOM_ask_assoc_double_array(a1, "out_angle_pos", L"1", &v38);
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"0", &v26);
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"1", &v27);
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"2", &v28);
      sprintf(&Dest, "MOM_output_literal \"ROT X%.3lf \"", v38, v39);
      UF_MOM_execute_command(a1, &Dest);
      sprintf(&Dest, "MOM_output_literal \"AROT Y%.3lf \"", v36, v37);
      UF_MOM_execute_command(a1, &Dest);
    }
    if ( !strcmp(*(const char **)(a4 + 4), "PLANE_UBZ") )
    {
      UF_MOM_ask_assoc_double_array(a1, "out_angle_pos", L"0", &v36);
      UF_MOM_ask_assoc_double_array(a1, "out_angle_pos", L"1", &v38);
      sprintf(&Dest, "MOM_output_literal \"ROT X%.3lf Z%.3lf \"", v36, v37, v38, v39);
      UF_MOM_execute_command(a1, &Dest);
    }
    if ( !strcmp(*(const char **)(a4 + 4), "PLANE_moving_UBZ") )
    {
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"0", &v26);
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"1", &v27);
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"2", &v28);
      sprintf(&Dest, "MOM_output_literal \"G0 X%.3lf Y%.3lf \"", *(_QWORD *)&v26, *(_QWORD *)&v27);
      UF_MOM_execute_command(a1, &Dest);
      sprintf(&Dest, "MOM_output_literal \"G0 Z%.3lf \"", *(_QWORD *)&v28);
      UF_MOM_execute_command(a1, &Dest);
    }
    if ( !strcmp(*(const char **)(a4 + 4), "INPUT_ZERO") )
    {
      UF_UI_close_listing_window();
      UF_UI_lock_ug_access(1);
      uc1600(&unk_1012B338, &v80, &v71);
      UF_MOM_set_string(a1, "zero", &v80);
      UF_UI_unlock_ug_access(1);
    }
    if ( !strcmp(*(const char **)(a4 + 4), "INPUT_RETRACT") )
    {
      UF_UI_close_listing_window();
      UF_UI_lock_ug_access(1);
      uc1608(&unk_1012B2F0, &v51, 2, &v69, &v31, &v67);
      UF_MOM_set_double(a1, "kin_retract_distance", v31, v32);
      UF_MOM_set_double(a1, "kin_reengage_distance", v33, v34);
      UF_UI_unlock_ug_access(1);
    }
    if ( !strcmp(*(const char **)(a4 + 4), "INPUT_RETRACT_DIST") )
    {
      uc1601(&unk_1012B288, 0);
      UF_MOM_ask_assoc_double_array(a1, "prev_mcs_goto", L"0", &v62);
      UF_MOM_ask_assoc_double_array(a1, "prev_mcs_goto", L"1", &v63);
      UF_MOM_ask_assoc_double_array(a1, "prev_mcs_goto", L"2", &v64);
      UF_MOM_ask_assoc_double_array(a1, "prev_tool_axis", L"0", &v48);
      UF_MOM_ask_assoc_double_array(a1, "prev_tool_axis", L"1", &v49);
      UF_MOM_ask_assoc_double_array(a1, "prev_tool_axis", L"2", &v50);
      UF_MOM_ask_string(a1, "kin_retract_distance", &String);
      UF_MOM_ask_string(a1, "kin_reengage_distance", &v35);
      v29 = atof(String);
      v25 = atof(v35);
      UF_free(String);
      v26 = v48 * v29 + v62;
      v27 = v49 * v29 + v63;
      v28 = v50 * v29 + v64;
      v45 = v48 * v25 + v62;
      v46 = v49 * v25 + v63;
      v47 = v50 * v25 + v64;
      UF_MOM_set_assoc_double_array(v8, COERCE_UNSIGNED_INT64(v48 * v29 + v62) >> 32);
      UF_MOM_set_assoc_double_array(HIDWORD(v27), LODWORD(v27));
      UF_MOM_set_assoc_double_array(LODWORD(v28), v9);
      UF_MOM_set_assoc_double_array(v10, HIDWORD(v45));
      UF_MOM_set_assoc_double_array(HIDWORD(v46), LODWORD(v46));
      UF_MOM_set_assoc_double_array(LODWORD(v47), v11);
    }
    LODWORD(v25) = "M128";
    v12 = *(_DWORD *)(a4 + 4);
    while ( 1 )
    {
      v13 = *(_BYTE *)v12 < *LODWORD(v25);
      if ( *(_BYTE *)v12 != *LODWORD(v25) )
        break;
      if ( !*(_BYTE *)v12 )
        goto LABEL_23;
      v14 = *(_BYTE *)(v12 + 1);
      v13 = v14 < *(_BYTE *)(LODWORD(v25) + 1);
      if ( v14 != *(_BYTE *)(LODWORD(v25) + 1) )
        break;
      v12 += 2;
      LODWORD(v25) += 2;
      if ( !v14 )
      {
LABEL_23:
        v15 = 0;
        goto LABEL_25;
      }
    }
    v15 = -v13 - (v13 - 1);
LABEL_25:
    if ( !v15 )
    {
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"0", &v26);
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"1", &v27);
      UF_MOM_ask_assoc_double_array(a1, "mcs_goto", L"2", &v28);
      UF_MOM_set_assoc_double_array(LODWORD(v26), v16);
      UF_MOM_set_assoc_double_array(v17, HIDWORD(v27));
      UF_MOM_set_assoc_double_array(HIDWORD(v28), LODWORD(v28));
    }
    if ( !strcmp(*(const char **)(a4 + 4), "VICE_PBZ") )
    {
      uc1601("VICES...", 0);
      LODWORD(v29) = 0;
      UF_OBJ_cycle_by_name("POINT0", &v24);
      if ( v24 )
      {
        UF_OBJ_ask_name_origin(v24, &v40);
        v75 = v40;
        v76 = v41;
        v77 = v42;
        v78 = v43;
        v79 = v44;
      }
      else
      {
        uc1601(&unk_1012B1DC, 1);
      }
      LODWORD(v25) = 1;
      do
      {
        sprintf(&v85, "POINT%d", LODWORD(v25));
        UF_UI_write_listing_window(&v85);
        UF_OBJ_cycle_by_name(&v85, &v24);
        UF_OBJ_ask_display_properties(v24, &v72);
        UF_DISP_set_highlight(v24, 1);
        sprintf(&Dest, "%d", v73);
        if ( !v24 || v73 )
        {
          uc1601("Not_found or blanked", 0);
          UF_DISP_set_highlight(v24, 0);
          sprintf(&Dest, "Кле", &v85);
          UF_UI_write_listing_window(&Dest);
        }
        else
        {
          ++LODWORD(v29);
          UF_OBJ_ask_name_origin(v24, &v40);
          UF_VEC3_distance(&v75, &v40, &v65);
          sprintf(&Dest, "Ди", &v85, v65, v66);
          UF_UI_write_listing_window(&Dest);
          UF_DISP_set_highlight(v24, 0);
          sprintf(&v85, "%d", LODWORD(v25));
          UF_MOM_set_assoc_double_array(HIDWORD(v40), v40);
        }
        v22 = __SETO__(LODWORD(v25) + 1, 15);
        v20 = LODWORD(v25) == 14;
        v21 = LODWORD(v25)++ - 14 < 0;
      }
      while ( (unsigned __int8)(v21 ^ v22) | v20 );
      UF_MOM_set_assoc_double_array(v19, v18);
      v24 = 0;
    }
    if ( !strcmp(*(const char **)(a4 + 4), "UNLOAD") )
      dword_10145AE4 = 0;
    UF_MOM_set_string(a1, &v84, &Dest);
    UF_terminate(v23);
    result = 0;
  }
  else
  {
    UF_UI_display_nonmodal_msg("Внимание!", &unk_1012B4AC, 0);
    UF_terminate(v5);
    result = 0;
  }
  return result;
}
// 100029A0: using guessed type int __cdecl UF_VEC3_distance(_DWORD, _DWORD, _DWORD);
// 10122