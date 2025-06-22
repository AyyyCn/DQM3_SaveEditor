void __stdcall JsonSerializer__deserializeSpecializationEnum___Il2CppFullySharedGenericStructType_(AntiCheat_T__o **dst, System_String_o *json, const MethodInfo_199C800 *method)
{
  signed __int32 v6[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v6, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  ((void (__fastcall *)(AntiCheat_T__o **, System_String_o *, MethodInfo *))method->rgctx_data->_1_JsonSerializer_deserializeSpecializationImpl_AntiCheat_T___T_->methodPointer)(
    dst,
    json,
    method->rgctx_data->_1_JsonSerializer_deserializeSpecializationImpl_AntiCheat_T___T_);
}
