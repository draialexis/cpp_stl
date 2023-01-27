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

    cout << endl;
    anime.front()->parler("I'm in the front");
    anime.back()->parler("I'm in the back");

    Personnage *second = *(next(anime.begin()));
    cout << endl;
    second->parler("I'm here too");
    // that sucked

    return 0;
}
