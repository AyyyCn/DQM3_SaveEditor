void __stdcall JsonSerializer__serializeSpecialization_6448147184(JsonSerializer_o *this, AntiCheat_eMonsterSkill__o *src, const MethodInfo *method)
{
  signed __int32 v5[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D62E )
  {
    sub_180499EE0(&Method_JsonSerializer_serializeSpecializationEnum_eMonsterSkill___);
    _InterlockedOr(v5, 0);
    byte_18579D62E = 1;
  }
  JsonSerializer__serializeSpecializationEnum_Int32Enum_(
    this,
    (AntiCheat_T__o *)src,
    (const MethodInfo_199D7A0 *)Method_JsonSerializer_serializeSpecializationEnum_eMonsterSkill___);
}
