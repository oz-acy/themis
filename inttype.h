/***********************************************************************//**
 *
 *  @file inttype.h
 *  @author oZ/acy(名賀月晃嗣)
 *  @brief 整數型別名定義
 *  @date 2019.7.16 内容整形
 *//*
 *  (c) 2001-2019 oZ/acy.  ALL RIGHTS RESERVED.
 */

#ifndef INC_THEMIS_INTTYPE_H___
#define INC_THEMIS_INTTYPE_H___

#include <cstdint>

namespace themis
{
  typedef std::uint8_t Byte;
  typedef std::uint8_t UByte;
  typedef std::int8_t SByte;

  typedef std::uint16_t Word;
  typedef std::uint16_t UWord;
  typedef std::int16_t SWord;

  typedef std::uint32_t DWord;
  typedef std::uint32_t UDWord;
  typedef std::int32_t SDWord;
  typedef std::uint32_t Dword;
  typedef std::uint32_t UDword;
  typedef std::int32_t SDword;

  typedef std::uint64_t Quad;
  typedef std::uint64_t UQuad;
  typedef std::int64_t SQuad;


}//end of namespace themis


#endif // INC_THEMIS_INTTYPE_H___
