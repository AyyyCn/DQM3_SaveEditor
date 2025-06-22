void __stdcall JsonSerializer__appendClassCurrentOnly(JsonSerializer_o *this, Il2CppObject *src, System_Type_o *type, const MethodInfo *method)
{
  __int64 v7; // rcx
  System_Reflection_FieldInfo_array *v8; // rbp
  __int64 v9; // r8
  signed int v10; // ebx
  __int64 v11; // rdx
  System_Reflection_FieldInfo_o *v12; // rsi
  __int64 v13; // rdx
  System_Type_o *v14; // rdi
  System_String_o *v15; // rdi
  Il2CppObject *v16; // rax
  signed __int32 v17[8]; // [rsp+0h] [rbp-58h] BYREF

  if ( !byte_18579D619 )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v17, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v17, 0);
    byte_18579D619 = 1;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, src);
  v8 = JsonSerializer__getAndCacheFieldInfoArray(type, 0i64);
  v10 = 0;
  v11 = 0i64;
  if ( !v8 )
LABEL_16:
    sub_1804BDCA0(v7, v11, v9);
  while ( 1 )
  {
    v7 = LODWORD(v8->max_length);
    if ( (int)v11 >= (int)v7 )
      break;
    if ( v10 >= (unsigned int)v7 )
      sub_1804BDCB0(v7, v11, v9);
    v12 = v8->m_Items[v10];
    if ( !v12 )
      goto LABEL_16;
    v14 = (System_Type_o *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v12->klass->vtable._9_unknown.methodPtr)(
                             v8->m_Items[v10],
                             v12->klass->vtable._9_unknown.method);
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, v13);
    if ( v14 == type )
    {
      v15 = (System_String_o *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, const MethodInfo *))v12->klass->vtable._8_unknown.methodPtr)(
                                 v12,
                                 v12->klass->vtable._8_unknown.method);
      v16 = (Il2CppObject *)((__int64 (__fastcall *)(System_Reflection_FieldInfo_o *, Il2CppObject *, const MethodInfo *))v12->klass->vtable._25_unknown.methodPtr)(
                              v12,
                              src,
                              v12->klass->vtable._25_unknown.method);
      JsonSerializer__serialize(this, v15, v16, 0, 0i64);
    }
    v11 = (unsigned int)++v10;
  }
}
