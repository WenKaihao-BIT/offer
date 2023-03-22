//
// Created by Q on 2023/3/6.
//

#ifndef OFFER_STRBLOBPTR_H
#define OFFER_STRBLOBPTR_H

#include <memory>
#include "iostream"
#include "vector"
#include "StrBlob.h"
class StrBlobPtr{
public:

    StrBlobPtr():curr(0){ }
//    StrBlobPtr(StrBlob &a,size_t sz=0):
//            wptr(a.data),curr(sz){}




private:
    std::shared_ptr<std::vector<std::string>>check(std::size_t,const std::string&)const;
    std::weak_ptr<std::vector<std::string >>wptr;
    std::size_t curr;
    std::vector<StrBlob>data;
};




#endif //OFFER_STRBLOBPTR_H
