//
// Created by Q on 2023/3/1.
//
#include <set>
#include <vector>
#include <functional>
#include <map>
#include <cassert>
#include <unordered_set>
#include "iostream"
#include "Sales_data.h"
#include "StrVec.h"
#include "Quote.h"
#include "Qurey.h"
#include "algorithm"
#include "template_test.h"
#include "Blob.h"
#include "BlobPtr.h"
#include "Screen.h"
#include "Vec.h"
#include "DebugDelete.h"
#include "newHash.h"
using namespace std;
class Base{
public:
    void pub_mem();
protected:
    int port_mem;
private:
    char priv_mem;
};
struct Pub_Derv:public Base{
    int f(){return port_mem;}
    void memfcn(Base &b){
        b=*this;
        cout<<"Pub_Derv"<<endl;
    }
};
struct Priv_Derv:private Base{
    int f1()const{return port_mem;}
    void memfcn(Base &b){
        b=*this;
        cout<<"Priv_Derv"<<endl;
    }
};
struct Prot_Derv:protected Base{
    int f2(){return port_mem;}
    void memfcn(Base &b){
        b=*this;
        cout<<"Prot_Derv"<<endl;
    }
};
struct Derived_from_Public:public Pub_Derv{
    int use_base(){return port_mem;}
};
void read_file(const string& file){
    ifstream infile;
    infile.open(file);   //将文件流对象与文件连接起来
    assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行

    string s;
    while (getline(infile, s))
    {
        cout << s << endl;
    }
    infile.close();
}
void test_1542() {
    string file = R"(D:\Clion_Project\C++Primer\data.txt)";
    std::ifstream is;
    is.open(file);
    TextQuery file_text(is);
    Query a = Query("is")|Query("her");
    print(cout, a.eval(file_text));
}
void fun(const int &num){
    cout<<num<<endl;
}
int main() {
//    Foo2<string>fs;
//    fs.Bar();
//    Foo2<int>fi;
//    fi.Bar();
//    vector<int>a={1,2,1,1,1};
//    string s="11";
//    vector<string>b={"11","22","11"};
//    vector<double>c={1.13,2.2,1.11};
//    cout<<check_count(b,"11")<<endl;
//    Sales_data data1("001-01",1,100);
//    Sales_data data2;
//    Sales_data data3("001-02");
//    cout<<hex<<std::hash<string>()("001-01")<<endl;
//    cout<<hex<<std::hash<unsigned >()(1)<<endl;
//    cout<<hex<<std::hash<double>()(100)<<endl;
//    unordered_multiset<Sales_data>SDset;
//    SDset.emplace(data1);
//    SDset.emplace("001-03",1,100);
//    SDset.emplace(data3);
//    for(auto item:SDset)
//        cout<<" the hash code of "<<item.isbn()<<":\n0x"<<hex<<hash<Sales_data>()(item)<<endl;
//    tuple<size_t,size_t,size_t>threeD;
//    tuple<string,vector<double>,int,list<int>>
//        someVal("constants",{3,4},42,{0,1,2,3,4,5});
//    cout<<get<0>(someVal)<<endl;
//    get<0>(someVal)="hello";
//    cout<<get<0>(someVal)<<endl;
//    auto item = make_tuple("0-999-78345-x",3,20.00);
//    typedef decltype(item) trans;
//    size_t sz=tuple_size<trans>::value;
//    cout<<sz<<endl;
//    tuple_element<1,trans>::type cnt =get<2>(item);
//    cout<< typeid(cnt).name()<<endl;
//    tuple<int,int,int>ThreeInt(1,2,3);






}
















