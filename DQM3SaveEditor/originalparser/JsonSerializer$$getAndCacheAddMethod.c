System_Reflection_MethodInfo_o *__stdcall JsonSerializer__getAndCacheAddMethod(System_Type_o *type, const MethodInfo *method)
{
  __int64 v2; // r8
  JsonSerializer_c *v4; // rax
  System_Collections_Generic_Dictionary_TKey__TValue__o *v5; // rcx
  JsonSerializer_c *v6; // rax
  System_Collections_Generic_Dictionary_object__object__o *v7; // rdi
  Il2CppObject *v8; // rax
  JsonSerializer_c *v9; // rax
  __int64 v11; // rax
  System_ArgumentNullException_o *v12; // rbx
  __int64 v13; // rdx
  System_String_o *v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rax
  signed __int32 v17[8]; // [rsp+0h] [rbp-48h] BYREF

  if ( !byte_18579D60D )
  {
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__MethodInfo__ContainsKey__);
    _InterlockedOr(v17, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__MethodInfo__get_Item__);
    _InterlockedOr(v17, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__MethodInfo__set_Item__);
    _InterlockedOr(v17, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v17, 0);
    sub_180499EE0(&StringLiteral_14289);
    _InterlockedOr(v17, 0);
    byte_18579D60D = 1;
  }
  v4 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v4 = JsonSerializer_TypeInfo;
  }
  v5 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v4->static_fields->_addMethodCache;
  if ( !v5 )
    goto LABEL_17;
  if ( System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
         v5,
         (Il2CppObject *)type,
         *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__MethodInfo__ContainsKey__
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
  v7 = (System_Collections_Generic_Dictionary_object__object__o *)v6->static_fields->_addMethodCache;
  if ( !type )
    goto LABEL_17;
  if ( !StringLiteral_14289 )
  {
    v11 = sub_180466220(&System_ArgumentNullException_TypeInfo, StringLiteral_14289);
    v12 = (System_ArgumentNullException_o *)sub_1804BDC50(v11);
    v14 = (System_String_o *)sub_180466220(&StringLiteral_5948, v13);
    System_ArgumentNullException___ctor_6495755600(v12, v14, 0i64);
    v16 = sub_180466220(&Method_System_Type_GetMethod__, v15);
    sub_1804BDC60(v12, v16);
  }
  v8 = (Il2CppObject *)((__int64 (__fastcall *)(System_Type_o *, System_String_o *, __int64, _QWORD, int, _QWORD, _QWORD, const MethodInfo *))type->klass->vtable._97_unknown.methodPtr)(
                         type,
                         StringLiteral_14289,
                         28i64,
                         0i64,
                         3,
                         0i64,
                         0i64,
                         type->klass->vtable._97_unknown.method);
  if ( !v7 )
LABEL_17:
    sub_1804BDCA0(v5, method, v2);
  System_Collections_Generic_Dictionary_object__object___TryInsert(
    v7,
    (Il2CppObject *)type,
    v8,
    1u,
    *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__MethodInfo__set_Item__
                                                         + 32)
                                             + 192i64)
                                 + 272i64));
LABEL_13:
  v9 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v9 = JsonSerializer_TypeInfo;
  }
  v5 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v9->static_fields->_addMethodCache;
  if ( !v5 )
    goto LABEL_17;
  return (System_Reflection_MethodInfo_o *)System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___get_Item(
                                             v5,
                                             (Il2CppObject *)type,
                                             (const MethodInfo_2E092A0 *)Method_System_Collections_Generic_Dictionary_Type__MethodInfo__get_Item__);
}
