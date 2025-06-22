int32_t __stdcall JsonSerializer__indexOfColon(System_ReadOnlySpan_char__o *json, const MethodInfo *method)
{
  __int64 v2; // r8
  System_ReadOnlySpan_char__o *v3; // rsi
  int v4; // edi
  int v5; // ebx
  bool v6; // cf
  signed __int32 v8[8]; // [rsp+0h] [rbp-38h] BYREF
  System_ReadOnlySpan_char__o v9; // [rsp+20h] [rbp-18h] BYREF

  v3 = json;
  if ( !byte_18579D5FC )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v8, 0);
    sub_180499EE0(&Utility_TypeInfo);
    _InterlockedOr(v8, 0);
    byte_18579D5FC = 1;
  }
  v4 = v3->fields._length;
  v5 = 0;
  if ( v4 <= 0 )
    return -1;
  v6 = v4 != 0;
  while ( 1 )
  {
    if ( !v6 )
      sub_1804BDCB0(json, method, v2);
    json = (System_ReadOnlySpan_char__o *)v5;
    method = (const MethodInfo *)*(unsigned __int16 *)(v3->fields._pointer.fields._value + 2i64 * v5);
    if ( (_WORD)method == 58 )
      return v5;
    if ( (_WORD)method != 34 )
      goto LABEL_17;
    if ( !Utility_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Utility_TypeInfo, method);
    v9 = *v3;
    v5 = Utility__searchStringEndIndex_6455484992(&v9, v5, 0i64);
    if ( v5 >= 0 )
    {
LABEL_17:
      v6 = ++v5 < (unsigned int)v4;
      if ( v5 < v4 )
        continue;
    }
    return -1;
  }
}
