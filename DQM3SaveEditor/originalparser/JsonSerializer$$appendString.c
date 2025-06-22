void __stdcall JsonSerializer__appendString(JsonSerializer_o *this, System_String_o *src, const MethodInfo *method)
{
  JsonSerializer_Fields *v5; // rbp
  __int64 v6; // rdx
  __int64 v7; // r8
  unsigned int v8; // edi
  int32_t v9; // ecx
  uint16_t *v10; // rsi
  uint16_t v11; // bx
  signed __int32 v12[10]; // [rsp+0h] [rbp-28h] BYREF

  if ( !byte_18579D614 )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v12, 0);
    byte_18579D614 = 1;
  }
  v5 = &this->fields;
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, src);
  sub_180570A70(v5, 34i64);
  v8 = 0;
  v9 = 0;
  if ( !src )
    sub_1804BDCA0(0i64, v6, v7);
  v10 = &src->fields._firstChar;
  while ( v9 < src->fields._stringLength )
  {
    if ( v8 >= (__int64)src->fields._stringLength )
      System_ThrowHelper__ThrowIndexOutOfRangeException(0i64);
    v11 = *v10;
    if ( *v10 == 92 || v11 == 34 )
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v6);
      sub_180570B10(v5, 92i64, v11);
      ++v8;
      ++v10;
      v9 = v8;
    }
    else
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v6);
      sub_180570A70(v5, v11);
      ++v8;
      ++v10;
      v9 = v8;
    }
  }
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v6);
  sub_180570A70(v5, 34i64);
}
