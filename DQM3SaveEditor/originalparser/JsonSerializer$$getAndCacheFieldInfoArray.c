System_Reflection_FieldInfo_array *__stdcall JsonSerializer__getAndCacheFieldInfoArray(System_Type_o *type, const MethodInfo *method)
{
  __int64 v2; // r8
  JsonSerializer_c *v4; // rax
  System_Collections_Generic_Dictionary_TKey__TValue__o *v5; // rcx
  JsonSerializer_c *v6; // rax
  System_Collections_Generic_Dictionary_object__object__o *v7; // rdi
  Il2CppObject *v8; // rax
  JsonSerializer_c *v9; // rax
  signed __int32 v11[8]; // [rsp+0h] [rbp-38h] BYREF

  if ( !byte_18579D60A )
  {
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__FieldInfo____ContainsKey__);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__FieldInfo____get_Item__);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__FieldInfo____set_Item__);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v11, 0);
    byte_18579D60A = 1;
  }
  v4 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v4 = JsonSerializer_TypeInfo;
  }
  v5 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v4->static_fields->_fieldInfoArrayCache;
  if ( !v5 )
    goto LABEL_16;
  if ( System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
         v5,
         (Il2CppObject *)type,
         *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__FieldInfo____ContainsKey__
                                                              + 32)
                                                  + 192i64)
                                      + 264i64)) >= 0 )
    goto LABEL_12;
  v6 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v6 = JsonSerializer_TypeInfo;
  }
  v7 = (System_Collections_Generic_Dictionary_object__object__o *)v6->static_fields->_fieldInfoArrayCache;
  if ( !type
    || (v8 = (Il2CppObject *)((__int64 (__fastcall *)(System_Type_o *, __int64, const MethodInfo *))type->klass->vtable._86_unknown.methodPtr)(
                               type,
                               52i64,
                               type->klass->vtable._86_unknown.method),
        !v7) )
  {
LABEL_16:
    sub_1804BDCA0(v5, method, v2);
  }
  System_Collections_Generic_Dictionary_object__object___TryInsert(
    v7,
    (Il2CppObject *)type,
    v8,
    1u,
    *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__FieldInfo____set_Item__
                                                         + 32)
                                             + 192i64)
                                 + 272i64));
LABEL_12:
  v9 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v9 = JsonSerializer_TypeInfo;
  }
  v5 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v9->static_fields->_fieldInfoArrayCache;
  if ( !v5 )
    goto LABEL_16;
  return (System_Reflection_FieldInfo_array *)System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___get_Item(
                                                v5,
                                                (Il2CppObject *)type,
                                                (const MethodInfo_2E092A0 *)Method_System_Collections_Generic_Dictionary_Type__FieldInfo____get_Item__);
}
