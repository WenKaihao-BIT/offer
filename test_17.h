//
// Created by Q on 2023/3/25.
//

#ifndef OFFER_TEST_17_H
#define OFFER_TEST_17_H

#include <fstream>
#include <bitset>
#include <regex>
#include "iostream"
#include "findbook.h"
using namespace std;

vector<Sales_data>build_store(const string &s){
    Sales_data item;
    vector<Sales_data>ret;
    ifstream is(s);
    while (read(is,item))
        ret.push_back(item);
    sort(ret.begin(),ret.end(), compareIsbn);
    return ret;
}
void test1704(){
    string s1="D:/Clion_Project/C++Primer/book1.txt";
    string s2="D:/Clion_Project/C++Primer/book2.txt";
    vector<vector<Sales_data>>files;
    files.push_back(build_store(s1));
    files.push_back(build_store(s2));

    for(auto item:files){
        for(auto it:item){
            print(cout,it);
            cout<<endl;
        }
        cout<<"--------"<<endl;
    }
    reportResults3(cin,cout,files);
}
void test_bitset(){
    bitset<30>quizB;
    cout<<quizB<<endl;
    quizB.set(27);
    cout<<quizB<<endl;
    quizB.reset(27);
    cout<<quizB<<endl;
}
/** region ## 17.11-17.13 ## */
template<size_t N>
class exam{
public:
    exam():s(){}
    size_t get_size(){return N;}
    void set_solution(size_t n,bool b){s.set(n,b);}
    bitset<N>get_solution()const{return s;}
    size_t score(const bitset<N> &a);
private:
    bitset<N>s;
};

template<size_t N>
size_t exam<N>::score(const bitset<N> &a) {
    size_t ret=0;
    for(size_t i=0;i<N;i++)
        if(s[i]==a[i])
            ret++;
    return ret;
}
void test_1713(){
    exam<80>e;
    e.set_solution(0,1);
    e.set_solution(79,1);
    cout<<e.get_solution()<<endl;
    bitset<80>a;
    a.set(10,1);
    cout<<e.get_size()<< "题对了"<<e.score(a)<<" 题"<<endl;
}
/** endregion */
/** region ## 正则化 ## */
void test_regex(){
    string pattern("[^c]ei");
    cout<<pattern<<endl;
    pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    cout<<pattern<<endl;
    regex r(pattern);
    smatch results;
    string test_str="receipt freind theif receive";
    if(regex_search(test_str,results,r))
        cout<<results.str()<<endl;
}
void test_regex(int i) {
    try {
        regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
        smatch results;
        string filename;
        while (cin >> filename)
            if (regex_search(filename, results, r))
                cout << results.str() << endl;
    } catch (regex_error e) {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }

}
void test_regex2(){
    string pattern("[^c]ei");
    cout<<pattern<<endl;
    pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    string s("regex2.txt"),item;
    ifstream is(s);
    vector<string>words;

}
/** endregion */
/** region ## 17.15 ## */
void test_1715(){
    string pattern("[^c]ei");
    cout<<pattern<<endl;
    pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    cout<<pattern<<endl;
    regex r(pattern);
    smatch results;
    string test_str;
    while (1){
        cout<<"Enter a word,or q to quit"<<endl;
        cin>>test_str;
        if(test_str=="q")
            break;
        if(regex_search(test_str,results,r))
            cout<<results.str()<<endl;
    }

}
/** endregion */














#endif //OFFER_TEST_17_H
