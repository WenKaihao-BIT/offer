//
// Created by Q on 2023/3/30.
//

#ifndef OFFER_SALES_DATA_ERROR_H
#define OFFER_SALES_DATA_ERROR_H
#include "iostream"
/** region ## isbn_mismatch ## */
class isbn_mismatch:public std::logic_error{
public:
    explicit isbn_mismatch(const std::string &s):
            std::logic_error(s){}
    isbn_mismatch(const std::string &s,const std::string &lhs,const std::string &rhs):
            std::logic_error(s),left(lhs),right(rhs){}
    const std::string left,right;
};
/** endregion */
/** region ## out of stock ## */
class out_of_stock:public std::runtime_error{
public:
    explicit out_of_stock(const std::string &s):
            std::runtime_error(s){}
};
/** endregion */
#endif //OFFER_SALES_DATA_ERROR_H
