/**************************************************************************
*
*  manage.h
*  by oZ/acy
*  (c) 2001-2011 oZ/acy. ALL RIGHTS RESERVED.
*
*  MANAGEr/managed object  in THEMIS
*  管理・被管理オブジェクト用装備一式
*
*  last update: 2011.9.8
**************************************************************************/

#ifndef INC_THEMIS_MANAGE_H___
#define INC_THEMIS_MANAGE_H___

#include <vector>
#include <algorithm>
#include <boost/utility.hpp>


namespace themis
{
  class Managed;
  class ManagerBase;
  template<class T> class Manager;
};


/*-------------------------------
*  ManagerBase
*  管理オブジェクト基底クラス
*------------------------------*/
class themis::ManagerBase
{
  friend class themis::Managed;

protected:
  virtual void kill(themis::Managed*) =0;
  void mankill(themis::Managed*);

public:
  virtual ~ManagerBase() {}
};


/*-----------------------------------
*  Managed
*  被管理オブジェクト用基底クラス
*----------------------------------*/
class themis::Managed : boost::noncopyable
{
  friend class themis::ManagerBase;

private:
  themis::ManagerBase* mng_;

protected:
  Managed(themis::ManagerBase* m =nullptr) : mng_(m) {}

public:
  virtual ~Managed()
  {
    if(mng_)
      mng_->kill(this);
  }
};


/*----------------------------------------------------
*  Manager<T>
*  T型のオブジェクトに対する管理オブジェクトクラス
*---------------------------------------------------*/
template<class T_>
class themis::Manager : public themis::ManagerBase
{
protected:
  std::vector<T_*> a_;

  virtual void kill(themis::Managed* obj);

public:
  Manager() {}
  ~Manager();

  void add(T_* t) { a_.push_back(t); }

  template<class FNC>
  void forEach(FNC fnc) { std::for_each(a_.begin(), a_.end(), fnc); }
};



/* inline methods */
inline void themis::ManagerBase::mankill(themis::Managed* obj)
{
  obj->mng_ = nullptr;
}


template<class T_>
inline
themis::Manager<T_>::~Manager()
{
  std::vector<T_*>::iterator i;
  for(i=a_.begin(); i!=a_.end(); i++)
    mankill(*i);
}

template<class T_>
inline
void themis::Manager<T_>::kill(themis::Managed* obj)
{
  std::vector<T_*>::iterator i = std::find(a_.begin(), a_.end(), obj);
  if(i!=a_.end())
  {
    mankill(obj);
    a_.erase(i);
  }
}


#endif // INC_THEMIS_MANAGE_H___
