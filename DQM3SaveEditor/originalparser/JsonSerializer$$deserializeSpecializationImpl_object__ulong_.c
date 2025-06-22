void __stdcall JsonSerializer__deserializeSpecializationImpl_object__ulong_(Il2CppObject **dst, System_String_o *json, const MethodInfo_199CF40 *method)
{
  Il2CppObject *v6; // rax
  __int64 *v7; // rdx
  bool v8; // zf
  __int64 v9; // rtt
  System_ReadOnlySpan_char__o v10; // xmm6
  JsonSerializer_SeparateString_o *v11; // rax
  __int64 v12; // rdx
  System_String_o *v13; // rbx
  __int128 v14; // xmm1
  System_ReadOnlySpan_char__o v15; // xmm7
  __int128 v16; // xmm0
  System_ReadOnlySpan_char__o v17; // xmm6
  System_Globalization_CultureInfo_o *v18; // rax
  __int64 v19; // rdx
  const MethodInfo_199CF40_RGCTXs *v20; // rcx
  __int64 v21; // r8
  System_Globalization_CompareInfo_o *v22; // rax
  __int64 v23; // rdx
  Il2CppType *v24; // rbx
  __int64 v25; // rdx
  System_Type_o *v26; // rbx
  Il2CppObject *v27; // rbx
  __int64 v28; // rax
  Il2CppClass *v29; // rbx
  Il2CppObject *v30; // rsi
  Il2CppClass *v31; // rax
  signed __int32 v32[6]; // [rsp+8h] [rbp-100h] BYREF
  System_ReadOnlySpan_char__o v33; // [rsp+28h] [rbp-E0h]
  System_ReadOnlySpan_char__o v34; // [rsp+38h] [rbp-D0h]
  System_ReadOnlySpan_char__o v35; // [rsp+48h] [rbp-C0h] BYREF
  System_ReadOnlySpan_char__o v36; // [rsp+58h] [rbp-B0h] BYREF
  System_ReadOnlySpan_char__o v37[2]; // [rsp+68h] [rbp-A0h] BYREF
  System_ReadOnlySpan_char__o v38; // [rsp+88h] [rbp-80h]
  __int128 v39; // [rsp+98h] [rbp-70h]
  __int128 v40; // [rsp+A8h] [rbp-60h]
  __int128 v41; // [rsp+B8h] [rbp-50h]
  JsonSerializer_SeparateString_o v42; // [rsp+F8h] [rbp-10h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&StringLiteral_17451);
    _InterlockedOr(v32, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v6 = System_Activator__CreateInstance_object_((const MethodInfo_1861B30 *)method->rgctx_data->_1_System_Activator_CreateInstance_TAntiCheat_);
  v8 = dword_18579B674 == 0;
  *dst = v6;
  if ( !v8 )
  {
    v7 = &qword_185801160[(((unsigned __int64)dst >> 12) & 0x1FFFFF) >> 6];
    _m_prefetchw(v7);
    do
      v9 = *v7;
    while ( v9 != _InterlockedCompareExchange64(v7, *v7 | (1i64 << (((unsigned __int64)dst >> 12) & 0x3F)), *v7) );
  }
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v32, 0);
    byte_18579AC1D = 1;
  }
  if ( json )
  {
    v33.fields._pointer.fields._value = (intptr_t)&json->fields._firstChar;
    *(_QWORD *)&v33.fields._length = (unsigned int)json->fields._stringLength;
    v10 = v33;
  }
  else
  {
    v10 = 0i64;
    v40 = 0i64;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v7);
  v36 = v10;
  v11 = JsonSerializer__separateToNameAndValue(&v42, &v36, 0i64);
  v13 = StringLiteral_17451;
  v14 = (__int128)v11->fields.value;
  v15 = v11->fields.name;
  v37[1] = v11->fields.name;
  v16 = (__int128)v11->fields.nextVariable;
  v38 = (System_ReadOnlySpan_char__o)v14;
  v39 = v16;
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v32, 0);
    byte_18579AC1D = 1;
  }
  if ( v13 )
  {
    v34.fields._pointer.fields._value = (intptr_t)&v13->fields._firstChar;
    *(_QWORD *)&v34.fields._length = (unsigned int)v13->fields._stringLength;
    v17 = v34;
  }
  else
  {
    v17 = 0i64;
    v41 = 0i64;
  }
  if ( !byte_1857AE50A )
  {
    sub_180499EE0(&System_Globalization_CompareInfo_TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&System_Globalization_CultureInfo_TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v32, 0);
    byte_1857AE50A = 1;
  }
  if ( !System_Globalization_CultureInfo_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Globalization_CultureInfo_TypeInfo, v12);
  v18 = System_Globalization_CultureInfo__get_CurrentCulture(0i64);
  if ( !v18 )
    goto LABEL_39;
  v22 = (System_Globalization_CompareInfo_o *)((__int64 (__fastcall *)(System_Globalization_CultureInfo_o *, const MethodInfo *))v18->klass->vtable._13_get_CompareInfo.methodPtr)(
                                                v18,
                                                v18->klass->vtable._13_get_CompareInfo.method);
  if ( !v22 )
    goto LABEL_39;
  v37[0] = v17;
  v35 = v15;
  if ( System_Globalization_CompareInfo__CompareOptionNone(v22, &v35, v37, 0i64) )
    return;
  v24 = method->rgctx_data->_3_TType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, v23);
  v26 = System_Type__GetTypeFromHandle((System_RuntimeTypeHandle_o)v24, 0i64);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v25);
  v35 = v38;
  v27 = JsonSerializer__analyze(&v35, v26, 0i64);
  if ( !*dst )
    goto LABEL_39;
  v20 = method->rgctx_data;
  v28 = (__int64)v20->_4_TType;
  if ( (*(_BYTE *)(v28 + 309) & 1) == 0 )
    v28 = sub_1804E30B0(v20->_4_TType);
  if ( !v27 )
LABEL_39:
    sub_1804BDCA0(v20, v19, v21);
  if ( v27->klass->_1.element_class != *(Il2CppClass **)(v28 + 64) )
    sub_1804BE2F0(v27, v28);
  v29 = v27[1].klass;
  v30 = *dst;
  v31 = method->rgctx_data->_5_AntiCheat_Interface_TType_;
  if ( (*(&v31->_2.bitflags2 + 2) & 1) == 0 )
    v31 = (Il2CppClass *)sub_1804E30B0(method->rgctx_data->_5_AntiCheat_Interface_TType_);
  sub_18000BF00(1i64, v31, v30, v29);
}
