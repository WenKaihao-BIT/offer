//
// Created by Q on 2023/3/20.
//

#ifndef OFFER_DEBUGDELETE_H
#define OFFER_DEBUGDELETE_H
#include "iostream"
class DebugDelete{
public:
    DebugDelete(std::ostream &s=std::cerr):os(s){}

    template<typename T>void operator()(T *p) const
    {
        os<<"deleting unique_ptr"<<std::endl;delete p;
    }

private:
    std::ostream &os;
};
#endif //OFFER_DEBUGDELETE_H
