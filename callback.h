#ifndef _CALLBACK_H_
#define _CALLBACK_H_

#include <functional>

#include "stock_data.h"

namespace stock {

class Callback {
 public:
  virtual void Run(const StockDataBase* data) = 0;

 private:
  virtual ~Callback() {}
};  // class StockLineCallback

template <typename T>
class CallbackT : public Callback {
 public:
  using Functor = std::function<void(const T* data)>; 

  CallbackT(Functor&& callback) : callback_(callback) {}

  void Run(const StockDataBase* data) {
    const T* p = reinterpret_cast<const T*>(data);
    callback_(p);
  }

  private:
   Functor callback_;
};  // class StockLineCallbackT

}  // namespace stock

#endif  // _CALLBACK_H_ 
