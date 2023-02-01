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

    list<Personnage *> anime = {new Personnage("Eric", 8),
                                new Kenny(),
                                new Kenny("Benny", 13)};

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
    anime.insert(next(anime.begin()), new Personnage("Stan", 12));

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
    auto kyle = new Personnage("Kyle", 15);
    vanime.insert(next(vanime.begin()), kyle);
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

    cout << endl << "alpha: " << alpha->name() << " omega: " << omega->name() << endl << endl;

    // delete only element only present in vanime
    delete kyle;

    auto *otherKenny = new Kenny("Kenny", 18);
    anime.push_back(otherKenny);

    for (Personnage *character: anime)
    {
        cout << character->name() << ":\n\t";
        character->parler("hi");
    }
    cout << endl;

    auto begin = vanime.begin();
    auto end = vanime.end();

    for (auto p = begin; p != end; ++p)
    {
        cout << "typeid(character) == typeid(Kenny): "
             << typeid(*p).name() << "==" << typeid(Kenny).name() << ": "
             << (typeid(*p) == typeid(Kenny))
             << endl << endl;

        // FIXME
        if (typeid(*p) == typeid(Kenny))
        {
            vanime.erase(p);
        }
    }

    for (Personnage *character: anime)
    {
        character->parler("I survived");
    }

    string name = "aziudga";
    for (int i = 0; i < 10; ++i)
    {
        name += std::to_string(i);
        anime.push_back(new Personnage(name, int(name.length())));
    }

    for (Personnage *character: anime)
    {
        character->parler("sup");
        cout << character->hp() << " HP" << endl;
    }

    for (auto p = anime.rbegin(); p != anime.rend(); ++p)
    {
        (*p)->parler("hey");
    }

    for (auto character: anime)
        delete character;
    return 0;
}
