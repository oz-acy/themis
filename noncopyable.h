/*
 * Copyright 2019-2021 oZ/acy (名賀月晃嗣)
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
 *  @file noncopyable.h
 *  @author oZ/acy(名賀月晃嗣)
 *  @brief コピー禁止クラステンプレート
 *  @date 2019.8.26 新規作成
 *  @date 2021.3.25 實質を伴はざる若干の修正
 */

#ifndef INCLUDE_GUARD_THEMIS_NONCOPYABLE_H
#define INCLUDE_GUARD_THEMIS_NONCOPYABLE_H


namespace themis
{

/**
 *  @brief コピー禁止クラステンプレート
 *
 *  コピー禁止とするクラスのprivate基底となるクラステンプレート。
 *  class Tをコピー禁止にするとき、
 *  boost::noncopyableに替へてNoncopyable<T>を用ゐる。
 */
template<class T>
class Noncopyable
{
public:
  constexpr Noncopyable() = default;
  ~Noncopyable() = default;
  Noncopyable(const Noncopyable&) = delete;
  Noncopyable& operator=(const Noncopyable&) = delete;
};


}//end of namespace themis


#endif // INCLUDE_GUARD_THEMIS_NONCOPYABLE_H
