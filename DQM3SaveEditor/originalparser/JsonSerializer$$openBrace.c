void __stdcall JsonSerializer__openBrace(JsonSerializer_o *this, const MethodInfo *method)
{
  signed __int32 v3[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D60E )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v3, 0);
    byte_18579D60E = 1;
  }
  if ( this->fields._enableOptimize )
  {
    if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, method);
    sub_180570A70(&this->fields, 123i64);
    ++this->fields._indentCnt;
  }
  else
  {
    if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, method);
    sub_180570B10(&this->fields, 123i64, 10i64);
    ++this->fields._indentCnt;
  }
}
