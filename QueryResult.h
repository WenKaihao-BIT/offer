//
// Created by Q on 2023/3/13.
//

#ifndef OFFER_QUERYRESULT_H
#define OFFER_QUERYRESULT_H

#include "iostream"
#include "memory"
#include "set"
#include "vector"
class QueryResult {
    using line_no = std::vector<std::string>::size_type;
friend std::ostream & print(std::ostream &,const QueryResult&);
public:
    QueryResult(std::string s,std::shared_ptr<std::set<line_no>>p,std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){ }
    std::set<line_no>::iterator begin()const {return lines->begin();}
    std::set<line_no>::iterator end()const {return lines->end();}
    std::shared_ptr<std::vector<std::string>> get_file(){return std::make_shared<std::vector<std::string>>(*file);}
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>>lines;
    std::shared_ptr<std::vector<std::string>>file;
};


#endif //OFFER_QUERYRESULT_H
