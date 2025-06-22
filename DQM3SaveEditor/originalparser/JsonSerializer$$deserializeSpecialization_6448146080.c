void __stdcall JsonSerializer__deserializeSpecialization_6448146080(AntiCheat_ULong_o **dst, System_String_o *json, const MethodInfo *method)
{
  signed __int32 v5[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D625 )
  {
    sub_180499EE0(&Method_JsonSerializer_deserializeSpecializationImpl_AntiCheat_ULong__ulong___);
    _InterlockedOr(v5, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v5, 0);
    byte_18579D625 = 1;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  JsonSerializer__deserializeSpecializationImpl_object__ulong_(
    (Il2CppObject **)dst,
    json,
    (const MethodInfo_199CF40 *)Method_JsonSerializer_deserializeSpecializationImpl_AntiCheat_ULong__ulong___);
}
