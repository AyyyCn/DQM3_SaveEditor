System_Reflection_FieldInfo_o *__stdcall JsonSerializer__getAndCacheFieldInfoDictionary(System_Type_o *type, System_String_o *name, const MethodInfo *method)
{
  JsonSerializer_c *v5; // rax
  System_Collections_Generic_Dictionary_object__object__o *v6; // rcx
  System_Reflection_FieldInfo_array *v7; // rsi
  System_Collections_Generic_Dictionary_TKey__TValue__o *v8; // rbp
  unsigned int v9; // edi
  int v10; // eax
  Il2CppObject *v11; // rbx
  Il2CppObject *v12; // rax
  JsonSerializer_c *v13; // rax
  JsonSerializer_c *v14; // rax
  System_Collections_Generic_Dictionary_TKey__TValue__o *v15; // rbx
  int32_t v16; // eax
  struct System_Collections_Generic_Dictionary_Entry_TKey__TValue__array *v17; // rbx
  System_Collections_Generic_Dictionary_TKey__TValue__o *v18; // rbx
  int32_t v20; // eax
  signed __int32 v21[8]; // [rsp+0h] [rbp-48h] BYREF

  if ( !byte_18579D60B )
  {
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Dictionary_string__FieldInfo___ContainsKey__);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_string__FieldInfo__ContainsKey__);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_string__FieldInfo___ctor__);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_string__FieldInfo__get_Item__);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Dictionary_string__FieldInfo___get_Item__);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_string__FieldInfo__set_Item__);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Dictionary_string__FieldInfo___set_Item__);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&System_Collections_Generic_Dictionary_string__FieldInfo__TypeInfo);
    _InterlockedOr(v21, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v21, 0);
    byte_18579D60B = 1;
  }
  v5 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, name);
    v5 = JsonSerializer_TypeInfo;
  }
  v6 = (System_Collections_Generic_Dictionary_object__object__o *)v5->static_fields->_fieldInfoDictionaryCache;
  if ( !v6 )
    goto LABEL_32;
  if ( System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
         (System_Collections_Generic_Dictionary_TKey__TValue__o *)v6,
         (Il2CppObject *)type,
         *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__Dictionary_string__FieldInfo___ContainsKey__
                                                              + 32)
                                                  + 192i64)
                                      + 264i64)) < 0 )
  {
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, name);
    v7 = JsonSerializer__getAndCacheFieldInfoArray(type, 0i64);
    v8 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)sub_180481BA0(System_Collections_Generic_Dictionary_string__FieldInfo__TypeInfo);
    System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData____ctor(
      v8,
      Method_System_Collections_Generic_Dictionary_string__FieldInfo___ctor__);
    v9 = 0;
    v6 = 0i64;
    if ( !v7 )
      goto LABEL_32;
    while ( 1 )
    {
      v10 = v7->max_length;
      if ( (int)v6 >= v10 )
        break;
      if ( v9 >= v10 )
        goto LABEL_35;
      v11 = (Il2CppObject *)v7->m_Items[v9];
      if ( !v11 )
        goto LABEL_32;
      v12 = (Il2CppObject *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v11->klass->vtable[8].methodPtr)(
                              v7->m_Items[v9],
                              v11->klass->vtable[8].method);
      if ( !v8 )
        goto LABEL_32;
      System_Collections_Generic_Dictionary_object__object___TryInsert(
        (System_Collections_Generic_Dictionary_object__object__o *)v8,
        v12,
        v11,
        1u,
        *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_string__FieldInfo__set_Item__
                                                             + 32)
                                                 + 192i64)
                                     + 272i64));
      v6 = (System_Collections_Generic_Dictionary_object__object__o *)++v9;
    }
    v13 = JsonSerializer_TypeInfo;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    {
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, name);
      v13 = JsonSerializer_TypeInfo;
    }
    v6 = (System_Collections_Generic_Dictionary_object__object__o *)v13->static_fields->_fieldInfoDictionaryCache;
    if ( !v6 )
      goto LABEL_32;
    System_Collections_Generic_Dictionary_object__object___TryInsert(
      v6,
      (Il2CppObject *)type,
      (Il2CppObject *)v8,
      1u,
      *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__Dictionary_string__FieldInfo___set_Item__
                                                           + 32)
                                               + 192i64)
                                   + 272i64));
  }
  v14 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, name);
    v14 = JsonSerializer_TypeInfo;
  }
  v15 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v14->static_fields->_fieldInfoDictionaryCache;
  if ( !v15 )
    goto LABEL_32;
  v16 = System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
          v15,
          (Il2CppObject *)type,
          *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__Dictionary_string__FieldInfo___get_Item__
                                                               + 32)
                                                   + 192i64)
                                       + 264i64));
  if ( v16 < 0 )
    System_ThrowHelper__ThrowKeyNotFoundException((Il2CppObject *)type, 0i64);
  v17 = v15->fields._entries;
  if ( !v17 )
    goto LABEL_32;
  if ( (unsigned int)v16 >= LODWORD(v17->max_length) )
    goto LABEL_35;
  v18 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v17->m_Items[v16].fields.value;
  if ( !v18 )
    goto LABEL_32;
  if ( System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
         v18,
         (Il2CppObject *)name,
         *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_string__FieldInfo__ContainsKey__
                                                              + 32)
                                                  + 192i64)
                                      + 264i64)) < 0 )
    return 0i64;
  v20 = System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
          v18,
          (Il2CppObject *)name,
          *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_string__FieldInfo__get_Item__
                                                               + 32)
                                                   + 192i64)
                                       + 264i64));
  if ( v20 < 0 )
    System_ThrowHelper__ThrowKeyNotFoundException((Il2CppObject *)name, 0i64);
  v6 = (System_Collections_Generic_Dictionary_object__object__o *)v18->fields._entries;
  if ( !v6 )
LABEL_32:
    sub_1804BDCA0(v6, name, method);
  if ( (unsigned int)v20 >= LODWORD(v6->fields._entries) )
LABEL_35:
    sub_1804BDCB0(v6, name, method);
  return (System_Reflection_FieldInfo_o *)(&v6->fields._comparer)[3 * v20];
}
