bool __stdcall JsonSerializer__deserialize___Il2CppFullySharedGenericType_(System_String_o *json, System_String_o *root_name, Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *dst, const MethodInfo_199C590 *method)
{
  __int64 v8; // rdx
  __int64 v9; // rdx
  __int64 v10; // rcx
  __int128 v11; // xmm0
  Il2CppMethodPointer v12; // rax
  signed __int32 v14[12]; // [rsp+0h] [rbp-88h] BYREF
  __int64 v15[2]; // [rsp+30h] [rbp-58h] BYREF
  __int128 v16; // [rsp+40h] [rbp-48h] BYREF
  int32_t count[4]; // [rsp+50h] [rbp-38h]
  int v18; // [rsp+68h] [rbp-20h]
  Cysharp_Text_Utf16ValueStringBuilder_o v19; // [rsp+70h] [rbp-18h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&Method_System_ArraySegment_char__get_Array__);
    _InterlockedOr(v14, 0);
    sub_180499EE0(&System_ArraySegment_char__TypeInfo);
    _InterlockedOr(v14, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v14, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__op_Implicit__);
    _InterlockedOr(v14, 0);
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v14, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v18 = 0;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, root_name);
  *(Cysharp_Text_Utf16ValueStringBuilder_o *)count = *JsonSerializer__removeSpaceAndNewLineCode(&v19, json, 0i64);
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v8);
  if ( !byte_1857BA378 )
  {
    sub_180499EE0(&Method_System_ArraySegment_char___ctor__);
    _InterlockedOr(v14, 0);
    byte_1857BA378 = 1;
  }
  v15[1] = 0i64;
  if ( !*(_QWORD *)count || count[2] > *(_DWORD *)(*(_QWORD *)count + 24i64) )
    System_ThrowHelper__ThrowArraySegmentCtorValidationFailedExceptions(*(System_Array_o **)count, 0, count[2], 0i64);
  v15[0] = *(_QWORD *)count;
  sub_1804283A0(v15);
  if ( !System_ArraySegment_char__TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_ArraySegment_char__TypeInfo, v9);
  *((_QWORD *)&v16 + 1) = 0i64;
  v10 = *(_QWORD *)(Method_System_ReadOnlySpan_char__op_Implicit__ + 32);
  if ( (*(_BYTE *)(v10 + 309) & 1) == 0 )
    sub_1804E30B0(v10);
  if ( v15[0] )
  {
    *(_QWORD *)&v16 = v15[0] + 32;
    DWORD2(v16) = *(_DWORD *)(v15[0] + 24);
    v11 = v16;
  }
  else
  {
    v11 = 0i64;
  }
  v12 = method->rgctx_data->_1_JsonSerializer_analyze_T_->methodPointer;
  v16 = v11;
  return ((__int64 (__fastcall *)(__int128 *, System_String_o *, Unity_IL2CPP_Metadata___Il2CppFullySharedGenericType_o *))v12)(
           &v16,
           root_name,
           dst);
}
