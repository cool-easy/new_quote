#ifndef _SHANGHAI_EXCHANGE_H_
#define _SHANGHAIS_EXCHANGE_H_

#include <functional>

#include "data.h"
#include "stock_line.h"

namespace stock {

void func() {}

template <typename T>
class StockData;

class ShangHaiExchange {
 public:
  ShangHaiExchange() {
    std::function<void(const StockData<ShangHai>*)> p = std::bind(&ShangHaiExchange::ShangHaiLine,
		                                                 this,
								 nullptr);
    stock_line_.RegisterCallback(std::bind(&ShangHaiExchange::ShangHaiLine, this, nullptr));
  }

  void ShangHaiLine(const StockData<ShangHai>* data) {
    (void)data;
  }

 private:
  StockLine stock_line_;
};  // class ShangHaiExchange

}  // namespace stock

#endif  // _SHANGHAI_EXCHANGE_H_
