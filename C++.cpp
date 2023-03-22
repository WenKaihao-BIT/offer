//
// Created by Q on 2023/2/6.
//
#include <iostream>
#include "vector"
#include "list"
#include  <algorithm>
#include "functional"
#include <iterator>
#include <numeric>
#include <fstream>
#include <sstream>
#include "map"
#include "Sales_data.h"
#include "cstring"
using namespace std;

void test_47_1(){
    string a= "ab2c3d7R4E6";
    vector<int>result;
    int pos = 0;int index = 0;
    while (index!=-1){
        index = a.find_first_of("0123456789",pos);
        if(index!=-1){
            result.push_back(index);
            cout<<index<<endl;
        }

        pos=index+1;
    }
}
void test_47_2(){
    string a= "ab2c3d7R4E6";
    vector<int>b(a.size(),1);
    int pos = 0;int index = 0;
    while (index!=-1){
        index = a.find_first_not_of("0123456789",pos);
        if(index!=-1){
            pos=index+1;
            b[index]=0;
//            cout<<index<<endl;
        }
    }
    for(int i=0;i<b.size();i++ ){
        if(b.at(i)==1)
            cout<<i<<endl;

    }
}
// 9.48  npos

//9.49
void test_949(){
    int check_word(string);
    string word = "wwe" ;
    int result = check_word(word);
    cout<<result;
}

int check_word(string word){
    int length = 0;
    int index;
    index = word.find_first_of("qypfghjlbm");
    if(index==-1)
        return word.size();
    else
        return -1;


}
//101
int count_same(vector<int>nums,int x){
    int count =0;
    if(!nums.empty()){
        for(auto it:nums){
            if(it==x)
                count++;
        }
    }
    return count;
}
void test_101(){
    vector<int>nums{1,2,2,4,5,4,2};
    cout<<count_same(nums,2);
}
//102
int count_same(list<string>words,string target){
    int count=0;
    if(!words.empty()){
        for(auto item : words)
            if(item ==target)
                count++;
    }
    return count;
}
void test_102(){
    list<string> words ={"hello","hello","world","world"};
    cout<<count_same(words,"hello");

}

//103
int sum_103(vector<int>nums){
    int sum=0;
    if(!nums.empty()){
        for(auto item :nums)
            sum+=item;
    }
    return sum;
}
void test_103(){
    vector<int>nums={1,2,3,3,4};
    cout<<sum_103(nums);

}


//106
void test_106(){
    vector<int>nums = {1,2,3,4,5,6};
    fill_n(nums.begin(),nums.size(),0);
    for(auto item:nums )    cout<<item<<endl;
}

//109
void elimDups(vector<string>&ss){
    sort(ss.begin(),ss.end());
    auto end_unique = unique(ss.begin(),ss.end());
    ss.erase(end_unique,ss.end());
}
void test_109(){
    vector<string>ss={"123","123","456"};
    elimDups(ss);
    for(auto item:ss) cout<<item<<endl;
}
//1010
//改变容器大小会造成迭代器失效

//1011
bool isShort(const string &s1,const string &s2){
    return s1.size()<s2.size();
}
void elimDups2(vector<string>&words){
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}
void test_1011(){
    vector<string>words = {"the","quick","red","fox","jumps","over","the","slow","the","turtle"};
//    elimDups2(words);
    elimDups2(words);
    for(auto item : words)
        cout<<item<<endl;
}

//1013
bool is5(string s){
    return s.size()<=4;
}
void compare_fun(vector<string>words){
    auto end_of = partition(words.begin(),words.end(),is5);
    for(auto i=words.begin();i<end_of;i++)
        cout<<*i<<' ';
    cout<<endl;
}
void test_1013(){
    vector<string>words = {"the","quick","red","fox","jumps","over","the","slow","the","turtle"};
    compare_fun(words);
}

//1014
auto f(const int a,const int b){return a+b;};
//1015
void  test_1015(){
    int a=2;
    auto f= [a](int b){return a+b;};
    cout<<f(4);
}
//1017
void test_1017(){
    vector<string>words ={"hello","hello","world","1","231","778"};
    elimDups2(words);
    sort(words.begin(),words.end(),[]( const string &word1,const string &word2){return word1.size()>word2.size();});
    for(auto item:words)
        cout<<item<<endl;
}

//1018-1019
void biggies(vector<string>&words,vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(),words.end(),[]( const string &word1,const string &word2){return word1.size()>word2.size();});
    auto wc = stable_partition(words.begin(),words.end(),[sz](const string &word){return word.size()<sz;});
    auto count = words.end()-wc;
    for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;
}
void test_1018(){
    vector<string>words = {"the","quick","red","fox","jumps","over","the","slow","the","turtle"};
    biggies(words,4);
}
//1020
void biggies2(vector<string>&words,vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(),words.end(),[]( const string &word1,const string &word2){return word1.size()>word2.size();});
    auto wc = stable_partition(words.begin(),words.end(),[sz](const string &word){return word.size()<=sz;});
//    auto count = words.end()-wc;
    int count = count_if(words.begin(),words.end(),[sz](const string &word){return word.size()>sz;});
    cout<<"the result of count is "<<count<<endl;
    for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;
}
void test_1020(){
    vector<string>words = {"the","quick","red","fox","jumps","over","the","slow","the","turtle"};
    biggies2(words,6);
}
//1021
void test_1021(){
    int count=80;
    auto f =[&count]() ->bool  {if(count!=0){count--;return false;}else{return true;}};
    while(!f()){
        cout<<count<<endl;
    }
}
//1022
bool CountOver6(const string &word,vector<string>::size_type sz){
    return word.size()>sz;
}
void biggies3(vector<string>&words,vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(),words.end(),[]( const string &word1,const string &word2){return word1.size()>word2.size();});
    auto wc = stable_partition(words.begin(),words.end(),[sz](const string &word){return word.size()<=sz;});
    int count = count_if(words.begin(),words.end(),bind(CountOver6,placeholders::_1,sz));
//    auto count = words.end()-wc;
//    int count = count_if(words.begin(),words.end(),[sz](const string &word){return word.size()>sz;});
    cout<<"the result of count is "<<count<<endl;
    for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;
}
void test_1022(){
    vector<string>words = {"the","quick","red","fox","jumps","over","the","slow","the","turtle"};
    biggies3(words,5);
}

//1024
bool chek_size(string &word,vector<string>::size_type sz){
    return word.size()>sz;
}
void test_1024(){
    vector<string>words = {"the","quick","red","fox","jumps","over","the","slow","the","turtle"};
    vector<string>::size_type sz;
    sz =4;
    auto f = bind(chek_size,placeholders::_1,sz);
    for(auto item:words){
        if(f(item,sz)){
            cout<<item<<endl;
            break;
        }
    }

}

//1025
void biggies4(vector<string>&words,vector<string>::size_type sz){
    elimDups(words);
    stable_sort(words.begin(),words.end(),[]( const string &word1,const string &word2){return word1.size()>word2.size();});
    auto wc = partition(words.begin(),words.end(),bind(chek_size,placeholders::_1,sz));

//    auto count = words.end()-wc;
    int count = count_if(words.begin(),words.end(),[sz](const string &word){return word.size()>sz;});
    cout<<"the result of count is "<<count<<endl;
    for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;
}
void test_1025(){
    vector<string>words = {"the","quick","red","fox","jumps","over","the","slow","the","turtle"};
    biggies4(words,5);
}

//1027
void test_1027(){
    vector<int>sources = {1,2,3,4,5,6,7,8,9,1,2,3};
    list<int>result;
    sort(sources.begin(),sources.end());
    unique_copy(sources.begin(),sources.end(), inserter(result,result.begin()));
    for(auto item :result)
        cout<<item<<endl;

}
//1028
void test_1028(){
    vector<int>sources = {1,2,3,4,5,6,7,8,9};
    list<int>result1,result2,result3;
    unique_copy(sources.begin(),sources.end(), inserter(result1,result1.begin()));
    unique_copy(sources.begin(),sources.end(), back_inserter(result2));
    unique_copy(sources.begin(),sources.end(), front_inserter(result3));
    for(auto item :result1)
        cout<<item;
    cout<<endl;
    for(auto item :result2)
        cout<<item;
    cout<<endl;
    for(auto item :result3)
        cout<<item;
    cout<<endl;

}
//1029
void test_1029(){
    ifstream ifs("D:/Clion_Project/offer/test_1029.txt");
    istream_iterator<string>str_istream_iter(ifs),eof;
    vector<string>v1(str_istream_iter,eof);
    ostream_iterator<string>cout_iter(cout," ");
    copy(v1.begin(),v1.end(),cout_iter);
    cout<<endl;

}
//1030
void test_1030(){
    istream_iterator<int>int_istream_input(cin),eof;
    vector<int>v1(int_istream_input,eof);
    sort(v1.begin(),v1.end(),[](const int &a,const int &b){return a<=b;});
    ostream_iterator<int>int_istream_output(cout," ");
    copy(v1.begin(),v1.end(),int_istream_output);
    cout<<endl;
}
//1031
void test_1031(){
    istream_iterator<int>int_istream_input(cin),eof;
    vector<int>v1(int_istream_input,eof);
    sort(v1.begin(),v1.end(),[](const int &a,const int &b){return a<=b;});
    ostream_iterator<int>int_istream_output(cout," ");
    unique_copy(v1.begin(),v1.end(),int_istream_output);
    cout<<endl;
}
//1033
void function(ifstream ifs,ofstream ofs1,ofstream ofs2){

}

void test_1033(){
    ifstream ifs("D:/Clion_Project/offer/test_1033.txt");
    istream_iterator<int>input(ifs),eof;
    vector<int>v1(input,eof),v2,v3;
    ofstream ofs1("D:/Clion_Project/offer/test_1033_out1.txt");
    ostream_iterator<int>odd_iter(ofs1,"\n");
    copy_if(v1.begin(),v1.end(),odd_iter,[](int i){return i%2;});
    ofs1.close();
    ofstream ofs2("D:/Clion_Project/offer/test_1033_out2.txt");
    ostream_iterator<int>even_iter(ofs2," ");
    copy_if(v1.begin(),v1.end(),even_iter,[](int i){return !(i%2);});
    ofs2.close();

}
//1034
void test_1034(){
    vector<int>nums={1,2,3,4,5};
    for(auto iter = nums.rbegin();iter!=nums.rend();iter++)
        cout<<*iter<<endl;
}
//1035
void test_1035(){
    vector<int>nums={1,2,3,4,5};
    for(auto iter=nums.end()-1;iter>=nums.begin();iter--)
        cout<<*iter<<endl;
}
void test_1036(){
    list<int>nums={1,2,0,0,1};
    auto iter = find(nums.crbegin(),nums.crend(),0);
    int result= distance(iter,nums.crend())-1;
    cout<<result<<endl;
}
void test_1037(){
    vector<int>nums = {1,2,3,4,5,6,7,8,9,10};
//    cout<<*(nums.crbegin()+2);
    list<int>nums_copy(nums.crbegin()+2,nums.crbegin()+7);
    for(auto item:nums_copy) cout<<item<<endl;
}
// 1103
void test_1103(){
    map<string,int>words;
    string word;
//    istream_iterator<string>str_input(cin),eof;
    while (cin>>word){
        ++words[word];
    }

    for(const auto item :words)
        cout<<item.first<<" occuers "<<item.second<<((item.second>1)?" times ":" time ")<<endl;


}
//1104
void test_1104(){
    map<string,int>words;
    string word;
//    istream_iterator<string>str_input(cin),eof;
    while (cin>>word){
        word.erase(find_if(word.begin(),word.end(), ::ispunct),word.end());
        for_each(word.begin(),word.end(),[](char &c){c= tolower(c);});
        ++words[word];

    }

    for(const auto item :words)
        cout<<item.first<<" occuers "<<item.second<<((item.second>1)?" times ":" time ")<<endl;


}
//1107
void Add_Kid(map<string,vector<string>>&family,string new_family,string new_kid){
    family[new_family].push_back(new_kid);
}
//1107
void test_1107(){
    map<string,vector<string>>family;
    Add_Kid(family,"Li","Li Ming");
    Add_Kid(family,"Li","Li XiaoMing");
    Add_Kid(family,"xi","xi Ming");
    Add_Kid(family,"xi","xi XiaoMing");
    for(const auto item:family){
        cout<<item.first<<" kids:";
        for(const auto item1:item.second)
            cout<<" "<<item1;
        cout<<endl;
    }



}
//1109
void test_1109(){
    map<string,list<size_t>>word_list;
    word_list["hello"]={1,2,3,4,5};
}
//1112-1113
void test_1110(){
    vector<pair<string,int>>words;
    string a;int b;
    while(cin>>a>>b){
//        words.push_back(pair<string,int>(a,b));
//        words.push_back(make_pair(a,b));
        pair<string,int>p={a,b};
        words.push_back(p);
    }
    for(const auto item:words)
        cout<<item.first<<' '<<item.second<<endl;
}

//1114
void Add_Kid2(map<string,vector<pair<string,string>>>&family,string new_family,pair<string,string> new_kid){
    family[new_family].push_back(new_kid);
}
void test_1112(){
    map<string,vector<pair<string,string>>>family;
    Add_Kid2(family,"Li",pair<string,string>("Li xiaoMing","2002-08-17"));
    Add_Kid2(family,"Li",pair<string,string>("Li Ming","2000-08-17"));
    for(const auto item:family){
        cout<<item.first<<" kids: "<<endl;
        for(const auto item1:item.second)
            cout<<item1.first<<' '<<item1.second<<endl;
    }
}
//1116
void test_1116(){
    map<string,int>nums={{"LiMing",123}};
    auto iter =nums.begin();
    iter->second=456;
    cout<<nums["LiMing"]<<endl;

}
//1120
void test_1120(){
    map<string,int>words_list;
    string a;int b;
    while(cin>>a){
        auto iter=words_list.insert({a,1});
        if(!iter.second)
            ++iter.first->second;
    }
    for(auto item : words_list){
        cout<<item.first<<' '<<item.second<<endl;
    }
}

//1122
void test_1122(){
    map<string,vector<int>>test;
    pair<string,vector<int>>a;
    bool c;
    pair<map<string,vector<int>>::iterator,bool>ret = test.insert(a);

}
//1128
void test_1128(){
    map<int,vector<int>>test = {{1,{1,2}}};
    map<int,vector<int>>::iterator iter;
    iter = test.find(1);
    if(iter==test.end())
        cout<<"not find"<<endl;
    else
        cout<<iter->second[1]<<endl;
}
//1131
void dele_str(multimap<string,string>&maps,string tar){
    for(auto iter = maps.equal_range(tar);iter.first!=iter.second;iter.first++)
        maps.erase(iter.first);
}
void test_1131(){
    multimap<string,string>maps={{"li","hello"},{"li","hello world"}};
    for(auto iter = maps.equal_range("li");iter.first!=iter.second;iter.first++)
        cout<<iter.first->second<<endl;
    dele_str(maps,"123");
    for(auto iter = maps.equal_range("li");iter.first!=iter.second;iter.first++)
        cout<<iter.first->second<<endl;


}
//1132
void test_1132(){
    multimap<string,string>maps={{"li","hello"},{"li","hello world"}};
    for(auto iter = maps.equal_range("li");iter.first!=iter.second;iter.first++)
        cout<<iter.first->first<<"   "<<iter.first->second<<endl;
}
//1133
map<string,string>buildMap(ifstream &map_file){
    map<string,string>trans_map;
    string key,value;
    while (map_file>>key && getline(map_file,value)){
//        cout<<"ok"<<endl;
        if(value.size()>1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for "+key);
    }
//    for(auto item :trans_map)
//        cout<<item.first<<" "<<item.second<<endl;
    return trans_map;
}
const string &transform(const string &s, const map<string,string>&m){
    auto map_it =m.find(s);
    if(map_it!=m.cend())
        return map_it->second;
    else
        return s;
}
void word_transform(ifstream &map_file, ifstream &input){
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input,text)) {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout<<endl;
        }

}

void test_1133(){
    ifstream map_file("D:/Clion_Project/offer/test_1131_2.txt");
    ifstream input("D:/Clion_Project/offer/test_1131.txt");
    word_transform(map_file,input);
//    buildMap(map_file);
}
#include <memory>
#include <valarray>
#include <set>


//1202
class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string>il);
    size_type size() const {return data->size();};
    bool empty() const {return data->empty();};
    void push_back(const string &t){data->push_back(t);};
    string & front();
    string & back();
    void pop_back();
    const string &front() const;
    const string &back() const;

private:
    std::shared_ptr<vector<string>>data;
    void check(size_type i,const string &msg) const;
};
StrBlob::StrBlob():data(make_shared<vector<string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string> il) :data(make_shared<vector<string>>(il)){}

void StrBlob::check(StrBlob::size_type i, const std::string &msg) const {
    if(i>=data->size())
        throw out_of_range(msg);
}
std::string & StrBlob ::front(){
    check(0,"front on empty StrBlob");
    return data->front();
}
const string & StrBlob::front() const {
    check(0,"front on empty StrBlob");
    return data->front();
}
string &StrBlob::back() {
    check(0,"front on empty StrBlob");
    return data->back();
}
const string &StrBlob::back() const {
    check(0,"front on empty StrBlob");
    return data->back();
}
//1206
vector<int>* fun(){
    vector<int> *p =new vector<int>;
    return p;
}
vector<int>* save_data(){
    auto ptr = fun();
    int a;
    while(cin>>a){
        ptr->push_back(a);
    }
    return ptr;
}
void test_1206(){
    auto ptr=save_data();
    for(auto item :*ptr)
        cout<<item<<endl;
    delete ptr;
}
//1207
shared_ptr<vector<int>> fun2(){
    return make_shared<vector<int>>();
}
shared_ptr<vector<int>> save_data2(){
    auto ptr = fun2();
    int a;
    while(cin>>a){
        ptr->push_back(a);
    }
    return ptr;
}
void test_1207(){
    auto ptr=save_data2();
    for(auto item :*ptr)
        cout<<item<<endl;
}
//1214-1215
struct destination{};
struct connection{};
connection connect(destination *pd){
    cout<<"打开连接"<<endl;
    return connection();
}
void disconnect(connection c){
    cout<<"关闭连接"<<endl;
}
void f(destination &d) {
    cout << "直接管理connect" << endl;
    connection c = connect(&d);
    //忘记调用 disconnect 关闭连接
    cout << endl;
}
void end_connection(connection *p){ disconnect(*p);}

//使用 shared_ptr
void f1(destination &d){
    cout<<"用 shared_ptr管理connect"<<endl;
    connection c = connect(&d);

    shared_ptr<connection>p(&c, end_connection);
    //忘记调用 disconnect 关闭连接
    cout<<endl;
}
// lambda
void f2(destination &d){
    cout<<"用 shared_ptr管理connect"<<endl;
    connection c = connect(&d);

    shared_ptr<connection>p(&c, [](connection *p){ disconnect(*p);});
    //忘记调用 disconnect 关闭连接
    cout<<endl;
}
void test_1214(){
    destination d;
    f(d);
    f1(d);
    f2(d);
}
class B {
public:
    B(){cout<<"默认构造！"<<endl;};
    B(B&b){cout<<"拷贝构造！"<<endl;};
};
B f(B a){return a;};
struct NoDtor{
    NoDtor() =default;
    ~NoDtor()=delete;//错误
};


void test_0214(){
    Sales_data data1,data2;
    Sales_data data3("123");
//    double price=0;
//    cin>>data1.bookNo>>data1.units_sold>>price;
//    data1.revenue = data1.units_sold * price;
//    cin>>data2.bookNo>>data2.units_sold>>price;
//    data2.revenue = data2.units_sold * price;
//    read(cin,data1);
//    read(cin,data2);
//    sum_data(data1,data2);

}
bool NumOverflow(char*number,int length){
    int c=1,temp;
    for(int i=length-1;i>=0;i--){
        temp=number[i]-'0'+c;
        if(temp>9){
            c=1;
            number[i]=temp-10+'0';
        }
        else{
            c=0;
            number[i]=temp+'0';
        }

    }
    return (c==1)? true: false;
}
int  save(char *number,int length){
    bool isbegin =true;
    int result=0;
    for(int i=0;i<length;i++){
        if(isbegin&&number[i]!='0')
            isbegin =false;
        if(!isbegin){
//            cout<<(number[i]-'0')*pow(10,(length-i))<<endl;
            result+=(number[i]-'0')*pow(10,(length-i-1));
        }

    }
    return result;
}
//
class x{
public:
    const int err = 0;
    x(){cout<<"构造函数x（）"<<endl;}
    x(const x&){cout<<"拷贝构造函数x(const x&)"<<endl;}
    x& operator=(const x &rhs){cout<<"拷贝赋值运算符=（const x&）"<<endl;return *this; }
    ~x(){cout<<"析构函数~x()"<<endl;}

};
void f1(x a){}
void f2(x &a){}
class PrivateCopy{
public:
    PrivateCopy()=default;
    PrivateCopy(const PrivateCopy&)=delete;
    PrivateCopy &operator=(const PrivateCopy&);
    ~PrivateCopy();
};
//1318
class Employee{
public:
    Employee(){mysn=sn++;}
    Employee(const string &s){name=s;mysn=sn++;}
    Employee(Employee &e){name=e.name;mysn=sn++;}
    Employee&operator=(Employee &e){name=e.name;mysn=sn++;return *this;}
    string id;
    const string &get_name(){return name;}
    int get_mysn(){return mysn;}
private:
    static int sn;
    string name;
    int mysn;

};
int Employee::sn=0;
void test_1318(){
    Employee a("a");
    cout<<a.get_name()<<' '<<a.get_mysn()<<endl;
    Employee b("s");
    cout<<b.get_name()<<' '<<b.get_mysn()<<endl;
    Employee c("d");
    cout<<c.get_name()<<' '<<c.get_mysn()<<endl;
}
class Folder{
public:
    friend class Message;
    void addMsg(const Message &);

};
class Message{
    friend class Folder;
public:
    explicit Message(const string &str = ""):contents(str) {}
    Message(const Message&);
    Message & operator=(const Message &);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    string contents;
    std::set<Folder*>folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
};
void Message::save(Folder &f) {
    folders.insert(&f);
    f.addMsg(this);
}
int main(){
//    test_1318();
    const string &s=string();
    cout<<s<<endl;



    return 0;

}





















