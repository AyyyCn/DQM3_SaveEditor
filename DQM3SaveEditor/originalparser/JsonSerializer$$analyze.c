Il2CppObject *__stdcall JsonSerializer__analyze(System_ReadOnlySpan_char__o *json, System_Type_o *type, const MethodInfo *method)
{
  System_Type_o *v3; // r12
  unsigned int v5; // edi
  JsonSerializer_SeparateString_o *v6; // rax
  __int64 v7; // rdx
  __int64 v8; // r8
  struct System_ReadOnlySpan_char__o v9; // xmm6
  struct System_ReadOnlySpan_char__o v10; // xmm7
  struct System_ReadOnlySpan_char__o v11; // xmm8
  Il2CppObject *v12; // r13
  Il2CppType *v13; // rbx
  __int64 v14; // rcx
  __int64 v15; // rax
  __int64 v16; // rax
  __int64 v17; // rdx
  System_Collections_Generic_Dictionary_TKey__TValue__o *v18; // rcx
  __int64 v19; // rdx
  JsonSerializer_c *v20; // rax
  struct JsonSerializer_StaticFields *v21; // rax
  System_Collections_Generic_Dictionary_object__object__o *v22; // rbx
  struct System_Type_o *v23; // rcx
  __int64 v24; // rax
  Il2CppObject *v25; // rax
  JsonSerializer_c *v26; // rax
  System_Collections_Generic_Dictionary_TKey__TValue__o *v27; // rcx
  __int64 v28; // rdx
  UnityEngine_UIElements_StyleComplexSelector_PseudoStateData_o v29; // rbx
  JsonSerializer_c *v30; // rdx
  JsonSerializer_c *v31; // rcx
  __int64 v32; // rdx
  __int64 v33; // r15
  __int64 v34; // rbx
  __int64 v35; // rdx
  JsonSerializer_c *v36; // rax
  struct System_Type_o *v37; // rcx
  __int64 v38; // rbx
  System_Type_o *v39; // rbx
  Il2CppObject *result; // rax
  __int64 v41; // rsi
  struct System_Type_o *v42; // rbx
  System_Object_array *v43; // r13
  int v44; // ebx
  System_String_o *v45; // rsi
  __int128 v46; // xmm0
  unsigned int v47; // eax
  __int64 v48; // rsi
  System_Type_o *v49; // rbx
  Il2CppObject *v50; // rax
  Il2CppObject *v51; // rbx
  JsonSerializer_SeparateString_o *v52; // rax
  __int64 v53; // rdx
  System_String_o *v54; // rbx
  __int64 v55; // rdx
  int32_t v56; // ebx
  __int64 v57; // r15
  System_String_o *v58; // rsi
  unsigned int v59; // ecx
  __int128 v60; // xmm0
  int v61; // esi
  System_Text_StringBuilder_o *v62; // r13
  int v63; // er14
  unsigned int v64; // esi
  unsigned __int16 *v65; // r12
  _WORD *v66; // r15
  int v67; // eax
  _WORD *v68; // rax
  __int64 v69; // r15
  Localize_c *v70; // rax
  System_IFormatProvider_o *v71; // rbx
  __int64 v72; // rax
  signed __int32 v73[8]; // [rsp+0h] [rbp-258h] BYREF
  System_ReadOnlySpan_char__o v74; // [rsp+40h] [rbp-218h] BYREF
  struct System_ReadOnlySpan_char__o v75; // [rsp+50h] [rbp-208h]
  int32_t capacity[4]; // [rsp+60h] [rbp-1F8h] BYREF
  struct System_ReadOnlySpan_char__o v77; // [rsp+70h] [rbp-1E8h]
  __int128 v78; // [rsp+90h] [rbp-1C8h]
  __int128 v79; // [rsp+A0h] [rbp-1B8h]
  __int128 v80; // [rsp+B0h] [rbp-1A8h]
  __int128 v81; // [rsp+C0h] [rbp-198h]
  __m128i v82; // [rsp+D0h] [rbp-188h]
  System_ReadOnlySpan_char__o v83; // [rsp+E0h] [rbp-178h]
  System_ReadOnlySpan_char__o v84; // [rsp+F0h] [rbp-168h]
  int v85; // [rsp+108h] [rbp-150h]
  JsonSerializer_SeparateString_o v86; // [rsp+110h] [rbp-148h] BYREF
  System_ReadOnlySpan_char__o v87; // [rsp+150h] [rbp-108h] BYREF
  System_ReadOnlySpan_char__o v88; // [rsp+160h] [rbp-F8h] BYREF
  System_ReadOnlySpan_char__o v89[3]; // [rsp+170h] [rbp-E8h] BYREF
  JsonSerializer_SeparateString_o v90; // [rsp+1A0h] [rbp-B8h] BYREF
  JsonSerializer_SeparateString_o v91[2]; // [rsp+1D0h] [rbp-88h] BYREF
  int v92; // [rsp+260h] [rbp+8h]
  System_Type_o *v93; // [rsp+268h] [rbp+10h]

  v93 = type;
  v3 = type;
  if ( !byte_18579D5F5 )
  {
    sub_180499EE0(&System_Convert_TypeInfo);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&System_Enum_TypeInfo);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&Localize_TypeInfo);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&object___TypeInfo);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__ToString__);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&System_Text_StringBuilder_TypeInfo);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&string_var);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&StringLiteral_14297);
    _InterlockedOr(v73, 0);
    sub_180499EE0(&StringLiteral_14296);
    _InterlockedOr(v73, 0);
    byte_18579D5F5 = 1;
  }
  v5 = 0;
  v85 = 0;
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, type);
  v87 = *json;
  v6 = JsonSerializer__separateToNameAndValue(&v90, &v87, 0i64);
  v9 = v6->fields.name;
  v75 = v6->fields.name;
  v10 = v6->fields.value;
  *(struct System_ReadOnlySpan_char__o *)capacity = v10;
  v11 = v6->fields.nextVariable;
  v77 = v11;
  v12 = 0i64;
  v13 = string_var;
  v14 = (__int64)System_Type_TypeInfo;
  if ( !System_Type_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Type_TypeInfo, v7);
  if ( !byte_1857AE60A )
  {
    sub_180499EE0(&System_Type_TypeInfo);
    _InterlockedOr(v73, 0);
    byte_1857AE60A = 1;
    v11 = v77;
    v10 = *(struct System_ReadOnlySpan_char__o *)capacity;
    v9 = v75;
  }
  if ( v13 )
  {
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, v7);
    LOBYTE(v7) = 1;
    v15 = sub_18045F530(v13, v7);
    v16 = il2cpp_type_get_object_0(v15 + 32);
  }
  else
  {
    v16 = 0i64;
  }
  if ( v3 == (System_Type_o *)v16 )
  {
    v56 = capacity[2];
    if ( !capacity[2] )
      goto LABEL_155;
    v57 = *(_QWORD *)capacity;
    if ( **(_WORD **)capacity != 34 )
      goto LABEL_114;
    v61 = capacity[2] - 1;
    v92 = capacity[2] - 1;
    if ( (unsigned int)(capacity[2] - 1) >= capacity[2] )
      goto LABEL_155;
    if ( *(_WORD *)(*(_QWORD *)capacity + 2i64 * capacity[2] - 2) != 34 )
    {
LABEL_114:
      v58 = StringLiteral_14297;
      if ( !byte_18579AC1D )
      {
        sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
        _InterlockedOr(v73, 0);
        byte_18579AC1D = 1;
        v56 = capacity[2];
        v57 = *(_QWORD *)capacity;
      }
      if ( v58 )
      {
        v59 = v58->fields._stringLength;
        *(_QWORD *)&v80 = &v58->fields._firstChar;
        *((_QWORD *)&v80 + 1) = v59;
        v60 = v80;
      }
      else
      {
        v60 = 0i64;
        v89[2] = 0i64;
      }
      v81 = v60;
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v7);
      if ( !byte_18579D603 )
      {
        sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
        _InterlockedOr(v73, 0);
        byte_18579D603 = 1;
        v56 = capacity[2];
        v57 = *(_QWORD *)capacity;
      }
      if ( v56 == DWORD2(v81) )
      {
        v8 = v56;
        if ( v56 <= 0 )
          return 0i64;
        v14 = 0i64;
        v68 = (_WORD *)v81;
        v69 = v57 - v81;
        while ( 1 )
        {
          if ( v5 >= v56 )
            goto LABEL_155;
          v7 = *(unsigned __int16 *)((char *)v68 + v69);
          if ( v5 >= DWORD2(v81) )
            goto LABEL_155;
          if ( (_WORD)v7 != *v68 )
            break;
          ++v5;
          ++v14;
          ++v68;
          if ( v14 >= v56 )
            return 0i64;
        }
      }
      v70 = Localize_TypeInfo;
      if ( !Localize_TypeInfo->_2.cctor_finished )
      {
        il2cpp_runtime_class_init_0(Localize_TypeInfo, v7);
        v70 = Localize_TypeInfo;
      }
      v71 = (System_IFormatProvider_o *)v70->static_fields->JpCultureInfo;
      if ( !System_Convert_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(System_Convert_TypeInfo, v7);
      return System_Convert__ChangeType_6495787424(v12, v3, v71, 0i64);
    }
    v62 = (System_Text_StringBuilder_o *)sub_180481BA0(System_Text_StringBuilder_TypeInfo);
    System_Text_StringBuilder___ctor_6494445120(v62, v56, 0x7FFFFFFF, 0i64);
    v63 = 1;
    if ( v61 <= 1 )
      goto LABEL_135;
    v64 = 2;
    v65 = (unsigned __int16 *)(v57 + 2);
    v66 = (_WORD *)(v57 + 4);
    v67 = v92;
    while ( 1 )
    {
      if ( v63 >= (unsigned int)v56 )
        goto LABEL_155;
      v7 = *v65;
      if ( (_WORD)v7 == 92 )
      {
        if ( v64 >= v56 )
          goto LABEL_155;
        if ( *v66 != 92 )
          goto LABEL_133;
        if ( !v62 )
          goto LABEL_157;
        System_Text_StringBuilder__Append_6494454160(v62, 0x5Cu, 0i64);
        ++v63;
        ++v64;
        ++v65;
        ++v66;
      }
      else
      {
        if ( !v62 )
          goto LABEL_157;
        System_Text_StringBuilder__Append_6494454160(v62, v7, 0i64);
      }
      v67 = v92;
LABEL_133:
      ++v63;
      ++v64;
      ++v65;
      ++v66;
      if ( v63 >= v67 )
      {
        v57 = *(_QWORD *)capacity;
        v3 = v93;
LABEL_135:
        if ( v62 )
        {
          v12 = (Il2CppObject *)((__int64 (__fastcall *)(System_Text_StringBuilder_o *, const MethodInfo *))v62->klass->vtable._3_ToString.methodPtr)(
                                  v62,
                                  v62->klass->vtable._3_ToString.method);
          goto LABEL_114;
        }
LABEL_157:
        sub_1804BDCA0();
      }
    }
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v7);
  if ( JsonSerializer__isBasicType_6448137248(v3, 0i64) )
  {
    v12 = (Il2CppObject *)System_ReadOnlySpan_char___ToString(
                            (System_ReadOnlySpan_char__o *)capacity,
                            (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
    v56 = capacity[2];
    v57 = *(_QWORD *)capacity;
    goto LABEL_114;
  }
  if ( !v3 )
    goto LABEL_157;
  if ( ((unsigned __int8 (__fastcall *)(System_Type_o *, const MethodInfo *))v3->klass->vtable._69_get_IsEnum.methodPtr)(
         v3,
         v3->klass->vtable._69_get_IsEnum.method) )
  {
    v54 = System_ReadOnlySpan_char___ToString(
            (System_ReadOnlySpan_char__o *)capacity,
            (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
    if ( !System_Enum_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Enum_TypeInfo, v53);
    if ( !byte_1857AE702 )
    {
      sub_180499EE0(&System_Type_TypeInfo);
      _InterlockedOr(v73, 0);
      byte_1857AE702 = 1;
    }
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, v53);
    if ( ((unsigned __int8 (__fastcall *)(System_Type_o *, System_String_o *, const MethodInfo *))v3->klass->vtable._16_IsEnumDefined.methodPtr)(
           v3,
           v54,
           v3->klass->vtable._16_IsEnumDefined.method) )
    {
      if ( !System_Enum_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(System_Enum_TypeInfo, v55);
      return System_Enum__Parse(v3, v54, 0i64);
    }
    return 0i64;
  }
  if ( ((unsigned __int8 (__fastcall *)(System_Type_o *, const MethodInfo *))v3->klass->vtable._32_unknown.methodPtr)(
         v3,
         v3->klass->vtable._32_unknown.method) )
  {
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v17);
    v74 = *json;
    result = JsonSerializer__analyzeArray(0i64, &v74, v3, 0i64);
  }
  else
  {
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v17);
    if ( !byte_18579D60C )
    {
      sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Type__ContainsKey__);
      _InterlockedOr(v73, 0);
      sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Type__get_Item__);
      _InterlockedOr(v73, 0);
      sub_180499EE0(&Method_System_Collections_Generic_Dictionary_Type__Type__set_Item__);
      _InterlockedOr(v73, 0);
      sub_180499EE0(&JsonSerializer_TypeInfo);
      _InterlockedOr(v73, 0);
      byte_18579D60C = 1;
      v11 = v77;
      v10 = *(struct System_ReadOnlySpan_char__o *)capacity;
      v9 = v75;
    }
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v17);
    v18 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)JsonSerializer_TypeInfo->static_fields->_collectionInterfaceCache;
    if ( !v18 )
      goto LABEL_157;
    if ( System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___FindEntry(
           v18,
           (Il2CppObject *)v3,
           *(const MethodInfo_2E09BE0 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__Type__ContainsKey__
                                                                + 32)
                                                    + 192i64)
                                        + 264i64)) < 0 )
    {
      v20 = JsonSerializer_TypeInfo;
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      {
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v19);
        v20 = JsonSerializer_TypeInfo;
      }
      v21 = v20->static_fields;
      v22 = (System_Collections_Generic_Dictionary_object__object__o *)v21->_collectionInterfaceCache;
      v23 = v21->_collectionType;
      if ( !v23 )
        goto LABEL_157;
      v24 = ((__int64 (__fastcall *)(struct System_Type_o *, const MethodInfo *))v23->klass->vtable._8_unknown.methodPtr)(
              v23,
              v23->klass->vtable._8_unknown.method);
      v25 = (Il2CppObject *)((__int64 (__fastcall *)(System_Type_o *, __int64, _QWORD, const MethodInfo *))v3->klass->vtable._116_unknown.methodPtr)(
                              v3,
                              v24,
                              0i64,
                              v3->klass->vtable._116_unknown.method);
      if ( !v22 )
        goto LABEL_157;
      System_Collections_Generic_Dictionary_object__object___TryInsert(
        v22,
        (Il2CppObject *)v3,
        v25,
        1u,
        *(const MethodInfo_2E1E360 **)(*(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_Dictionary_Type__Type__set_Item__
                                                             + 32)
                                                 + 192i64)
                                     + 272i64));
    }
    v26 = JsonSerializer_TypeInfo;
    if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    {
      il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v19);
      v26 = JsonSerializer_TypeInfo;
    }
    v27 = (System_Collections_Generic_Dictionary_TKey__TValue__o *)v26->static_fields->_collectionInterfaceCache;
    if ( !v27 )
      goto LABEL_157;
    v29 = System_Collections_Generic_Dictionary_object__StyleComplexSelector_PseudoStateData___get_Item(
            v27,
            (Il2CppObject *)v3,
            Method_System_Collections_Generic_Dictionary_Type__Type__get_Item__);
    if ( !System_Type_TypeInfo->_2.cctor_finished )
      il2cpp_runtime_class_init_0(System_Type_TypeInfo, v28);
    if ( v29 )
    {
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v28);
      v74 = *json;
      result = JsonSerializer__analyzeCollection(&v74, v3, 0i64);
    }
    else
    {
      if ( !((unsigned __int8 (__fastcall *)(System_Type_o *, const MethodInfo *))v3->klass->vtable._40_get_IsGenericType.methodPtr)(
              v3,
              v3->klass->vtable._40_get_IsGenericType.method) )
      {
        v31 = JsonSerializer_TypeInfo;
        if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
          goto LABEL_69;
        goto LABEL_70;
      }
      v33 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))v3->klass->vtable._50_GetGenericArguments.methodPtr)(
              v3,
              v3->klass->vtable._50_GetGenericArguments.method);
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v32);
      if ( !byte_18579D602 )
      {
        sub_180499EE0(&JsonSerializer_TypeInfo);
        _InterlockedOr(v73, 0);
        sub_180499EE0(&System_Type_TypeInfo);
        _InterlockedOr(v73, 0);
        byte_18579D602 = 1;
        v11 = v77;
        v10 = *(struct System_ReadOnlySpan_char__o *)capacity;
        v9 = v75;
      }
      if ( !v33 )
        goto LABEL_157;
      if ( *(_DWORD *)(v33 + 24) != 1 )
        goto LABEL_62;
      v34 = *(_QWORD *)(v33 + 32);
      if ( !v34 )
        goto LABEL_157;
      if ( ((*(__int64 (__fastcall **)(_QWORD, _QWORD))(*(_QWORD *)v34 + 1192i64))(
              *(_QWORD *)(v33 + 32),
              *(_QWORD *)(*(_QWORD *)v34 + 1200i64)) & 0x20) == 0
        && !(*(unsigned __int8 (__fastcall **)(__int64, _QWORD))(*(_QWORD *)v34 + 1512i64))(
              v34,
              *(_QWORD *)(*(_QWORD *)v34 + 1520i64)) )
      {
        goto LABEL_62;
      }
      v36 = JsonSerializer_TypeInfo;
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
      {
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v35);
        v36 = JsonSerializer_TypeInfo;
      }
      v37 = v36->static_fields->_nullableBaseType;
      if ( !v37 )
        goto LABEL_157;
      v38 = ((__int64 (__fastcall *)(struct System_Type_o *, __int64, const MethodInfo *))v37->klass->vtable._125_MakeGenericType.methodPtr)(
              v37,
              v33,
              v37->klass->vtable._125_MakeGenericType.method);
      v14 = (__int64)System_Type_TypeInfo;
      if ( !System_Type_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(System_Type_TypeInfo, v7);
      if ( v3 != (System_Type_o *)v38 )
      {
LABEL_62:
        v41 = ((__int64 (__fastcall *)(System_Type_o *, const MethodInfo *))v3->klass->vtable._48_GetGenericTypeDefinition.methodPtr)(
                v3,
                v3->klass->vtable._48_GetGenericTypeDefinition.method);
        v30 = JsonSerializer_TypeInfo;
        if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        {
          il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, JsonSerializer_TypeInfo);
          v30 = JsonSerializer_TypeInfo;
        }
        v42 = v30->static_fields->_keyValuePairType;
        if ( !System_Type_TypeInfo->_2.cctor_finished )
        {
          il2cpp_runtime_class_init_0(System_Type_TypeInfo, v30);
          v30 = JsonSerializer_TypeInfo;
        }
        if ( (struct System_Type_o *)v41 == v42 )
        {
          v43 = (System_Object_array *)il2cpp_array_new_specific_0(object___TypeInfo, 2i64);
          v82 = (__m128i)v9;
          v83 = v10;
          v84 = v11;
          v44 = v9.fields._length;
          while ( 1 )
          {
            v45 = StringLiteral_14296;
            if ( !byte_18579AC1D )
            {
              sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
              _InterlockedOr(v73, 0);
              byte_18579AC1D = 1;
              v44 = v82.m128i_i32[2];
            }
            v46 = 0i64;
            v89[1] = 0i64;
            if ( v45 )
            {
              *(_QWORD *)&v78 = &v45->fields._firstChar;
              *((_QWORD *)&v78 + 1) = (unsigned int)v45->fields._stringLength;
              v46 = v78;
            }
            v79 = v46;
            v14 = (__int64)JsonSerializer_TypeInfo;
            if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
              il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v7);
            if ( !byte_18579D603 )
            {
              sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
              _InterlockedOr(v73, 0);
              byte_18579D603 = 1;
              v44 = v82.m128i_i32[2];
            }
            if ( v44 == DWORD2(v79) )
            {
              v14 = 0i64;
              v8 = 0i64;
              if ( v44 > 0 )
              {
                v7 = v82.m128i_i64[0];
                while ( (unsigned int)v14 < v44 && (unsigned int)v14 < DWORD2(v79) )
                {
                  if ( *(_WORD *)v7 != *(_WORD *)(v79 - v82.m128i_i64[0] + v7) )
                    goto LABEL_88;
                  v14 = (unsigned int)(v14 + 1);
                  ++v8;
                  v7 += 2i64;
                  if ( v8 >= v44 )
                    goto LABEL_87;
                }
LABEL_155:
                sub_1804BDCB0(v14, v7, v8);
              }
LABEL_87:
              v47 = 0;
            }
            else
            {
LABEL_88:
              v47 = 1;
            }
            if ( v47 >= *(_DWORD *)(v33 + 24) )
              goto LABEL_155;
            v48 = v47;
            v49 = *(System_Type_o **)(v33 + 8i64 * v47 + 32);
            if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
              il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v7);
            v88 = v83;
            v50 = JsonSerializer__analyze(&v88, v49, 0i64);
            v51 = v50;
            if ( !v43 )
              goto LABEL_157;
            if ( v50 && !sub_180481AF0(v50, v43->obj.klass->_1.element_class) )
            {
              v72 = sub_1804BDEC0();
              sub_1804BDC60(v72, 0i64);
            }
            sub_180006A40(v43, v48, v51);
            v89[0] = v84;
            v52 = JsonSerializer__separateToNameAndValue(v91, v89, 0i64);
            v82 = (__m128i)v52->fields.name;
            v83 = v52->fields.value;
            v84 = v52->fields.nextVariable;
            v44 = _mm_cvtsi128_si32(_mm_srli_si128(v82, 8));
            if ( v44 <= 0 )
              return System_Activator__CreateInstance_6496657616(v3, 532, 0i64, v43, 0i64, 0i64, 0i64);
          }
        }
        if ( !v30->_2.cctor_finished )
        {
          v31 = v30;
LABEL_69:
          il2cpp_runtime_class_init_0(v31, v30);
        }
LABEL_70:
        v74 = *json;
        v86.fields.name = v9;
        v86.fields.value = v10;
        v86.fields.nextVariable = v11;
        return JsonSerializer__analyzeClass(&v86, &v74, v3, 0i64);
      }
      if ( !*(_DWORD *)(v33 + 24) )
        goto LABEL_155;
      v39 = *(System_Type_o **)(v33 + 32);
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v7);
      v74 = *json;
      result = JsonSerializer__analyze(&v74, v39, 0i64);
    }
  }
  return result;
}
