/**************************************************************************
 *
 *  strconv.cpp
 *  by oZ/acy
 *  (c) 2009-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  óöó
 *   13 Nov MMIX  çÏê¨
 *   26 Feb MMXVI  èCê≥
 */
#include <algorithm>
#include "strconv.h"

/*===========================================
 *  StringConverter::StringConverter()
 */
themis::StringConverter::StringConverter(
  const std::string& tocode, const std::string& fromcode)
{
  cv_ = iconv_open(tocode.c_str(), fromcode.c_str());
}


/*===========================================
 *  StringConverter::convert()
 */
std::string themis::StringConverter::convert(const std::string& s)
{
  using namespace std;

  size_t ilen = s.size();
  char* ibuf = new char[ilen + 1];
  copy(s.c_str(), s.c_str() + ilen + 1, ibuf);
  char* pi = ibuf;

  size_t rlen = (ilen + 1) * 2;
  char* rbuf = new char[rlen];
  fill(rbuf, rbuf + rlen, 0);
  char* pr = rbuf;

  size_t rlen2 = rlen;
  rlen2 = iconv(cv_, &pi, &ilen, &pr, &rlen2);

  string r = rbuf;

  delete[] rbuf;
  delete[] ibuf;

  return r;
}




//eof
