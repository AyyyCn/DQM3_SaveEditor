JsonSerializer_InsideBraces_o *JsonSerializer__extractInsideBraces(JsonSerializer_InsideBraces_o *retstr, System_ReadOnlySpan_char__o *json, int32_t start_index, const MethodInfo *method)
{
  __int64 v5; // rdi
  unsigned int v7; // ebx
  intptr_t v8; // rax
  intptr_t v9; // rsi
  __int64 v10; // rcx
  int32_t v11; // ebx
  JsonSerializer_InsideBracesIndex_o *v12; // rax
  __int64 v13; // r8
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // kr00_8
  __int64 v18; // rax
  System_Exception_o *v19; // rbx
  __int64 v20; // rdx
  System_String_o *v21; // rax
  __int64 v22; // rdx
  __int64 v23; // rax
  __int64 v24; // rax
  System_Exception_o *v25; // rbx
  __int64 v26; // rdx
  System_String_o *v27; // rax
  __int64 v28; // rdx
  __int64 v29; // rax
  signed __int32 v30[8]; // [rsp+0h] [rbp-68h] BYREF
  int32_t v31; // [rsp+20h] [rbp-48h]
  const MethodInfo *v32; // [rsp+28h] [rbp-40h]
  __int64 v33; // [rsp+30h] [rbp-38h]
  JsonSerializer_InsideBracesIndex_o v34; // [rsp+40h] [rbp-28h] BYREF
  System_ReadOnlySpan_char__o v35; // [rsp+50h] [rbp-18h] BYREF

  v5 = start_index;
  if ( !byte_18579D5FF )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v30, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice__);
    _InterlockedOr(v30, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v30, 0);
    byte_18579D5FF = 1;
  }
  v7 = json->fields._length;
  if ( (unsigned int)v5 > v7 )
    System_ThrowHelper__ThrowArgumentOutOfRangeException(0i64);
  v8 = json->fields._pointer.fields._value;
  *(&v35.fields._length + 1) = 0;
  v9 = v8 + 2 * v5;
  v10 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice__ + 32);
  if ( (*(_BYTE *)(v10 + 309) & 1) == 0 )
    sub_1804E30B0(v10);
  v11 = v7 - v5;
  v35.fields._pointer.fields._value = v9;
  v35.fields._length = v11;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  v12 = JsonSerializer__extractInsideBracesIndex(&v34, &v35, 0i64);
  v14 = (unsigned int)v12->fields.nextStartIndex;
  v33 = *(_QWORD *)&v12->fields.startIndex;
  if ( v33 < 0 || SHIDWORD(v33) > v11 )
  {
    v24 = sub_180466220(&System_Exception_TypeInfo, v14);
    v25 = (System_Exception_o *)sub_1804BDC50(v24);
    v27 = (System_String_o *)sub_180466220(&StringLiteral_14295, v26);
    System_Exception___ctor_6496732416(v25, v27, 0i64);
    v29 = sub_180466220(&Method_JsonSerializer_extractInsideBraces__, v28);
    sub_1804BDC60(v25, v29);
  }
  if ( (_DWORD)v14 != v11 )
  {
    v15 = (unsigned int)(v14 - 1);
    if ( (unsigned int)v15 >= v11 )
      sub_1804BDCB0(v15, v14, v13);
    if ( *(_WORD *)(v9 + 2i64 * (int)v15) != 44 && *(_WORD *)(v9 + 2i64 * (int)v15) != 125 )
    {
      v18 = sub_180466220(&System_Exception_TypeInfo, v14);
      v19 = (System_Exception_o *)sub_1804BDC50(v18);
      v21 = (System_String_o *)sub_180466220(&StringLiteral_14294, v20);
      System_Exception___ctor_6496732416(v19, v21, 0i64);
      v23 = sub_180466220(&Method_JsonSerializer_extractInsideBraces__, v22);
      sub_1804BDC60(v19, v23);
    }
  }
  v16 = v33;
  v32 = 0i64;
  retstr->fields.srcStr = 0i64;
  v31 = v14 + v5;
  retstr->fields.inside = 0i64;
  *(_OWORD *)&retstr->fields.insideIndex.fields.start = 0i64;
  v35 = *json;
  JsonSerializer_InsideBraces___ctor(retstr, &v35, v16 + v5, HIDWORD(v16) - v16 + 1, v31, v32);
  return retstr;
}
