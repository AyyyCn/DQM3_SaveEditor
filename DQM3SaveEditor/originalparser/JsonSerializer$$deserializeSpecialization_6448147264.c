void __stdcall JsonSerializer__deserializeSpecialization_6448147264(AntiCheat_eMonsterSkill__o **dst, System_String_o *json, const MethodInfo *method)
{
  signed __int32 v5[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D62F )
  {
    sub_180499EE0(&Method_JsonSerializer_deserializeSpecializationEnum_eMonsterSkill___);
    _InterlockedOr(v5, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v5, 0);
    byte_18579D62F = 1;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  JsonSerializer__deserializeSpecializationEnum_Int32Enum_(
    (AntiCheat_T__o **)dst,
    json,
    (const MethodInfo_199C780 *)Method_JsonSerializer_deserializeSpecializationEnum_eMonsterSkill___);
}
