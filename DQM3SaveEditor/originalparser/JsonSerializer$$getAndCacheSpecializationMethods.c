JsonSerializer_SpecializationMethods_o *__stdcall JsonSerializer__getAndCacheSpecializationMethods(System_Type_o *type, const MethodInfo *method)
{
  unsigned __int64 v2; // r8
  JsonSerializer_c *v4; // rax
  JsonSerializer_SpecializationMethods_o *v5; // rdi
  System_Collections_Generic_Dictionary_TKey__TValue__o *v6; // rcx
  bool v7; // sf
  JsonSerializer_c *v8; // rax
  System_Type_o *v9; // rbp
  __int64 v10; // rax
  System_Type_array *types; // rsi
  System_Reflection_MethodInfo_o *v12; // r15
  JsonSerializer_c *v13; // rax
  Il2CppObject *v14; // r8
  System_Type_o *v15; // r14
  System_Type_array *v16; // rsi
  __int64 v17; // rax
  __int64 v18; // rbp
  struct JsonSerializer_StaticFields *v19; // rcx
  struct System_Type_o *v20; // rbp
  System_Reflection_MethodInfo_o *v21; // rsi
  __int64 v22; // rax
  int v23; // ecx
  signed __int64 v24; // rtt
  unsigned int v25; // er8
  unsigned __int64 v26; // rax
  signed __int64 v27; // rtt
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 v31; // rax
  signed __int32 v32[8]; // [rsp+0h] [rbp-58h] BYREF

  if ( !byte_18579D609 )
  {
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_SpecializationMethods__ContainsKey__);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_SpecializationMethods__get_Item__);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_SpecializationMethods__set_Item__);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&JsonSerializer_SpecializationMethods_TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&System_Type___TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&StringLiteral_14291);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&StringLiteral_14290);
    _InterlockedOr(v32, 0);
    byte_18579D609 = 1;
  }
  v4 = JsonSerializer_TypeInfo;
  v5 = 0i64;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v4 = JsonSerializer_TypeInfo;
  }
  v6 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v4->static_fields->_specializationMethodsCache;
  if ( !v6 )
    goto LABEL_42;
  v7 = System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
         v6,
         (Il2CppObject *)type,
         *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_SpecializationMethods__ContainsKey__
                                                              + 32)
                                                  + 192i64)
                                      + 264i64)) < 0;
  v8 = JsonSerializer_TypeInfo;
  if ( v7 )
  {
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    {
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
      v8 = JsonSerializer_TypeInfo;
    }
    v9 = v8->static_fields->_thisType;
    v10 = il2cpp_array_new_specific_0(System_Type___TypeInfo, 1i64);
    types = (System_Type_array *)v10;
    if ( v10 )
    {
      if ( type && !sub_180481AF0(type, *(_QWORD *)(*(_QWORD *)v10 + 64i64)) )
      {
        v29 = sub_1804BDEC0();
        sub_1804BDC60(v29, 0i64);
      }
      sub_180006A40(types, 0i64, type);
      if ( v9 )
      {
        v12 = System_Type__GetMethod_6496573728(v9, StringLiteral_14290, 65588, 0i64, 3, types, 0i64, 0i64);
        v13 = JsonSerializer_TypeInfo;
        if ( v12 )
        {
          if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
          {
            il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
            v13 = JsonSerializer_TypeInfo;
          }
          v15 = v13->static_fields->_thisType;
          v16 = (System_Type_array *)il2cpp_array_new_specific_0(System_Type___TypeInfo, 2i64);
          if ( type )
          {
            v17 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))type->klass->vtable._124_MakeByRefType.methodPtr)(
                    type,
                    type->klass->vtable._124_MakeByRefType.method);
            v18 = v17;
            if ( v16 )
            {
              if ( v17 && !sub_180481AF0(v17, v16->obj.klass->_1.element_class) )
              {
                v30 = sub_1804BDEC0();
                sub_1804BDC60(v30, 0i64);
              }
              sub_180006A40(v16, 0i64, v18);
              v19 = JsonSerializer_TypeInfo->static_fields;
              v20 = v19->_stringType;
              if ( v20 && !sub_180481AF0(v19->_stringType, v16->obj.klass->_1.element_class) )
              {
                v31 = sub_1804BDEC0();
                sub_1804BDC60(v31, 0i64);
              }
              sub_180006A40(v16, 1i64, v20);
              if ( v15 )
              {
                v21 = System_Type__GetMethod_6496573728(v15, StringLiteral_14291, 65592, 0i64, 3, v16, 0i64, 0i64);
                v22 = sub_180481BA0(JsonSerializer_SpecializationMethods_TypeInfo);
                v23 = dword_18579B674;
                *(_QWORD *)(v22 + 16) = v12;
                v5 = (JsonSerializer_SpecializationMethods_o *)v22;
                if ( v23 )
                {
                  method = (const MethodInfo *)&qword_1857BAE80[(((unsigned __int64)(v22 + 16) >> 12) & 0x1FFFFF) >> 6];
                  _m_prefetchw(&method[3266].parameters);
                  do
                    v24 = (signed __int64)method[3266].parameters;
                  while ( v24 != _InterlockedCompareExchange64(
                                   (volatile signed __int64 *)&method[3266].parameters,
                                   v24 | (1i64 << (((unsigned __int64)(v22 + 16) >> 12) & 0x3F)),
                                   v24) );
                  v23 = dword_18579B674;
                }
                *(_QWORD *)(v22 + 24) = v21;
                v2 = v22 + 24;
                if ( v23 )
                {
                  v25 = (v2 >> 12) & 0x1FFFFF;
                  v26 = (unsigned __int64)v25 >> 6;
                  v2 = v25 & 0x3F;
                  method = (const MethodInfo *)&qword_1857BAE80[v26];
                  _m_prefetchw(&method[3266].parameters);
                  do
                    v27 = (signed __int64)method[3266].parameters;
                  while ( v27 != _InterlockedCompareExchange64(
                                   (volatile signed __int64 *)&method[3266].parameters,
                                   v27 | (1i64 << v2),
                                   v27) );
                }
                v6 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)JsonSerializer_TypeInfo->static_fields->_specializationMethodsCache;
                if ( v6 )
                {
                  v14 = (Il2CppObject *)v5;
                  goto LABEL_40;
                }
              }
            }
          }
        }
        else
        {
          if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
          {
            il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
            v13 = JsonSerializer_TypeInfo;
          }
          v6 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v13->static_fields->_specializationMethodsCache;
          if ( v6 )
          {
            v14 = 0i64;
LABEL_40:
            System_Collections_Generic_Dictionary_object__object___TryInsert(
              (System_Collections_Generic_Dictionary_object__object__o *)v6,
              (Il2CppObject *)type,
              v14,
              1u,
              *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_SpecializationMethods__set_Item__
                                                                   + 32)
                                                       + 192i64)
                                           + 272i64));
            return v5;
          }
        }
      }
    }
LABEL_42:
    sub_1804BDCA0(v6, method, v2);
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v8 = JsonSerializer_TypeInfo;
  }
  v6 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v8->static_fields->_specializationMethodsCache;
  if ( !v6 )
    goto LABEL_42;
  return (JsonSerializer_SpecializationMethods_o *)System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___get_Item(
                                                     v6,
                                                     (Il2CppObject *)type,
                                                     Method_System_Collections_Generic_Dictionary_Type__JsonSerializer_SpecializationMethods__get_Item__);
}
