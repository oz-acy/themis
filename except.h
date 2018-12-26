/**********************************************************************//**
 *
 *  @file except.h
 *  @author oZ/acy (名賀月晃嗣)
 *  @brief 例外情報格納クラス
 *  @date 2016.3.2  C++11對應
 *//*
 *  (c) 2001-2018 oZ/acy. ALL RIGHTS RESERVED.
 */
#ifndef INC_THEMIS_EXCEPT_H__
#define INC_THEMIS_EXCEPT_H__

#include <string>
#include <iostream>
#include <exception>

namespace themis
{

/*--------------------------------------*//**
 * @brief 空の例外クラス
 */
class EmptyException : public std::exception
{
public:
  EmptyException() noexcept {}
  virtual ~EmptyException() noexcept {}

  /// @brief エラー内容取得
  ///
  /// std::exception::what()をオーバーライド。
  /// C文字列"themis::EmptyException"を返す。
  const char* what() const noexcept override
  {
    static const char rstr[] = "themis::EmptyException";
    return rstr;
  }
};



//-------------------------------------------
class Exception;

std::ostream& operator<<(std::ostream& os, const Exception& ex);

/**
 * @brief メッセージ文字列を持つ例外クラス
 */
class Exception : public EmptyException
{
  friend std::ostream&
         themis::operator<<(std::ostream& os, const Exception& ex);

protected:
  std::string msg_; ///< メッセージ文字列

public:
  /// @brief デフォルト構築子
  ///
  /// メッセージを空文字で初期化する。
  Exception() noexcept {}

  /// @brief 構築子
  ///
  /// メッセージ文字列を文字列mで初期化する。
  Exception(const std::string& m) : msg_(m) {}

  /// @brief メッセージ文字列の頭にクラス名、函數名を附加する場合の構築子
  ///
  /// メッセージ文字列を、"クラス名c::函數名f : メッセージm"の書式で
  /// 初期化する。
  /// @param c クラス名
  /// @param f 函數名
  /// @param m メッセージ
  Exception(const std::string& c, const std::string& f, const std::string& m)
  {
    msg_ = c + "::" + f + " : " + m;
  }

  /// @brief 解體子
  ~Exception() {}

  /// @brief エラー内容取得
  ///
  /// std::exception::what()をオーバーライド。
  /// C文字列"themis::Exception"を返す。
  const char* what() const noexcept override
  {
    static const char rstr[] = "themis::Exception";
    return rstr;
  }
};


/// @brief 出力ストリームにメッセージ文字列を出力
///
/// 出力ストリームosに、例外exの保持するメッセージ文字列を出力する。
inline std::ostream& operator<<(std::ostream& os, const Exception& ex)
{
  return os << ex.msg_;
}


}// end of namespace themis


#endif
