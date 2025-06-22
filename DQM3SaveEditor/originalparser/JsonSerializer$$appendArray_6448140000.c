void __stdcall JsonSerializer__appendArray_6448140000(JsonSerializer_o *this, System_Array_o *array, int32_t dimension, System_Int32_array *indexs, bool is_basic_type, const MethodInfo *method)
{
  __int64 v7; // rbp
  JsonSerializer_Fields *v10; // r13
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  System_Array_Fields v14; // r12
  System_Array_c *v15; // r12
  int32_t v16; // ebx
  Il2CppObject *v17; // rax
  __int64 v18; // rdx
  __int64 v19; // rdx
  __int64 v20; // rax
  signed __int32 v21[8]; // [rsp+0h] [rbp-58h] BYREF

  v7 = dimension;
  if ( !byte_18579D616 )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v21, 0);
    byte_18579D616 = 1;
  }
  if ( (int)v7 > 0 && !is_basic_type )
  {
    JsonSerializer__appendIndent(this, 0i64);
    v10 = &this->fields;
    goto LABEL_7;
  }
  v10 = &this->fields;
  if ( !is_basic_type )
  {
LABEL_7:
    if ( this->fields._enableOptimize )
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, array);
      sub_180570A70(v10, 123i64);
      ++this->fields._indentCnt;
    }
    else
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, array);
      sub_180570B10(v10, 123i64, 10i64);
      ++this->fields._indentCnt;
    }
    goto LABEL_17;
  }
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, array);
  sub_180570A70(&this->fields, 123i64);
LABEL_17:
  if ( !array )
    goto LABEL_43;
  if ( (int)v7 < 0 || (v12 = array->klass->_2.bitflags1, (int)v7 >= (int)v12) )
  {
    v20 = sub_18048F830();
    sub_18048E750(v20, 0i64);
  }
  v14 = array->fields;
  if ( v14 )
    v15 = *(System_Array_c **)(*(_QWORD *)&v14 + 16 * v7);
  else
    v15 = array[1].klass;
  v16 = 0;
  if ( (int)v15 > 0 )
  {
    while ( indexs )
    {
      if ( (unsigned int)v7 >= LODWORD(indexs->max_length) )
        sub_1804BDCB0(v12, v11, v13);
      indexs->m_Items[v7] = v16;
      if ( (_DWORD)v7 + 1 == array->klass->_2.bitflags1 )
      {
        v17 = (Il2CppObject *)System_Array__GetValue_6496631984_0(array, indexs);
        JsonSerializer__serialize(this, 0i64, v17, is_basic_type, 0i64);
      }
      else
      {
        JsonSerializer__appendArray_6448140000(this, array, v7 + 1, indexs, is_basic_type, 0i64);
      }
      if ( ++v16 >= (int)v15 )
        goto LABEL_30;
    }
LABEL_43:
    sub_1804BDCA0(v12, v11, v13);
  }
LABEL_30:
  if ( !is_basic_type )
  {
    --this->fields._indentCnt;
    JsonSerializer__appendIndent(this, 0i64);
  }
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v11);
  sub_180570A70(v10, 125i64);
  if ( (_DWORD)v7 )
  {
    if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v18);
    sub_180570A70(v10, 44i64);
    if ( !is_basic_type && !this->fields._enableOptimize )
    {
      if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v19);
      sub_180570A70(v10, 10i64);
    }
  }
}
