#ifndef _STOCK_LINE_H_
#define _STOCK_LINE_H_

#include "stock_type.h"

#include <functional>
#include <map>
#include <memory> 

#include "callback.h"
#include "stock_data.h"

namespace stock {

class StockDataDescriptorBase;
class StockDataBase;

class StockLine {
 public:
  using CallbackSet = std::map<const StockDataDescriptorBase*, Callback*>;

  template <typename T>
  void RegisterCallback(typename CallbackT<T>::Functor&& functor) {
    callback_set_[T::descriptor()] = new CallbackT<T>(std::move(functor));
  }

  void Run(const StockDataBase* data) {
    (void)data;
//    callback_set_[data->GetDescriptor()](data);
  } 

 private:
  CallbackSet callback_set_;

  std::map<StockDataDescriptorBase*, StockDataBase*> pre_stock_data_set_;
};  // class StockLine

}  // namespace stock 

#endif  // _STOCK_LINE_H_
