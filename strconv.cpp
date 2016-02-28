/**************************************************************************
 *
 *  strconv.cpp
 *  by oZ/acy
 *  (c) 2009-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  óöó
 *   13 Nov MMIX  çÏê¨
 *   28 Feb MMXVI  èCê≥
 */

#include <algorithm>
#include <memory>
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
  unique_ptr<char[]> ibuf(new char[ilen + 1]);

  copy(s.c_str(), s.c_str() + ilen + 1, ibuf.get());
  char* pi = ibuf.get();

  size_t rlen = (ilen + 1) * 2;
  unique_ptr<char[]> rbuf(new char[rlen]); 
  fill(rbuf.get(), rbuf.get() + rlen, 0);
  char* pr = rbuf.get();

  size_t rlen2 = rlen;
  rlen2 = iconv(cv_, &pi, &ilen, &pr, &rlen2);

  return string(rbuf.get());
}




//eof
