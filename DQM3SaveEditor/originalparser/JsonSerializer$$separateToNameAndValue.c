JsonSerializer_SeparateString_o *JsonSerializer__separateToNameAndValue(JsonSerializer_SeparateString_o *retstr, System_ReadOnlySpan_char__o *json, const MethodInfo *method)
{
  JsonSerializer_c *v5; // rcx
  int v6; // edi
  int v7; // ebx
  intptr_t v8; // r15
  bool v9; // cf
  struct System_ReadOnlySpan_char__o v10; // xmm0
  unsigned int v12; // er15
  _WORD *v13; // rdi
  __int64 v14; // rcx
  __int64 v15; // rcx
  struct System_ReadOnlySpan_char__o v16; // xmm6
  unsigned int v17; // ebx
  _WORD *v18; // rdi
  __int64 v19; // rcx
  __int128 *v20; // rax
  struct System_ReadOnlySpan_char__o v21; // xmm1
  __int128 v22; // xmm0
  int v23; // edi
  int v24; // ebx
  intptr_t v25; // rsi
  __int64 v26; // rcx
  struct System_ReadOnlySpan_char__o v27; // xmm0
  signed __int32 v28[8]; // [rsp+0h] [rbp-100h] BYREF
  struct System_ReadOnlySpan_char__o v29; // [rsp+20h] [rbp-E0h]
  struct System_ReadOnlySpan_char__o v30; // [rsp+30h] [rbp-D0h]
  System_ReadOnlySpan_char__o v31; // [rsp+40h] [rbp-C0h]
  struct System_ReadOnlySpan_char__o v32; // [rsp+50h] [rbp-B0h]
  System_ReadOnlySpan_char__o v33; // [rsp+60h] [rbp-A0h]
  struct System_ReadOnlySpan_char__o v34; // [rsp+70h] [rbp-90h]
  System_ReadOnlySpan_char__o v35; // [rsp+80h] [rbp-80h] BYREF
  System_ReadOnlySpan_char__o v36; // [rsp+90h] [rbp-70h] BYREF
  __int128 v37; // [rsp+A0h] [rbp-60h]
  struct System_ReadOnlySpan_char__o v38; // [rsp+B0h] [rbp-50h]
  __int128 v39; // [rsp+C0h] [rbp-40h]
  JsonSerializer_InsideBraces_o v40; // [rsp+100h] [rbp+0h] BYREF

  if ( !byte_18579D5FB )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice__);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice___6531935520);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Empty__);
    _InterlockedOr(v28, 0);
    byte_18579D5FB = 1;
  }
  v5 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  v33 = *json;
  if ( !byte_18579D5FC )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Utility_TypeInfo);
    _InterlockedOr(v28, 0);
    byte_18579D5FC = 1;
  }
  v6 = v33.fields._length;
  v7 = 0;
  if ( v33.fields._length <= 0 )
    goto LABEL_16;
  v8 = v33.fields._pointer.fields._value;
  v9 = v33.fields._length != 0;
  while ( 1 )
  {
    if ( !v9 )
      goto LABEL_44;
    v5 = (JsonSerializer_c *)*(unsigned __int16 *)(v8 + 2i64 * v7);
    if ( (_WORD)v5 == 58 )
      break;
    if ( (_WORD)v5 != 34 )
      goto LABEL_48;
    if ( !Utility_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Utility_TypeInfo, json);
    v35 = *json;
    v7 = Utility__searchStringEndIndex_6455484992(&v35, v7, 0i64);
    if ( v7 >= 0 )
    {
LABEL_48:
      v9 = ++v7 < (unsigned int)v6;
      if ( v7 < v6 )
        continue;
    }
    goto LABEL_16;
  }
  if ( v7 < 0 )
  {
LABEL_16:
    retstr->fields.name = 0i64;
    v10 = *json;
    retstr->fields.nextVariable = 0i64;
    retstr->fields.value = v10;
    return retstr;
  }
  v12 = json->fields._length;
  if ( v7 > v12 )
LABEL_45:
    System_ThrowHelper__ThrowArgumentOutOfRangeException(0i64);
  v13 = (_WORD *)json->fields._pointer.fields._value;
  *(&v30.fields._length + 1) = 0;
  v14 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice___6531935520 + 32);
  if ( (*(_BYTE *)(v14 + 309) & 1) == 0 )
    sub_1804E30B0(v14);
  v5 = JsonSerializer_TypeInfo;
  v30.fields._pointer.fields._value = (intptr_t)v13;
  v30.fields._length = v7;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  if ( !byte_18579D5FD )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice___6531935520);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v28, 0);
    byte_18579D5FD = 1;
  }
  if ( !v7 )
    goto LABEL_44;
  if ( *v13 != 34 )
  {
LABEL_34:
    v16 = v30;
    goto LABEL_35;
  }
  if ( v7 - 1 >= (unsigned int)v7 )
LABEL_44:
    sub_1804BDCB0(v5, json, method);
  if ( v13[v7 - 1] != 34 )
    goto LABEL_34;
  if ( v7 - 2 > (unsigned int)(v7 - 1) )
    goto LABEL_45;
  *(&v29.fields._length + 1) = 0;
  v15 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice___6531935520 + 32);
  if ( (*(_BYTE *)(v15 + 309) & 1) == 0 )
    sub_1804E30B0(v15);
  v29.fields._pointer.fields._value = (intptr_t)(v13 + 1);
  v29.fields._length = v7 - 2;
  v16 = v29;
LABEL_35:
  v17 = v7 + 1;
  v34 = v16;
  if ( v17 > v12 )
    goto LABEL_45;
  *(&v31.fields._length + 1) = 0;
  v18 = &v13[v17];
  v19 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice__ + 32);
  if ( (*(_BYTE *)(v19 + 309) & 1) == 0 )
    sub_1804E30B0(v19);
  v31.fields._pointer.fields._value = (intptr_t)v18;
  v31.fields._length = v12 - v17;
  v36 = v31;
  v20 = (__int128 *)JsonSerializer__extractInsideBraces(&v40, &v36, 0, 0i64);
  v21 = (struct System_ReadOnlySpan_char__o)v20[1];
  v37 = *v20;
  v22 = v20[2];
  v38 = v21;
  v39 = v22;
  if ( !byte_18579ED1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice__);
    _InterlockedOr(v28, 0);
    v16 = v34;
    byte_18579ED1D = 1;
  }
  v23 = DWORD2(v39);
  v24 = DWORD2(v37);
  if ( DWORD2(v39) > DWORD2(v37) )
    goto LABEL_45;
  *(&v32.fields._length + 1) = 0;
  v25 = v37 + 2i64 * SDWORD2(v39);
  v26 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice__ + 32);
  if ( (*(_BYTE *)(v26 + 309) & 1) == 0 )
    sub_1804E30B0(v26);
  v32.fields._pointer.fields._value = v25;
  v32.fields._length = v24 - v23;
  v27 = v32;
  retstr->fields.name = v16;
  retstr->fields.nextVariable = v27;
  retstr->fields.value = v21;
  return retstr;
}
