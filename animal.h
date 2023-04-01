//
// Created by Q on 2023/3/30.
//

#ifndef OFFER_ANIMAL_H
#define OFFER_ANIMAL_H
#include "iostream"
class zooAnimal{};
class Endangerd{};
class Bear:public zooAnimal{
    Bear(std::string name,bool onExhibit)
};
class Panda:public Bear,public Endangerd{
    Panda(std::string name,bool onExhibit);
};

Panda::Panda(std::string name, bool onExhibit) : Bear(name,,""){
}

#endif //OFFER_ANIMAL_H
