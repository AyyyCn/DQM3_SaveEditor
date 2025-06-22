Il2CppObject *__stdcall JsonSerializer__analyzeCollection(System_ReadOnlySpan_char__o *json, System_Type_o *type, const MethodInfo *method)
{
  Il2CppObject *v3; // rdi
  System_String_o *v5; // rbx
  unsigned int v6; // ecx
  __int128 v7; // xmm0
  __int64 v8; // rcx
  _WORD *i; // rax
  System_Collections_Generic_Dictionary_TKey__TValue__o *v11; // rcx
  System_Type_o *v12; // rax
  System_Type_o *v13; // rbx
  __int64 v14; // r14
  Il2CppObject *v15; // rdi
  System_Reflection_MethodInfo_o *v16; // r12
  __int64 v17; // rsi
  int j; // ebx
  __int64 v19; // rcx
  unsigned __int64 v20; // rax
  __int64 v21; // rdx
  __int64 v22; // r8
  unsigned __int64 v23; // rdi
  intptr_t v24; // r13
  __int64 v25; // rcx
  System_Type_o *v26; // rdi
  Il2CppObject *v27; // rax
  __int64 v28; // rdx
  __int64 v29; // rcx
  __int64 v30; // r8
  Il2CppObject *v31; // rdi
  __int64 v32; // rdx
  __int64 v33; // rcx
  __int64 v34; // r8
  __int64 v35; // rax
  signed __int32 v36[20]; // [rsp+0h] [rbp-158h] BYREF
  __int64 v37; // [rsp+50h] [rbp-108h]
  System_Reflection_MethodInfo_o *v38; // [rsp+58h] [rbp-100h]
  __int64 v39; // [rsp+60h] [rbp-F8h]
  __int128 v40; // [rsp+70h] [rbp-E8h]
  __int128 v41; // [rsp+80h] [rbp-D8h]
  System_ReadOnlySpan_char__o v42; // [rsp+90h] [rbp-C8h]
  JsonSerializer_SeparateArray_o v43; // [rsp+A0h] [rbp-B8h]
  System_ReadOnlySpan_char__o v44; // [rsp+C0h] [rbp-98h]
  System_ReadOnlySpan_char__o v45; // [rsp+E0h] [rbp-78h] BYREF
  System_ReadOnlySpan_char__o v46[2]; // [rsp+F0h] [rbp-68h] BYREF
  JsonSerializer_SeparateArray_o v47; // [rsp+110h] [rbp-48h] BYREF
  Il2CppObject *v48; // [rsp+178h] [rbp+20h]

  v3 = (Il2CppObject *)type;
  if ( !byte_18579D5F8 )
  {
    sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Type__get_Item__);
    _InterlockedOr(v36, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v36, 0);
    sub_180499EE0(&object___TypeInfo);
    _InterlockedOr(v36, 0);
    sub_180499EE0(&StringLiteral_14297);
    _InterlockedOr(v36, 0);
    byte_18579D5F8 = 1;
  }
  v36[18] = 0;
  v5 = StringLiteral_14297;
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v36, 0);
    byte_18579AC1D = 1;
  }
  if ( v5 )
  {
    v6 = v5->fields._stringLength;
    *(_QWORD *)&v40 = &v5->fields._firstChar;
    *((_QWORD *)&v40 + 1) = v6;
    v7 = v40;
  }
  else
  {
    v7 = 0i64;
    v46[1] = 0i64;
  }
  v41 = v7;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, type);
  v44 = *json;
  if ( !byte_18579D603 )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v36, 0);
    byte_18579D603 = 1;
  }
  if ( v44.fields._length == DWORD2(v41) )
  {
    v8 = 0i64;
    if ( v44.fields._length <= 0 )
      return 0i64;
    type = 0i64;
    for ( i = (_WORD *)v41; ; ++i )
    {
      if ( (unsigned int)v8 >= v44.fields._length
        || (method = (const MethodInfo *)*(unsigned __int16 *)((char *)i + v44.fields._pointer.fields._value - v41),
            (unsigned int)v8 >= DWORD2(v41)) )
      {
        sub_1804BDCB0(v8, type, method);
      }
      if ( (_WORD)method != *i )
        break;
      v8 = (unsigned int)(v8 + 1);
      type = (System_Type_o *)((char *)type + 1);
      if ( (__int64)type >= v44.fields._length )
        return 0i64;
    }
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, type);
  v11 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)JsonSerializer_TypeInfo->static_fields->_collectionInterfaceCache;
  if ( !v11
    || (v12 = (System_Type_o *)System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___get_Item(
                                 v11,
                                 v3,
                                 Method_System_Collections_Generic_Dictionary_Type__Type__get_Item__),
        (v13 = v12) == 0i64) )
  {
LABEL_45:
    sub_1804BDCA0(v11, type, method);
  }
  v14 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))v12->klass->vtable._50_GetGenericArguments.methodPtr)(
          v12,
          v12->klass->vtable._50_GetGenericArguments.method);
  v37 = v14;
  v15 = System_Activator__CreateInstance_6496658320((System_Type_o *)v3, 0, 1, 0i64);
  v48 = v15;
  v16 = JsonSerializer__getAndCacheAddMethod(v13, 0i64);
  v38 = v16;
  v45 = *json;
  v43 = *JsonSerializer__separateArrayValue(&v47, &v45, 0i64);
  v17 = il2cpp_array_new_specific_0(object___TypeInfo, 1i64);
  v39 = v17;
  for ( j = 0; ; ++j )
  {
    if ( !byte_18579ED1F )
    {
      sub_180499EE0(&System_Collections_Generic_IReadOnlyCollection_JsonSerializer_InsideIndex__TypeInfo);
      _InterlockedOr(v36, 0);
      byte_18579ED1F = 1;
    }
    method = (const MethodInfo *)v43.fields._elementIndexs;
    if ( !v43.fields._elementIndexs )
      goto LABEL_45;
    if ( j >= (int)sub_18000BE70(
                     0i64,
                     System_Collections_Generic_IReadOnlyCollection_JsonSerializer_InsideIndex__TypeInfo) )
      break;
    if ( !byte_18579ED20 )
    {
      sub_180499EE0(&System_Collections_Generic_IReadOnlyList_JsonSerializer_InsideIndex__TypeInfo);
      _InterlockedOr(v36, 0);
      sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice___6531935520);
      _InterlockedOr(v36, 0);
      byte_18579ED20 = 1;
    }
    v20 = sub_1800402F0(
            v19,
            System_Collections_Generic_IReadOnlyList_JsonSerializer_InsideIndex__TypeInfo,
            v43.fields._elementIndexs,
            (unsigned int)j);
    v23 = HIDWORD(v20);
    if ( (unsigned int)v20 > v43.fields._srcJson.fields._length
      || HIDWORD(v20) > (unsigned int)(v43.fields._srcJson.fields._length - v20) )
    {
      System_ThrowHelper__ThrowArgumentOutOfRangeException(0i64);
    }
    v24 = v43.fields._srcJson.fields._pointer.fields._value + 2i64 * (int)v20;
    *(&v42.fields._length + 1) = 0;
    v25 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice___6531935520 + 32);
    if ( (*(_BYTE *)(v25 + 309) & 1) == 0 )
      sub_1804E30B0(v25);
    v42.fields._pointer.fields._value = v24;
    v42.fields._length = v23;
    if ( !v14 )
      sub_1804BDCA0(v25, v21, v22);
    if ( !*(_DWORD *)(v14 + 24) )
      sub_1804BDCB0(v25, v21, v22);
    v26 = *(System_Type_o **)(v14 + 32);
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v21);
    v46[0] = v42;
    v27 = JsonSerializer__analyze(v46, v26, 0i64);
    v31 = v27;
    if ( !v17 )
      sub_1804BDCA0(v29, v28, v30);
    if ( v27 && !sub_180481AF0(v27, *(_QWORD *)(*(_QWORD *)v17 + 64i64)) )
    {
      v35 = sub_1804BDEC0();
      sub_1804BDC60(v35, 0i64);
    }
    sub_180006A40(v17, 0i64, v31);
    if ( !v16 )
      sub_1804BDCA0(v33, v32, v34);
    v15 = v48;
    ((void (__fastcall *)(System_Reflection_MethodInfo_o *, Il2CppObject *, _QWORD, _QWORD, __int64, _QWORD, const MethodInfo *))v16->klass->vtable._31_unknown.methodPtr)(
      v16,
      v48,
      0i64,
      0i64,
      v17,
      0i64,
      v16->klass->vtable._31_unknown.method);
  }
  return v15;
}
