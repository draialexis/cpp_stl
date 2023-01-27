//
// Created by draia on 27/01/23.
//
#include <iostream>
#include "Personnage.h"

using namespace std;

void Personnage::parler(const string &message) const
{
    cout << message << endl;
}

Personnage::Personnage()
        : Personnage("FNU", "wat")
{}

Personnage::Personnage(const std::string &name,
                       const std::string &pv)
        : name(name), pv(pv)
{}

const string &Personnage::getName() const
{
    return name;
}
