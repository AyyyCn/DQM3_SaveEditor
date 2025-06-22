bool __stdcall JsonSerializer__isEqual(System_ReadOnlySpan_char__o *l, System_ReadOnlySpan_char__o *r, const MethodInfo *method)
{
  System_ReadOnlySpan_char__o *v3; // rdi
  System_ReadOnlySpan_char__o *v4; // rsi
  __int64 v5; // r10
  unsigned int v6; // er11
  __int64 v7; // r8
  __int64 v8; // r9
  signed __int32 v10[10]; // [rsp+0h] [rbp-28h] BYREF

  v3 = r;
  v4 = l;
  if ( !byte_18579D603 )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v10, 0);
    byte_18579D603 = 1;
  }
  v5 = v4->fields._length;
  v6 = v3->fields._length;
  if ( (_DWORD)v5 == v6 )
  {
    v7 = 0i64;
    if ( (int)v5 <= 0 )
      return 1;
    v8 = 0i64;
    while ( 1 )
    {
      if ( (unsigned int)v7 >= (unsigned int)v5 || (unsigned int)v7 >= v6 )
        sub_1804BDCB0(l, r, v7);
      r = (System_ReadOnlySpan_char__o *)v4->fields._pointer.fields._value;
      l = (System_ReadOnlySpan_char__o *)*(unsigned __int16 *)(v3->fields._pointer.fields._value + 2 * v8);
      if ( *(_WORD *)(v4->fields._pointer.fields._value + 2 * v8) != (_WORD)l )
        break;
      v7 = (unsigned int)(v7 + 1);
      if ( ++v8 >= v5 )
        return 1;
    }
  }
  return 0;
}
