#ifndef _STOCK_DATA_DESCRIPTOR_H_
#define _STOCK_DATA_DESCRIPTOR_H_

namespace stock {

template <typename T>
class StockData;
class StockDataBase;

class StockDataDescriptorBase {
 public:
  virtual ~StockDataDescriptorBase() {}

  virtual StockDataBase* New(const char* buff, int len) = 0;
  virtual const char* name() = 0;
};  // class Descriptor

template <typename T>
class StockDataDescriptor : public StockDataDescriptorBase { 
 public: 
  virtual ~StockDataDescriptor() {}

  virtual StockDataBase* New(const char* buff, int len); 
  virtual const char* name() {
    return data_name_;
  } 

 private:
  friend class StockData<T>;

  static const char* mark_name_ ;
  static const char* data_name_;
};  // class StockDataDescriptor

}  // namespace stock

#endif  // _STOCK_DATA_DESCRIPTOR_H_
