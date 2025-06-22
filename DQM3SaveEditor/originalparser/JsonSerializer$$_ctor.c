void __stdcall JsonSerializer___ctor(JsonSerializer_o *this, bool enable_optimize, const MethodInfo *method)
{
  JsonSerializer_IntArrayCache_o *v5; // rbx
  bool v6; // zf
  __int64 *v7; // rdx
  signed __int64 v8; // rtt
  __int64 *v9; // rdx
  signed __int64 v10; // rtt
  signed __int32 v11[8]; // [rsp+0h] [rbp-38h] BYREF
  struct Cysharp_Text_Utf16ValueStringBuilder_o v12; // [rsp+20h] [rbp-18h] BYREF

  if ( !byte_18579D604 )
  {
    sub_180499EE0(&JsonSerializer_IntArrayCache_TypeInfo);
    _InterlockedOr(v11, 0);
    byte_18579D604 = 1;
  }
  v5 = (JsonSerializer_IntArrayCache_o *)sub_180481BA0(JsonSerializer_IntArrayCache_TypeInfo);
  JsonSerializer_IntArrayCache___ctor(v5, 0i64);
  v6 = dword_18579B674 == 0;
  this->fields._intArrayCache = v5;
  if ( !v6 )
  {
    v7 = &qword_1857BAE80[(((unsigned __int64)&this->fields._intArrayCache >> 12) & 0x1FFFFF) >> 6];
    _m_prefetchw(v7 + 35932);
    do
      v8 = v7[35932];
    while ( v8 != _InterlockedCompareExchange64(
                    v7 + 35932,
                    v8 | (1i64 << (((unsigned __int64)&this->fields._intArrayCache >> 12) & 0x3F)),
                    v8) );
  }
  v12 = 0i64;
  sub_180570760(&v12, 0i64, 0x200000i64);
  v6 = dword_18579B674 == 0;
  this->fields._str = v12;
  if ( !v6 )
  {
    v9 = &qword_1857BAE80[(((unsigned __int64)&this->fields >> 12) & 0x1FFFFF) >> 6];
    _m_prefetchw(v9 + 35932);
    do
      v10 = v9[35932];
    while ( v10 != _InterlockedCompareExchange64(
                     v9 + 35932,
                     v10 | (1i64 << (((unsigned __int64)&this->fields >> 12) & 0x3F)),
                     v10) );
  }
  this->fields._enableOptimize = enable_optimize;
}
