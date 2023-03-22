//
// Created by Q on 2023/3/4.
//

#ifndef OFFER_STRVEC_H
#define OFFER_STRVEC_H
#include "iostream"
#include "memory"
class StrVec{
public:
    StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec &);//拷贝构造函数
    StrVec & operator = (const StrVec &);//拷贝赋值运算符
    ~StrVec();//析构函数
    void push_back(const std::string &);//拷贝元素
    size_t size() const {return first_free-elements;}
    size_t capacity()const {return cap-elements;}
    std::string *begin() const {return elements;}
    std::string *end() const {return first_free;}
    StrVec & operator=(std::initializer_list<std::string>il);
    std::string  & operator[](std::size_t n){return elements[n];}
    const std::string & operator[](std::size_t n) const {return elements[n];}

    template<class ...Args>
    void emplace_back(Args&&...);

private:
    static std::allocator<std::string>alloc;
    void chk_n_alloc(){if (size()==capacity()) reallocate();}
    std::pair<std::string*,std::string*>alloc_n_copy(const std::string*,const std::string*);
    void free();
    void reallocate();
    std::string *elements,*first_free,*cap;

};
std::allocator<std::string> StrVec::alloc;
void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++,s);
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(const std::string *b, const std::string *e) {

    auto data=alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}

void StrVec::free() {
    if(elements){
        for(auto p=first_free;p!=elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements,cap-elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements=newdata.first;
    first_free=cap=newdata.second;
}
StrVec::~StrVec() {free();}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements=data.first;
    first_free=cap=data.second;
    return *this;
}
// 采用 移动构造函数，避免拷贝
void StrVec::reallocate() {
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

StrVec &StrVec::operator=(std::initializer_list<std::string> il) {
    auto data = alloc_n_copy(il.begin(),il.end());
    free();
    elements = data.first;
    first_free=cap=data.second;
    return *this;
}

template<class... Args>
inline
void StrVec::emplace_back(Args &&...args) {
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}

#endif //OFFER_STRVEC_H
