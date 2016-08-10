/**************************************************************************
 *
 *  listen.h
 *  by oZ/acy
 *  (c) 2001-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  イベントドリブン機構基底一式
 *  Observerパターンに基づく
 *
 *  2016.8.10  Talker<E_>::changed() を Talker<E_>::notify() に變更
 *             其の他修正
 *************************************************************************/

#ifndef INC_THEMIS_LISTENER_H___
#define INC_THEMIS_LISTENER_H___

#include <vector>
#include <algorithm>
#include <boost/utility.hpp>

namespace themis
{
  template<class E_> class Listener;
  template<class E_> class Talker;
}


/*---------------------------------------------------------------
 *  Listener<E_>
 *  イベント E_ をTalker<E_>から通知されて處理するクラスの基底
 */
template<class E_>
class themis::Listener : boost::noncopyable
{
  friend class themis::Talker<E_>;

private:
  typedef themis::Talker<E_> T_;

private:
  std::vector<T_*> tkr_;

public:
  constexpr Listener() noexcept {}

  virtual ~Listener()
  {
    //std::vector<T_*>::iterator it;
    for (auto it = tkr_.begin(); it != tkr_.end(); it++)
      (*it)->remove(this);
  }

  virtual void update(const E_&) =0;

private:
  /*
   *  tkr_ から t を取り除く
   *  Talker<E_>::remove()から呼ばれる
   */
  void removeFromTalker__(T_* t)
  {
    //std::vector<T_*>::iterator it = std::find(tkr_.begin(),tkr_.end(),t);
    auto it = std::find(tkr_.begin(), tkr_.end(), t);
    if(it != tkr_.end())
      tkr_.erase(it);
  }
};


/*---------------------------------------------------------------
 * Talker<E_>
 * イベント E_ を Listener<E_> に一齊通知するクラスの基底
 * 通知對象の Listener<E_> は豫め Talker<E_> に add() される
 */
template<class E_>
class themis::Talker : boost:noncopyable
{
private:
  typedef class themis::Listener L_;

private:
  std::vector<L_*> lsns_;

public:
  constexpr Talker() noexcept {}

  virtual ~Talker()
  {
    //std::vector<L_*>::iterator it;
    for (auto it = lsns_.begin(); it != lsns_.end(); it++)
      (*it)->removeFromTalker__(this);
  }


  /*===================================================
   *  add()
   *  リスナー lsn をイベント通知對象に加へる
   */
  void add(L_* lsn)
  {
    //std::vector<L_*>::iterator it;
    auto it = std::find(lsns_.begin(), lsns_.end(), lsn);
    if (it == lsns_.end())
      lsns_.push_back(lsn);
  }


  /*===================================================
   *  remove()
   *  リスナー lsn をイベント通知對象から削る
   */
  void remove(L_* lsn)
  {
    //std::vector<L_*>::iterator it;
    auto it = std::find(lsns_.begin(), lsns_.end(), lsn);
    if (it != lsns_.end())
    {
      (*it)->removeFromTalker__(this);
      lsns_.erase(it);
    }
  }

  /*===================================================
   *  notify()
   *  イベント e をリスナーに一齊通知する
   */
  void notify(const E_& e)
  {
    //std::vector<L_*>::iterator it;
    for (auto it = lsns_.begin(); it != lsns_.end(); it++)
      (*it)->update(e);
  }
};




#endif // INC_THEMIS_LISTENER_H___
