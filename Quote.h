//
// Created by Q on 2023/3/8.
//

#ifndef OFFER_QUOTE_H
#define OFFER_QUOTE_H
#include "iostream"
class Quote{
public:
    Quote()=default;
    Quote(const std::string &book,double  sales_price):bookNo(book),price(sales_price){std::cout<<"Quote的构造函数"<<std::endl;};
    Quote(const Quote&)=default;
    Quote(Quote &&) =default;
    Quote & operator=(const Quote &) = default;
    Quote & operator=(Quote &&) =default;

    std::string isbn()const{return bookNo;}
    virtual double net_price(std::size_t n) const {std::cout<<"Quote-function"<< std::endl;return n*price;};
    virtual void debug(){std::cout<<"bookNo="<<bookNo<<"  price="<<price<<std::endl;}
    virtual ~Quote() {std::cout<<"Quote的析构函数"<<std::endl;}
    //以引用的形式返回 左值
    virtual Quote* clone() const &{return new Quote(*this);}
    //此处不加const限定，因为move操作会改变this所指的内容
    virtual Quote* clone() &&{return new Quote(std::move(*this));}
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
class Disc_quote :public Quote{
public:
    Disc_quote()=default;
    Disc_quote(const std::string & book,double price,std::size_t qty,double disc):Quote(book,price),quantity(qty),discount(disc){std::cout<<" Disc_quote的构造函数"<<std::endl; }
    Disc_quote(const Disc_quote &)=default;
    double net_price (std::size_t n) const override =0 ;
    ~Disc_quote()override{std::cout<<"Dis_quote的构造函数"<<std::endl;}
protected:
    std::size_t quantity=0;
    double  discount=0;
};
class Bulk_quote:public Disc_quote{
public:
    Bulk_quote()=default;
    explicit Bulk_quote(const std::string &book="",double price=0.0,size_t qty=0,double disc=0.0):Disc_quote(book,price,qty,disc){std::cout<<"Bulk_quote的构造函数"<<std::endl;}
    Bulk_quote(const Bulk_quote &)=default;
    Bulk_quote( Bulk_quote &&)=default;
    double net_price(std::size_t ) const override;
    void debug()override{Quote::debug();std::cout<<"min_qty="<<quantity<<" discount="<<discount<<std::endl;}
    ~Bulk_quote() override {std::cout<<"Bulk_quote的析构函数"<<std::endl;}
    Bulk_quote* clone()const & override {return new Bulk_quote(*this);}
    Bulk_quote* clone() && override {return new Bulk_quote(std::move(*this));}


};

double Bulk_quote::net_price(std::size_t cnt) const {
    std::cout<<"Bulk-function"<< std::endl;
    if(cnt>quantity)
        return cnt*(1-discount)*price;
    else
        return cnt*price;
}

double print_total(std::ostream &os,const Quote &item,size_t n){
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<"# sold: "<<n<<" total due: "<<ret<<std::endl;
    return ret;
}
class Limited_quote:public Disc_quote{
public:
    Limited_quote()=default;
    Limited_quote(const std::string &book="",double p=0.0,size_t qty=0,double disc=0.0):Disc_quote(book,price,qty,disc){}
    double net_price(std::size_t cnt)const override{
        {
            if (cnt<quantity)
                return cnt*(1-discount)*price;
            else
                return quantity*(1-quantity)*price+(cnt-quantity)*price;
        }
    }

};
class Basket{

public:
    // 采用默认的构造函数


    void add_item(const std::shared_ptr<Quote> &sale){items.insert(sale);}
    // 采用拷贝&移动方式进行操作
    void  add_item(const Quote & sale){
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void  add_item( Quote&& sale){
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    double total_receipt(std::ostream&)const;


private:
    static bool compare(const std::shared_ptr<Quote> &lhs,const std::shared_ptr<Quote>&rhs)
    {return lhs->isbn()<rhs->isbn();}
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*>items{compare};
};
double Basket::total_receipt(std::ostream &os) const {
    double sum=0.0;
    for(auto iter=items.cbegin();iter!=items.end();iter=items.upper_bound(*iter)){
//        os<<"number= "<<items.count(*iter)<<std::endl;
        sum+= print_total(os,**iter,items.count(*iter));
    }
    os<<"Total Sale: "<<sum<<std::endl;
    return sum;
}

#endif //OFFER_QUOTE_H




















