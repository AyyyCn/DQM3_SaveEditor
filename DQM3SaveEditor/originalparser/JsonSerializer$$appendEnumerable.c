void __stdcall JsonSerializer__appendEnumerable(JsonSerializer_o *this, System_Collections_IEnumerable_o *enumerable, System_Type_o *type, const MethodInfo *method)
{
  __int64 v6; // rdx
  __int64 v7; // rcx
  __int64 v8; // r8
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int64 v11; // rdx
  __int64 v12; // rcx
  __int64 v13; // r8
  __int64 v14; // rbx
  __int64 v15; // r10
  unsigned __int16 v16; // cx
  unsigned __int16 v17; // dx
  __int64 v18; // r8
  __int64 v19; // rdx
  Il2CppObject *v20; // rax
  __int64 v21; // rax
  __int64 v22; // rdx
  signed __int32 v23[8]; // [rsp+0h] [rbp-98h] BYREF
  __int64 v24; // [rsp+30h] [rbp-68h] BYREF
  int v25; // [rsp+58h] [rbp-40h]
  __int64 v26; // [rsp+60h] [rbp-38h]
  __int64 *v27; // [rsp+68h] [rbp-30h]
  __int64 *v28; // [rsp+70h] [rbp-28h]
  __int64 *v29; // [rsp+A8h] [rbp+10h] BYREF

  if ( !byte_18579D617 )
  {
    sub_180499EE0(&System_IDisposable_TypeInfo);
    _InterlockedOr(v23, 0);
    sub_180499EE0(&System_Collections_IEnumerable_TypeInfo);
    _InterlockedOr(v23, 0);
    sub_180499EE0(&System_Collections_IEnumerator_TypeInfo);
    _InterlockedOr(v23, 0);
    byte_18579D617 = 1;
  }
  v29 = 0i64;
  v24 = 0i64;
  v25 = 0;
  JsonSerializer__openBrace(this, 0i64);
  if ( !enumerable )
    sub_1804BDCA0(v7, v6, v8);
  v29 = (__int64 *)sub_18000BE70(0i64, System_Collections_IEnumerable_TypeInfo);
  v26 = 0i64;
  v27 = (__int64 *)&v29;
  v28 = &v24;
  while ( 1 )
  {
    if ( !v29 )
      sub_1804BDCA0(v10, v9, 0i64);
    if ( !(unsigned __int8)sub_18000BE70(0i64, System_Collections_IEnumerator_TypeInfo) )
      break;
    v14 = (__int64)v29;
    if ( !v29 )
      sub_1804BDCA0(v12, v11, v13);
    v15 = *v29;
    v16 = 0;
    v17 = *(_WORD *)(*v29 + 302);
    if ( v17 )
    {
      v18 = *(_QWORD *)(v15 + 176);
      while ( *(System_Collections_IEnumerator_c **)(v18 + 16i64 * v16) != System_Collections_IEnumerator_TypeInfo )
      {
        if ( ++v16 >= v17 )
          goto LABEL_12;
      }
      v19 = 16i64 * (*(_DWORD *)(v18 + 16i64 * v16 + 8) + 1) + v15 + 312;
    }
    else
    {
LABEL_12:
      v19 = sub_1804E3680(v29, System_Collections_IEnumerator_TypeInfo, 1i64);
    }
    v20 = (Il2CppObject *)(*(__int64 (__fastcall **)(__int64, _QWORD))v19)(v14, *(_QWORD *)(v19 + 8));
    JsonSerializer__serialize(this, 0i64, v20, 0, 0i64);
  }
  v21 = sub_180481AF0(v29, System_IDisposable_TypeInfo);
  v24 = v21;
  if ( v21 )
    sub_180006940(0i64, System_IDisposable_TypeInfo, v21);
  if ( !byte_18579D60F )
  {
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v23, 0);
    byte_18579D60F = 1;
  }
  --this->fields._indentCnt;
  JsonSerializer__appendIndent(this, 0i64);
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v22);
  sub_180570A70(&this->fields, 125i64);
}
