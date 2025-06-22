bool __stdcall JsonSerializer__isBasicType(Il2CppObject *src, const MethodInfo *method)
{
  __int64 v2; // r8
  __int64 v4; // rdx
  System_Type_o *v5; // rbx
  signed __int32 v7[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D610 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v7, 0);
    byte_18579D610 = 1;
  }
  if ( !src )
    sub_1804BDCA0(src, method, v2);
  v5 = (System_Type_o *)il2cpp_type_get_object_0(&src->klass->_1.byval_arg);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v4);
  return JsonSerializer__isBasicType_6448137248(v5, 0i64);
}
