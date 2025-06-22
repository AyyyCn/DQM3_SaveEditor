void __stdcall JsonSerializer__serializeSpecialization_6448145152(JsonSerializer_o *this, AntiCheat_UInt_o *src, const MethodInfo *method)
{
  __int64 v5; // rbx
  __int64 v6; // rax
  __int64 v7; // r8
  Il2CppObject *v8; // rax
  signed __int32 v9[8]; // [rsp+0h] [rbp-38h] BYREF
  int v10; // [rsp+48h] [rbp+10h] BYREF

  if ( !byte_18579D620 )
  {
    sub_180499EE0(&Method_JsonSerializer_serializeSpecializationImpl_uint___);
    _InterlockedOr(v9, 0);
    byte_18579D620 = 1;
  }
  v5 = Method_JsonSerializer_serializeSpecializationImpl_uint___;
  if ( !*(_QWORD *)(Method_JsonSerializer_serializeSpecializationImpl_uint___ + 56) )
  {
    sub_180499EE0(&StringLiteral_17451);
    _InterlockedOr(v9, 0);
    if ( !*(_QWORD *)(v5 + 56) )
      sub_1804E3130(v5);
  }
  if ( !src )
    sub_1804BDCA0(this, src, method);
  v6 = **(_QWORD **)(v5 + 56);
  if ( (*(_BYTE *)(v6 + 309) & 1) == 0 )
    v6 = sub_1804E30B0(**(_QWORD **)(v5 + 56));
  v10 = sub_18000BE70(0i64, v6);
  v8 = (Il2CppObject *)il2cpp_value_box_0(*(_QWORD *)(*(_QWORD *)(v5 + 56) + 16i64), &v10, v7);
  JsonSerializer__serialize(this, StringLiteral_17451, v8, 0, 0i64);
}
