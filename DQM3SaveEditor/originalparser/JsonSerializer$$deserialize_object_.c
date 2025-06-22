bool __stdcall JsonSerializer__deserialize_object_(System_String_o *json, System_String_o *root_name, Il2CppObject **dst, const MethodInfo_199C3A0 *method)
{
  System_ReadOnlySpan_char__o v8; // xmm0
  const MethodInfo_199C3A0_RGCTXs *v9; // rax
  signed __int32 v11[12]; // [rsp+0h] [rbp-88h] BYREF
  __int64 v12[2]; // [rsp+30h] [rbp-58h] BYREF
  System_ReadOnlySpan_char__o v13; // [rsp+40h] [rbp-48h] BYREF
  int32_t count[4]; // [rsp+50h] [rbp-38h]
  int v15; // [rsp+68h] [rbp-20h]
  Cysharp_Text_Utf16ValueStringBuilder_o v16; // [rsp+70h] [rbp-18h] BYREF

  if ( !method->rgctx_data )
  {
    sub_180499EE0(&Method_System_ArraySegment_char__get_Array__);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&System_ArraySegment_char__TypeInfo);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__op_Implicit__);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v11, 0);
    if ( !method->rgctx_data )
      sub_1804E3130(method);
  }
  v15 = 0;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0();
  *(Cysharp_Text_Utf16ValueStringBuilder_o *)count = *JsonSerializer__removeSpaceAndNewLineCode(&v16, json, 0i64);
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0();
  if ( !byte_1857BA378 )
  {
    sub_180499EE0(&Method_System_ArraySegment_char___ctor__);
    _InterlockedOr(v11, 0);
    byte_1857BA378 = 1;
  }
  v12[1] = 0i64;
  if ( !*(_QWORD *)count || count[2] > *(_DWORD *)(*(_QWORD *)count + 24i64) )
    System_ThrowHelper__ThrowArraySegmentCtorValidationFailedExceptions(*(System_Array_o **)count, 0, count[2], 0i64);
  v12[0] = *(_QWORD *)count;
  sub_1804283A0(v12);
  if ( !System_ArraySegment_char__TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0();
  *(_QWORD *)&v13.fields._length = 0i64;
  if ( (*(_BYTE *)(*(_QWORD *)(Method_System_ReadOnlySpan_char__op_Implicit__ + 32) + 309i64) & 1) == 0 )
    sub_1804E30B0();
  if ( v12[0] )
  {
    v13.fields._pointer.fields._value = v12[0] + 32;
    v13.fields._length = *(_DWORD *)(v12[0] + 24);
    v8 = v13;
  }
  else
  {
    v8 = 0i64;
  }
  v9 = method->rgctx_data;
  v13 = v8;
  return JsonSerializer__analyze_object_(
           &v13,
           root_name,
           dst,
           (const MethodInfo_199B890 *)v9->_1_JsonSerializer_analyze_T_);
}
