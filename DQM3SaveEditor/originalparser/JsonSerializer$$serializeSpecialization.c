void __stdcall JsonSerializer__serializeSpecialization(JsonSerializer_o *this, UnityEngine_Vector3_o *vec, const MethodInfo *method)
{
  Il2CppObject *v5; // rax
  __int64 v6; // r8
  Il2CppObject *v7; // rax
  __int64 v8; // r8
  Il2CppObject *v9; // rax
  signed __int32 v10[8]; // [rsp+0h] [rbp-38h] BYREF
  float v11; // [rsp+48h] [rbp+10h] BYREF

  if ( !byte_18579D61A )
  {
    sub_180499EE0(&float_TypeInfo);
    _InterlockedOr(v10, 0);
    sub_180499EE0(&StringLiteral_14287);
    _InterlockedOr(v10, 0);
    sub_180499EE0(&StringLiteral_14286);
    _InterlockedOr(v10, 0);
    sub_180499EE0(&StringLiteral_14285);
    _InterlockedOr(v10, 0);
    byte_18579D61A = 1;
  }
  v11 = vec->fields.x;
  v5 = (Il2CppObject *)il2cpp_value_box_0(float_TypeInfo, &v11, method);
  JsonSerializer__serialize(this, StringLiteral_14287, v5, 0, 0i64);
  v11 = vec->fields.y;
  v7 = (Il2CppObject *)il2cpp_value_box_0(float_TypeInfo, &v11, v6);
  JsonSerializer__serialize(this, StringLiteral_14286, v7, 0, 0i64);
  v11 = vec->fields.z;
  v9 = (Il2CppObject *)il2cpp_value_box_0(float_TypeInfo, &v11, v8);
  JsonSerializer__serialize(this, StringLiteral_14285, v9, 0, 0i64);
}
