Il2CppObject *__stdcall JsonSerializer__analyzeClassImpl(Il2CppObject **dst, JsonSerializer_SeparateString_o *name_and_value, System_Type_o *type, const MethodInfo *method)
{
  JsonSerializer_SeparateString_o *v7; // rax
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // r8
  System_Type_o *v11; // rax
  __int64 v12; // rdx
  struct System_ReadOnlySpan_char__o v13; // xmm0
  __int64 v15; // rdx
  System_String_o *v16; // rdi
  System_Reflection_FieldInfo_o *v17; // rax
  System_Reflection_FieldInfo_o *v18; // rdi
  __int64 v19; // rax
  __int64 v20; // rdx
  __int64 v21; // r8
  Il2CppObject *v22; // rsi
  __int64 v23; // rdx
  System_Type_o *v24; // r15
  __int64 v25; // rcx
  __int64 v26; // rdx
  System_Type_o *v27; // rsi
  signed __int32 v28[8]; // [rsp+0h] [rbp-118h] BYREF
  System_ReadOnlySpan_char__o v29; // [rsp+20h] [rbp-F8h] BYREF
  int v30; // [rsp+38h] [rbp-E0h]
  System_ReadOnlySpan_char__o v31; // [rsp+50h] [rbp-C8h] BYREF
  JsonSerializer_SeparateString_o v32; // [rsp+60h] [rbp-B8h] BYREF
  struct System_ReadOnlySpan_char__o v33; // [rsp+98h] [rbp-80h]
  JsonSerializer_SeparateString_o v34; // [rsp+B0h] [rbp-68h] BYREF

  if ( !byte_18579D5FA )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__ToString__);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&System_Array_TypeInfo);
    _InterlockedOr(v28, 0);
    byte_18579D5FA = 1;
  }
  v30 = 0;
  do
  {
    if ( name_and_value->fields.name.fields._length > 0
      && *(_WORD *)name_and_value->fields.name.fields._pointer.fields._value == 64 )
    {
      v32.fields.name = name_and_value->fields.name;
      v32.fields.nextVariable = name_and_value->fields.nextVariable;
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, name_and_value);
      v31 = name_and_value->fields.value;
      v7 = JsonSerializer__separateToNameAndValue(&v32, &v31, 0i64);
      v31 = v7->fields.name;
      v33 = v7->fields.value;
      v29 = v7->fields.nextVariable;
      if ( !type )
        sub_1804BDCA0(v9, v8, v10);
      v11 = (System_Type_o *)((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))type->klass->vtable._113_unknown.methodPtr)(
                               type,
                               type->klass->vtable._113_unknown.method);
      v34.fields.name = v31;
      v34.fields.value = v33;
      v34.fields.nextVariable = v29;
      JsonSerializer__analyzeClassImpl(dst, &v34, v11, 0i64);
    }
    else
    {
      v16 = System_ReadOnlySpan_char___ToString(
              &name_and_value->fields.name,
              (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v15);
      v17 = JsonSerializer__getAndCacheFieldInfoDictionary(type, v16, 0i64);
      v18 = v17;
      if ( v17 )
      {
        v19 = ((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v17->klass->vtable._17_unknown.methodPtr)(
                v17,
                v17->klass->vtable._17_unknown.method);
        if ( !v19 )
          sub_1804BDCA0(0i64, v20, v21);
        if ( (*(unsigned __int8 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v19 + 824i64))(
               v19,
               *(_QWORD *)(*(_QWORD *)v19 + 832i64))
          && (v22 = (Il2CppObject *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, Il2CppObject *, const MethodInfo *))v18->klass->vtable._25_unknown.methodPtr)(
                                      v18,
                                      *dst,
                                      v18->klass->vtable._25_unknown.method)) != 0i64 )
        {
          v32.fields.name = name_and_value->fields.name;
          v32.fields.nextVariable = name_and_value->fields.nextVariable;
          v24 = (System_Type_o *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v18->klass->vtable._17_unknown.methodPtr)(
                                   v18,
                                   v18->klass->vtable._17_unknown.method);
          if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
            il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v23);
          v29 = name_and_value->fields.value;
          v25 = System_Array_TypeInfo->_2.naturalAligment;
          if ( v22->klass->_2.naturalAligment < (unsigned __int8)v25
            || (System_Array_c *)v22->klass->_2.typeHierarchy[v25 - 1] != System_Array_TypeInfo )
          {
            sub_1804BE2F0(v22, System_Array_TypeInfo);
          }
          JsonSerializer__analyzeArray((System_Array_o *)v22, &v29, v24, 0i64);
        }
        else
        {
          v32.fields.name = name_and_value->fields.name;
          v32.fields.nextVariable = name_and_value->fields.nextVariable;
          v27 = (System_Type_o *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v18->klass->vtable._17_unknown.methodPtr)(
                                   v18,
                                   v18->klass->vtable._17_unknown.method);
          if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
            il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v26);
          v29 = name_and_value->fields.value;
          v22 = JsonSerializer__analyze(&v29, v27, 0i64);
        }
        System_Reflection_FieldInfo__SetValue(v18, *dst, v22, 0i64);
      }
    }
    v32.fields.name = name_and_value->fields.name;
    v32.fields.value = name_and_value->fields.value;
    v13 = name_and_value->fields.nextVariable;
    v29 = v13;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    {
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v12);
      v13 = v29;
    }
    v29 = v13;
    *name_and_value = *JsonSerializer__separateToNameAndValue(&v32, &v29, 0i64);
  }
  while ( name_and_value->fields.name.fields._length > 0 );
  return *dst;
}
