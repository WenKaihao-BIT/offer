//
// Created by Q on 2023/3/20.
//

#ifndef OFFER_SP_H
#define OFFER_SP_H

#include <functional>
#include "iostream"
using namespace std;
template<typename T>
class SP{
public:
    SP():p(nullptr),use(nullptr){}
    explicit SP(T*pt):p(pt),use(new size_t(1)){}
    SP(const SP &sp):
        p(sp.p),use(sp.use){if(use) ++*use;}
    SP & operator=(const SP&);
    ~SP();
    T& operator*(){return *p;}
    T&operator*() const{return *p;}
private:
    T *p;
    size_t *use;
    std::function<void(T*)>deleter;

};

template<typename T>
SP<T> &SP<T>::operator=(const SP &rhs) {
    if(rhs.use)
        ++*rhs.use;
    if(use&&--*use==0){
        delete p;
        delete use;
    }
    p=rhs.p;
    use=rhs.use;
    return *this;
}

template<typename T>
SP<T>::~SP() {
    if(use&&--*use==0){
        delete p;
        delete use;
    }
}

#endif //OFFER_SP_H
