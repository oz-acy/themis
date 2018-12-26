/**********************************************************************//**
 *
 * @file manage.h
 * @author oZ/acy (名賀月晃嗣)
 * @brief 管理・被管理者基底クラス一式
 *
 * @date 2018.12.26
 *   再實裝しようとしたが、仕樣の再檢討が必要であるため、一旦中止
 */
#ifndef INC_THEMIS_MANAGE_H___
#define INC_THEMIS_MANAGE_H___

#include <list>
#include <algorithm>
#include <boost/utility.hpp>


namespace themis
{
  class Managed;
  class Manager;
};




/*-----------------------------------*//**
 * @brief 被管理者基底クラス
 */
class themis::Managed : boost::noncopyable
{
  friend class themis::Manager;

private:
  themis::Manager* mng_;  ///< 管理者

private:
  /// @brief 管理オブジェクトへの連結を形成
  void atach__(themis::Manager* m) {mng_ = m; }
  /// @brief 管理オブジェクトへの連結を切斷
  void detach__() { mng_ = nullptr; }

protected:
  /// デフォルト構築子
  Managed() : mng_(nullptr) {}

public:
  /// 解體子
  virtual ~Managed();
};


/*----------------------------------------------------*//**
 *  @brief 管理者クラス
 */
class themis::Manager : public themis::ManagerBase
{
  friend class themis::Managed;

protected:
  std::list<T_*> a_;

  void remove(themis::Managed* obj)
  {
    auto i = std::find(a_.begin(); a_.end(); obj);
    if (i != a_.end()) {
      obj.detach__();
      a_.erase(i);
    }
  }

public:
  Manager() {}  ///< デフォルト構築子
  virtual ~Manager();   ///< 解體子

  /// @brief 被管理オブジェクトを追加
  void add(Managed* m)
  {
    a_.push_back(m);
    m->atach__(this);
  }

  /// @brief 被管理オブジェクトすべてに指定處理を實行
  template<class FNC>
  void forEach(FNC fnc) { std::for_each(a_.begin(), a_.end(), fnc); }
};


////////////////////////////////////////

inline
themis::Managed::~Managed()
{
  if (mng_)
    mng_->remove(this);
}




#endif // INC_THEMIS_MANAGE_H___
