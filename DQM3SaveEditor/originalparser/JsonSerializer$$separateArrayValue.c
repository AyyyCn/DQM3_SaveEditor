JsonSerializer_SeparateArray_o *JsonSerializer__separateArrayValue(JsonSerializer_SeparateArray_o *retstr, System_ReadOnlySpan_char__o *json, const MethodInfo *method)
{
  System_Collections_Generic_List_UICommon_MonsterCustodyOrganizeMember_MonsterCustodyOrganizeMemberSwap_sSwappingReceiveIconData__o *v5; // rbx
  __int64 v6; // rdx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 *v9; // rdx
  bool v10; // zf
  __int64 v11; // rtt
  int32_t v12; // esi
  __int64 v13; // rcx
  int32_t v14; // edi
  JsonSerializer_InsideBraces_o *v15; // rax
  __int64 v16; // r8
  __int64 v17; // rcx
  __int128 v18; // xmm1
  System_ReadOnlySpan_char__o v19; // xmm2
  __int64 v20; // rax
  struct System_ReadOnlySpan_char__o v21; // xmm0
  JsonSerializer_SeparateArray_o *result; // rax
  signed __int32 v23[8]; // [rsp+0h] [rbp-D8h] BYREF
  System_ReadOnlySpan_char__o v24; // [rsp+20h] [rbp-B8h] BYREF
  UICommon_MonsterCustodyOrganizeMember_MonsterCustodyOrganizeMemberSwap_sSwappingReceiveIconData_o item[2]; // [rsp+50h] [rbp-88h]
  __int128 v26; // [rsp+80h] [rbp-58h]
  JsonSerializer_InsideBraces_o v27; // [rsp+90h] [rbp-48h] BYREF

  if ( !byte_18579D5FE )
  {
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v23, 0);
    sub_180499EE0(&Method_System_Collections_Generic_List_JsonSerializer_InsideIndex__Add__);
    _InterlockedOr(v23, 0);
    sub_180499EE0(&Method_System_Collections_Generic_List_JsonSerializer_InsideIndex___ctor__);
    _InterlockedOr(v23, 0);
    sub_180499EE0(&System_Collections_Generic_List_JsonSerializer_InsideIndex__TypeInfo);
    _InterlockedOr(v23, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__get_Length__);
    _InterlockedOr(v23, 0);
    byte_18579D5FE = 1;
  }
  v5 = (System_Collections_Generic_List_UICommon_MonsterCustodyOrganizeMember_MonsterCustodyOrganizeMemberSwap_sSwappingReceiveIconData__o *)sub_180481BA0(System_Collections_Generic_List_JsonSerializer_InsideIndex__TypeInfo);
  v6 = *(_QWORD *)(*(_QWORD *)(Method_System_Collections_Generic_List_JsonSerializer_InsideIndex___ctor__ + 32) + 192i64);
  v7 = *(_QWORD *)(v6 + 24);
  if ( (*(_BYTE *)(v7 + 309) & 1) == 0 )
    v7 = sub_1804E30B0(*(_QWORD *)(v6 + 24));
  v8 = il2cpp_array_new_specific_0(v7, 16i64);
  v10 = dword_18579B674 == 0;
  v5->fields._items = (struct UICommon_MonsterCustodyOrganizeMember_MonsterCustodyOrganizeMemberSwap_sSwappingReceiveIconData_array *)v8;
  if ( !v10 )
  {
    v9 = &qword_185801160[(((unsigned __int64)&v5->fields >> 12) & 0x1FFFFF) >> 6];
    _m_prefetchw(v9);
    do
      v11 = *v9;
    while ( v11 != _InterlockedCompareExchange64(
                     v9,
                     *v9 | (1i64 << (((unsigned __int64)&v5->fields >> 12) & 0x3F)),
                     *v9) );
  }
  v12 = json->fields._length;
  if ( v12 > 0 )
  {
    if ( !byte_18579ED1E )
    {
      sub_180499EE0(&Method_System_ReadOnlySpan_char__Slice___6531935520);
      _InterlockedOr(v23, 0);
      byte_18579ED1E = 1;
    }
    v24 = *json;
    v13 = *(_QWORD *)(Method_System_ReadOnlySpan_char__Slice___6531935520 + 32);
    if ( (*(_BYTE *)(v13 + 309) & 1) == 0 )
      sub_1804E30B0(v13);
    v14 = 0;
    do
    {
      if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
        il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, v9);
      v15 = JsonSerializer__extractInsideBraces(&v27, &v24, v14, 0i64);
      v9 = (__int64 *)v5->fields._items;
      v17 = v5->fields._size;
      v18 = *(_OWORD *)&v15->fields.insideIndex.fields.start;
      v19 = v15->fields.srcStr;
      v20 = Method_System_Collections_Generic_List_JsonSerializer_InsideIndex__Add__;
      ++v5->fields._version;
      v24 = v19;
      v26 = v18;
      *(_OWORD *)&item[0].fields.focus = v18;
      if ( !v9 )
        sub_1804BDCA0(v17, 0i64, v16);
      if ( (unsigned int)v17 < *((_DWORD *)v9 + 6) )
      {
        v5->fields._size = v17 + 1;
        if ( (unsigned int)v17 >= *((_DWORD *)v9 + 6) )
          sub_1804BDCB0(v17, v9, v16);
        v9[v17 + 4] = (__int64)item[0];
      }
      else
      {
        System_Collections_Generic_List_UICommon_MonsterCustodyOrganizeMember_MonsterCustodyOrganizeMemberSwap_sSwappingReceiveIconData___AddWithResize(
          v5,
          item[0],
          *(const MethodInfo_1CACA90 **)(*(_QWORD *)(*(_QWORD *)(v20 + 32) + 192i64) + 112i64));
      }
      v14 = DWORD2(v26);
    }
    while ( v12 > SDWORD2(v26) );
  }
  v21 = *json;
  retstr->fields._elementIndexs = (struct System_Collections_Generic_IReadOnlyList_JsonSerializer_InsideIndex__o *)v5;
  result = retstr;
  retstr->fields._srcJson = v21;
  return result;
}
