void __stdcall JsonSerializer__appendIndent(JsonSerializer_o *this, const MethodInfo *method)
{
  __int64 v2; // r8
  int32_t i; // er14
  Cysharp_Text_Utf16ValueStringBuilder_c *v5; // rcx
  System_String_o *v6; // rbx
  struct System_Char_array *v7; // rax
  int32_t v8; // esi
  signed __int32 v9[8]; // [rsp+0h] [rbp-48h] BYREF

  if ( !byte_18579D613 )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v9, 0);
    sub_180499EE0(&StringLiteral_14288);
    _InterlockedOr(v9, 0);
    byte_18579D613 = 1;
  }
  if ( !this->fields._enableOptimize )
  {
    for ( i = 0; i < this->fields._indentCnt; this->fields._str.fields.index += v6->fields._stringLength )
    {
      v5 = Cysharp_Text_Utf16ValueStringBuilder_TypeInfo;
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, method);
      v6 = StringLiteral_14288;
      if ( !byte_18579AC17 )
      {
        sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
        _InterlockedOr(v9, 0);
        byte_18579AC17 = 1;
      }
      v7 = this->fields._str.fields.buffer;
      if ( !v7 || !v6 )
        sub_1804BDCA0(v5, method, v2);
      v8 = v6->fields._stringLength;
      if ( LODWORD(v7->max_length) - this->fields._str.fields.index < v8 )
      {
        if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
          il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, method);
        Cysharp_Text_Utf16ValueStringBuilder__Grow(&this->fields._str, v8, 0i64);
      }
      System_String__CopyTo(
        v6,
        0,
        this->fields._str.fields.buffer,
        this->fields._str.fields.index,
        v6->fields._stringLength,
        0i64);
      ++i;
    }
  }
}
