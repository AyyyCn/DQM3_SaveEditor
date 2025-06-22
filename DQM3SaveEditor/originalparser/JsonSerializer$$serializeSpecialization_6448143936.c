void __stdcall JsonSerializer__serializeSpecialization_6448143936(JsonSerializer_o *this, UnityEngine_Vector2Int_o vec, const MethodInfo *method)
{
  int32_t v3; // ebx
  Il2CppObject *v5; // rax
  __int64 v6; // r8
  Il2CppObject *v7; // rax
  signed __int32 v8[8]; // [rsp+0h] [rbp-38h] BYREF
  UnityEngine_Vector2Int_o v9; // [rsp+48h] [rbp+10h] BYREF
  int32_t v10; // [rsp+58h] [rbp+20h] BYREF

  v9 = vec;
  v3 = vec.fields.m_X;
  if ( !byte_18579D61C )
  {
    sub_180499EE0(&int_TypeInfo);
    _InterlockedOr(v8, 0);
    sub_180499EE0(&StringLiteral_14287);
    _InterlockedOr(v8, 0);
    sub_180499EE0(&StringLiteral_14286);
    _InterlockedOr(v8, 0);
    byte_18579D61C = 1;
  }
  v10 = v3;
  v5 = (Il2CppObject *)il2cpp_value_box_0(int_TypeInfo, &v10, method);
  JsonSerializer__serialize(this, StringLiteral_14287, v5, 0, 0i64);
  v9.fields.m_X = v9.fields.m_Y;
  v7 = (Il2CppObject *)il2cpp_value_box_0(int_TypeInfo, &v9, v6);
  JsonSerializer__serialize(this, StringLiteral_14286, v7, 0, 0i64);
}
