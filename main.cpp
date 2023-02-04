#include <iostream>
#include <random>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
#include <map>
#include "Personnage/Personnage.h"
#include "Personnage/Kenny.h"

using namespace std;

Personnage *find_half_dead(int hp, list<Personnage *> &liste)
{
    // TODO: Essayez d'utilisez un find_if avec une lambda
    for (auto character: liste)
    {
        if (character->hp() <= hp)
        {
            return character;
        }
    }
    return nullptr;

}

int main()
{

    list<Personnage *> anime = {new Personnage("Eric", 1),
                                new Kenny(),
                                new Kenny("Benny", 2)};

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
    // delete kyle;  // Ça pue. Kyle est détruit mais son pointeur doit encore être présent dans la liste!

    auto *otherKenny = new Kenny("Kenny", 12);
    anime.push_back(otherKenny);

    for (Personnage *character: anime)
    {
        cout << character->name() << ":\n\t";
        character->parler("hi");
    }
    cout << endl;

    auto found = remove_if(std::begin(vanime), std::end(vanime),
            [](Personnage *p){return dynamic_cast<Kenny*>(p) != nullptr; }
    );
    vanime.erase(found, std::end(vanime));

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

    multimap<string, Personnage *> mm;
    for (auto character: anime)
    {
        mm.insert({character->name(), character});
    }

    if (auto found = mm.find("Eric"); found != mm.end())
    {
        found->second->parler("wazaaaaaa'");
    }

    try
    {
        if (mm.find("Bleaoguroau") == mm.end())
        {
            throw exception();
        }
    } catch (const exception &e)
    {
        cout << "no luck" << endl;
        // cerr << "no luck" << endl;
        // does not display in main terminal
    }

    for (const auto &kvp: mm)
    {
        cout << kvp.first << " => " << kvp.second << endl;
    }

    for (auto character: anime)
    {
        if (character->hp() < 3)
        {
            cout << "found one: " << character->name() << "(" << character << ")" << endl;
            break;
        }
    }

    for (auto character: vanime)
    {
        if (character->hp() < 3)
        {
            cout << "found one: " << character->name() << "(" << character << ")" << endl;
            break;
        }
    }

    auto x = find_half_dead(4, anime);
    if (x != nullptr)
    {
        cout << "found one with function: " << x->name() << "(" << x << ")" << endl;
    }

    sort(vanime.begin(), vanime.end(), [](Personnage *p1, Personnage *p2)
    {
        return p1->name() < p2->name();
    });

    for (auto character: vanime)
    {
        cout << character->name() << endl;
    }


    sort(vanime.begin(), vanime.end(), [](Personnage *p1, Personnage *p2)
    {
        return (p1->hp() != p2->hp()) ? (p1->hp() < p2->hp()) : (p1->name() < p2->name());
    });

    for (auto character: vanime)
    {
        cout << character->name() << " : " << character->hp() << endl;
    }

    shuffle(vanime.begin(), vanime.end(), std::mt19937(std::random_device()()));

    for (auto character: vanime)
    {
        cout << character->name() << endl;
    }

    // no random access iterators on lists...

    cout << endl << "permutations" << endl << endl;
    do
    {
        for (auto character: vanime)
        {
            cout << character->name() << endl;
        }
        cout << endl;
    } while (next_permutation(vanime.begin(), vanime.end()));
    // FIXME

    for (auto character: anime)
        delete character;
    return 0;
}
