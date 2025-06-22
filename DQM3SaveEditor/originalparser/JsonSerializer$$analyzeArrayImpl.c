void __stdcall JsonSerializer__analyzeArrayImpl(System_Array_o *array, System_Type_o *element_type, JsonSerializer_SeparateArray_o *jsons, int32_t dimension, System_Int32_array *indexs, const MethodInfo *method)
{
  __int64 v6; // rsi
  int32_t v10; // ebx
  int32_t i; // er12
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // r8
  __int64 v15; // rdx
  System_ReadOnlySpan_char__o v16; // xmm6
  signed __int32 v17; // er12
  __int64 v18; // rdx
  System_ReadOnlySpan_char__o v19; // xmm6
  Il2CppObject *v20; // rax
  signed __int32 v21[24]; // [rsp+0h] [rbp-128h] BYREF
  System_ReadOnlySpan_char__o v22; // [rsp+60h] [rbp-C8h] BYREF
  System_ReadOnlySpan_char__o v23; // [rsp+70h] [rbp-B8h] BYREF
  JsonSerializer_SeparateArray_o v24; // [rsp+80h] [rbp-A8h] BYREF
  System_ReadOnlySpan_char__o v25; // [rsp+A0h] [rbp-88h] BYREF
  System_ReadOnlySpan_char__o v26; // [rsp+B0h] [rbp-78h] BYREF
  JsonSerializer_SeparateArray_o v27; // [rsp+C0h] [rbp-68h] BYREF

  v6 = dimension;
  v21[19] = dimension;
  if ( !byte_18579D5F7 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v21, 0);
    byte_18579D5F7 = 1;
  }
  v10 = 0;
  v21[16] = 0;
  if ( !indexs )
    goto LABEL_27;
  if ( (_DWORD)v6 != LODWORD(indexs->max_length) - 1 )
  {
    for ( i = 0; ; ++i )
    {
      if ( !byte_18579ED1F )
      {
        sub_180499EE0(&System_Collections_Generic_IReadOnlyCollection_JsonSerializer_InsideIndex__TypeInfo);
        _InterlockedOr(v21, 0);
        byte_18579ED1F = 1;
      }
      if ( !jsons->fields._elementIndexs )
        break;
      if ( i >= (int)sub_18000BE70(
                       0i64,
                       System_Collections_Generic_IReadOnlyCollection_JsonSerializer_InsideIndex__TypeInfo) )
        return;
      if ( (unsigned int)v6 >= LODWORD(indexs->max_length) )
        goto LABEL_25;
      indexs->m_Items[v6] = i;
      v16 = *JsonSerializer_SeparateArray__element(&v25, jsons, i, 0i64);
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v15);
      v22 = v16;
      v24 = *JsonSerializer__separateArrayValue(&v27, &v22, 0i64);
      JsonSerializer__analyzeArrayImpl(array, element_type, &v24, v6 + 1, indexs, 0i64);
    }
LABEL_27:
    sub_1804BDCA0();
  }
  if ( !byte_18579ED1F )
  {
    sub_180499EE0(&System_Collections_Generic_IReadOnlyCollection_JsonSerializer_InsideIndex__TypeInfo);
    _InterlockedOr(v21, 0);
    byte_18579ED1F = 1;
  }
  if ( !jsons->fields._elementIndexs )
    goto LABEL_27;
  v17 = sub_18000BE70(0i64, System_Collections_Generic_IReadOnlyCollection_JsonSerializer_InsideIndex__TypeInfo);
  v21[18] = v17;
  while ( 1 )
  {
    v21[12] = v10;
    if ( v10 >= v17 )
      break;
    v13 = (int)v6;
    if ( (unsigned int)dimension >= LODWORD(indexs->max_length) )
LABEL_25:
      sub_1804BDCB0(v13, v12, v14);
    indexs->m_Items[(int)v6] = v10;
    v19 = *JsonSerializer_SeparateArray__element(&v26, jsons, v10, 0i64);
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v18);
    v23 = v19;
    v20 = JsonSerializer__analyze(&v23, element_type, 0i64);
    if ( !array )
      sub_1804BDCA0();
    System_Array__SetValue_6496632000(array, v20, indexs, 0i64);
    ++v10;
  }
}
