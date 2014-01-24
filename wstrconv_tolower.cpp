/**************************************************************************
 *
 *  wstrconv_tolower.cpp
 *  by oZ/acy
 *  (c) 2009 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  ����
 *    4 Apr MMIX  �쐬
 *    6 Apr MMIX  �C��
 *   16 Apr MMIX  �C��
 *   13 Nov MMIX  �C��
 */
#include "strconv.h"
#include <cwctype>

std::wstring themis::StringConverter::toLower(const std::wstring& s)
{
  using namespace std;

  std::wstring r = s;
  std::wstring::iterator i = r.begin();
  while (i != r.end())
  {
    *i = towlower(*i);
    ++i;
  }
  return r;
}

//eof
