Il2CppObject *__stdcall JsonSerializer__analyzeArray(System_Array_o *array, System_ReadOnlySpan_char__o *json, System_Type_o *type, const MethodInfo *method)
{
  System_Type_o *v4; // rsi
  System_ReadOnlySpan_char__o *v5; // r14
  System_String_o *v7; // rdi
  unsigned int v8; // ecx
  __int128 v9; // xmm0
  __int64 v10; // rcx
  __int64 v11; // rdx
  _WORD *i; // rax
  System_Type_o *v14; // r13
  unsigned int v15; // eax
  __int64 v16; // rdx
  unsigned int v17; // edi
  __int64 v18; // rsi
  __m128i v19; // xmm7
  unsigned int v20; // er15
  int v21; // eax
  __int128 v22; // xmm6
  __int128 *v23; // rax
  int v24; // edi
  int v25; // ebx
  __int64 v26; // r14
  int v27; // ebx
  JsonSerializer_SeparateArray_o *v28; // rax
  struct System_ReadOnlySpan_char__o v29; // xmm6
  struct System_Collections_Generic_IReadOnlyList_JsonSerializer_InsideIndex__o *v30; // xmm7_8
  System_Int32_array *v31; // rax
  signed __int32 v32[8]; // [rsp+0h] [rbp-1D8h] BYREF
  unsigned int v33; // [rsp+30h] [rbp-1A8h]
  __int128 v34; // [rsp+40h] [rbp-198h]
  __int128 v35; // [rsp+50h] [rbp-188h]
  __m128i v36; // [rsp+60h] [rbp-178h]
  System_ReadOnlySpan_char__o v37; // [rsp+70h] [rbp-168h]
  __m128i v38; // [rsp+80h] [rbp-158h]
  int v39; // [rsp+98h] [rbp-140h]
  __int128 v40; // [rsp+A0h] [rbp-138h]
  __int128 v41; // [rsp+B0h] [rbp-128h]
  __int128 v42; // [rsp+C0h] [rbp-118h]
  __m128i v43; // [rsp+E0h] [rbp-F8h] BYREF
  __int128 v44; // [rsp+F0h] [rbp-E8h]
  __int128 v45; // [rsp+100h] [rbp-D8h] BYREF
  JsonSerializer_SeparateArray_o v46; // [rsp+110h] [rbp-C8h] BYREF
  __int128 v47; // [rsp+130h] [rbp-A8h]
  JsonSerializer_SeparateArray_o v48; // [rsp+140h] [rbp-98h] BYREF
  JsonSerializer_InsideBraces_o v49; // [rsp+158h] [rbp-80h] BYREF
  System_ReadOnlySpan_char__o *v50; // [rsp+1E8h] [rbp+10h]

  v50 = json;
  v4 = type;
  v5 = json;
  if ( !byte_18579D5F6 )
  {
    sub_180499EE0(&int___TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v32, 0);
    sub_180499EE0(&StringLiteral_14297);
    _InterlockedOr(v32, 0);
    byte_18579D5F6 = 1;
  }
  v39 = 0;
  v7 = StringLiteral_14297;
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v32, 0);
    byte_18579AC1D = 1;
  }
  if ( v7 )
  {
    v8 = v7->fields._stringLength;
    *(_QWORD *)&v34 = &v7->fields._firstChar;
    *((_QWORD *)&v34 + 1) = v8;
    v9 = v34;
  }
  else
  {
    v9 = 0i64;
    v47 = 0i64;
  }
  v35 = v9;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  v37 = *v5;
  if ( !byte_18579D603 )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v32, 0);
    byte_18579D603 = 1;
  }
  if ( v37.fields._length == DWORD2(v35) )
  {
    v10 = 0i64;
    if ( v37.fields._length <= 0 )
      return 0i64;
    v11 = 0i64;
    for ( i = (_WORD *)v35; ; ++i )
    {
      if ( (unsigned int)v10 >= v37.fields._length )
        goto LABEL_42;
      type = (System_Type_o *)*(unsigned __int16 *)((char *)i + v37.fields._pointer.fields._value - v35);
      if ( (unsigned int)v10 >= DWORD2(v35) )
        goto LABEL_42;
      if ( (_WORD)type != *i )
        break;
      v10 = (unsigned int)(v10 + 1);
      if ( ++v11 >= v37.fields._length )
        return 0i64;
    }
  }
  if ( !v4 )
    goto LABEL_40;
  v14 = (System_Type_o *)((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))v4->klass->vtable._46_unknown.methodPtr)(
                           v4,
                           v4->klass->vtable._46_unknown.method);
  v15 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))v4->klass->vtable._47_GetArrayRank.methodPtr)(
          v4,
          v4->klass->vtable._47_GetArrayRank.method);
  v17 = v15;
  v33 = v15;
  if ( !array )
  {
    v18 = il2cpp_array_new_specific_0(int___TypeInfo, v15);
    v19 = *(__m128i *)v5;
    v38 = *(__m128i *)v5;
    v20 = 0;
    v10 = 0i64;
    if ( v18 )
    {
      while ( 1 )
      {
        v21 = *(_DWORD *)(v18 + 24);
        if ( (int)v10 >= v21 )
          break;
        v22 = 0i64;
        v44 = 0i64;
        if ( v20 >= v21 )
          goto LABEL_42;
        *(_DWORD *)(v18 + 4i64 * (int)v20 + 32) = 0;
        if ( _mm_cvtsi128_si32(_mm_srli_si128(v19, 8)) > 0 )
        {
          while ( 1 )
          {
            if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
              il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v11);
            v43 = v19;
            v23 = (__int128 *)JsonSerializer__extractInsideBraces(&v49, (System_ReadOnlySpan_char__o *)&v43, 0, 0i64);
            v40 = *v23;
            v22 = v23[1];
            v41 = v22;
            v42 = v23[2];
            if ( !byte_18579ED1D )
            {
              sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice__);
              _InterlockedOr(v32, 0);
              byte_18579ED1D = 1;
              v22 = v41;
            }
            v24 = DWORD2(v42);
            v25 = DWORD2(v40);
            if ( DWORD2(v42) > DWORD2(v40) )
              System_ThrowHelper__ThrowArgumentOutOfRangeException(0i64);
            v26 = v40 + 2i64 * SDWORD2(v42);
            v36.m128i_i64[1] = 0i64;
            v10 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice__ + 32);
            if ( (*(_BYTE *)(v10 + 309) & 1) == 0 )
              sub_1804E30B0(v10);
            v36.m128i_i64[0] = v26;
            v27 = v25 - v24;
            v36.m128i_i32[2] = v27;
            v19 = v36;
            v38 = v36;
            v44 = v22;
            if ( v20 >= *(_DWORD *)(v18 + 24) )
              break;
            ++*(_DWORD *)(v18 + 4i64 * (int)v20 + 32);
            if ( v27 <= 0 )
              goto LABEL_35;
          }
LABEL_42:
          sub_1804BDCB0(v10, v11, type);
        }
LABEL_35:
        v19 = (__m128i)v22;
        v38 = (__m128i)v22;
        v10 = ++v20;
      }
      array = System_Array__CreateInstance_6496634512(v14, (System_Int32_array *)v18, 0i64);
      v17 = v33;
      v5 = v50;
      goto LABEL_37;
    }
LABEL_40:
    sub_1804BDCA0();
  }
LABEL_37:
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v16);
  v45 = (__int128)*v5;
  v28 = JsonSerializer__separateArrayValue(&v48, (System_ReadOnlySpan_char__o *)&v45, 0i64);
  v29 = v28->fields._srcJson;
  v30 = v28->fields._elementIndexs;
  v31 = (System_Int32_array *)il2cpp_array_new_specific_0(int___TypeInfo, v17);
  v46.fields._srcJson = v29;
  v46.fields._elementIndexs = v30;
  JsonSerializer__analyzeArrayImpl(array, v14, &v46, 0, v31, 0i64);
  return (Il2CppObject *)array;
}
