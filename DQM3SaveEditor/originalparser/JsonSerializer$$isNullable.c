bool __stdcall JsonSerializer__isNullable(System_Type_o *type, System_Type_array *generic_arguments, const MethodInfo *method)
{
  System_Type_o *v4; // rsi
  System_Type_o *v5; // rdi
  JsonSerializer_c *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // rbx
  signed __int32 v10[10]; // [rsp+0h] [rbp-28h] BYREF

  v4 = type;
  if ( !byte_18579D602 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v10, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v10, 0);
    byte_18579D602 = 1;
  }
  if ( !generic_arguments )
    goto LABEL_15;
  if ( LODWORD(generic_arguments->max_length) != 1 )
    return 0;
  v5 = generic_arguments->m_Items[0];
  if ( !v5 )
    goto LABEL_15;
  if ( (((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *, const MethodInfo *))v5->klass->vtable._55_unknown.methodPtr)(
          generic_arguments->m_Items[0],
          v5->klass->vtable._55_unknown.method,
          method) & 0x20) == 0
    && !((unsigned __int8 (__fastcall *)(System_Type_o *, const MethodInfo *))v5->klass->vtable._75_IsValueTypeImpl.methodPtr)(
          v5,
          v5->klass->vtable._75_IsValueTypeImpl.method) )
  {
    return 0;
  }
  v6 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, generic_arguments);
    v6 = JsonSerializer_TypeInfo;
  }
  type = v6->static_fields->_nullableBaseType;
  if ( !type )
LABEL_15:
    sub_1804BDCA0(type, generic_arguments, method);
  v8 = ((__int64 (__fastcall *)(System_Type_o *, System_Type_array *, const MethodInfo *))type->klass->vtable._125_MakeGenericType.methodPtr)(
         type,
         generic_arguments,
         type->klass->vtable._125_MakeGenericType.method);
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, v7);
  return v4 == (System_Type_o *)v8;
}
