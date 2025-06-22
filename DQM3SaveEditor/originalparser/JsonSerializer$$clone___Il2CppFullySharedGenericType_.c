Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *JsonSerializer__clone___Il2CppFullySharedGenericType_(Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *retstr, System_String_o *root_name, Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *obj, const MethodInfo_199C1E0 *method)
{
  unsigned __int64 v6; // rbx
  __int64 v7; // rax
  void *v8; // rsp
  __int64 v9; // rax
  void *v10; // rsp
  __int64 v11; // rax
  void *v12; // rsp
  JsonSerializer_o *v13; // r12
  System_String_o **v14; // rdx
  __int64 v15; // r8
  Il2CppObject *v16; // rax
  __int64 v17; // rdx
  __int64 v18; // rcx
  __int64 v19; // r8
  JsonSerializer_o *v20; // rax
  System_String_o *v21; // r12
  __int64 v22; // rdx
  signed __int32 v24[8]; // [rsp+0h] [rbp-30h] BYREF
  char v25[48]; // [rsp+30h] [rbp+0h] BYREF
  System_String_o *v26; // [rsp+78h] [rbp+48h] BYREF
  Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *v27; // [rsp+80h] [rbp+50h]

  v27 = obj;
  v26 = root_name;
  if ( !method->rgctx_data )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v24, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v6 = method->rgctx_data->_0_T->_2.actualSize;
  v7 = v6 + 15;
  if ( v6 + 15 <= v6 )
    v7 = 0xFFFFFFFFFFFFFF0i64;
  v8 = alloca(v7 & 0xFFFFFFFFFFFFFFF0ui64);
  v9 = v6 + 15;
  if ( v6 + 15 <= v6 )
    v9 = 0xFFFFFFFFFFFFFF0i64;
  v10 = alloca(v9 & 0xFFFFFFFFFFFFFFF0ui64);
  v11 = v6 + 15;
  if ( v6 + 15 <= v6 )
    v11 = 0xFFFFFFFFFFFFFF0i64;
  v12 = alloca(v11 & 0xFFFFFFFFFFFFFFF0ui64);
  sub_1804EF650(v25, 0i64, method->rgctx_data->_0_T->_2.actualSize);
  v13 = (JsonSerializer_o *)sub_180481BA0(JsonSerializer_TypeInfo);
  JsonSerializer___ctor(v13, 1, 0i64);
  v14 = &v26;
  if ( (method->rgctx_data->_0_T->_1.byval_arg.bits & 0x80000000) != 0 )
    v14 = (System_String_o **)v26;
  sub_1804EEFA0(v25, v14, v6);
  v16 = (Il2CppObject *)il2cpp_value_box_0(method->rgctx_data->_0_T, v25, v15);
  if ( !v13 || (v20 = JsonSerializer__serialize(v13, (System_String_o *)retstr, v16, 0, 0i64)) == 0i64 )
    sub_1804BDCA0(v18, v17, v19);
  v21 = JsonSerializer__str(v20, 0, 0i64);
  sub_1804EF650(v25, 0i64, v6);
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v22);
  ((void (__fastcall *)(System_String_o *, Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *, char *, MethodInfo *))method->rgctx_data->_1_JsonSerializer_deserialize_T_->methodPointer)(
    v21,
    retstr,
    v25,
    method->rgctx_data->_1_JsonSerializer_deserialize_T_);
  sub_1804EEFA0(v25, v25, v6);
  return (Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *)sub_1804EEFA0(v27, v25, v6);
}
