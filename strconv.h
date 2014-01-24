/**************************************************************************
 *
 *  strconv.h
 *  by oZ/acy
 *  (c) 2009 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  ������̊��ꎮ
 *
 *  ����
 *    4 Apr MMIX  �쐬
 *    6 Apr MMIX  �C��
 *    7 Nov MMIX  �C��
 *    9 Nov MMIX  �C��
 *   14 Nov MMIX  �C��
 */
#ifndef INC_STRING_CONV_H_
#define INC_STRING_CONV_H_

#include <string>
#include <iconv.h>


#if !defined(HAVE_STD_WSTRING)
namespace std {
typedef basic_string<wchar_t> wstring;
}
#endif


namespace themis{

class StringConverter
{
private:
  iconv_t cv_;

public:
  StringConverter(const std::string& tocode, const std::string& fromcode);
  ~StringConverter() { iconv_close(cv_); }

  std::string convert(const std::string& src);

  static std::string toLower(const std::string& s);
  static std::wstring toLower(const std::wstring& ws);
};

std::string toLower(const std::string& s);
std::wstring toLower(const std::wstring& ws);


}//end of namespace themis


#endif
