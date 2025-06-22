void __stdcall JsonSerializer__serializeSpecializationImpl_uint_(JsonSerializer_o *this, AntiCheat_Interface_T__o *src, const MethodInfo_199D980 *method)
{
  Il2CppClass *v6; // rax
  __int64 v7; // r8
  Il2CppObject *v8; // rax
  signed __int32 v9[8]; // [rsp+0h] [rbp-38h] BYREF
  int v10; // [rsp+48h] [rbp+10h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&StringLiteral_17451);
    _InterlockedOr(v9, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  if ( !src )
    sub_1804BDCA0(this, src, method);
  v6 = method->rgctx_data->_0_AntiCheat_Interface_T_;
  if ( (*(&v6->_2.bitflags2 + 2) & 1) == 0 )
    v6 = (Il2CppClass *)sub_1804E30B0(method->rgctx_data->_0_AntiCheat_Interface_T_);
  v10 = sub_18000BE70(0i64, v6);
  v8 = (Il2CppObject *)il2cpp_value_box_0(method->rgctx_data->_2_T, &v10, v7);
  JsonSerializer__serialize(this, StringLiteral_17451, v8, 0, 0i64);
}
