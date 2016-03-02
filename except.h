/**************************************************************************
 *
 *  except.h
 *  by oZ/acy
 *  (c) 2001-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  EXCEPTion information container
 *  例外情報格納クラスヘッダー
 *
 *  履歴
 *    2016.3.2  C++11對應
 *************************************************************************/
#ifndef INC_THEMIS_EXCEPT_H__
#define INC_THEMIS_EXCEPT_H__

#include <string>
#include <iostream>
#include <exception>

namespace themis
{

/*---------------------------------------------------------------------------
*  class EmptyException
*  空の例外クラス
*  part "THEMIS" での例外はこのクラス(or 派生クラス)のインスタンスたるべし
*--------------------------------------------------------------------------*/
class EmptyException : public std::exception
{
public:
  EmptyException() noexcept {}
  virtual ~EmptyException() noexcept {}

  virtual const char* what() const noexcept
  {
    static const char rstr[] = "themis::EmptyException";
    return rstr;
  }
};




/*------------------------------------------
*  class Exception
*  メッセージ文字列を持つ例外クラス
*  std::ostream への出力も可能
*-----------------------------------------*/
class Exception;
std::ostream& operator<<(std::ostream& os, const Exception& ex);

class Exception : public EmptyException
{
  friend std::ostream&
         themis::operator<<(std::ostream& os, const Exception& ex);

protected:
  std::string msg_;

public:
  Exception() noexcept {}
  Exception(const std::string& m) : msg_(m) {}

  Exception(const std::string& c, const std::string& f, const std::string& w)
  {
    msg_ = c + "::" + f + " : " + w;
  }

  ~Exception() throw () {}

  const char* what() const noexcept
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


#endif
