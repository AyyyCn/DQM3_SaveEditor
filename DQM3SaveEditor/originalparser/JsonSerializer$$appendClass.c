void __stdcall JsonSerializer__appendClass(JsonSerializer_o *this, Il2CppObject *src, System_Type_o *type, const MethodInfo *method)
{
  JsonSerializer_SpecializationMethods_o *v7; // rdi
  __int64 v8; // rdx
  __int64 v9; // rcx
  __int64 v10; // r8
  struct JsonSerializer_StaticFields *v11; // rdx
  __int64 v12; // rbx
  __int64 v13; // rdx
  __int64 v14; // rdi
  struct System_Type_o *v15; // rbx
  __int64 v16; // rdx
  __int64 v17; // rdi
  struct System_Type_o *v18; // rbx
  __int64 v19; // rdx
  System_Type_o *v20; // rax
  __int64 v21; // rdx
  System_Reflection_FieldInfo_array *v22; // r15
  signed int v23; // edi
  System_Reflection_FieldInfo_o *v24; // rsi
  __int64 v25; // rdx
  System_Type_o *v26; // rbx
  System_String_o *v27; // rbx
  Il2CppObject *v28; // rax
  struct System_Reflection_MethodInfo_o *v29; // rdi
  __int64 v30; // rax
  __int64 v31; // rbx
  __int64 v32; // rdx
  __int64 v33; // rax
  signed __int32 v34[8]; // [rsp+0h] [rbp-68h] BYREF

  if ( !byte_18579D618 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v34, 0);
    sub_180499EE0(&object___TypeInfo);
    _InterlockedOr(v34, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v34, 0);
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v34, 0);
    byte_18579D618 = 1;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, src);
  v7 = JsonSerializer__getAndCacheSpecializationMethods(type, 0i64);
  JsonSerializer__openBrace(this, 0i64);
  if ( v7 )
  {
    v29 = v7->fields.serialize;
    v30 = il2cpp_array_new_specific_0(object___TypeInfo, 1i64);
    v31 = v30;
    if ( v30 )
    {
      if ( src && !sub_180481AF0(src, *(_QWORD *)(*(_QWORD *)v30 + 64i64)) )
      {
        v33 = sub_1804BDEC0();
        sub_1804BDC60(v33, 0i64);
      }
      sub_180006A40(v31, 0i64, src);
      if ( v29 )
      {
        ((void (__fastcall *)(struct System_Reflection_MethodInfo_o *, JsonSerializer_o *, _QWORD, _QWORD, __int64, _QWORD, const MethodInfo *))v29->klass->vtable._31_unknown.methodPtr)(
          v29,
          this,
          0i64,
          0i64,
          v31,
          0i64,
          v29->klass->vtable._31_unknown.method);
        goto LABEL_47;
      }
    }
LABEL_52:
    sub_1804BDCA0(v9, v8, v10);
  }
  if ( !type )
    goto LABEL_52;
  v12 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))type->klass->vtable._113_unknown.methodPtr)(
          type,
          type->klass->vtable._113_unknown.method);
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, v11);
  if ( v12 )
  {
    v14 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))type->klass->vtable._113_unknown.methodPtr)(
            type,
            type->klass->vtable._113_unknown.method);
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v13);
    v11 = JsonSerializer_TypeInfo->static_fields;
    v15 = v11->_systemObjectType;
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, v11);
    if ( (struct System_Type_o *)v14 != v15 )
    {
      v17 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))type->klass->vtable._113_unknown.methodPtr)(
              type,
              type->klass->vtable._113_unknown.method);
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v16);
      v11 = JsonSerializer_TypeInfo->static_fields;
      v18 = v11->_systemValueType;
      if ( !System_Type_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(System_Type_TypeInfo, v11);
      if ( (struct System_Type_o *)v17 != v18 )
      {
        JsonSerializer__appendIndent(this, 0i64);
        if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
          il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v19);
        sub_180570B10(&this->fields, 64i64, 58i64);
        v20 = (System_Type_o *)((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))type->klass->vtable._113_unknown.methodPtr)(
                                 type,
                                 type->klass->vtable._113_unknown.method);
        JsonSerializer__appendClass(this, src, v20, 0i64);
        if ( this->fields._enableOptimize )
        {
          if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
            il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v21);
          sub_180570A70(&this->fields, 44i64);
        }
        else
        {
          if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
            il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v21);
          sub_180570B10(&this->fields, 44i64, 10i64);
        }
      }
    }
  }
  if ( !byte_18579D619 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v34, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v34, 0);
    byte_18579D619 = 1;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v11);
  v22 = JsonSerializer__getAndCacheFieldInfoArray(type, 0i64);
  v23 = 0;
  v8 = 0i64;
  if ( !v22 )
    goto LABEL_52;
  while ( 1 )
  {
    v9 = LODWORD(v22->max_length);
    if ( (int)v8 >= (int)v9 )
      break;
    if ( v23 >= (unsigned int)v9 )
      sub_1804BDCB0(v9, v8, v10);
    v24 = v22->m_Items[v23];
    if ( !v24 )
      goto LABEL_52;
    v26 = (System_Type_o *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v24->klass->vtable._9_unknown.methodPtr)(
                             v22->m_Items[v23],
                             v24->klass->vtable._9_unknown.method);
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, v25);
    if ( v26 == type )
    {
      v27 = (System_String_o *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v24->klass->vtable._8_unknown.methodPtr)(
                                 v24,
                                 v24->klass->vtable._8_unknown.method);
      v28 = (Il2CppObject *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, Il2CppObject *, const MethodInfo *))v24->klass->vtable._25_unknown.methodPtr)(
                              v24,
                              src,
                              v24->klass->vtable._25_unknown.method);
      JsonSerializer__serialize(this, v27, v28, 0, 0i64);
    }
    v8 = (unsigned int)++v23;
  }
LABEL_47:
  if ( !byte_18579D60F )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v34, 0);
    byte_18579D60F = 1;
  }
  --this->fields._indentCnt;
  JsonSerializer__appendIndent(this, 0i64);
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v32);
  sub_180570A70(&this->fields, 125i64);
}
