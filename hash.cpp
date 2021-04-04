#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

hash1::hash1()
{
    for (int i = 0; i < tailleTableau; i++)
    {
        HashTable[i] = new item;
        HashTable[i]->nom = "vide";
        HashTable[i]->tel = "vide";
        HashTable[i]->next = NULL;
    }
}

int hash1::HASH(string cle)
{
    int index;
    int hashage = 0;
    for (int i = 0; i < cle.length(); i++)
    {
        hashage = hashage + (int)cle[i];
    }
    index = hashage % tailleTableau;
    return index;
}

void hash1::ajouterItem(string nom, string tel)
{
    int index = HASH(nom);
    if (HashTable[index]->nom == "vide" && HashTable[index]->tel == "vide")
    {
        HashTable[index]->nom = nom;
        HashTable[index]->tel = tel;
    }
    else
    {
        item *elts = HashTable[index]->next;
        item *precedent = HashTable[index];

        while (elts != NULL)
        {
            precedent = elts;
            elts = elts->next;
        }
        elts = new item;
        elts->nom = nom;
        elts->tel = tel;
        elts->next = NULL;
        precedent->next = elts;
    }
    cout << "the item has been added successfuly into index:" << index << endl;
}

int hash1::nombreItems(int index)
{
    int count = 1;
    item *elts = HashTable[index]->next;
    while (elts != NULL)
    {
        count++;
        elts = elts->next;
    }
    cout << "Le nombre des items dans l'index " << index << " est : " << count << endl;
    return count;
}

void hash1::afficherItemsDansIndex(int index)
{
    cout << "Le nom est : " << HashTable[index]->nom << endl;
    cout << "le numero de telephone est : " << HashTable[index]->tel << endl;
    item *elts = HashTable[index]->next;
    while (elts != NULL)
    {
        cout << "Le nom est : " << elts->nom << endl;
        cout << "le numero de telephone est : " << elts->tel << endl;
        elts = elts->next;
    }
}

void hash1::chercherItem(string nom)
{
    int indice = HASH(nom);
    item *element = HashTable[indice];
    while (element != NULL)
    {
        if (strcmp((element->nom).c_str(), nom.c_str()) == 0)
        {
            cout << nom;
            cout << " trouvee avec succes a l'idice " << indice << endl;
            break;
        }
        else
        {
            cout << "element untrouvable" << endl;
        }
        element = element->next;
    }
}

void hash1::supprimerItem(string nom)
{
    int index = HASH(nom);
    item *parcour = HashTable[index];
    item *precedent = parcour;
    item *supprimer = parcour;
    while (parcour != NULL)
    {
        if (parcour->nom == nom)
        {
            supprimer = parcour;
            break;
        }
        precedent = parcour;
        parcour = parcour->next;
    }
    precedent->next = supprimer->next;
    cout << "le nom : " << supprimer->nom << " tel :" << supprimer->tel << " est supprimee avec succes " << endl;
    delete (supprimer);
}
