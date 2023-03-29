//
// Created by Q on 2023/3/29.
//

#ifndef OFFER_TRY_TEST_H
#define OFFER_TRY_TEST_H
#include "Blob.h"
#include "iostream"
#include "exception"
template<typename T>
class Blob2{
public:
    Blob2(std::initializer_list<T>il);
private:
    std::shared_ptr<std::vector<T>>data;
};

template<typename T>
Blob2<T>::Blob2(std::initializer_list<T>il)try :data(std::make_shared<std::vector<T>>(il)){}
catch(const std::bad_alloc &e){std::cout<<"error"<<std::endl;}

void f()noexcept{
    throw std::exception();
}
#endif //OFFER_TRY_TEST_H
