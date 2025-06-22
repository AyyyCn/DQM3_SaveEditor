void __stdcall JsonSerializer__deserializeSpecialization(UnityEngine_Vector3_o *result, System_String_o *json, const MethodInfo *method)
{
  System_ReadOnlySpan_char__o v5; // xmm6
  JsonSerializer_SeparateString_o *v6; // rax
  System_ReadOnlySpan_char__o v7; // xmm1
  System_ReadOnlySpan_char__o v8; // xmm0
  JsonSerializer_SeparateString_o *v9; // rax
  System_ReadOnlySpan_char__o v10; // xmm1
  System_ReadOnlySpan_char__o v11; // xmm0
  JsonSerializer_SeparateString_o *v12; // rax
  System_ReadOnlySpan_char__o v13; // xmm1
  System_ReadOnlySpan_char__o v14; // xmm0
  Il2CppObject *v15; // rsi
  struct JsonSerializer_StaticFields *v16; // rdx
  Localize_c *v17; // rcx
  System_Type_o *v18; // r14
  System_IFormatProvider_o *v19; // rbx
  float *v20; // rax
  __int64 v21; // rdx
  __int64 v22; // rcx
  System_Single_c *v23; // r8
  Il2CppObject *v24; // rax
  float *v25; // rax
  Il2CppObject *v26; // rax
  float *v27; // rax
  signed __int32 v28[6]; // [rsp+8h] [rbp-100h] BYREF
  System_ReadOnlySpan_char__o v29[2]; // [rsp+28h] [rbp-E0h] BYREF
  System_ReadOnlySpan_char__o v30[3]; // [rsp+48h] [rbp-C0h] BYREF
  System_ReadOnlySpan_char__o v31[3]; // [rsp+78h] [rbp-90h] BYREF
  System_ReadOnlySpan_char__o v32[5]; // [rsp+A8h] [rbp-60h] BYREF
  JsonSerializer_SeparateString_o v33; // [rsp+F8h] [rbp-10h] BYREF
  JsonSerializer_SeparateString_o v34; // [rsp+128h] [rbp+20h] BYREF
  JsonSerializer_SeparateString_o v35; // [rsp+158h] [rbp+50h] BYREF

  if ( !byte_18579D61B )
  {
    sub_180499EE0(&System_Convert_TypeInfo);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&JsonSerializer_TypeInfo);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Localize_TypeInfo);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&Method_System_ReadOnlySpan_char__ToString__);
    _InterlockedOr(v28, 0);
    sub_180499EE0(&float_TypeInfo);
    _InterlockedOr(v28, 0);
    byte_18579D61B = 1;
  }
  if ( !byte_18579AC1D )
  {
    sub_180499EE0(&Method_System_ReadOnlySpan_char___ctor___6531933024);
    _InterlockedOr(v28, 0);
    byte_18579AC1D = 1;
  }
  if ( json )
  {
    v29[0].fields._pointer.fields._value = (intptr_t)&json->fields._firstChar;
    *(_QWORD *)&v29[0].fields._length = (unsigned int)json->fields._stringLength;
    v5 = v29[0];
  }
  else
  {
    v5 = 0i64;
  }
  if ( !JsonSerializer_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(JsonSerializer_TypeInfo, json);
  v29[0] = v5;
  v6 = JsonSerializer__separateToNameAndValue(&v33, v29, 0i64);
  v7 = v6->fields.value;
  v29[1] = v6->fields.name;
  v8 = v6->fields.nextVariable;
  v30[0] = v7;
  v30[1] = v8;
  v29[0] = v8;
  v9 = JsonSerializer__separateToNameAndValue(&v34, v29, 0i64);
  v10 = v9->fields.value;
  v30[2] = v9->fields.name;
  v11 = v9->fields.nextVariable;
  v31[0] = v10;
  v31[1] = v11;
  v29[0] = v11;
  v12 = JsonSerializer__separateToNameAndValue(&v35, v29, 0i64);
  v13 = v12->fields.value;
  v31[2] = v12->fields.name;
  v14 = v12->fields.nextVariable;
  v32[0] = v13;
  v32[1] = v14;
  v15 = (Il2CppObject *)System_ReadOnlySpan_char___ToString(
                          v30,
                          (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
  v16 = JsonSerializer_TypeInfo->static_fields;
  v17 = Localize_TypeInfo;
  v18 = v16->_floatType;
  if ( !Localize_TypeInfo->_2.cctor_finished )
  {
    il2cpp_runtime_class_init_0(Localize_TypeInfo, v16);
    v17 = Localize_TypeInfo;
  }
  v19 = (System_IFormatProvider_o *)v17->static_fields->JpCultureInfo;
  if ( !System_Convert_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_Convert_TypeInfo, v16);
  v20 = (float *)System_Convert__ChangeType_6495787424(v15, v18, v19, 0i64);
  v23 = float_TypeInfo;
  if ( !v20 )
    goto LABEL_21;
  if ( *(Il2CppClass **)(*(_QWORD *)v20 + 64i64) != float_TypeInfo->_1.element_class )
    sub_1804BE2F0(v20, float_TypeInfo);
  result->fields.x = v20[4];
  v24 = (Il2CppObject *)System_ReadOnlySpan_char___ToString(
                          v31,
                          (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
  v25 = (float *)System_Convert__ChangeType_6495787424(
                   v24,
                   JsonSerializer_TypeInfo->static_fields->_floatType,
                   (System_IFormatProvider_o *)Localize_TypeInfo->static_fields->JpCultureInfo,
                   0i64);
  v23 = float_TypeInfo;
  if ( !v25 )
    goto LABEL_21;
  if ( *(Il2CppClass **)(*(_QWORD *)v25 + 64i64) != float_TypeInfo->_1.element_class )
    sub_1804BE2F0(v25, float_TypeInfo);
  result->fields.y = v25[4];
  v26 = (Il2CppObject *)System_ReadOnlySpan_char___ToString(
                          v32,
                          (const MethodInfo_1FF00C0 *)Method_System_ReadOnlySpan_char__ToString__);
  v27 = (float *)System_Convert__ChangeType_6495787424(
                   v26,
                   JsonSerializer_TypeInfo->static_fields->_floatType,
                   (System_IFormatProvider_o *)Localize_TypeInfo->static_fields->JpCultureInfo,
                   0i64);
  v23 = float_TypeInfo;
  if ( !v27 )
LABEL_21:
    sub_1804BDCA0(v22, v21, v23);
  if ( *(Il2CppClass **)(*(_QWORD *)v27 + 64i64) != float_TypeInfo->_1.element_class )
    sub_1804BE2F0(v27, float_TypeInfo);
  result->fields.z = v27[4];
}
