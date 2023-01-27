//
// Created by draia on 27/01/23.
//

#include <iostream>
#include "Kenny.h"

using namespace std;

void Kenny::parler(const string &message) const
{
    cout << "MMmmmhhmmmm" << endl;
}

Kenny::Kenny() : Kenny("Kenny", "huh?")
{}

Kenny::Kenny(const std::string &name,
             const std::string &pv)
        : Personnage(name, pv)
{}
