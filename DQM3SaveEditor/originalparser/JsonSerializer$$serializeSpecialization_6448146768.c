void __stdcall JsonSerializer__serializeSpecialization_6448146768(JsonSerializer_o *this, AntiCheat_eMonsterKind__o *src, const MethodInfo *method)
{
  signed __int32 v5[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D62A )
  {
    sub_180499EE0(&Method_JsonSerializer_serializeSpecializationEnum_eMonsterKind___);
    _InterlockedOr(v5, 0);
    byte_18579D62A = 1;
  }
  JsonSerializer__serializeSpecializationEnum_Int32Enum_(
    this,
    (AntiCheat_T__o *)src,
    (const MethodInfo_199D7A0 *)Method_JsonSerializer_serializeSpecializationEnum_eMonsterKind___);
}
