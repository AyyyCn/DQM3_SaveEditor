// local variable allocation has failed, the output may be wrong!
System_String_o *__stdcall JsonSerializer__str(JsonSerializer_o *this, bool enable_optimize, const MethodInfo *method)
{
  int32_t v5; // er8
  System_String_o *v6; // rbx
  Cysharp_Text_Utf16ValueStringBuilder_o *v7; // rax
  __int64 v8; // rdx
  bool v9; // zf
  System_String_o *result; // rax
  signed __int32 v11[8]; // [rsp+0h] [rbp-48h] BYREF
  Cysharp_Text_Utf16ValueStringBuilder_o v12; // [rsp+20h] [rbp-28h]
  Cysharp_Text_Utf16ValueStringBuilder_o v13; // [rsp+30h] [rbp-18h] BYREF

  if ( !byte_18579D606 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v11, 0);
    byte_18579D606 = 1;
  }
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, enable_optimize);
  if ( !byte_1857BA395 )
  {
    sub_180499EE0(&string_TypeInfo);
    _InterlockedOr(v11, 0);
    byte_1857BA395 = 1;
  }
  v5 = this->fields._str.fields.index;
  if ( v5 )
    v6 = System_String__Ctor_6494404128(this->fields._str.fields.buffer, 0, v5, 0i64);
  else
    v6 = string_TypeInfo->static_fields->Empty;
  if ( !enable_optimize )
    return v6;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, enable_optimize);
  v7 = JsonSerializer__removeSpaceAndNewLineCode(&v13, v6, 0i64);
  v9 = Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished == 0;
  v12 = *v7;
  if ( v9 )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v8);
  if ( !byte_1857BA395 )
  {
    sub_180499EE0(&string_TypeInfo);
    _InterlockedOr(v11, 0);
    byte_1857BA395 = 1;
  }
  if ( v12.fields.index )
    result = System_String__Ctor_6494404128(v12.fields.buffer, 0, v12.fields.index, 0i64);
  else
    result = string_TypeInfo->static_fields->Empty;
  return result;
}
