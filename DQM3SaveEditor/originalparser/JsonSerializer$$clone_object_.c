Il2CppObject *__stdcall JsonSerializer__clone_object_(System_String_o *root_name, Il2CppObject *obj, const MethodInfo_199C0F0 *method)
{
  JsonSerializer_o *v6; // rdi
  __int64 v7; // rdx
  __int64 v8; // rcx
  __int64 v9; // r8
  JsonSerializer_o *v10; // rax
  __int64 v11; // rdx
  System_String_o *v12; // rdi
  signed __int32 v14[8]; // [rsp+0h] [rbp-38h] BYREF
  Il2CppObject *dst; // [rsp+40h] [rbp+8h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v14, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v6 = (JsonSerializer_o *)sub_180481BA0(JsonSerializer_TypeInfo);
  JsonSerializer___ctor(v6, 1, 0i64);
  if ( !v6 || (v10 = JsonSerializer__serialize(v6, root_name, obj, 0, 0i64)) == 0i64 )
    sub_1804BDCA0(v8, v7, v9);
  v12 = JsonSerializer__str(v10, 0, 0i64);
  dst = 0i64;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v11);
  JsonSerializer__deserialize_object_(
    v12,
    root_name,
    &dst,
    (const MethodInfo_199C3A0 *)method->rgctx_data->_1_JsonSerializer_deserialize_T_);
  return dst;
}
