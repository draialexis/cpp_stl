#include <iostream>
#include <string>
#include <list>
#include <algorithm>
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

    cout << endl;
    anime.insert(next(anime.begin()), new Personnage());

    for (Personnage *character: anime)
    {
        character->parler("Hey dude.");
    }

    cout << endl;
    vector<Personnage *> vanime;

    for (Personnage *character: vanime)
    {
        character->parler("Hey dude.");
    }

    cout << endl;
    copy(anime.begin(), anime.end(), back_inserter(vanime));


    for (Personnage *character: vanime)
    {
        character->parler("Hey dude.");
    }

    cout << endl;
    vanime[2]->parler("I'm third");
    vanime.insert(next(vanime.begin()), new Personnage());
    // same as with the list...

    cout << endl;
    for (Personnage *character: vanime)
    {
        character->parler("Hey dude.");
    }


    // we copied pointers in vanime, we didn't call 'new()' -- no need to delete from both collections
    for_each(vanime.begin(), vanime.end(), [](auto *x)
    { delete x; });
    return 0;
}
