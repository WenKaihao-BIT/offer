//
// Created by Q on 2023/3/14.
//

#ifndef OFFER_TEMPLATE_TEST_H
#define OFFER_TEMPLATE_TEST_H

#include <cstring>
#include <regex>
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

template<unsigned N,unsigned M>
int compare(const char (&p1)[N],const char (&p2)[M]){
    return strcmp(p1,p2);
}

template<typename T> int compare(const T&,const T&);
//compare 的特殊版本
template<>
int compare(const char* const&p1,const char * const &p2){
    return strcmp(p1,p2);
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

template <typename T>string debug_rep(T*p);
string debug_rep(const string &s){
    return '"'+s+'"';
}
//string debug_rep(char *p){
//    return debug_rep(string(p));
//}
//string debug_rep(const char *p){
//    return debug_rep(string(p));
//}
//特例化版本
template<>string debug_rep(char *p){
    return debug_rep(string(p));
}
template<>string debug_rep(const char*cp){
    return debug_rep(string(cp));
}
//可变参数模板
template<typename T,typename...Args >
void foo(const T &t,const Args...rest){
    cout<<sizeof...(Args)<<endl;
    cout<<sizeof...(rest)<<endl;
}

template<typename T>
ostream &print(ostream &os,const T&t){
    return os<<t;
}

template<typename T,typename ...Args>
ostream &print(ostream &os,const T &t,const Args...rest){
    os<<t<<",";
    return print(os,rest...);
}

template<typename ...Args>
ostream &errorMsg(ostream &os,const Args&...rest){
    return print(os, debug_rep(rest)...);
}

template<class T>struct remove_reference2{
//    remove_reference2(){std::cout<<"初始模板"<<std::endl;}
    typedef T type;
};
template<class T>struct remove_reference2<T&>{
//    remove_reference2(){std::cout<<"模板1"<<std::endl;}
    typedef T type;
};
template<class T>struct remove_reference2<T&&>{
//    remove_reference2(){std::cout<<"模板2"<<std::endl;}
    typedef T type;
};
template<typename T>struct Foo2{
    Foo2(const T&t=T()):mem(t){}
    void Bar(){cout<<"Bar"<<endl;}
    T mem;
};
template<>//特例化模板
void Foo2<int>::Bar() { //特例化成员函数
    cout<<"Bar-int"<<endl;
}
//无法将C字符串匹配，因此要特例
template<typename T>
size_t check_count(const std::vector<T>&v,const T& target){
    size_t count=0;
    for(auto i=v.begin();i!=v.end();i++)
        if(*i==target)
            count++;
    return count;
}
template<>
size_t check_count(const std::vector<char*>&v,char* const &target){
    size_t count=0;
    for(auto item :v)
        if(!strcmp(item,target))
            count++;
    return count;
}
size_t check_count(const std::vector<string>&v,char* target){
    size_t count=0;
    for(const auto & i : v)
        if(i==string (target))
            count++;
    return count;
}
/** region ## 正则化 ## */
void test_region2() {
    string file = {"receipt freind theif receive"};
    cout << file << endl;
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern, regex::icase);
    for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
        auto pos = it->prefix().length();
        pos = pos > 40 ? pos - 40 : 0;
        cout << it->prefix().str().substr(pos) << "\t>>>" << it->str() << " <<<\t" << it->suffix().str().substr(0, 40)
             << endl;

    }
}
void test_region3(){
        regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$",regex::icase);
        string filename="123.cpp";
        smatch result;
        if(regex_search(filename,result,r))
            cout<<result.str(2)<<endl;
    }
bool valid(const smatch&m);
void test_region4(){
    regex phone("(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ])?(\\d{4})");
    smatch m;
    string s;
    while (getline(cin,s)){
        for(sregex_iterator it(s.begin(),s.end(),phone),end_it;it!=end_it;it++)
            if(valid(*it))
                cout<<"valid: "<<it->str()<<endl;
            else
                cout<<"not valid: "<<it->str()<<endl;

    }
}
bool valid(const smatch&m){
    if(m[1].matched)
        return m[3].matched&&(m[4].matched==0||m[4]==" ");
    else
        return !m[3].matched&&m[4].str()==m[6].str();
}

/** endregion */



















#endif //OFFER_TEMPLATE_TEST_H
