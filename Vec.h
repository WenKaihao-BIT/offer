//
// Created by Q on 2023/3/17.
//

#ifndef OFFER_VEC_H
#define OFFER_VEC_H
#include "iostream"
#include "memory"
template<typename T>class Vec{
public:
    Vec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    Vec(const Vec &);//拷贝构造函数
    Vec & operator = (const Vec &);//拷贝赋值运算符
    ~Vec(){free();};//析构函数
    void push_back(const T &);//拷贝元素
    size_t size() const {return first_free-elements;}
    size_t capacity()const {return cap-elements;}
    T *begin() const {return elements;}
    T *end() const {return first_free;}
    Vec & operator=(std::initializer_list<T>il);
    T  & operator[](std::size_t n){return elements[n];}
    const T & operator[](std::size_t n) const {return elements[n];}



private:
    static std::allocator<T>alloc;
    void chk_n_alloc(){if(size()==capacity())reallocate();};
    std::pair<T*,T*>alloc_n_copy(const T*,const T*);
    void free();
    void reallocate();
    T *elements,*first_free,*cap;
};

template<typename T>
Vec<T>::Vec(const Vec &s) {
    auto newdata = alloc_n_copy(s.begin().s.end());
    free();
    elements=newdata.first;
    first_free=cap=newdata.second;


}

template<typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
    auto data= alloc_n_copy(rhs.begin(),rhs.end());
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}

template<typename T>
void Vec<T>::free() {
    for(auto i=first_free;i!=elements;)
        alloc.template destroy(--i);
    alloc.deallocate(elements,cap-elements);
}

template<typename T>
void Vec<T>::push_back(const T &s) {
    chk_n_alloc();
    alloc.template construct(first_free++,s);
}

template<typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il) {
    auto data= alloc_n_copy(il.begin(),il.end());
    elements = data.first;
    first_free = cap=data.second;
    return *this;
}

template<typename T>
std::pair<T *, T *> Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}

template<typename T>
void Vec<T>::reallocate() {
    auto newcapacity = size()?2*size():1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem =elements;
    for(size_t i=0;i!=size();++i)
        alloc.construct(dest++,std::move(*elements++));
    free();
    elements=newdata;
    first_free=dest;
    cap=elements+newcapacity;

}

#endif //OFFER_VEC_H
