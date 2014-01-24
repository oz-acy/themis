/***************************************************************************
*
*  inttype.h
*  by oZ/acy
*  (c) 2001-2008 oZ/acy.  ALL RIGHTS RESERVED.
*
*  last update: 2008.4.19
*
*  integer type alias on THEMIS
*  êÆêîå^ï ñº
***************************************************************************/

#ifndef INC_THEMIS_INTTYPE_H___
#define INC_THEMIS_INTTYPE_H___

namespace themis
{
  typedef unsigned char  Byte;
  typedef signed char  SByte;
  typedef unsigned char  UByte;
  typedef signed char  int8;
  typedef unsigned char uint8;

  typedef unsigned short  Word;
  typedef signed short  SWord;
  typedef unsigned short  UWord;
  typedef signed short  int16;
  typedef unsigned short uint16;

  typedef unsigned int  uint;

  typedef unsigned long  Dword;
  typedef unsigned long  DWord;
  typedef signed long  SDWord;
  typedef unsigned long  UDWord;
  typedef signed long  SDword;
  typedef unsigned long  UDword;
  typedef signed long  int32;
  typedef unsigned long uint32;


  // for 64bit integer
#if defined(__BORLANDC__) || defined(_MSC_VER)
  typedef __int64  longlong;
  typedef unsigned __int64 ulonglong;
  typedef __int64  SQuad;
  typedef unsigned __int64  UQuad;
  typedef unsigned __int64  Quad;
  typedef __int64  int64;
  typedef unsigned __int64  uint64;
#elif defined(__GNUC__)
  typedef long long int  longlong;
  typedef unsigned long long int  ulonglong;
  typedef longlong  SQuad;
  typedef ulonglong  UQuad;
  typedef ulonglong  Quad;
  typedef SQuad  int64;
  typedef UQuad  uint64;
#endif


}//end of namespace themis


#endif // INC_THEMIS_INTTYPE_H___
