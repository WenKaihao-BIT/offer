//
// Created by Q on 2023/3/24.
//

#ifndef OFFER_FINDBOOK_H
#define OFFER_FINDBOOK_H

#include <algorithm>
#include "iostream"
#include "Sales_data.h"
#include "vector"
#include "tuple"
#include<numeric>
using namespace std;
/** region ## tuple ## */
typedef std::tuple<std::vector<Sales_data>::size_type,
        std::vector<Sales_data>::const_iterator,
        std::vector<Sales_data>::const_iterator> matches;

// files 保存每家店是销售记录
// findbook 返回vector
std::vector<matches>findbook(const std::vector<std::vector<Sales_data>>&files,const std::string &book) {
    std::vector<matches>ret;
    for(auto it=files.cbegin();it!=files.end();++it){
        auto found=std::equal_range(it->cbegin(),it->cend(),book,compareIsbn);
        if(found.first!=found.second)
            ret.push_back(std::make_tuple(it-files.cbegin(),found.first,found.second));
    }
    return ret;
}
void reportResults(std::istream& in,std::ostream& os,const std::vector<std::vector<Sales_data>>& files){
    std::string s;
    while (in>>s){
        auto trans = findbook(files,s);/*tuple*/
        if(trans.empty()){
            std::cout<<s<<" not found in any stores"<<std::endl;
            continue;
        }
        for(const auto &store : trans)
            os<<"store "<<std::get<0>(store)<<" sales: "
              <<std::accumulate(std::get<1>(store),std::get<2>(store),Sales_data(s))<<std::endl;
    }
}
/** endregion */


/** region ## pair ## */
typedef pair<vector<Sales_data>::size_type ,pair<vector<Sales_data>::const_iterator,vector<Sales_data>::const_iterator>> matches2;
std::vector<matches2>findbook2(const std::vector<std::vector<Sales_data>>&files,const std::string &book) {
    std::vector<matches2>ret;
    for(auto it=files.cbegin();it!=files.end();++it){
        auto found=std::equal_range(it->cbegin(),it->cend(),book,compareIsbn);
        if(found.first!=found.second)
            ret.push_back(make_pair(it-files.cbegin(), make_pair(found.first,found.second)));
    }
    return ret;
}
void reportResults2(std::istream& in,std::ostream& os,const std::vector<std::vector<Sales_data>>& files){
    std::string s;
    while (in>>s){
        auto trans = findbook2(files,s);/*tuple*/
        if(trans.empty()){
            std::cout<<s<<" not found in any stores"<<std::endl;
            continue;
        }
        for(const auto &store : trans)
            os<<"store "<<store.first<<" sales: "
              <<std::accumulate(store.second.first,store.second.second,Sales_data(s))<<std::endl;
    }
}
/** endregion */


/** region ## class实现 ## */
class matches3{
public:
    matches3(vector<Sales_data>::size_type n,
             vector<Sales_data>::const_iterator f,
             vector<Sales_data>::const_iterator l)
            :num(n),first(f),last(l){}
    vector<Sales_data>::size_type get_num()const{return num;}
    vector<Sales_data>::const_iterator get_first()const{return first;}
    vector<Sales_data>::const_iterator get_last()const{return last;}
private:
    vector<Sales_data>::size_type num;
    vector<Sales_data>::const_iterator first,last;

};
std::vector<matches3>findbook3(const std::vector<std::vector<Sales_data>>&files,const std::string &book) {
    std::vector<matches3>ret;
    for(auto it=files.cbegin();it!=files.end();++it){
        auto found=std::equal_range(it->cbegin(),it->cend(),book,compareIsbn);
        if(found.first!=found.second)
            ret.push_back(matches3(it-files.cbegin(),found.first,found.second));
    }
    return ret;
}
void reportResults3(std::istream& in,std::ostream& os,const std::vector<std::vector<Sales_data>>& files){
    std::string s;
    while (in>>s){
        auto trans = findbook3(files,s);/*tuple*/
        if(trans.empty()){
            std::cout<<s<<" not found in any stores"<<std::endl;
            continue;
        }
        for(const auto &store : trans)
            os<<"store "<<store.get_num()<<" sales: "
              <<std::accumulate(store.get_first(),store.get_last(),Sales_data(s))<<std::endl;
    }
}
/** endregion */
#endif //OFFER_FINDBOOK_H
