Cysharp_Text_Utf16ValueStringBuilder_o *JsonSerializer__removeSpaceAndNewLineCode(Cysharp_Text_Utf16ValueStringBuilder_o *retstr, System_String_o *str, const MethodInfo *method)
{
  Cysharp_Text_Utf16ValueStringBuilder_o *v4; // r15
  unsigned int v5; // ebx
  int32_t v6; // ebx
  uint16_t v7; // si
  uint16_t *v8; // rdi
  int32_t v9; // er14
  __int64 v10; // rdx
  uint16_t v11; // si
  signed __int32 v13[8]; // [rsp+0h] [rbp-38h] BYREF

  v4 = retstr;
  if ( !byte_18579D608 )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v13, 0);
    sub_180499EE0(&Utility_TypeInfo);
    _InterlockedOr(v13, 0);
    sub_180499EE0(&StringLiteral_14292);
    _InterlockedOr(v13, 0);
    byte_18579D608 = 1;
  }
  *v4 = 0i64;
  if ( !str )
LABEL_25:
    sub_1804BDCA0(retstr, str, method);
  v5 = str->fields._stringLength;
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, str);
  sub_180570760(v4, 0i64, v5);
  v6 = 0;
  while ( v6 < str->fields._stringLength )
  {
    retstr = (Cysharp_Text_Utf16ValueStringBuilder_o *)str->fields._stringLength;
    if ( (unsigned int)v6 >= (__int64)retstr )
      goto LABEL_26;
    v7 = *(&str->fields._firstChar + v6);
    v8 = &str->fields._firstChar + v6;
    if ( v7 == 34 )
    {
      if ( !Utility_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Utility_TypeInfo, str);
      v9 = Utility__searchStringEndIndex(str, v6, 0i64);
      if ( v6 <= v9 )
      {
        while ( 1 )
        {
          v10 = str->fields._stringLength;
          if ( (unsigned int)v6 >= v10 )
            break;
          v11 = *v8;
          if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
            il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v10);
          sub_180570A70(v4, v11);
          ++v6;
          ++v8;
          if ( v6 > v9 )
            goto LABEL_22;
        }
LABEL_26:
        System_ThrowHelper__ThrowIndexOutOfRangeException(0i64);
      }
LABEL_22:
      v6 = v9;
      goto LABEL_23;
    }
    if ( !StringLiteral_14292 )
      goto LABEL_25;
    if ( System_SpanHelpers__IndexOf_6496540096(
           (uint16_t *)(StringLiteral_14292 + 20),
           v7,
           *(_DWORD *)(StringLiteral_14292 + 16),
           0i64) == -1 )
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, str);
      sub_180570A70(v4, v7);
      ++v6;
    }
    else
    {
LABEL_23:
      ++v6;
    }
  }
  return v4;
}
