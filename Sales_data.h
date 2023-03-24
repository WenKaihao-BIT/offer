//
// Created by Q on 2023/2/22.
//

#ifndef OFFER_SALES_DATA_H
#define OFFER_SALES_DATA_H
#include "iostream"
#include <string>


class  Sales_data{
public:
    Sales_data() {std::cout<<"默认构造函数"<<std::endl;}
    Sales_data(const std::string &s,unsigned n,double p):bookNo(s),units_sold(n),revenue(n*p) {std::cout<<"非默认构造函数"<<std::endl;}
    Sales_data(const std::string &s):bookNo(s){}
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    friend Sales_data add(const Sales_data&,const Sales_data&);
    friend std::ostream &print(std::ostream&,const Sales_data&);
    friend std::istream &read(std::istream&,Sales_data&);
    friend int sum_data(Sales_data,Sales_data);
    friend std::istream & operator>>(std::istream &,Sales_data &);
    friend std::ostream & operator<<(std::ostream &,const Sales_data &);
    Sales_data & operator+=(const Sales_data &);
    friend Sales_data  operator+(const Sales_data &data1,const Sales_data &data2);
    friend bool operator==(const Sales_data &data1,const Sales_data &data2);
    friend bool operator!=(const Sales_data &data1,const Sales_data &data2);
    Sales_data & operator=(const std::string & isbn);
    //使用模板特例Hash
    friend class std::hash<Sales_data>;


//    Sales_data &
private:
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

double Sales_data::avg_price() const {
    if(units_sold)
        return revenue/units_sold;
    else
        return 0;
}
Sales_data & Sales_data::combine(const Sales_data &rhs) {
    units_sold+=rhs.units_sold;
    revenue+=rhs.revenue;
    return *this;
}
std::istream &read(std::istream &is,Sales_data &item){
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    item.revenue=price*item.units_sold;
    return is;
}
std::ostream &print(std::ostream &os,const Sales_data &item){
    os<<item.isbn()<<' '<<item.units_sold<<' '<<item.revenue<<' '<<item.avg_price();
    return os;
}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs){
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}
int sum_data(Sales_data data1,Sales_data data2){
    if(data1.bookNo==data2.bookNo){
        unsigned totalCnt = data1.units_sold+data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        std::cout<<data1.bookNo<<" "<<totalCnt<<" "<<totalRevenue<<" ";
        if(totalCnt!=0)
            std::cout<<totalRevenue/totalCnt<<std::endl;
        else
            std::cout<<"(no sales)"<<std::endl;
        return 0;
    }
    else{
        std::cerr<<"Data must refer to the same ISBN"<<std::endl;
        return -1;
    }
}
std::istream & operator>>(std::istream &is,Sales_data &item){
    double price = 0;
    is>>item.bookNo>>item.units_sold>>price;
    if(is)
        item.revenue=price*item.units_sold;
    else
        item=Sales_data();
    return is;
}
std::ostream & operator<<(std::ostream &os,const Sales_data &item){
    char sep ='\t';
    os<<item.bookNo<<sep<<item.units_sold<<sep<<item.revenue;
    return os;
}

Sales_data &Sales_data::operator+=(const Sales_data & data2) {
    if(this->bookNo==data2.bookNo){
        this->units_sold+=data2.units_sold;
        this->revenue+= data2.revenue;
        return *this;
    }
    else{
        std::cerr<<"Data must refer to the same ISBN"<<std::endl;
        return *this;
    }
}

Sales_data operator+(const Sales_data &data1, const Sales_data & data2) {
    Sales_data temp=data1;
    temp+=data2;
    return temp;

}

bool operator==(const Sales_data &data1, const Sales_data &data2) {
    return data1.isbn()==data2.isbn()&&
            data1.units_sold==data2.units_sold&&
            data1.revenue==data2.revenue;
}

bool operator!=(const Sales_data &data1, const Sales_data &data2) {
    return !(data1==data2);
}

Sales_data &Sales_data::operator=(const std::string & isbn) {
    bookNo=isbn;
    return *this;
}
bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs){
    return lhs.isbn()<rhs.isbn();
}

#endif //OFFER_SALES_DATA_H
