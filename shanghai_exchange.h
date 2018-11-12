#ifndef _SHANGHAI_EXCHANGE_H_
#define _SHANGHAI_EXCHANGE_H_

#include <functional>

#include "data.h"
#include "stock_line.h"

namespace stock {

template <typename T>
class StockData;

class ShangHaiExchange {
 public:
  ShangHaiExchange() {
    stock_line_.RegisterCallback<StockData<ShangHai>>(std::bind(&ShangHaiExchange::ShangHaiLine,
			                   this,
					   std::placeholders::_1));
  }

  void ShangHaiLine(const StockData<ShangHai>* data) {
    (void)data;
  }

 private:
  StockLine stock_line_;
};  // class ShangHaiExchange

}  // namespace stock

#endif  // _SHANGHAI_EXCHANGE_H_
