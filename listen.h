/**************************************************************************
*
*  listen.h
*  by oZ/acy
*  (c) 2001-2008 oZ/acy. ALL RIGHTS RESERVED.
*
*  イベントドリブン機構基底一式
*
*  last update: 2008.4.26
**************************************************************************/

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


/*-------------------
 *  Listener<E_>
 *-----------------*/
template<class E_>
class themis::Listener : boost::noncopyable
{
  friend class themis::Talker<E_>;

private:
  typedef themis::Talker<E_> T_;

private:
  std::vector<T_*> tkr_;

public:
  Listener() {}

  virtual ~Listener()
  {
    std::vector<T_*>::iterator it;
    for(it=tkr_.begin(); it!=tkr_.end(); it++)
      (*it)->remove(this);
  }

  virtual void update(const E_&) =0;

private:
  void removeTalker__(T_* t)
  {
    std::vector<T_*>::iterator it = std::find(tkr_.begin(),tkr_.end(),t);
    if(it!=tkr_.end())
      tkr_.erase(it);
  }
};


/*---------------
   Talker<E_>
---------------*/
template<class E_>
class themis::Talker : boost:noncopyable
{
private:
  typedef class themis::Listener L_;

private:
  std::vector<L_*> lsns_;

public:
  Talker() {}

  virtual ~Talker()
  {
    std::vector<L_*>::iterator it;
    for (it=lsns_.begin(); it!=lsns_.end(); it++)
      (*it)->removeTalker__(this);
  }


  void add(L_* lsn)
  {
    std::vector<L_*>::iterator it;

    it = std::find(lsns_.begin(), lsns_.end(), lsn);
    if (it==lsns_.end())
      lsns_.push_back(lsn);
  }

  void remove(L_* lsn)
  {
    std::vector<L_*>::iterator it;

    it = std::find(lsns_.begin(), lsns_.end(), lsn);
    if (it!=lsns_.end())
    {
      (*it)->removeTalker__(this);
      lsns_.erase(it);
    }
  }

  void changed(const E_& e)
  {
    std::vector<L_*>::iterator it;
    for (it=lsns_.begin(); it!=lsns_.end(); it++)
      (*it)->update(e);
  }
};


#endif // INC_THEMIS_LISTENER_H___
