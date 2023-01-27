//
// Created by draia on 27/01/23.
//

#ifndef CPP_STL_KENNY_H
#define CPP_STL_KENNY_H


#include "Personnage.h"

class Kenny : public Personnage
{
public:
    void parler(const std::string &message) const override;

    Kenny();

    Kenny(const std::string &name,
          const std::string &pv);
};


#endif //CPP_STL_KENNY_H
