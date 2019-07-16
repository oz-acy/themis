/**************************************************************************
 *
 *  wstrconv_tolower.cpp
 *  by oZ/acy
 *  (c) 2009 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  履歴
 *    4 Apr MMIX  作成
 *    6 Apr MMIX  修正
 *   16 Apr MMIX  修正
 *   13 Nov MMIX  修正
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
