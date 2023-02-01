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

Personnage::Personnage(const std::string &name,
                       const int &hp)
        : m_name(name), m_hp(hp)
{}

const string &Personnage::name() const
{
    return m_name;
}

Personnage::~Personnage()
= default;
