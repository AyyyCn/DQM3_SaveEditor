bool __stdcall JsonSerializer__analyze___Il2CppFullySharedGenericType_(System_ReadOnlySpan_char__o *json, System_String_o *root_name, Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *dst, const MethodInfo_199BC70 *method)
{
  System_String_o *v6; // rdi
  unsigned __int64 v8; // r13
  __int64 v9; // rax
  void *v10; // rsp
  Il2CppObject *v11; // r12
  unsigned int v12; // ebx
  unsigned int v13; // ecx
  __int128 v14; // xmm0
  System_ReadOnlySpan_char__o v15; // xmm6
  _WORD *v16; // rdi
  __int128 *v17; // rax
  __int64 v18; // r8
  unsigned int v19; // eax
  JsonSerializer_c *v20; // rcx
  __int64 v21; // rax
  Il2CppType *v22; // rbx
  __int64 v23; // rdx
  System_Type_o *v24; // rbx
  Il2CppObject *v25; // rdi
  const MethodInfo_199BC70_RGCTXs *v26; // rcx
  __int64 v27; // rbx
  Il2CppClass *v28; // rdx
  __int64 v29; // rcx
  char *v30; // r9
  __int64 v31; // rax
  char *v32; // rcx
  __int64 v33; // rax
  Il2CppClass *v34; // rcx
  unsigned int v35; // er14
  __int64 *v36; // rdx
  char v37; // r14
  __int64 v38; // rtt
  signed __int32 v40[8]; // [rsp+0h] [rbp-20h] BYREF
  _QWORD v41[2]; // [rsp+20h] [rbp+0h] BYREF
  __int128 v42; // [rsp+30h] [rbp+10h]
  __int128 v43; // [rsp+40h] [rbp+20h]
  int v44; // [rsp+58h] [rbp+38h]
  __int128 v45; // [rsp+60h] [rbp+40h]
  System_ReadOnlySpan_char__o v46; // [rsp+70h] [rbp+50h]
  System_ReadOnlySpan_char__o v47; // [rsp+80h] [rbp+60h]
  System_ReadOnlySpan_char__o v48; // [rsp+A0h] [rbp+80h] BYREF
  System_ReadOnlySpan_char__o v49; // [rsp+B0h] [rbp+90h] BYREF
  __int128 v50; // [rsp+C0h] [rbp+A0h]
  __int128 v51; // [rsp+F0h] [rbp+D0h]
  JsonSerializer_SeparateString_o v52; // [rsp+100h] [rbp+E0h] BYREF

  v6 = root_name;
  if ( !method->rgctx_data )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v40, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v40, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v40, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v8 = method->rgctx_data->_2_T->_2.actualSize;
  v9 = v8 + 15;
  if ( v8 + 15 <= v8 )
    v9 = 0xFFFFFFFFFFFFFF0i64;
  v10 = alloca(v9 & 0xFFFFFFFFFFFFFFF0ui64);
  v11 = (Il2CppObject *)v41;
  v12 = 0;
  v44 = 0;
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v40, 0);
    byte_18579AC1D = 1;
  }
  if ( v6 )
  {
    v13 = v6->fields._stringLength;
    *(_QWORD *)&v42 = &v6->fields._firstChar;
    *((_QWORD *)&v42 + 1) = v13;
    v14 = v42;
  }
  else
  {
    v14 = 0i64;
    v51 = 0i64;
  }
  v43 = v14;
  v15 = *json;
  v16 = (_WORD *)v14;
  do
  {
LABEL_12:
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, root_name);
    v48 = v15;
    v17 = (__int128 *)JsonSerializer__separateToNameAndValue(&v52, &v48, 0i64);
    v45 = *v17;
    v46 = (System_ReadOnlySpan_char__o)v17[1];
    v15 = (System_ReadOnlySpan_char__o)v17[2];
    v47 = v15;
    if ( _mm_cvtsi128_si32(_mm_srli_si128((__m128i)v15, 8)) <= 0 )
      goto LABEL_26;
    v50 = *v17;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, root_name);
    if ( !byte_18579D603 )
    {
      sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
      _InterlockedOr(v40, 0);
      byte_18579D603 = 1;
      v15 = v47;
    }
  }
  while ( DWORD2(v50) != DWORD2(v14) );
  v19 = 0;
  root_name = 0i64;
  if ( SDWORD2(v50) > 0 )
  {
    v20 = (JsonSerializer_c *)v14;
    while ( v19 < DWORD2(v50) )
    {
      v18 = *(unsigned __int16 *)((char *)&v20->_1.image + v50 - v14);
      if ( v19 >= DWORD2(v14) )
        break;
      if ( (_WORD)v18 != LOWORD(v20->_1.image) )
        goto LABEL_12;
      ++v19;
      root_name = (System_String_o *)((char *)root_name + 1);
      v20 = (JsonSerializer_c *)((char *)v20 + 2);
      if ( (__int64)root_name >= SDWORD2(v50) )
        goto LABEL_26;
    }
LABEL_65:
    sub_1804BDCB0(v20, root_name, v18);
  }
LABEL_26:
  v20 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, root_name);
  if ( !byte_18579D603 )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v40, 0);
    byte_18579D603 = 1;
  }
  root_name = (System_String_o *)SDWORD2(v45);
  if ( DWORD2(v45) != DWORD2(v14) )
    return 0;
  if ( SDWORD2(v45) > 0 )
  {
    v21 = 0i64;
    v18 = v45 - v14;
    while ( v12 < DWORD2(v45) )
    {
      v20 = (JsonSerializer_c *)*(unsigned __int16 *)((char *)v16 + v18);
      if ( v12 >= DWORD2(v14) )
        break;
      if ( (_WORD)v20 != *v16 )
        return 0;
      ++v12;
      ++v21;
      ++v16;
      if ( v21 >= SDWORD2(v45) )
        goto LABEL_37;
    }
    goto LABEL_65;
  }
LABEL_37:
  v22 = method->rgctx_data->_0_T;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, SDWORD2(v45));
  v24 = System_Type__GetTypeFromHandle((System_RuntimeTypeHandle_o)v22, 0i64);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v23);
  v49 = v46;
  v25 = JsonSerializer__analyze(&v49, v24, 0i64);
  if ( v25 )
  {
    v26 = method->rgctx_data;
    v27 = (__int64)v26->_2_T;
    if ( (*(_BYTE *)(v27 + 309) & 1) == 0 )
      v27 = sub_1804E30B0(v26->_2_T);
    if ( *(int *)(v27 + 40) >= 0 )
    {
      v33 = sub_180481AF0(v25, v27);
      if ( !v33 )
        sub_1804BE2F0(v25, v27);
      v41[0] = v33;
    }
    else if ( *(_QWORD *)(v27 + 96) && (*(_BYTE *)(v27 + 309) & 8) != 0 )
    {
      v28 = *(Il2CppClass **)(v27 + 64);
      if ( v25->klass != v28 )
        sub_1804BE2F0(v25, v28);
      v29 = *(_QWORD *)(v27 + 128);
      v30 = (char *)v41 + *(int *)(v29 + 56);
      v31 = *(_QWORD *)(v29 + 48);
      v32 = v30 - 16;
      if ( *(int *)(v31 + 40) >= 0 )
        v32 = v30;
      sub_1804EEFA0(v32, &v25[1], v28->_2.instance_size - 16);
      LOBYTE(v41[0]) = 1;
    }
    else
    {
      if ( v25->klass->_1.element_class != *(Il2CppClass **)(v27 + 64) )
        sub_1804BE2F0(v25, v27);
      v11 = v25 + 1;
    }
    sub_1804EEFA0(dst, v11, v8);
    v34 = method->rgctx_data->_2_T;
    if ( (*(&v34->_2.bitflags2 + 2) & 1) == 0 )
      sub_1804E30B0(v34);
    if ( dword_18579B674 )
    {
      v35 = ((unsigned __int64)dst >> 12) & 0x1FFFFF;
      v36 = &qword_185801160[(unsigned __int64)v35 >> 6];
      v37 = v35 & 0x3F;
      _m_prefetchw(v36);
      do
        v38 = *v36;
      while ( v38 != _InterlockedCompareExchange64(v36, *v36 | (1i64 << v37), *v36) );
    }
  }
  else
  {
    sub_1804EF650(dst, 0i64, v8);
  }
  return 1;
}
