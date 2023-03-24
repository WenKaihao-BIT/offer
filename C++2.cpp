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
    unordered_multiset<Sales_data>SDset;

}

























