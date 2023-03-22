//
// Created by Q on 2023/3/15.
//

#ifndef OFFER_BLOB_H
#define OFFER_BLOB_H
#include "iostream"
#include "vector"
#include "memory"

template<typename>class BlobPtr;
template <typename T>class Blob;
template<typename T>
bool operator==(const Blob<T>&,const Blob<T>&);
template <typename T>class Blob{
public:
    friend class BlobPtr<T>;
    //定义宏
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    //构造函数
    Blob():data(make_shared<vector<T>>()){}
    //构造函数
    template<typename It>
    Blob(It b,It e):data(make_shared<vector<T>>(b,e)){}
    //构造函数-接受初始化列表
    Blob(std::initializer_list<T>il):data(make_shared<vector<T>>(il)){}
    //查询元素是否为空
    size_type size()const{return data->size();}
    bool empty()const {return data->empty();}
    //添加和删除元素
    void push_back(const T &t){data->push_back(t);}
    //移动版本
    void push_back(T &&t){data->push_back(std::move(t));}
    void pop_back();
    //访问元素
    T& back();
    T& operator[](size_type i);
    //迭代器
    auto begin(){return data->begin();}
    auto end(){return data->end();}
private:
    std::shared_ptr<std::vector<T>>data;
    void check(size_t i,const std::string &msg) const;
};

template<typename T>
void Blob<T>::check(size_t i, const string &msg) const {
    if(i>=data->size())
        throw std::out_of_range(msg);
}

template<typename T>
T &Blob<T>::back() {
    check(0,"back on empty Blob");
    return data->back();
}

template<typename T>
T &Blob<T>::operator[](Blob::size_type i) {
    check(i,"subscript out of range");
    return (*data)[i];
}

template<typename T>
void Blob<T>::pop_back() {
    check(0,"pop_back on empty Blob");
    data->pop_back();
}


#endif //OFFER_BLOB_H
