/**************************************************************************
 *
 *  strconv.h
 *  by oZ/acy
 *  (c) 2009-2014 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  •¶š—ñÌŠ·ˆê®
 *
 *  —š—ğ
 *    4 Apr MMIX  ì¬
 *    6 Apr MMIX  C³
 *    7 Nov MMIX  C³
 *    9 Nov MMIX  C³
 *   14 Nov MMIX  C³
 *   25 Jan MMXIV  C³
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




}//end of namespace themis


#endif
