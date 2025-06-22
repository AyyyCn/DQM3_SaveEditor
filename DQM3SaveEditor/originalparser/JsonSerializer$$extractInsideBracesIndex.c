JsonSerializer_InsideBracesIndex_o *JsonSerializer__extractInsideBracesIndex(JsonSerializer_InsideBracesIndex_o *retstr, System_ReadOnlySpan_char__o *json, const MethodInfo *method)
{
  JsonSerializer_InsideBracesIndex_o *v4; // rsi
  int32_t v5; // ebp
  intptr_t v6; // r15
  __int16 v7; // ax
  __int64 v8; // rdx
  int v9; // ebx
  int32_t v10; // eax
  int32_t v12; // eax
  int32_t v13; // edi
  int v14; // ebx
  __int64 v15; // rdx
  int32_t v16; // eax
  int v17; // edi
  bool v18; // cf
  signed __int32 v19[8]; // [rsp+0h] [rbp-68h] BYREF
  System_ReadOnlySpan_char__o v20; // [rsp+20h] [rbp-48h]
  System_ReadOnlySpan_char__o v21; // [rsp+30h] [rbp-38h] BYREF
  System_ReadOnlySpan_char__o v22; // [rsp+40h] [rbp-28h] BYREF

  v4 = retstr;
  if ( !byte_18579D600 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v19, 0);
    sub_180499EE0(&Method_System_MemoryExtensions_IndexOf_char___);
    _InterlockedOr(v19, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v19, 0);
    sub_180499EE0(&Utility_TypeInfo);
    _InterlockedOr(v19, 0);
    byte_18579D600 = 1;
  }
  v5 = json->fields._length;
  if ( !v5 )
    goto LABEL_46;
  v6 = json->fields._pointer.fields._value;
  v7 = *(_WORD *)json->fields._pointer.fields._value;
  if ( v7 != 123 )
  {
    if ( v7 != 34 )
    {
      v21 = *json;
      v9 = System_MemoryExtensions__IndexOf_char_(
             (System_ReadOnlySpan_T__o *)&v21,
             0x2Cu,
             (const MethodInfo_570DA0 *)Method_System_MemoryExtensions_IndexOf_char___);
      if ( v9 < 0 )
      {
        v21 = *json;
        v9 = System_MemoryExtensions__IndexOf_char_(
               (System_ReadOnlySpan_T__o *)&v21,
               0x7Du,
               (const MethodInfo_570DA0 *)Method_System_MemoryExtensions_IndexOf_char___);
        if ( v9 < 0 )
          v9 = v5;
      }
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v8);
      v21 = *json;
      v10 = JsonSerializer__ignoreCloseChar(&v21, v9, 0i64);
      v4->fields.startIndex = 0;
      goto LABEL_12;
    }
    if ( !Utility_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Utility_TypeInfo, json);
    v22 = *json;
    v12 = Utility__searchStringEndIndex_6455484992(&v22, 0, 0i64);
    retstr = (JsonSerializer_InsideBracesIndex_o *)JsonSerializer_TypeInfo;
    v13 = v12;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
    v14 = v13 + 1;
    v20 = *json;
    if ( !byte_18579D601 )
    {
      sub_180499EE0(&JsonSerializer_TypeInfo);
      _InterlockedOr(v19, 0);
      sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
      _InterlockedOr(v19, 0);
      byte_18579D601 = 1;
    }
    if ( v14 < 0 )
    {
      v14 = v20.fields._length;
      goto LABEL_29;
    }
    if ( v14 >= v20.fields._length )
    {
LABEL_29:
      v4->fields.endIndex = v13;
      v4->fields.startIndex = 0;
      v4->fields.nextStartIndex = v14;
      return v4;
    }
    if ( (unsigned int)v14 < v20.fields._length )
    {
      v15 = *(unsigned __int16 *)(v20.fields._pointer.fields._value + 2i64 * v14);
      if ( (_WORD)v15 == 44 || (_WORD)v15 == 125 )
      {
        if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
          il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v15);
        v21 = *json;
        v16 = JsonSerializer__ignoreCloseChar(&v21, v13 + 2, 0i64);
        v4->fields.endIndex = v13;
        v4->fields.startIndex = 0;
        v4->fields.nextStartIndex = v16;
        return v4;
      }
      goto LABEL_29;
    }
LABEL_46:
    sub_1804BDCB0(retstr, json, method);
  }
  v17 = 1;
  v9 = 1;
  if ( v5 <= 1 )
  {
LABEL_45:
    v4->fields.endIndex = -1;
    v4->fields.startIndex = 0;
    v4->fields.nextStartIndex = 0;
    return v4;
  }
  v18 = (unsigned int)v5 > 1;
  while ( 1 )
  {
    if ( !v18 )
      goto LABEL_46;
    retstr = (JsonSerializer_InsideBracesIndex_o *)*(unsigned __int16 *)(v6 + 2i64 * v9);
    if ( (_WORD)retstr == 34 )
    {
      if ( !Utility_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Utility_TypeInfo, json);
      v21 = *json;
      v9 = Utility__searchStringEndIndex_6455484992(&v21, v9, 0i64);
      goto LABEL_44;
    }
    if ( (_WORD)retstr != 123 )
      break;
    ++v17;
LABEL_44:
    v18 = ++v9 < (unsigned int)v5;
    if ( v9 >= v5 )
      goto LABEL_45;
  }
  if ( (_WORD)retstr != 125 )
    goto LABEL_44;
  if ( --v17 )
    goto LABEL_44;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  v21 = *json;
  v10 = JsonSerializer__ignoreCloseChar(&v21, v9, 0i64);
  v4->fields.startIndex = 1;
LABEL_12:
  v4->fields.nextStartIndex = v10;
  v4->fields.endIndex = v9 - 1;
  return v4;
}
