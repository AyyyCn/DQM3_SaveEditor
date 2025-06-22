System_ReadOnlySpan_char__o *JsonSerializer__eraseDoubleQuotation(System_ReadOnlySpan_char__o *retstr, System_ReadOnlySpan_char__o *json, const MethodInfo *method)
{
  System_ReadOnlySpan_char__o *v4; // rdi
  __int64 v5; // rdx
  int32_t v6; // ebx
  char *v7; // rsi
  __int64 v8; // rcx
  System_ReadOnlySpan_char__o *result; // rax
  signed __int32 v10[8]; // [rsp+0h] [rbp-38h] BYREF
  System_ReadOnlySpan_char__o v11; // [rsp+20h] [rbp-18h]

  v4 = retstr;
  if ( !byte_18579D5FD )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice___6531935520);
    _InterlockedOr(v10, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v10, 0);
    byte_18579D5FD = 1;
  }
  v5 = json->fields._length;
  if ( !(_DWORD)v5 )
    goto LABEL_12;
  retstr = (System_ReadOnlySpan_char__o *)json->fields._pointer.fields._value;
  if ( *(_WORD *)json->fields._pointer.fields._value != 34 )
  {
LABEL_11:
    result = v4;
    *v4 = *json;
    return result;
  }
  method = (const MethodInfo *)(unsigned int)(v5 - 1);
  if ( (unsigned int)method >= (unsigned int)v5 )
LABEL_12:
    sub_1804BDCB0(retstr, v5, method);
  if ( *((_WORD *)retstr + v5 - 1) != 34 )
    goto LABEL_11;
  v6 = v5 - 2;
  if ( (int)v5 - 2 > (unsigned int)method )
    System_ThrowHelper__ThrowArgumentOutOfRangeException(0i64);
  v7 = (char *)&retstr->fields._pointer.fields._value + 2;
  *(&v11.fields._length + 1) = 0;
  v8 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice___6531935520 + 32);
  if ( (*(_BYTE *)(v8 + 309) & 1) == 0 )
    sub_1804E30B0(v8);
  v11.fields._pointer.fields._value = (intptr_t)v7;
  result = v4;
  v11.fields._length = v6;
  *v4 = v11;
  return result;
}
