//
// Created by Q on 2023/3/14.
//

#ifndef OFFER_TEMPLATE_TEST_H
#define OFFER_TEMPLATE_TEST_H
#include "iostream"
#include "string"
#include "vector"
#include "list"
#include "StrBlob.h"
using namespace std;
template <typename I,typename T>
I find2(I b,I e,const T &v){
    while(b!=e&&*b!=v)
        b++;
    return b;
}
template <typename T,size_t N>
void print(const T (&a)[N])
{
    cout<<N<<endl;
    for(auto iter = begin(a);iter !=end(a);iter++)
        cout<<*iter<<' ';
    cout<<endl;
}
template<typename T>class Foo{
public:
    static std::size_t count(){return ctr;}
private:
        static std::size_t ctr;
    };
template<typename T >
size_t Foo<T>::ctr=0;

template<typename T,typename F =less<T>>
int compare(const T&v1,const T&v2,F f=F()){
    if(f(v1,v2)) return -1;
    if(f(v2,v1))return 1;
    return 0;
}
//template<typename C>
//void print(const C &c){
//    for(typename C::size_type i=0;i<c.size();i++)
//        cout<<c.at(i)<<" ";
//    cout<<endl;
//}
template<typename C>
void print(const C &c){
    for(auto i=c.begin();i!=c.end();i++)
        cout<<*i<<" ";
    cout<<endl;

}























#endif //OFFER_TEMPLATE_TEST_H
