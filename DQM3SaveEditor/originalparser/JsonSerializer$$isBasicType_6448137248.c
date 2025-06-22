bool __stdcall JsonSerializer__isBasicType_6448137248(System_Type_o *type, const MethodInfo *method)
{
  JsonSerializer_c *v3; // rcx
  System_Type_o *v4; // rdi
  System_Type_o *v5; // rdi
  System_Type_o *v6; // rdi
  System_Type_o *v7; // rdi
  System_Type_o *v8; // rdi
  System_Type_o *v9; // rdi
  System_Type_o *v10; // rdi
  System_Type_o *v11; // rdi
  System_Type_o *v12; // rdi
  System_Type_o *v13; // rdi
  System_Type_o *v14; // rdi
  signed __int32 v16[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D611 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v16, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v16, 0);
    byte_18579D611 = 1;
  }
  v3 = JsonSerializer_TypeInfo;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v4 = v3->static_fields->_intType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v4 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v5 = v3->static_fields->_floatType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v5 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v6 = v3->static_fields->_boolType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v6 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v7 = v3->static_fields->_ulongType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v7 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v8 = v3->static_fields->_uintType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v8 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v9 = v3->static_fields->_longType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v9 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v10 = v3->static_fields->_byteType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v10 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v11 = v3->static_fields->_sbyteType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v11 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v12 = v3->static_fields->_shortType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v12 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v13 = v3->static_fields->_ushortType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
    v3 = JsonSerializer_TypeInfo;
  }
  if ( type == v13 )
    return 1;
  if ( !v3->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(v3, method);
    v3 = JsonSerializer_TypeInfo;
  }
  v14 = v3->static_fields->_doubleType;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, method);
  return type == v14;
}
