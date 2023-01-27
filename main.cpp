#include <iostream>
#include <string>
#include <list>
#include "Personnage/Personnage.h"
#include "Personnage/Kenny.h"


using namespace std;

int main()
{

    list<Personnage *> anime = {new Personnage(), new Kenny(), new Kenny()};

    for (Personnage *character: anime)
    {
        character->parler("Hey dude.");
    }

    return 0;
}
