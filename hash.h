#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

class hash1
{
private:
    static const int tailleTableau = 10;
    struct item
    {
        string nom;
        string tel;
        item *next;
    };
    item *HashTable[tailleTableau];

public:
    hash1();
    int HASH(string cle);
    void ajouterItem(string nom, string tel);
    int nombreItems(int index);
    void afficherItemsDansIndex(int index);
    void chercherItem(string nom);
    void supprimerItem(string nom);
};
#endif