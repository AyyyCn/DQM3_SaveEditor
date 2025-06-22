void __stdcall JsonSerializer__serializeSpecializationEnum_Int32Enum_(JsonSerializer_o *this, AntiCheat_T__o *src, const MethodInfo_199D7A0 *method)
{
  MethodInfo *v6; // rbx
  __int64 v7; // rax
  __int64 v8; // r8
  Il2CppObject *v9; // rax
  signed __int32 v10[8]; // [rsp+0h] [rbp-38h] BYREF
  int v11; // [rsp+48h] [rbp+10h] BYREF

  if ( !method->rgctx_data )
    sub_1804E3130(method);
  v6 = method->rgctx_data->_1_JsonSerializer_serializeSpecializationImpl_T_;
  if ( !v6->rgctx_data )
  {
    sub_180499EE0(&StringLiteral_17451);
    _InterlockedOr(v10, 0);
    if ( !v6->rgctx_data )
      sub_1804E3130(v6);
  }
  if ( !src )
    sub_1804BDCA0(this, src, method);
  v7 = (__int64)v6->rgctx_data->rgctxDataDummy;
  if ( (*(_BYTE *)(v7 + 309) & 1) == 0 )
    v7 = sub_1804E30B0(v6->rgctx_data->rgctxDataDummy);
  v11 = sub_18000BE70(0i64, v7);
  v9 = (Il2CppObject *)((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD))il2cpp_value_box_0)(
                         (const Il2CppRGCTXData)v6->rgctx_data[2].rgctxDataDummy,
                         &v11,
                         v8);
  JsonSerializer__serialize(this, StringLiteral_17451, v9, 0, 0i64);
}
