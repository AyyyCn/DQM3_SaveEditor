System_Byte_array *__stdcall JsonSerializer__binary(JsonSerializer_o *this, const MethodInfo *method)
{
  __int64 v3; // rdx
  System_Text_Encoding_o *v4; // rdi
  struct System_Char_array *v5; // rcx
  unsigned int v6; // er8
  __int64 v7; // rdx
  __int64 v8; // r8
  System_ArraySegment_char__c *v9; // rcx
  signed __int32 v11[8]; // [rsp+0h] [rbp-48h] BYREF
  __int64 v12[3]; // [rsp+30h] [rbp-18h] BYREF

  if ( !byte_18579D607 )
  {
    sub_180499EE0(&Method_System_ArraySegment_char__get_Array__);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&System_ArraySegment_char__TypeInfo);
    _InterlockedOr(v11, 0);
    sub_180499EE0(&Cysharp_Text_Utf16ValueStringBuilder_TypeInfo);
    _InterlockedOr(v11, 0);
    byte_18579D607 = 1;
  }
  v4 = System_Text_Encoding__get_UTF8(0i64);
  if ( !Cysharp_Text_Utf16ValueStringBuilder_TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(Cysharp_Text_Utf16ValueStringBuilder_TypeInfo, v3);
  if ( !byte_1857BA378 )
  {
    sub_180499EE0(&Method_System_ArraySegment_char___ctor__);
    _InterlockedOr(v11, 0);
    byte_1857BA378 = 1;
  }
  v5 = this->fields._str.fields.buffer;
  v6 = this->fields._str.fields.index;
  v12[1] = 0i64;
  if ( !v5 || v6 > LODWORD(v5->max_length) )
    System_ThrowHelper__ThrowArraySegmentCtorValidationFailedExceptions((System_Array_o *)v5, 0, v6, 0i64);
  v12[0] = (__int64)v5;
  sub_1804283A0(v12);
  v9 = System_ArraySegment_char__TypeInfo;
  if ( !System_ArraySegment_char__TypeInfo->_2.cctor_finished )
    il2cpp_runtime_class_init_0(System_ArraySegment_char__TypeInfo, v7);
  if ( !v4 )
    sub_1804BDCA0(v9, v7, v8);
  return (System_Byte_array *)((__int64 (__fastcall *)(System_Text_Encoding_o *, __int64, _QWORD, _QWORD, const MethodInfo *))v4->klass->vtable._15_GetBytes.methodPtr)(
                                v4,
                                v12[0],
                                0i64,
                                (unsigned int)this->fields._str.fields.index,
                                v4->klass->vtable._15_GetBytes.method);
}
