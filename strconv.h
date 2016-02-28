/**************************************************************************
 *
 *  strconv.h
 *  by oZ/acy
 *  (c) 2009-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  ������̊��ꎮ
 *
 *  ����
 *    4 Apr MMIX  �쐬
 *    6 Apr MMIX  �C��
 *    7 Nov MMIX  �C��
 *    9 Nov MMIX  �C��
 *   14 Nov MMIX  �C��
 *   25 Jan MMXIV  �C��
 *   26 Feb MMXVI  �C��
 */
#ifndef INC_STRING_CONV_H_
#define INC_STRING_CONV_H_

#include <string>
#include <iconv.h>


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
