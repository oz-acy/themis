/**************************************************************************
 *
 *  strconv_tolower.cpp
 *  by oZ/acy
 *  (c) 2009 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  ����
 *    4 Apr MMIX  �쐬
 *   16 Apr MMIX  �C��
 *   13 Nov MMIX  �C��
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
