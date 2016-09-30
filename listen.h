/**************************************************************************
 *
 *  listen.h
 *  by oZ/acy
 *  (c) 2001-2016 oZ/acy. ALL RIGHTS RESERVED.
 *
 *  �C�x���g�h���u���@�\���ꎮ
 *  Observer�p�^�[���Ɋ�Â�
 *
 *  2016.8.10  Talker<E_>::changed() �� Talker<E_>::notify() �ɝ̍X
 *             ���̑��C��
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
 *  �C�x���g E_ ��Talker<E_>����ʒm����ę|������N���X�̊��
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
   *  tkr_ ���� t ����菜��
   *  Talker<E_>::remove()����Ă΂��
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
 * �C�x���g E_ �� Listener<E_> �Ɉ�ꎒʒm����N���X�̊��
 * �ʒm���ۂ� Listener<E_> �͘��� Talker<E_> �� add() �����
 */
template<class E_>
class themis::Talker : boost::noncopyable
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
   *  ���X�i�[ lsn ���C�x���g�ʒm���ۂɉ��ւ�
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
   *  ���X�i�[ lsn ���C�x���g�ʒm���ۂ�����
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
   *  �C�x���g e �����X�i�[�Ɉ�ꎒʒm����
   */
  void notify(const E_& e)
  {
    //std::vector<L_*>::iterator it;
    for (auto it = lsns_.begin(); it != lsns_.end(); it++)
      (*it)->update(e);
  }
};




#endif // INC_THEMIS_LISTENER_H___
