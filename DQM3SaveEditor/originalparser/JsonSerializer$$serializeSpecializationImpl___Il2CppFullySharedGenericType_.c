void __stdcall JsonSerializer__serializeSpecializationImpl___Il2CppFullySharedGenericType_(JsonSerializer_o *this, AntiCheat_Interface_T__o *src, const MethodInfo_199DB00 *method)
{
  const MethodInfo_199DB00_RGCTXs *v6; // rdx
  unsigned __int64 v7; // rcx
  __int64 v8; // rax
  void *v9; // rsp
  __int64 v10; // rax
  __int64 v11; // r8
  Il2CppObject *v12; // rax
  signed __int32 v13[8]; // [rsp+0h] [rbp-30h] BYREF
  char vars0; // [rsp+30h] [rbp+0h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&StringLiteral_17451);
    _InterlockedOr(v13, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v6 = method->rgctx_data;
  v7 = v6->_2_T->_2.actualSize;
  v8 = v7 + 15;
  if ( v7 + 15 <= v7 )
    v8 = 0xFFFFFFFFFFFFFF0i64;
  v9 = alloca(v8 & 0xFFFFFFFFFFFFFFF0ui64);
  if ( !src )
    sub_1804BDCA0(v7, v6, method);
  v10 = (__int64)v6->_0_AntiCheat_Interface_T_;
  if ( (*(&v6->_0_AntiCheat_Interface_T_->_2.bitflags2 + 2) & 1) == 0 )
    v10 = sub_1804E30B0(v6->_0_AntiCheat_Interface_T_);
  sub_1800B1590(0i64, v10, src, &vars0);
  v12 = (Il2CppObject *)il2cpp_value_box_0(method->rgctx_data->_2_T, &vars0, v11);
  JsonSerializer__serialize(this, StringLiteral_17451, v12, 0, 0i64);
}
