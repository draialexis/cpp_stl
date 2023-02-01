//
// Created by draia on 27/01/23.
//

#ifndef CPP_STL_PERSONNAGE_H
#define CPP_STL_PERSONNAGE_H

#include <string>

class Personnage
{
private:
    std::string m_name;
    int m_hp;
public:
    virtual void parler(const std::string &message) const;

    const std::string &name() const;
    const int &hp() const;

    explicit Personnage(const std::string &name = "FNU",
                        const int &hp = 10);

    virtual ~Personnage();
};


#endif //CPP_STL_PERSONNAGE_H
