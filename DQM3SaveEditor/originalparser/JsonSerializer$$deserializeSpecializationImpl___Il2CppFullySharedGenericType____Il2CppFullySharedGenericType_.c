void __stdcall JsonSerializer__deserializeSpecializationImpl___Il2CppFullySharedGenericType____Il2CppFullySharedGenericType_(Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *dst, System_String_o *json, const MethodInfo_199D2A0 *method)
{
  Il2CppClass *v6; // rax
  unsigned __int64 v7; // rbx
  __int64 v8; // rax
  unsigned __int64 v9; // rcx
  unsigned __int64 v10; // rax
  void *v11; // rsp
  __int64 v12; // rax
  signed __int64 v13; // rax
  void *v14; // rsp
  const MethodInfo_199D2A0_RGCTXs *v15; // r8
  void *v16; // rsp
  unsigned __int64 v17; // rcx
  __int64 v18; // rax
  void *v19; // rsp
  __int128 *v20; // rsi
  __int64 *v21; // rdx
  Il2CppClass *v22; // rcx
  __int64 v23; // rtt
  __int64 v24; // r15
  __int128 v25; // xmm6
  JsonSerializer_SeparateString_o *v26; // rax
  __int64 v27; // rdx
  System_String_o *v28; // rbx
  __int128 v29; // xmm1
  System_ReadOnlySpan_char__o v30; // xmm7
  __int128 v31; // xmm0
  System_ReadOnlySpan_char__o v32; // xmm6
  System_Globalization_CultureInfo_o *v33; // rax
  __int64 v34; // rdx
  __int64 v35; // rcx
  __int64 v36; // r8
  System_Globalization_CompareInfo_o *v37; // rax
  __int64 v38; // rdx
  Il2CppType *v39; // rbx
  __int64 v40; // rdx
  System_Type_o *v41; // rbx
  Il2CppObject *v42; // rax
  const MethodInfo_199D2A0_RGCTXs *v43; // rcx
  __int128 *v44; // rbx
  __int64 v45; // rdi
  __int64 v46; // rdx
  __int64 v47; // rcx
  char *v48; // rdx
  bool v49; // sf
  char *v50; // rcx
  __int64 v51; // r8
  const MethodInfo_199D2A0_RGCTXs *v52; // rdx
  Il2CppClass *v53; // rax
  Il2CppClass *v54; // rbx
  signed __int32 v55[8]; // [rsp+0h] [rbp-30h] BYREF
  __int128 v56; // [rsp+30h] [rbp+0h] BYREF
  System_ReadOnlySpan_char__o v57; // [rsp+40h] [rbp+10h]
  System_ReadOnlySpan_char__o v58; // [rsp+50h] [rbp+20h] BYREF
  __int128 v59; // [rsp+60h] [rbp+30h] BYREF
  System_ReadOnlySpan_char__o v60[2]; // [rsp+70h] [rbp+40h] BYREF
  System_ReadOnlySpan_char__o v61; // [rsp+90h] [rbp+60h]
  __int128 v62; // [rsp+A0h] [rbp+70h]
  __int128 v63; // [rsp+B0h] [rbp+80h]
  __int128 v64; // [rsp+C0h] [rbp+90h]
  JsonSerializer_SeparateString_o v65; // [rsp+100h] [rbp+D0h] BYREF
  __int128 *v66; // [rsp+190h] [rbp+160h] BYREF
  __int128 *v67; // [rsp+198h] [rbp+168h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v55, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v55, 0);
    sub_180499EE0(&StringLiteral_17451);
    _InterlockedOr(v55, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v6 = method->rgctx_data->_2_TAntiCheat;
  v7 = v6->_2.actualSize;
  if ( (*(&v6->_2.bitflags2 + 2) & 1) == 0 )
    v6 = (Il2CppClass *)sub_1804E30B0(method->rgctx_data->_2_TAntiCheat);
  v8 = v6->_2.actualSize + 16;
  v9 = (unsigned int)v8;
  v10 = v8 + 15;
  if ( v10 <= v9 )
    v10 = 0xFFFFFFFFFFFFFF0i64;
  v11 = alloca(v10 & 0xFFFFFFFFFFFFFFF0ui64);
  v12 = v7 + 15;
  if ( v7 + 15 <= v7 )
    v12 = 0xFFFFFFFFFFFFFF0i64;
  v13 = v12 & 0xFFFFFFFFFFFFFFF0ui64;
  v14 = alloca(v13);
  v15 = method->rgctx_data;
  v16 = alloca(v13);
  v17 = v15->_4_TType->_2.actualSize;
  v18 = v17 + 15;
  if ( v17 + 15 <= v17 )
    v18 = 0xFFFFFFFFFFFFFF0i64;
  v19 = alloca(v18 & 0xFFFFFFFFFFFFFFF0ui64);
  v66 = &v56;
  v20 = &v56;
  ((void (__fastcall *)(Il2CppMethodPointer, MethodInfo *, _QWORD, __int128 **, __int128 *))v15->_1_System_Activator_CreateInstance_TAntiCheat_->invoker_method)(
    v15->_1_System_Activator_CreateInstance_TAntiCheat_->methodPointer,
    v15->_1_System_Activator_CreateInstance_TAntiCheat_,
    0i64,
    &v66,
    &v56);
  sub_1804EEFA0(dst, &v56, v7);
  v22 = method->rgctx_data->_2_TAntiCheat;
  if ( (*(&v22->_2.bitflags2 + 2) & 1) == 0 )
    sub_1804E30B0(v22);
  if ( dword_18579B674 )
  {
    v21 = &qword_185801160[(((unsigned __int64)dst >> 12) & 0x1FFFFF) >> 6];
    _m_prefetchw(v21);
    do
      v23 = *v21;
    while ( v23 != _InterlockedCompareExchange64(v21, *v21 | (1i64 << (((unsigned __int64)dst >> 12) & 0x3F)), *v21) );
  }
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v55, 0);
    byte_18579AC1D = 1;
  }
  v24 = 0i64;
  if ( json )
  {
    *(_QWORD *)&v56 = &json->fields._firstChar;
    *((_QWORD *)&v56 + 1) = (unsigned int)json->fields._stringLength;
    v25 = v56;
  }
  else
  {
    v25 = 0i64;
    v63 = 0i64;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v21);
  v59 = v25;
  v26 = JsonSerializer__separateToNameAndValue(&v65, (System_ReadOnlySpan_char__o *)&v59, 0i64);
  v28 = StringLiteral_17451;
  v29 = (__int128)v26->fields.value;
  v30 = v26->fields.name;
  v60[1] = v26->fields.name;
  v31 = (__int128)v26->fields.nextVariable;
  v61 = (System_ReadOnlySpan_char__o)v29;
  v62 = v31;
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v55, 0);
    byte_18579AC1D = 1;
  }
  if ( v28 )
  {
    v57.fields._pointer.fields._value = (intptr_t)&v28->fields._firstChar;
    *(_QWORD *)&v57.fields._length = (unsigned int)v28->fields._stringLength;
    v32 = v57;
  }
  else
  {
    v32 = 0i64;
    v64 = 0i64;
  }
  if ( !byte_1857AE50A )
  {
    sub_180499EE0(&System_Globalization_CompareInfo_TypeInfo);
    _InterlockedOr(v55, 0);
    sub_180499EE0(&System_Globalization_CultureInfo_TypeInfo);
    _InterlockedOr(v55, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v55, 0);
    byte_1857AE50A = 1;
  }
  if ( !System_Globalization_CultureInfo_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Globalization_CultureInfo_TypeInfo, v27);
  v33 = System_Globalization_CultureInfo__get_CurrentCulture(0i64);
  if ( !v33 )
    goto LABEL_64;
  v37 = (System_Globalization_CompareInfo_o *)((__int64 (__fastcall *)(System_Globalization_CultureInfo_o *, const MethodInfo *))v33->klass->vtable._13_get_CompareInfo.methodPtr)(
                                                v33,
                                                v33->klass->vtable._13_get_CompareInfo.method);
  if ( !v37 )
    goto LABEL_64;
  v60[0] = v32;
  v58 = v30;
  if ( System_Globalization_CompareInfo__CompareOptionNone(v37, &v58, v60, 0i64) )
    return;
  v39 = method->rgctx_data->_3_TType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, v38);
  v41 = System_Type__GetTypeFromHandle((System_RuntimeTypeHandle_o)v39, 0i64);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v40);
  v58 = v61;
  v42 = JsonSerializer__analyze(&v58, v41, 0i64);
  v43 = method->rgctx_data;
  v44 = (__int128 *)v42;
  v45 = (__int64)v43->_4_TType;
  if ( (*(_BYTE *)(v45 + 309) & 1) == 0 )
    v45 = sub_1804E30B0(v43->_4_TType);
  v35 = *(_DWORD *)(v45 + 40) >> 31;
  if ( *(int *)(v45 + 40) >= 0 )
  {
    if ( !v44 || (v24 = sub_180481AF0(v44, v45)) != 0 )
    {
      *(_QWORD *)&v56 = v24;
      goto LABEL_58;
    }
LABEL_66:
    sub_1804BE2F0(v44, v45);
  }
  if ( *(_QWORD *)(v45 + 96) && (*(_BYTE *)(v45 + 309) & 8) != 0 )
  {
    if ( v44 )
    {
      v46 = *(_QWORD *)(v45 + 64);
      if ( *(_QWORD *)v44 != v46 )
        sub_1804BE2F0(v44, v46);
    }
    v47 = *(_QWORD *)(v45 + 128);
    v48 = (char *)&v56 + *(int *)(v47 + 56);
    v49 = *(int *)(*(_QWORD *)(v47 + 48) + 40i64) < 0;
    v50 = v48 - 16;
    if ( !v49 )
      v50 = v48;
    v51 = (unsigned int)(*(_DWORD *)(*(_QWORD *)(v45 + 64) + 248i64) - 16);
    if ( v44 )
    {
      sub_1804EEFA0(v50, v44 + 1, v51);
      LOBYTE(v56) = 1;
    }
    else
    {
      sub_1804EF650(v50, 0i64, v51);
      LOBYTE(v56) = 0;
    }
    goto LABEL_58;
  }
  if ( !v44 )
LABEL_64:
    sub_1804BDCA0(v35, v34, v36);
  if ( *(_QWORD *)(*(_QWORD *)v44 + 64i64) != *(_QWORD *)(v45 + 64) )
    goto LABEL_66;
  v20 = v44 + 1;
LABEL_58:
  v52 = method->rgctx_data;
  if ( (v52->_4_TType->_1.byval_arg.bits & 0x80000000) == 0 )
    v20 = *(__int128 **)v20;
  v53 = v52->_2_TAntiCheat;
  v54 = v52[1]._0_TAntiCheat;
  if ( (*(&v53->_2.bitflags2 + 2) & 1) == 0 )
    LODWORD(v53) = sub_1804E30B0(v52->_2_TAntiCheat);
  v67 = v20;
  sub_1804BEE70((_DWORD)v53, (_DWORD)v54, (unsigned int)&v56, (_DWORD)dst, (__int64)&v67, (__int64)v20);
}
