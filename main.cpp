#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include "Personnage/Personnage.h"
#include "Personnage/Kenny.h"


using namespace std;

int main()
{

    list<Personnage *> anime = {new Personnage("Eric", "pv"),
                                new Kenny(),
                                new Kenny("Benny", "pv")};

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
    anime.insert(next(anime.begin()), new Personnage("Stan", "pv"));

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
    vanime.insert(next(vanime.begin()), new Personnage("Kyle", "pv"));
    // same as with the list...

    cout << endl;
    for (Personnage *character: vanime)
    {
        character->parler("Hey dude.");
    }

    Personnage *alpha = vanime.front();
    Personnage *omega = vanime.front();

    for_each(
            vanime.begin(),
            vanime.end(),
            [&alpha, &omega](Personnage *x)
            {
                // alpha's name is "greater" than x's name,
                // alpha should be "smallest",
                // fix that
                if (alpha->name().compare(x->name()) > 0)
                { alpha = x; }

                // omega's name is "smaller" than x's name,
                // omega should be "greatest",
                // fix that
                if (omega->name().compare(x->name()) < 0)
                { omega = x; }
            });

    cout << endl << "alpha: " << alpha->name() << " omega: " << omega->name() << endl;




    // we copied pointers in vanime, we didn't call 'new()' -- no need to delete from both collections
    //for_each(vanime.begin(), vanime.end(), [](auto *x)
    //{ delete x; });

    for(auto character : vanime )
        delete character;
    return 0;
}
