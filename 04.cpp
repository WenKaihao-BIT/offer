
#include "iostream"
using namespace std;
struct base {
    base(string szNm) : basename(szNm) {}
    string name()
    {
        return basename;
    }
    virtual void print(ostream &os)
    {
        os << basename;
    }
private:
    string basename;
};
struct derived : public base
{
    derived(string szName, int iVal) : base(szName),mem (iVal){}
    void print()
    {
        print(base::ostream &os);
        os << "--" <<mem;
    }
private :
    int mem;
};
