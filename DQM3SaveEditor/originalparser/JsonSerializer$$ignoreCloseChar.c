// local variable allocation has failed, the output may be wrong!
int32_t __stdcall JsonSerializer__ignoreCloseChar(System_ReadOnlySpan_char__o *json, int32_t close_index, const MethodInfo *method)
{
  __int64 v4; // rbx
  int32_t result; // eax
  __int64 v6; // rdx
  signed __int32 v7[8]; // [rsp+0h] [rbp-38h] BYREF
  System_ReadOnlySpan_char__o v8; // [rsp+20h] [rbp-18h] BYREF

  v4 = close_index;
  if ( !byte_18579D601 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v7, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v7, 0);
    byte_18579D601 = 1;
  }
  result = json->fields._length;
  if ( (int)v4 >= 0 )
  {
    if ( (int)v4 < result )
    {
      if ( (unsigned int)v4 >= result )
        sub_1804BDCB0(json, *(_QWORD *)&close_index, method);
      v6 = *(unsigned __int16 *)(json->fields._pointer.fields._value + 2 * v4);
      if ( (_WORD)v6 == 44 || (_WORD)v6 == 125 )
      {
        if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
          il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v6);
        v8 = *json;
        LODWORD(v4) = JsonSerializer__ignoreCloseChar(&v8, v4 + 1, 0i64);
      }
    }
    result = v4;
  }
  return result;
}
