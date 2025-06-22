Il2CppObject *__stdcall JsonSerializer__analyzeClass(JsonSerializer_SeparateString_o *name_and_value, System_ReadOnlySpan_char__o *json, System_Type_o *type, const MethodInfo *method)
{
  System_ReadOnlySpan_char__o *v5; // r14
  struct System_ReadOnlySpan_char__o v7; // xmm1
  System_String_o *v8; // rbx
  __int128 v9; // xmm0
  __int64 v10; // rcx
  __int64 v11; // r8
  Il2CppObject *result; // rax
  JsonSerializer_SpecializationMethods_o *v13; // rsi
  __int64 v14; // rdx
  struct System_ReadOnlySpan_char__o v15; // xmm1
  struct System_ReadOnlySpan_char__o v16; // xmm0
  __int64 v17; // rbx
  System_String_o *v18; // rax
  __int64 v19; // rdx
  struct System_Reflection_MethodInfo_o *v20; // rcx
  __int64 v21; // r8
  System_String_o *v22; // rdi
  __int64 v23; // rax
  signed __int32 v24[8]; // [rsp+0h] [rbp-E8h] BYREF
  __int128 v25; // [rsp+40h] [rbp-A8h]
  __int128 v26; // [rsp+50h] [rbp-98h]
  struct System_ReadOnlySpan_char__o v27; // [rsp+70h] [rbp-78h]
  JsonSerializer_SeparateString_o v28; // [rsp+90h] [rbp-58h] BYREF
  __int128 v29; // [rsp+C0h] [rbp-28h]
  Il2CppObject *v30; // [rsp+F0h] [rbp+8h] BYREF

  v5 = json;
  if ( !byte_18579D5F9 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v24, 0);
    sub_180499EE0(&object___TypeInfo);
    _InterlockedOr(v24, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__ToString__);
    _InterlockedOr(v24, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v24, 0);
    sub_180499EE0(&StringLiteral_14297);
    _InterlockedOr(v24, 0);
    byte_18579D5F9 = 1;
  }
  v7 = name_and_value->fields.value;
  v8 = StringLiteral_14297;
  v30 = 0i64;
  v27 = v7;
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v24, 0);
    byte_18579AC1D = 1;
  }
  if ( v8 )
  {
    *(_QWORD *)&v25 = &v8->fields._firstChar;
    *((_QWORD *)&v25 + 1) = (unsigned int)v8->fields._stringLength;
    v9 = v25;
  }
  else
  {
    v9 = 0i64;
    v29 = 0i64;
  }
  v26 = v9;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  if ( !byte_18579D603 )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v24, 0);
    byte_18579D603 = 1;
  }
  if ( v27.fields._length == DWORD2(v26) )
  {
    v10 = 0i64;
    if ( v27.fields._length > 0 )
    {
      json = (System_ReadOnlySpan_char__o *)v27.fields._pointer.fields._value;
      v11 = 0i64;
      while ( (unsigned int)v10 < v27.fields._length && (unsigned int)v10 < DWORD2(v26) )
      {
        if ( LOWORD(json->fields._pointer.fields._value) != *(_WORD *)((char *)&json->fields._pointer.fields._value
                                                                     + v26
                                                                     - v27.fields._pointer.fields._value) )
          goto LABEL_21;
        v10 = (unsigned int)(v10 + 1);
        ++v11;
        json = (System_ReadOnlySpan_char__o *)((char *)json + 2);
        if ( v11 >= v27.fields._length )
          goto LABEL_19;
      }
LABEL_35:
      sub_1804BDCB0(v10, json, v11);
    }
LABEL_19:
    if ( name_and_value->fields.name.fields._length <= 0 )
      return 0i64;
  }
LABEL_21:
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  v13 = JsonSerializer__getAndCacheSpecializationMethods(type, 0i64);
  if ( v13 )
  {
    v17 = il2cpp_array_new_specific_0(object___TypeInfo, 2i64);
    v18 = System_ReadOnlySpan_char___ToString(
            v5,
            (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
    v22 = v18;
    if ( !v17 )
      goto LABEL_33;
    if ( v18 && !sub_180481AF0(v18, *(_QWORD *)(*(_QWORD *)v17 + 64i64)) )
    {
      v23 = sub_1804BDEC0();
      sub_1804BDC60(v23, 0i64);
    }
    sub_180006A40(v17, 1i64, v22);
    v20 = v13->fields.deserialize;
    if ( !v20 )
LABEL_33:
      sub_1804BDCA0(v20, v19, v21);
    ((void (__fastcall *)(struct System_Reflection_MethodInfo_o *, _QWORD, _QWORD, _QWORD, __int64, _QWORD, const MethodInfo *))v20->klass->vtable._31_unknown.methodPtr)(
      v20,
      0i64,
      0i64,
      0i64,
      v17,
      0i64,
      v20->klass->vtable._31_unknown.method);
    if ( !*(_DWORD *)(v17 + 24) )
      goto LABEL_35;
    result = *(Il2CppObject **)(v17 + 32);
  }
  else
  {
    v30 = System_Activator__CreateInstance_6496658320(type, 0, 1, 0i64);
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v14);
    v15 = name_and_value->fields.value;
    v28.fields.name = name_and_value->fields.name;
    v16 = name_and_value->fields.nextVariable;
    v28.fields.value = v15;
    v28.fields.nextVariable = v16;
    result = JsonSerializer__analyzeClassImpl(&v30, &v28, type, 0i64);
  }
  return result;
}
