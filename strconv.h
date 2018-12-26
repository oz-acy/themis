/**********************************************************************//**
 *
 *  @file strconv.h
 *  @author oZ/acy (名賀月晃嗣)
 *  @brief 文字列變換
 *
 *  @date  4 Apr MMIX  作成
 *  @date  6 Apr MMIX  修正
 *  @date  7 Nov MMIX  修正
 *  @date  9 Nov MMIX  修正
 *  @date 14 Nov MMIX  修正
 *  @date 25 Jan MMXIV  修正
 *  @date 26 Feb MMXVI  修正
 *//*  
 *  (c) 2009-2016 oZ/acy. ALL RIGHTS RESERVED.
 */
#ifndef INC_STRING_CONV_H_
#define INC_STRING_CONV_H_

#include <string>
#include <iconv.h>


namespace themis{

/**
 * @brief 文字列變換クラス
 */
class StringConverter
{
private:
  iconv_t cv_;

public:
  /// @brief 構築子
  ///
  /// fromcodeからtocodeに變換する文字列變換オブジェクトを構築する。
  /// コード名はiconv_open()に與へるもの。
  /// 例へばUTF-8、SHIFT-JIS、SHIFT_JIS、EUC-JP、EUCJP、ISO-2022-JPなど。
  /// @param tocode 變換先コード名
  /// @param fromcode 變換元コード名
  StringConverter(const std::string& tocode, const std::string& fromcode);

  /// 解體子
  ~StringConverter() { iconv_close(cv_); }

  /// @brief 文字列の變換
  ///
  /// 文字列srcを文字コード變換した文字列を取得する。
  std::string convert(const std::string& src);

  /// @brief 小文字變換
  ///
  /// 文字列sのうち英字大文字を英字小文字に置換した文字列を取得する。
  static std::string toLower(const std::string& s);
  /// @brief 大文字變換
  ///
  /// 文字列sのうち英字小文字を英字大文字に置換した文字列を取得する。
  static std::wstring toLower(const std::wstring& ws);
};


}//end of namespace themis


#endif
