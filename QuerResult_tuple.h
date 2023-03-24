//
// Created by Q on 2023/3/24.
//

#ifndef OFFER_QUERRESULT_TUPLE_H
#define OFFER_QUERRESULT_TUPLE_H
#include "tuple"
#include "iostream"
#include "vector"
#include "set"
#include "memory"
typedef std::vector<std::string>::size_type line_no;
typedef std::set<line_no>::const_iterator line_it;
typedef std::tuple<std::vector<std::string>,std::shared_ptr<std::set<line_no>>
    ,std::shared_ptr<std::vector<std::string>>>QueryResult2;

//class QueryResult {
//    using line_no = std::vector<std::string>::size_type;
//    friend std::ostream & print(std::ostream &,const QueryResult&);
//public:
//    QueryResult(std::string s,std::shared_ptr<std::set<line_no>>p,std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){ }
//    std::set<line_no>::iterator begin()const {return lines->begin();}
//    std::set<line_no>::iterator end()const {return lines->end();}
//    std::shared_ptr<std::vector<std::string>> get_file(){return std::make_shared<std::vector<std::string>>(*file);}
//private:
//    std::string sought;
//    std::shared_ptr<std::set<line_no>>lines;
//    std::shared_ptr<std::vector<std::string>>file;
//};

#endif //OFFER_QUERRESULT_TUPLE_H
