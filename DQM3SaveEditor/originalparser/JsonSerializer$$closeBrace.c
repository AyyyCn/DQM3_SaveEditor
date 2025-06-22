void __stdcall JsonSerializer__closeBrace(JsonSerializer_o *this, const MethodInfo *method)
{
  __int64 v3; // rdx
  signed __int32 v4[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D60F )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v4, 0);
    byte_18579D60F = 1;
  }
  --this->fields._indentCnt;
  JsonSerializer__appendIndent(this, 0i64);
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v3);
  sub_180570A70(&this->fields, 125i64);
}
