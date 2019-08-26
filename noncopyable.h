/***********************************************************************//**
 *
 *  @file noncopyable.h
 *  @author oZ/acy(名賀月晃嗣)
 *  @brief コピー禁止クラステンプレート
 *  @date 2019.8.26 新規作成
 */

#ifndef INCLUDE_GUARD_THEMIS_NONCOPYABLE_H
#define INCLUDE_GUARD_THEMIS_NONCOPYABLE_H


namespace themis
{

/**
 *  @brief コピー禁止
 *
 *  コピー禁止とするクラスのprivate基底とするためのクラステンプレート。
 *  class Tをコピー禁止にするとき、
 *  boost::noncopyableの代はりにNoncopyable<T>を用ゐればよい。
 */
template<class T>
class Noncopyable
{
public:
  constexpr Noncopyable() = default;
  ~Noncopyable() = default;
  Noncopyable(const Noncopyable&) = delete;
  Noncopyable& operator=(const Noncopyable&) = delete;
};


}//end of namespace themis


#endif // INCLUDE_GUARD_THEMIS_NONCOPYABLE_H
