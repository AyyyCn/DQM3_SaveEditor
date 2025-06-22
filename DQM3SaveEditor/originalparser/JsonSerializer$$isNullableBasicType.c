bool __stdcall JsonSerializer__isNullableBasicType(System_Type_o *type, const MethodInfo *method)
{
  __int64 v2; // r8
  JsonSerializer_c *v4; // rax
  System_Type_c *v5; // rcx
  System_Type_o *v6; // rdi
  __int64 v8; // rax
  System_Type_o *v9; // rbx
  signed __int32 v10[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D612 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v10, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v10, 0);
    byte_18579D612 = 1;
  }
  v4 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v4 = JsonSerializer_TypeInfo;
  }
  v5 = System_Type_TypeInfo;
  v6 = v4->static_fields->_nullableBaseType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
  if ( v6 != type )
    return 0;
  if ( !type
    || (v8 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))type->klass->vtable._50_GetGenericArguments.methodPtr)(
               type,
               type->klass->vtable._50_GetGenericArguments.method)) == 0 )
  {
    sub_1804BDCA0(v5, method, v2);
  }
  if ( !*(_DWORD *)(v8 + 24) )
    sub_1804BDCB0(v5, method, v2);
  v9 = *(System_Type_o **)(v8 + 32);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
  return JsonSerializer__isBasicType_6448137248(v9, 0i64);
}
