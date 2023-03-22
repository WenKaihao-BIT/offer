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
template<typename C>
void print(const C &c){
    for(auto i=c.begin();i!=c.end();i++)
        cout<<*i<<" ";
    cout<<endl;

}
void f(int &v1,int &v2){
   cout<<++v1<<' '<<++v2 <<endl;
}
void g(int &&i,int & j){
    cout<<i<<" "<<j<<endl;
}
template<typename  F,typename T1,typename T2>
void flip2(F f,T1 &&t1,T2 &&t2){
    f(t2,t1);
}

template<typename T>
string debug_rep(const T &t){
    ostringstream ret;
    ret<<t;
    return ret.str();
}
template <typename T>
string debug_rep(T*p){
    ostringstream ret;
    ret << "pointer: "<<p<<endl;
    if(p)
        ret<<" "<<debug_rep(*p);
    else
        ret<<" null pointer";
    return ret.str();
}





















#endif //OFFER_TEMPLATE_TEST_H
