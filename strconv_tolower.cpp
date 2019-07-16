/**************************************************************************
 *
 *  strconv_tolower.cpp
 *  by oZ/acy
 *  (c) 2009 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  履歴
 *    4 Apr MMIX  作成
 *   16 Apr MMIX  修正
 *   13 Nov MMIX  修正
 */
#include "strconv.h"
#include <cctype>

std::string themis::StringConverter::toLower(const std::string& s)
{
  std::string r = s;
  std::string::iterator i = r.begin();
  while (i != r.end())
  {
    *i = std::tolower(*i);
    ++i;
  }
  return r;
}

//eof
