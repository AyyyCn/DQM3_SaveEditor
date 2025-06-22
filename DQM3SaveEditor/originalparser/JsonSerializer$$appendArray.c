void __stdcall JsonSerializer__appendArray(JsonSerializer_o *this, System_Array_o *array, System_Type_o *type, const MethodInfo *method)
{
  System_Type_o *v4; // rbx
  System_Array_o *v5; // r14
  JsonSerializer_o *v6; // rbp
  __int64 v7; // rdx
  System_Type_o *v8; // rbx
  struct System_Type_o *v9; // rdi
  __int64 v10; // rax
  System_Type_o *v11; // rdi
  struct System_Type_o *v12; // rsi
  bool is_basic_type; // di
  struct JsonSerializer_IntArrayCache_o *v14; // rbx
  __int64 v15; // rsi
  __int64 v16; // rax
  __int64 v17; // rbx
  struct JsonSerializer_IntArrayCache_o *v18; // rdi
  struct System_Collections_Generic_List_int____array *v19; // rax
  __int64 v20; // rax
  struct System_Char_array *v21; // r9
  signed __int32 v22[8]; // [rsp+0h] [rbp-38h] BYREF

  v4 = type;
  v5 = array;
  v6 = this;
  if ( !byte_18579D615 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v22, 0);
    byte_18579D615 = 1;
  }
  if ( !v4 )
    goto LABEL_53;
  v8 = (System_Type_o *)((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *, System_Type_o *, const MethodInfo *))v4->klass->vtable._46_unknown.methodPtr)(
                          v4,
                          v4->klass->vtable._46_unknown.method,
                          type,
                          method);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v7);
  if ( JsonSerializer__isBasicType_6448137248(v8, 0i64) )
    goto LABEL_27;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, array);
  if ( !byte_18579D612 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v22, 0);
    byte_18579D612 = 1;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, array);
  v9 = JsonSerializer_TypeInfo->static_fields->_nullableBaseType;
  this = (JsonSerializer_o *)System_Type_TypeInfo;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, array);
  if ( v9 != v8 )
    goto LABEL_58;
  if ( !v8 )
    goto LABEL_53;
  v10 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))v8->klass->vtable._50_GetGenericArguments.methodPtr)(
          v8,
          v8->klass->vtable._50_GetGenericArguments.method);
  if ( !v10 )
    goto LABEL_53;
  if ( !*(_DWORD *)(v10 + 24) )
    goto LABEL_55;
  v11 = *(System_Type_o **)(v10 + 32);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, array);
  if ( JsonSerializer__isBasicType_6448137248(v11, 0i64) )
  {
LABEL_27:
    is_basic_type = 1;
  }
  else
  {
LABEL_58:
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, array);
    v12 = JsonSerializer_TypeInfo->static_fields->_stringType;
    this = (JsonSerializer_o *)System_Type_TypeInfo;
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, array);
    is_basic_type = v8 == v12;
  }
  v14 = v6->fields._intArrayCache;
  if ( !v5 )
    goto LABEL_53;
  v15 = v5->klass->_2.bitflags1;
  if ( !v14 )
    goto LABEL_53;
  if ( !byte_18579ED21 )
  {
    sub_180499EE0(&int___TypeInfo);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&Method_System_Collections_Generic_List_int____RemoveAt__);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&Method_System_Collections_Generic_List_int____get_Count__);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&Method_System_Collections_Generic_List_int____get_Item__);
    _InterlockedOr(v22, 0);
    byte_18579ED21 = 1;
  }
  this = (JsonSerializer_o *)v14->fields._free;
  if ( !this )
    goto LABEL_53;
  if ( (unsigned int)(v15 - 1) >= this->fields._str.fields.index )
    goto LABEL_55;
  this = (JsonSerializer_o *)*((_QWORD *)&this->fields._str.fields.index + v15);
  if ( !this )
    goto LABEL_53;
  v16 = this->fields._str.fields.index;
  if ( !(_DWORD)v16 )
  {
    v17 = il2cpp_array_new_specific_0(int___TypeInfo, v15);
    goto LABEL_42;
  }
  array = (System_Array_o *)(unsigned int)(v16 - 1);
  if ( (unsigned int)array >= (unsigned int)v16 )
    System_ThrowHelper__ThrowArgumentOutOfRange_IndexException(0i64);
  type = (System_Type_o *)this->fields._str.fields.buffer;
  if ( !type )
LABEL_53:
    sub_1804BDCA0(this, array, type);
  if ( (unsigned int)(v16 - 1) >= LODWORD(type[1].klass) )
    goto LABEL_55;
  v17 = *((_QWORD *)&type[1].klass + v16);
  System_Collections_Generic_List_object___RemoveAt(
    (System_Collections_Generic_List_object__o *)this,
    (int32_t)array,
    Method_System_Collections_Generic_List_int____RemoveAt__);
  if ( !v17 )
    goto LABEL_53;
  System_Array__Clear((System_Array_o *)v17, 0, *(_DWORD *)(v17 + 24), 0i64);
LABEL_42:
  JsonSerializer__appendArray_6448140000(v6, v5, 0, (System_Int32_array *)v17, is_basic_type, 0i64);
  v18 = v6->fields._intArrayCache;
  if ( !v18 )
    goto LABEL_53;
  if ( !byte_18579ED22 )
  {
    sub_180499EE0(&Method_System_Collections_Generic_List_int____Add__);
    _InterlockedOr(v22, 0);
    byte_18579ED22 = 1;
  }
  v19 = v18->fields._free;
  if ( !v17 || !v19 )
    goto LABEL_53;
  this = (JsonSerializer_o *)(*(int *)(v17 + 24) - 1i64);
  if ( (unsigned int)this >= LODWORD(v19->max_length) )
LABEL_55:
    sub_1804BDCB0(this, array, type);
  this = (JsonSerializer_o *)v19->m_Items[(_QWORD)this];
  if ( !this )
    goto LABEL_53;
  v20 = Method_System_Collections_Generic_List_int____Add__;
  ++*(_DWORD *)&this->fields._str.fields.disposeImmediately;
  v21 = this->fields._str.fields.buffer;
  array = (System_Array_o *)this->fields._str.fields.index;
  if ( !v21 )
    goto LABEL_53;
  if ( (unsigned int)array < LODWORD(v21->max_length) )
  {
    this->fields._str.fields.index = (_DWORD)array + 1;
    sub_180006A40(v21, array, v17);
  }
  else
  {
    System_Collections_Generic_List_object___AddWithResize(
      (System_Collections_Generic_List_object__o *)this,
      (Il2CppObject *)v17,
      *(const MethodInfo_1D4B770 **)(*(_QWORD *)(*(_QWORD *)(v20 + 32) + 192i64) + 112i64));
  }
}
