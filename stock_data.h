#ifndef _STOCK_DATA_H_
#define _STOCK_DATA_H_

#include "stock_data_descriptor.h"

#include<string.h>

namespace stock {

class StockDataBase {
 public:
  virtual const StockDataDescriptorBase* GetDescriptor() const = 0;
};  // class StockDataBase

template <typename T>
class  StockData : public StockDataBase {
 public:
  StockData() {
  }

  static const StockDataDescriptor<T>* descriptor() {
    return descriptor_;
  }

  virtual const StockDataDescriptorBase* GetDescriptor() const {
    return StockData::descriptor();
  } 

  void BuffToData(const char* buff, int len) {
    descriptor_->Parse(buff, len, this);
  }

  T data_;
 private:
  friend class StockDataDescriptor<T>; 

  static bool Parse(const char* buff, int len, StockData<T>* p) {
    (void) buff;
    (void) len;
    (void) p;
    return true;
  }

  static const StockDataDescriptor<T>* descriptor_;
};  // class StockData

template <typename T>
const StockDataDescriptor<T>* StockData<T>::descriptor_;

}  // namespace stock

#endif  // _STOCK_DATA_H_ 
