/*
 * Copyright 2001-2021 oZ/acy (名賀月晃嗣)
 * Redistribution and use in source and binary forms, 
 *     with or without modification, 
 *   are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/**
 *  @file inttype.h
 *  @author oZ/acy(名賀月晃嗣)
 *  @brief 整數型別名定義
 *
 *  @date 2019.7.16 内容整形
 *  @date 2019.8.26 include guardを修正
 *  @date 2021.3.25 [[deprecated]]屬性を賦與
 */

#ifndef INCLUDE_GUARD_THEMIS_INTTYPE_H
#define INCLUDE_GUARD_THEMIS_INTTYPE_H

#include <cstdint>

namespace themis
{
  [[deprecated]] typedef std::uint8_t Byte;
  [[deprecated]] typedef std::uint8_t UByte;
  [[deprecated]] typedef std::int8_t SByte;

  [[deprecated]] typedef std::uint16_t Word;
  [[deprecated]] typedef std::uint16_t UWord;
  [[deprecated]] typedef std::int16_t SWord;

  [[deprecated]] typedef std::uint32_t DWord;
  [[deprecated]] typedef std::uint32_t UDWord;
  [[deprecated]] typedef std::int32_t SDWord;
  [[deprecated]] typedef std::uint32_t Dword;
  [[deprecated]] typedef std::uint32_t UDword;
  [[deprecated]] typedef std::int32_t SDword;

  [[deprecated]] typedef std::uint64_t Quad;
  [[deprecated]] typedef std::uint64_t UQuad;
  [[deprecated]] typedef std::int64_t SQuad;

}//end of namespace themis


#endif // INCLUDE_GUARD_THEMIS_INTTYPE_H
