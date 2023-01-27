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
                       const std::string &pv)
        : m_name(name), m_pv(pv)
{}

const string &Personnage::name() const
{
    return m_name;
}

Personnage::~Personnage()
= default;
