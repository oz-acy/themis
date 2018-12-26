/*************************************************************************//**
 *
 *  @file listen.h
 *  @author oZ/acy (名賀月晃嗣)
 *  @brief Observerパターンに基づくイベントドリブン機構の基底クラス一式
 *  @date 2016.8.10
 *    Talker<E_>::changed() を Talker<E_>::notify() に變更、其の他修正
 *  @date 2018.12.26
 *    拔本的修正
 *//*
 *  (c) 2001-2018 oZ/acy. ALL RIGHTS RESERVED.
 */
#ifndef INC_THEMIS_LISTENER_H___
#define INC_THEMIS_LISTENER_H___

#include <list>
#include <algorithm>
#include <boost/utility.hpp>

namespace themis
{
  template<class E_> class Listener;
  template<class E_> class Talker;
}


/**
 * @brief イベントE_をTalker<E_>から通知されて處理するクラスの基底
 */
template<class E_>
class themis::Listener : boost::noncopyable
{
  friend class themis::Talker<E_>;

private:
  themis::Talker<E_>* tkr_;

public:
  /// デフォルト構築子
  constexpr Listener() noexcept : tkr_(nullptr) {}

  /// 解體子
  virtual ~Listener()
  {
    if (tkr_)
      tkr_->remove(this);
  }

  /// @brief 更新(イベント通知)
  ///
  /// Talkerからイベントeを實引數として呼び出される。
  /// 處理内容は派生クラスで實裝する。
  virtual void update(const E_&) =0;

private:
  /**
   *  @brief Talkerの設定
   *
   *  Talkerが己をadd()したときに、その通知を受け、連結を形成する。
   */
  void setTalker__(themis::Talker<E_>* t)
  {
    if (tkr_)
      tkr_->remove(this);
    tkr_ = t;
  }

  /**
   *  @brief Talker除去
   *
   *  Talkerが己をremove()したときに、その通知を受け、連結を切斷する。
   */
  void removeFromTalker__()
  {
    tkr_ = nullptr;
  }
};


/**
 * @brief イベント E_ を Listener<E_> に一齊通知するクラスの基底
 */
template<class E_>
class themis::Talker : boost::noncopyable
{
private:
  std::list<themis::Listener<E_>*> lsns_; ///< 通知對象のListenerのリスト

public:
  /// @brief デフォルト構築子
  constexpr Talker() noexcept {}

  /// @brief 解體子
  virtual ~Talker()
  {
    for (auto it = lsns_.begin(); it != lsns_.end(); it++)
      (*it)->removeFromTalker__();
  }


  /**
   *  @brief リスナーlsnをイベント通知對象に追加
   */
  void add(themis::Listener<E_>* lsn)
  {
    auto it = std::find(lsns_.begin(), lsns_.end(), lsn);
    if (it == lsns_.end()) {
      lsns_.push_back(lsn);
      lsn->addToTalker__(this);
    }
  }


  /**
   * @brief リスナーlsnをイベント通知對象から除去
   */
  void remove(themis::Listener<E_>* lsn)
  {
    auto it = std::find(lsns_.begin(), lsns_.end(), lsn);
    if (it != lsns_.end())
    {
      (*it)->removeFromTalker__();
      lsns_.erase(it);
    }
  }

  /**
   * @brief イベント通知
   *
   * イベントeを通知對象のリスナー全てに通知する。
   */
  void notify(const E_& e)
  {
    for (auto it = lsns_.begin(); it != lsns_.end(); it++)
      (*it)->update(e);
  }
};




#endif // INC_THEMIS_LISTENER_H___
