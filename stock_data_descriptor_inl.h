#ifndef _STOCK_DATA_DESCRIPTOR_INL_H_
#define _STOCK_DATA_DESCRIPTOR_INL_H_

#include "stock_data.h"
#include "stock_data_descriptor.h"

namespace stock {
template <typename T>
StockDataBase* StockDataDescriptor<T>::New(const char* buff, int len) {
  StockData<T>* p = new StockData<T>;
  if (!StockData<T>::Parse(buff, len, p)) {
    delete p; 
    p = nullptr;
  };

  return p;
}

}

#endif  // _STOCK_DATA_DESCRIPTOR_INL_H_
