//
// Created by Q on 2023/3/13.
//

#ifndef OFFER_QUREY_H
#define OFFER_QUREY_H

#include <memory>
#include "iostream"
#include "TextQuery.h"
#include "QueryResult.h"
#include "algorithm"
//抽象基类
class Query;
class Query_base{
    friend class Query;
protected:
    using line_no=TextQuery::line_no;
    virtual ~Query_base()=default;
private:
    virtual QueryResult eval(const TextQuery &) const =0;
    virtual std::string rep() const =0;
};
class WordQuery:public Query_base{
    friend class Query;
private:
    WordQuery(const std::string &s):query_word(s){std::cout<<"WordQuery的构造函数"<<std::endl;}
    QueryResult eval(const TextQuery &t)const override {return t.query(query_word);}
    std::string rep() const override {return query_word; }
    std::string query_word;  //要查找的单词
};

class Query{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &,const Query &);
    friend Query operator&(const Query &,const Query &);
public:
    //Query的构造函数
    explicit Query(const std::string &);
    //
    QueryResult eval(const TextQuery &t)const{return q->eval(t);}
    std::string rep()const {return q->rep();}

private:
    Query(std::shared_ptr<Query_base>query):q(query){std::cout<<"Query的构造函数-share"<<std::endl;}
    std::shared_ptr<Query_base>q;
};
inline
Query::Query(const std::string &s) :q(new WordQuery(s)){std::cout<<"Query的构造函数"<<std::endl;}


class NotQuery:public Query_base{
    friend Query operator~(const Query &);
    NotQuery(const Query &q): query(q){}
    std::string rep() const override{return "~("+query.rep()+")";}
    QueryResult eval (const TextQuery&) const override;
    Query query;
};
inline
Query operator~(const Query &operand) {
    return std::shared_ptr<Query_base>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines= std::make_shared<std::set<line_no>>();
    auto beg=result.begin(),end = result.end();
    auto sz=result.get_file()->size();
    for(size_t n=0;n!=sz;++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}


class BinaryQuery:public Query_base{
protected:
    BinaryQuery(const Query &l,const Query &r,std::string s): lhs(l), rhs(r),opSym(s){std::cout<<"BinaryQuery的构造函数"<<std::endl;}
    //抽象类不定义eval，则BinaryQuery也为抽象类
    std::string rep() const override { return "("+lhs.rep()+" "+opSym+" "+rhs.rep()+")";}

    Query lhs,rhs;
    std::string  opSym;
};

class AndQuery:public BinaryQuery{
    friend Query operator&(const Query&,const Query&);
    AndQuery(const Query &left,const Query &right): BinaryQuery(left,right,"&"){std::cout<<"AndQuery的构造函数"<<std::endl;}
    QueryResult eval(const TextQuery &) const override;
};
inline
Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}

QueryResult AndQuery::eval(const TextQuery &text) const {
    auto right = rhs.eval(text),left=lhs.eval(text);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(),left.end(),right.begin(),right.end(), std::inserter(*ret_lines,ret_lines->begin()));

    return QueryResult(rep(),ret_lines,left.get_file());
}


class OrQuery:public BinaryQuery{
    friend Query operator|(const Query&,const Query&);
    OrQuery(const Query &left,const Query &right): BinaryQuery(left,right,"|"){std::cout<<"OrQuery的构造函数"<<std::endl;}
    QueryResult eval(const TextQuery &)const override;
};
inline
Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const {
    auto right = rhs.eval(text),left=lhs.eval(text);
    auto ret_lines= std::make_shared<std::set<line_no>>(left.begin(),left.end());
    ret_lines->insert(right.begin(),right.end());
    return QueryResult(rep(),ret_lines,left.get_file());
}

//打印输出运算符
std::ostream &operator<<(std::ostream &os,const Query &query){
    return os<<query.rep();
}
/*查找类
 * 给定一个String
 * */


























#endif //OFFER_QUREY_H
