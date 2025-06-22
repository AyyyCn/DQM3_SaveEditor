System_Type_o *__stdcall JsonSerializer__getAndCacheCollectionInterface(System_Type_o *type, const MethodInfo *method)
{
  __int64 v2; // r8
  JsonSerializer_c *v4; // rax
  System_Collections_Generic_Dictionary_TKey__TValue__o *v5; // rcx
  JsonSerializer_c *v6; // rax
  struct JsonSerializer_StaticFields *v7; // rax
  System_Collections_Generic_Dictionary_object__object__o *v8; // rdi
  __int64 v9; // rax
  Il2CppObject *v10; // rax
  JsonSerializer_c *v11; // rax
  signed __int32 v13[8]; // [rsp+0h] [rbp-38h] BYREF

  if ( !byte_18579D60C )
  {
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Type__ContainsKey__);
    _InterlockedOr(v13, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Type__get_Item__);
    _InterlockedOr(v13, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Type__set_Item__);
    _InterlockedOr(v13, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v13, 0);
    byte_18579D60C = 1;
  }
  v4 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v4 = JsonSerializer_TypeInfo;
  }
  v5 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v4->static_fields->_collectionInterfaceCache;
  if ( !v5 )
    goto LABEL_17;
  if ( System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
         v5,
         (Il2CppObject *)type,
         *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__Type__ContainsKey__
                                                              + 32)
                                                  + 192i64)
                                      + 264i64)) >= 0 )
    goto LABEL_13;
  v6 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v6 = JsonSerializer_TypeInfo;
  }
  v7 = v6->static_fields;
  v5 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v7->_collectionType;
  v8 = (System_Collections_Generic_Dictionary_object__object__o *)v7->_collectionInterfaceCache;
  if ( !v5
    || (v9 = ((__int64 (__fastcall *)(System_Collections_Generic_Dictionary_TKey__TValue__o *, const MethodInfo *))v5->klass->vtable._8_unknown.methodPtr)(
               v5,
               v5->klass->vtable._8_unknown.method),
        !type)
    || (v10 = (Il2CppObject *)((__int64 (__fastcall *)(System_Type_o *, __int64, _QWORD, const MethodInfo *))type->klass->vtable._116_unknown.methodPtr)(
                                type,
                                v9,
                                0i64,
                                type->klass->vtable._116_unknown.method),
        !v8) )
  {
LABEL_17:
    sub_1804BDCA0(v5, method, v2);
  }
  System_Collections_Generic_Dictionary_object__object___TryInsert(
    v8,
    (Il2CppObject *)type,
    v10,
    1u,
    *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__Type__set_Item__
                                                         + 32)
                                             + 192i64)
                                 + 272i64));
LABEL_13:
  v11 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v11 = JsonSerializer_TypeInfo;
  }
  v5 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v11->static_fields->_collectionInterfaceCache;
  if ( !v5 )
    goto LABEL_17;
  return (System_Type_o *)System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___get_Item(
                            v5,
                            (Il2CppObject *)type,
                            Method_System_Collections_Generic_Dictionary_Type__Type__get_Item__);
}
