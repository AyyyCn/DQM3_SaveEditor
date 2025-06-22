JsonSerializer_o *__stdcall JsonSerializer__serialize(JsonSerializer_o *this, System_String_o *name, Il2CppObject *src, bool in_in_array, const MethodInfo *method)
{
  __int64 v9; // rdx
  System_Type_o *v10; // rbx
  __int64 v11; // rdx
  System_Type_o *v12; // rdi
  __int64 v13; // rdx
  System_Collections_Generic_Dictionary_TKey__TValue__o *v14; // rcx
  __int64 v15; // r8
  __int64 v16; // rdx
  Il2CppClass *v17; // rax
  unsigned int v18; // edi
  Il2CppObject *v19; // r15
  __int64 v20; // rcx
  __int64 v21; // rdx
  System_Collections_IEnumerable_o *v22; // rax
  __int64 v23; // rax
  __int64 v24; // rdx
  JsonSerializer_c *v25; // rcx
  __int64 v26; // r15
  struct System_Type_o *v27; // rbp
  JsonSerializer_c *v28; // rax
  JsonSerializer_c *v29; // rax
  System_Collections_Generic_Dictionary_object__object__o *v30; // rbp
  JsonSerializer_KeyValueGetMethod_o *v31; // r15
  JsonSerializer_c *v32; // rax
  UnityEngine_UIElements_StyleComplexSelector_PseudoStateData_o v33; // rax
  UnityEngine_UIElements_StyleComplexSelector_PseudoStateData_o v34; // rbx
  Il2CppObject *v35; // rax
  Il2CppObject *v36; // rax
  __int64 v37; // rdx
  unsigned __int16 *v38; // r14
  unsigned __int16 v39; // bx
  __int64 v40; // rdx
  __int64 v41; // rdi
  System_String_o *v42; // rdx
  signed __int32 v44[8]; // [rsp+0h] [rbp-58h] BYREF

  if ( !byte_18579D605 )
  {
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_KeyValueGetMethod__ContainsKey__);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_KeyValueGetMethod__get_Item__);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_KeyValueGetMethod__set_Item__);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&System_Collections_IEnumerable_TypeInfo);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&JsonSerializer_KeyValueGetMethod_TypeInfo);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&System_Array_TypeInfo);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&string_TypeInfo);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&StringLiteral_14297);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&StringLiteral_14293);
    _InterlockedOr(v44, 0);
    sub_180499EE0(&StringLiteral_14296);
    _InterlockedOr(v44, 0);
    byte_18579D605 = 1;
  }
  if ( !in_in_array )
    JsonSerializer__appendIndent(this, 0i64);
  if ( name && name->fields._stringLength )
  {
    if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, name);
    sub_1805709C0(&this->fields, name);
    sub_180570A70(&this->fields, 58i64);
  }
  if ( !src )
  {
    if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, name);
    v42 = StringLiteral_14297;
    goto LABEL_74;
  }
  v10 = (System_Type_o *)il2cpp_type_get_object_0(&src->klass->_1.byval_arg);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v9);
  if ( !byte_18579D610 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v44, 0);
    byte_18579D610 = 1;
  }
  v12 = (System_Type_o *)il2cpp_type_get_object_0(&src->klass->_1.byval_arg);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v11);
  if ( JsonSerializer__isBasicType_6448137248(v12, 0i64) )
    goto LABEL_68;
  if ( !v10 )
    goto LABEL_85;
  if ( ((unsigned __int8 (__fastcall *)(System_Type_o *, const MethodInfo *))v10->klass->vtable._69_get_IsEnum.methodPtr)(
         v10,
         v10->klass->vtable._69_get_IsEnum.method) )
  {
LABEL_68:
    v41 = ((__int64 (__fastcall *)(Il2CppObject *, const MethodInfo *))src->klass->vtable[3].methodPtr)(
            src,
            src->klass->vtable[3].method);
    if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v40);
    v42 = (System_String_o *)v41;
LABEL_74:
    sub_1805709C0(&this->fields, v42);
    goto LABEL_75;
  }
  v17 = src->klass;
  v18 = 0;
  v19 = 0i64;
  if ( (System_String_c *)src->klass == string_TypeInfo )
    v19 = src;
  if ( !v19 )
  {
    v20 = System_Array_TypeInfo->_2.naturalAligment;
    if ( v17->_2.naturalAligment >= (unsigned __int8)v20
      && (System_Array_c *)v17->_2.typeHierarchy[v20 - 1] == System_Array_TypeInfo )
    {
      JsonSerializer__appendArray(this, (System_Array_o *)src, v10, 0i64);
      goto LABEL_75;
    }
    v22 = (System_Collections_IEnumerable_o *)sub_180481AF0(src, System_Collections_IEnumerable_TypeInfo);
    if ( v22 )
    {
      JsonSerializer__appendEnumerable(this, v22, v10, 0i64);
      goto LABEL_75;
    }
    if ( !((unsigned __int8 (__fastcall *)(System_Type_o *, const MethodInfo *))v10->klass->vtable._40_get_IsGenericType.methodPtr)(
            v10,
            v10->klass->vtable._40_get_IsGenericType.method) )
      goto LABEL_28;
    v23 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))v10->klass->vtable._48_GetGenericTypeDefinition.methodPtr)(
            v10,
            v10->klass->vtable._48_GetGenericTypeDefinition.method);
    v25 = JsonSerializer_TypeInfo;
    v26 = v23;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    {
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v24);
      v25 = JsonSerializer_TypeInfo;
    }
    v27 = v25->static_fields->_keyValuePairType;
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, v24);
    if ( (struct System_Type_o *)v26 != v27 )
    {
LABEL_28:
      JsonSerializer__appendClass(this, src, v10, 0i64);
      goto LABEL_75;
    }
    JsonSerializer__openBrace(this, 0i64);
    v28 = JsonSerializer_TypeInfo;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    {
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v13);
      v28 = JsonSerializer_TypeInfo;
    }
    v14 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v28->static_fields->_keyValueGetMethod;
    if ( v14 )
    {
      if ( System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
             v14,
             (Il2CppObject *)v10,
             *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_KeyValueGetMethod__ContainsKey__
                                                                  + 32)
                                                      + 192i64)
                                          + 264i64)) < 0 )
      {
        v29 = JsonSerializer_TypeInfo;
        if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        {
          il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v13);
          v29 = JsonSerializer_TypeInfo;
        }
        v30 = (System_Collections_Generic_Dictionary_object__object__o *)v29->static_fields->_keyValueGetMethod;
        v31 = (JsonSerializer_KeyValueGetMethod_o *)sub_180481BA0(JsonSerializer_KeyValueGetMethod_TypeInfo);
        JsonSerializer_KeyValueGetMethod___ctor(v31, v10, 0i64);
        if ( !v30 )
          goto LABEL_85;
        System_Collections_Generic_Dictionary_object__object___TryInsert(
          v30,
          (Il2CppObject *)v10,
          (Il2CppObject *)v31,
          1u,
          *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_KeyValueGetMethod__set_Item__
                                                               + 32)
                                                   + 192i64)
                                       + 272i64));
      }
      v32 = JsonSerializer_TypeInfo;
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      {
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v13);
        v32 = JsonSerializer_TypeInfo;
      }
      v14 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v32->static_fields->_keyValueGetMethod;
      if ( v14 )
      {
        v33 = System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___get_Item(
                v14,
                (Il2CppObject *)v10,
                Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_KeyValueGetMethod__get_Item__);
        v34 = v33;
        if ( v33 )
        {
          v14 = *(System_Collections_Generic_Dictionary_TKey__TValue__o **)(*(_QWORD *)&v33 + 16i64);
          if ( v14 )
          {
            v35 = (Il2CppObject *)((__int64 (__fastcall *)(System_Collections_Generic_Dictionary_TKey__TValue__o *, Il2CppObject *, _QWORD, _QWORD, _QWORD, _QWORD, const MethodInfo *))v14->klass->vtable._31_System_Collections_ICollection_CopyTo.methodPtr)(
                                    v14,
                                    src,
                                    0i64,
                                    0i64,
                                    0i64,
                                    0i64,
                                    v14->klass->vtable._31_System_Collections_ICollection_CopyTo.method);
            JsonSerializer__serialize(this, StringLiteral_14296, v35, 0, 0i64);
            v14 = *(System_Collections_Generic_Dictionary_TKey__TValue__o **)(*(_QWORD *)&v34 + 24i64);
            if ( v14 )
            {
              v36 = (Il2CppObject *)((__int64 (__fastcall *)(System_Collections_Generic_Dictionary_TKey__TValue__o *, Il2CppObject *, _QWORD, _QWORD, _QWORD, _QWORD, const MethodInfo *))v14->klass->vtable._31_System_Collections_ICollection_CopyTo.methodPtr)(
                                      v14,
                                      src,
                                      0i64,
                                      0i64,
                                      0i64,
                                      0i64,
                                      v14->klass->vtable._31_System_Collections_ICollection_CopyTo.method);
              JsonSerializer__serialize(this, StringLiteral_14293, v36, 0, 0i64);
              JsonSerializer__closeBrace(this, 0i64);
              goto LABEL_75;
            }
          }
        }
      }
    }
LABEL_85:
    sub_1804BDCA0(v14, v13, v15);
  }
  if ( !byte_18579D614 )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v44, 0);
    byte_18579D614 = 1;
  }
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v16);
  sub_180570A70(&this->fields, 34i64);
  v38 = (unsigned __int16 *)&v19[1].klass + 2;
  while ( (signed int)v18 < SLODWORD(v19[1].klass) )
  {
    if ( v18 >= (__int64)SLODWORD(v19[1].klass) )
      System_ThrowHelper__ThrowIndexOutOfRangeException(0i64);
    v39 = *v38;
    if ( *v38 == 92 || v39 == 34 )
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v37);
      sub_180570B10(&this->fields, 92i64, v39);
      ++v18;
      ++v38;
    }
    else
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v37);
      sub_180570A70(&this->fields, v39);
      ++v18;
      ++v38;
    }
  }
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v37);
  sub_180570A70(&this->fields, 34i64);
LABEL_75:
  if ( in_in_array || this->fields._enableOptimize )
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
  return this;
}
