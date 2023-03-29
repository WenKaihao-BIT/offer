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
#include "findbook.h"
#include "test_17.h"
#include "Persional_ID.h"
#include "try_test.h"
using namespace std;

void g(){}
void h()noexcept(noexcept(f())){f();}
void i()noexcept(noexcept(g())){g();}
int main() {
    try{
        cout<<"f: "<<std::boolalpha<<noexcept(f())<<endl;
        cout<<"g: "<<std::boolalpha<<noexcept(g())<<endl;
        cout<<"h: "<<std::boolalpha<<noexcept(h())<<endl;
        cout<<"i: "<<std::boolalpha<<noexcept(i())<<endl;
        f();
    }
    catch (exception &e) {
        cout<<"caught"<<e.what()<<endl;
    }


    return 0;
}
























