//
// Created by draia on 27/01/23.
//

#ifndef CPP_STL_PERSONNAGE_H
#define CPP_STL_PERSONNAGE_H

#include <string>

class Personnage
{
private:
    std::string name;
    std::string pv;
public:
    virtual void parler(const std::string &message) const;

    const std::string &getName() const;

    Personnage();

    Personnage(const std::string &name,
               const std::string &pv);
};


#endif //CPP_STL_PERSONNAGE_H
