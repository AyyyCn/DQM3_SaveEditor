void __stdcall JsonSerializer__deserializeSpecialization_6448144144(UnityEngine_Vector2Int_o *result, System_String_o *json, const MethodInfo *method)
{
  System_ReadOnlySpan_char__o v5; // xmm6
  JsonSerializer_SeparateString_o *v6; // rax
  System_ReadOnlySpan_char__o v7; // xmm1
  System_ReadOnlySpan_char__o v8; // xmm0
  JsonSerializer_SeparateString_o *v9; // rax
  System_ReadOnlySpan_char__o v10; // xmm1
  System_ReadOnlySpan_char__o v11; // xmm0
  Il2CppObject *v12; // rsi
  struct JsonSerializer_StaticFields *v13; // rdx
  Localize_c *v14; // rcx
  System_Type_o *v15; // rbp
  System_IFormatProvider_o *v16; // rbx
  Il2CppObject *v17; // rbx
  Il2CppObject *v18; // rax
  Il2CppObject *v19; // rax
  Il2CppClass *v20; // rdx
  Il2CppClass *v21; // rcx
  signed __int32 v22[8]; // [rsp+0h] [rbp-138h] BYREF
  System_ReadOnlySpan_char__o v23[2]; // [rsp+20h] [rbp-118h] BYREF
  System_ReadOnlySpan_char__o v24[3]; // [rsp+40h] [rbp-F8h] BYREF
  System_ReadOnlySpan_char__o v25[5]; // [rsp+70h] [rbp-C8h] BYREF
  JsonSerializer_SeparateString_o v26; // [rsp+C0h] [rbp-78h] BYREF
  JsonSerializer_SeparateString_o v27; // [rsp+F0h] [rbp-48h] BYREF
  UnityEngine_Vector2Int_o v28; // [rsp+148h] [rbp+10h]

  if ( !byte_18579D61D )
  {
    sub_180499EE0(&System_Convert_TypeInfo);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&int_TypeInfo);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&Localize_TypeInfo);
    _InterlockedOr(v22, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__ToString__);
    _InterlockedOr(v22, 0);
    byte_18579D61D = 1;
  }
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v22, 0);
    byte_18579AC1D = 1;
  }
  if ( json )
  {
    v23[0].fields._pointer.fields._value = (intptr_t)&json->fields._firstChar;
    *(_QWORD *)&v23[0].fields._length = (unsigned int)json->fields._stringLength;
    v5 = v23[0];
  }
  else
  {
    v5 = 0i64;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  v23[0] = v5;
  v6 = JsonSerializer__separateToNameAndValue(&v26, v23, 0i64);
  v7 = v6->fields.value;
  v23[1] = v6->fields.name;
  v8 = v6->fields.nextVariable;
  v24[0] = v7;
  v24[1] = v8;
  v23[0] = v8;
  v9 = JsonSerializer__separateToNameAndValue(&v27, v23, 0i64);
  v10 = v9->fields.value;
  v24[2] = v9->fields.name;
  v11 = v9->fields.nextVariable;
  v25[0] = v10;
  v25[1] = v11;
  v12 = (Il2CppObject *)System_ReadOnlySpan_char___ToString(
                          v24,
                          (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
  v13 = JsonSerializer_TypeInfo->static_fields;
  v14 = Localize_TypeInfo;
  v15 = v13->_intType;
  if ( !Localize_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(Localize_TypeInfo, v13);
    v14 = Localize_TypeInfo;
  }
  v16 = (System_IFormatProvider_o *)v14->static_fields->JpCultureInfo;
  if ( !System_Convert_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Convert_TypeInfo, v13);
  v17 = System_Convert__ChangeType_6495787424(v12, v15, v16, 0i64);
  v18 = (Il2CppObject *)System_ReadOnlySpan_char___ToString(
                          v25,
                          (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
  v19 = System_Convert__ChangeType_6495787424(
          v18,
          JsonSerializer_TypeInfo->static_fields->_intType,
          (System_IFormatProvider_o *)Localize_TypeInfo->static_fields->JpCultureInfo,
          0i64);
  if ( !v19 )
    goto LABEL_19;
  v20 = v19->klass;
  v21 = int_TypeInfo->_1.element_class;
  if ( v19->klass->_1.element_class != v21 )
    sub_1804BE2F0(v19, int_TypeInfo);
  if ( !v17 )
LABEL_19:
    sub_1804BDCA0(v21, v20, int_TypeInfo);
  if ( v17->klass->_1.element_class != int_TypeInfo->_1.element_class )
    sub_1804BE2F0(v17, int_TypeInfo);
  v28.fields.m_X = (int32_t)v17[1].klass;
  v28.fields.m_Y = (int32_t)v19[1].klass;
  *result = v28;
}
