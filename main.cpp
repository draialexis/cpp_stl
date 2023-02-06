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
    auto end = std::end(liste);
    auto result = find_if(std::begin(liste), end, [hp](auto p)
    { return p->hp() < hp; });

    return result != end ? *result : nullptr;
}

int main()
{

    list<Personnage *> anime_list = {new Personnage("Eric", 1),
                                     new Kenny(),
                                     new Kenny("Benny", 2)};

    for (Personnage *character: anime_list)
    {
        character->parler("Hey dude.");
    }

    cout << endl;
    anime_list.front()->parler("I'm in the front");
    anime_list.back()->parler("I'm in the back");

    Personnage *second = *(next(anime_list.begin()));
    cout << endl;
    second->parler("I'm here too");
    // that sucked

    cout << endl;
    anime_list.insert(next(anime_list.begin()), new Personnage("Stan", 12));

    for (Personnage *character: anime_list)
    {
        character->parler("Hey dude.");
    }

    cout << endl;
    vector<Personnage *> anime_vector;

    for (Personnage *character: anime_vector)
    {
        character->parler("Hey dude.");
    }

    cout << endl;
    copy(anime_list.begin(), anime_list.end(), back_inserter(anime_vector));


    for (Personnage *character: anime_vector)
    {
        character->parler("Hey dude.");
    }

    cout << endl;
    anime_vector[2]->parler("I'm third");
    auto kyle = new Personnage("Kyle", 15);
    anime_vector.insert(next(anime_vector.begin()), kyle);

    cout << endl;
    for (Personnage *character: anime_vector)
    {
        character->parler("Hey dude.");
    }

    Personnage *alpha = anime_vector.front();
    Personnage *omega = anime_vector.front();

    for_each(
            anime_vector.begin(),
            anime_vector.end(),
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

    // delete only element only present in anime_vector
//     delete kyle;  // Ça pue. Kyle est détruit mais son pointeur doit encore être présent dans la liste!

    auto kill = remove_if(std::begin(anime_vector), std::end(anime_vector),
                          [kyle](Personnage *p)
                          { return p == kyle; }
    );
    anime_vector.erase(kill, std::end(anime_vector));

    auto *otherKenny = new Kenny("Kenny", 12);
    anime_list.push_back(otherKenny);

    for (Personnage *character: anime_list)
    {
        cout << character->name() << ":\n\t";
        character->parler("hi");
    }
    cout << endl;

    auto found = remove_if(std::begin(anime_vector), std::end(anime_vector),
                           [](Personnage *p)
                           { return dynamic_cast<Kenny *>(p) != nullptr; }
    );
    anime_vector.erase(found, std::end(anime_vector));

    for (Personnage *character: anime_list)
    {
        character->parler("I survived");
    }

    string name = "aziudga";
    for (int i = 0; i < 10; ++i)
    {
        name += std::to_string(i);
        anime_list.push_back(new Personnage(name, int(name.length())));
    }

    for (Personnage *character: anime_list)
    {
        character->parler("sup");
        cout << character->hp() << " HP" << endl;
    }

    for (auto p = anime_list.rbegin(); p != anime_list.rend(); ++p)
    {
        (*p)->parler("hey");
    }

    multimap<string, Personnage *> mm;
    for (auto character: anime_list)
    {
        mm.insert({character->name(), character});
    }

    if (auto found2 = mm.find("Eric"); found2 != mm.end())
    {
        found2->second->parler("wazaaaaaa'");
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

    for (auto character: anime_list)
    {
        if (character->hp() < 3)
        {
            cout << "found one: " << character->name() << "(" << character << ")" << endl;
            break;
        }
    }

    auto pv = 3;
    auto harmed = find_if(std::begin(anime_vector), std::end(anime_vector), [pv](auto p)
    { return p->hp() < pv; });
    if (harmed != std::end(anime_vector))
        cout << "found one harmed: " << (*harmed)->name() << "(" << (*harmed) << ")" << endl;

    auto x = find_half_dead(4, anime_list);
    if (x != nullptr)
    {
        cout << "found one with function: " << x->name() << "(" << x << ")" << endl;
    }

    sort(anime_vector.begin(), anime_vector.end(), [](Personnage *p1, Personnage *p2)
    {
        return p1->name() < p2->name();
    });

    for (auto character: anime_vector)
    {
        cout << character->name() << endl;
    }


    sort(anime_vector.begin(), anime_vector.end(), [](Personnage *p1, Personnage *p2)
    {
        return (p1->hp() != p2->hp())
               ? (p1->hp() < p2->hp())
               : (p1->name() < p2->name());
    });

    for (auto character: anime_vector)
    {
        cout << character->name() << " : " << character->hp() << endl;
    }

    shuffle(anime_vector.begin(), anime_vector.end(), std::mt19937(std::random_device()()));

    for (auto character: anime_vector)
    {
        cout << character->name() << endl;
    }

    // no random access iterators on lists...

    cout << endl << "permutations" << endl << endl;
    do
    {
        for (auto character: anime_vector)
        {
            cout << character->name() << endl;
        }
        cout << endl;
    } while (next_permutation(anime_vector.begin(), anime_vector.end()));
    /* not sure that this is working
     * shows "Stan
     *        Eric"
     * instead of  "Stan
     *              Eric
     *
     *              Eric
     *              Stan"
     */

    delete (kyle); // above, we removed the element from the vector, now we free the memory
    for (auto character: anime_list)
        delete character;
    return 0;
}
