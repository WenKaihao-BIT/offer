//
// Created by Q on 2023/3/13.
//

#ifndef OFFER_TEXTQUERY_H
#define OFFER_TEXTQUERY_H

#include <sstream>
#include "iostream"
#include "vector"
#include "QueryResult.h"
#include "QuerResult_tuple.h"
#include "memory"
#include "set"
#include "map"
#include "string"
#include "fstream"
#include "DebugDelete.h"
std::string make_plural(int n,const std::string &s,const std::string &add);
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;
private:
    std::shared_ptr<std::vector<std::string>>file;
    std::map<std::string,std::shared_ptr<std::set<line_no>>>wm;
};

TextQuery::TextQuery(std::ifstream &is): file(new std::vector<std::string>,DebugDelete()) {
    std::string text;
    while (std::getline(is,text)){
        file->push_back(text);
        int n= file->size()-1;
        std::istringstream line(text);
        std::string word;
        while (line>>word){
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
    std::cout<<"Read Over!"<<std::endl;
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::set<line_no>>nodata(new std::set<line_no>);
    auto loc=wm.find(sought);
    if(loc==wm.end())
        return  QueryResult(sought,nodata,file);
    else
        return QueryResult(sought,loc->second,file);
}

std::ostream &print(std::ostream &os,const QueryResult &qr){
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "
    <<make_plural(qr.lines->size(),"time","s")<<std::endl;
    for(auto num:*qr.lines)
        os<<"\t(line "<<num+1<<") "<<*(qr.file->begin()+num)<<std::endl;
    return os;
}
std::string make_plural(int n,const std::string &s,const std::string &add){
    if(n>1) return s+add;
    else return s;
}







#endif //OFFER_TEXTQUERY_H
