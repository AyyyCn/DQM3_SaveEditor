bool __stdcall JsonSerializer__analyze_object_(System_ReadOnlySpan_char__o *json, System_String_o *root_name, Il2CppObject **dst, const MethodInfo_199B890 *method)
{
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  __int128 v10; // xmm0
  System_ReadOnlySpan_char__o v11; // xmm6
  _WORD *v12; // rdi
  __int128 *v13; // rax
  __int64 v14; // rdx
  __int64 v15; // r8
  unsigned int v16; // eax
  JsonSerializer_c *v17; // rcx
  __int64 v18; // rax
  Il2CppType *v19; // rbx
  __int64 v20; // rdx
  System_Type_o *v21; // rbx
  Il2CppObject *v22; // rdi
  const MethodInfo_199B890_RGCTXs *v23; // rcx
  __int64 v24; // rbx
  Il2CppObject *v25; // rax
  const MethodInfo_199B890_RGCTXs *v26; // rax
  __int64 v27; // rbx
  unsigned int v28; // er14
  __int64 *v29; // rdx
  char v30; // r14
  __int64 v31; // rtt
  signed __int32 v33[12]; // [rsp+0h] [rbp-148h] BYREF
  __int128 v34; // [rsp+30h] [rbp-118h]
  __int128 v35; // [rsp+40h] [rbp-108h]
  int v36; // [rsp+58h] [rbp-F0h]
  __int128 v37; // [rsp+60h] [rbp-E8h]
  System_ReadOnlySpan_char__o v38; // [rsp+70h] [rbp-D8h]
  System_ReadOnlySpan_char__o v39; // [rsp+80h] [rbp-C8h]
  System_ReadOnlySpan_char__o v40; // [rsp+A0h] [rbp-A8h] BYREF
  System_ReadOnlySpan_char__o v41; // [rsp+B0h] [rbp-98h] BYREF
  __int128 v42; // [rsp+C0h] [rbp-88h]
  __int128 v43; // [rsp+F0h] [rbp-58h]
  JsonSerializer_SeparateString_o v44; // [rsp+100h] [rbp-48h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v33, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v33, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v33, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v8 = 0;
  v36 = 0;
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v33, 0);
    byte_18579AC1D = 1;
  }
  if ( root_name )
  {
    v9 = root_name->fields._stringLength;
    *(_QWORD *)&v34 = &root_name->fields._firstChar;
    *((_QWORD *)&v34 + 1) = v9;
    v10 = v34;
  }
  else
  {
    v10 = 0i64;
    v43 = 0i64;
  }
  v35 = v10;
  v11 = *json;
  v12 = (_WORD *)v10;
  do
  {
LABEL_10:
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      ((void (*)(void))il2cpp_runtime_class_init_0)();
    v40 = v11;
    v13 = (__int128 *)JsonSerializer__separateToNameAndValue(&v44, &v40, 0i64);
    v37 = *v13;
    v38 = (System_ReadOnlySpan_char__o)v13[1];
    v11 = (System_ReadOnlySpan_char__o)v13[2];
    v39 = v11;
    if ( _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v11, 8)) <= 0 )
      goto LABEL_24;
    v42 = *v13;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      ((void (*)(void))il2cpp_runtime_class_init_0)();
    if ( !byte_18579D603 )
    {
      sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
      _InterlockedOr(v33, 0);
      byte_18579D603 = 1;
      v11 = v39;
    }
  }
  while ( DWORD2(v42) != DWORD2(v10) );
  v16 = 0;
  v14 = 0i64;
  if ( SDWORD2(v42) > 0 )
  {
    v17 = (JsonSerializer_c *)v10;
    while ( v16 < DWORD2(v42) )
    {
      v15 = *(unsigned __int16 *)((char *)&v17->_1.image + v42 - v10);
      if ( v16 >= DWORD2(v10) )
        break;
      if ( (_WORD)v15 != LOWORD(v17->_1.image) )
        goto LABEL_10;
      ++v16;
      ++v14;
      v17 = (JsonSerializer_c *)((char *)v17 + 2);
      if ( v14 >= SDWORD2(v42) )
        goto LABEL_24;
    }
LABEL_53:
    sub_1804BDCB0(v17, v14, v15);
  }
LABEL_24:
  v17 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v14);
  if ( !byte_18579D603 )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v33, 0);
    byte_18579D603 = 1;
  }
  v14 = SDWORD2(v37);
  if ( DWORD2(v37) != DWORD2(v10) )
    return 0;
  if ( SDWORD2(v37) > 0 )
  {
    v18 = 0i64;
    v15 = v37 - v10;
    while ( v8 < DWORD2(v37) )
    {
      v17 = (JsonSerializer_c *)*(unsigned __int16 *)((char *)v12 + v15);
      if ( v8 >= DWORD2(v10) )
        break;
      if ( (_WORD)v17 != *v12 )
        return 0;
      ++v8;
      ++v18;
      ++v12;
      if ( v18 >= SDWORD2(v37) )
        goto LABEL_35;
    }
    goto LABEL_53;
  }
LABEL_35:
  v19 = method->rgctx_data->_0_T;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, SDWORD2(v37));
  v21 = System_Type__GetTypeFromHandle((System_RuntimeTypeHandle_o)v19, 0i64);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v20);
  v41 = v38;
  v22 = JsonSerializer__analyze(&v41, v21, 0i64);
  if ( v22 )
  {
    v23 = method->rgctx_data;
    v24 = (__int64)v23->_2_T;
    if ( (*(_BYTE *)(v24 + 309) & 1) == 0 )
      v24 = sub_1804E30B0(v23->_2_T);
    v25 = (Il2CppObject *)sub_180481AF0(v22, v24);
    if ( !v25 )
      sub_1804BE2F0(v22, v24);
    *dst = v25;
    v26 = method->rgctx_data;
    v27 = (__int64)v26->_2_T;
    if ( (*(_BYTE *)(v27 + 309) & 1) == 0 )
      v27 = sub_1804E30B0(v26->_2_T);
    if ( !sub_180481AF0(v22, v27) )
      sub_1804BE2F0(v22, v27);
    if ( dword_18579B674 )
    {
      v28 = ((unsigned __int64)dst >> 12) & 0x1FFFFF;
      v29 = &qword_185801160[(unsigned __int64)v28 >> 6];
      v30 = v28 & 0x3F;
      _m_prefetchw(v29);
      do
        v31 = *v29;
      while ( v31 != _InterlockedCompareExchange64(v29, *v29 | (1i64 << v30), *v29) );
    }
  }
  else
  {
    *dst = 0i64;
  }
  return 1;
}
