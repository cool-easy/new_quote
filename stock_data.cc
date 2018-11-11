#include "stock_data.h"

#include <map>

#include "data.h"
#include "stock_data_descriptor.h"
#include "stock_data_descriptor_inl.h"

namespace stock {


template <>
const char* StockDataDescriptor<ShangHai>::mark_name_ = "M001";

template <>
const char* StockDataDescriptor<ShangHai>::data_name_ = "shanghai";

template <>
const StockDataDescriptor<ShangHai>*
    StockData<ShangHai>::descriptor_ = new StockDataDescriptor<ShangHai>;

std::map<std::string, const StockDataDescriptorBase*> descriptor_set;

}  // namespace stock
