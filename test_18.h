//
// Created by Q on 2023/3/30.
//

#ifndef OFFER_TEST_18_H
#define OFFER_TEST_18_H
#include "iostream"
#include "Sales_data.h"
using namespace std;
/** region ## 1809 ## */
void test1809(){
    Sales_data item1,item2,sum;
    while ((cin>>item1>>item2)){
        try{
            sum=item1+item2;
        }
        catch (const isbn_mismatch &e) {
            cerr<<e.what()<<": left isbn("<<e.left<<")right isbn"<<e.right<<")"<<endl;
        }
    }
}
/** endregion */
/** region ## 命名空间 ## */
namespace cplusplus_primer{
    class a{};
    class b{};
}

/** endregion */
/** region ## RTTI ## */
struct Base{
    virtual ~Base(){};
};
struct Derived:public Base{
    void print(const string&s){cout<<"Derived---"<<s<<endl;}
};
/** endregion */
#endif //OFFER_TEST_18_H
