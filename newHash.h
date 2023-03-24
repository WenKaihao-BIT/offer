//
// Created by handsome on 2023/3/24.
//

#ifndef OFFER_NEWHASH_H
#define OFFER_NEWHASH_H
#include "Sales_data.h"

namespace std{
template<>
struct hash<Sales_data>
{
    typedef size_t result_type;
    typedef Sales_data argument_type;
    size_t operator()(const Sales_data& s)const;
};

    size_t hash<Sales_data>::operator()(const Sales_data &s) const {
        return hash<string>()(s.bookNo)^hash<unsigned>()(s.units_sold)
                ^hash<double>()(s.revenue);

    }

}








#endif //OFFER_NEWHASH_H
