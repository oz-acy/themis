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
 *
 *  @file exception.h
 *  @author oZ/acy (名賀月晃嗣)
 *  @brief 例外クラス
 *
 *  @date 2016.3.2  C++11對應
 *  @date 2019.8.26 include guardを修正
 *  @date 2021.3.25 コメントを整理
 */
#ifndef INCLUDE_GUARD_THEMIS_EXCEPTION_H
#define INCLUDE_GUARD_THEMIS_EXCEPTION_H

#include <string>
#include <iostream>
#include <exception>

namespace themis
{

/**
 * @brief 空の例外クラス
 */
class EmptyException : public std::exception
{
public:
  /// @brief 構築子
  EmptyException() noexcept {} 

  /// @brief 解體子
  virtual ~EmptyException() noexcept {} 

  /// @brief エラー内容取得
  ///
  /// std::exception::what()の實裝定義。
  /// C文字列"themis::EmptyException"を返す。
  const char* what() const noexcept override
  {
    static const char rstr[] = "themis::EmptyException";
    return rstr;
  }
};


class Exception;
std::ostream& operator<<(std::ostream& os, const Exception& ex);

/**
 * @brief メッセージ文字列附き例外クラス
 *
 * 一つのメッセージ文字列を保持する例外クラス。
 * 出力ストリームに保持するメッセージ文字列を出力することができる。
 */
class Exception : public EmptyException
{
  /// @brief 插入演算子
  ///
  /// 出力ストリームにExceptionの保持するメッセージ文字列を出力する。
  /// @param os 左邊。出力ストリーム。
  /// @param ex 右邊。出力對象のException。
  friend std::ostream&
         themis::operator<<(std::ostream& os, const Exception& ex);

protected:
  std::string msg_; ///< メッセージ文字列

public:
  /// @brief デフォルト構築子
  ///
  /// メッセージ文字列を空文字列で初期化する。
  Exception() noexcept {}

  /// @brief 構築子
  ///
  /// メッセージ文字列を與へて初期化する。
  ///
  /// @param m メッセージ文字列
  Exception(const std::string& m) : msg_(m) {}

  /// @brief 構築子
  ///
  /// クラス名、函數名、メッセージを與へて初期化する。
  /// 
  /// メッセージ文字列を「クラス名::函數名 : メッセージ」の書式で初期化する。
  /// 
  /// @param c クラス名
  /// @param f 函數名
  /// @param m メッセージ文字列
  Exception(const std::string& c, const std::string& f, const std::string& m)
  {
    msg_ = c + "::" + f + " : " + m;
  }

  /// @brief 解體子
  ~Exception() {}

  /// @brief エラー内容取得
  ///
  /// std::exception::what()の実装定義。
  /// C文字列"themis::Exception"を返す。
  const char* what() const noexcept override
  {
    static const char rstr[] = "themis::Exception";
    return rstr;
  }
};

inline std::ostream& operator<<(std::ostream& os, const Exception& ex)
{
  return os << ex.msg_;
}


}// end of namespace themis


#endif // INCLUDE_GUARD_THEMIS_EXCEPT_H
