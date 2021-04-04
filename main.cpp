#include <iostream>
#include <string>
#include "hash.h"
#include "hash.cpp"

using namespace std;

int main()
{
    hash1 hashObj;
    int index;
    hashObj.ajouterItem("kotbi", "0613678765");
    hashObj.ajouterItem("khalid", "0623678765");
    hashObj.ajouterItem("kamal", "0633678765");
    hashObj.ajouterItem("Taha", "0643678765");
    hashObj.ajouterItem("othmane", "0653678765");
    int nbItems = hashObj.nombreItems(8);
    hashObj.afficherItemsDansIndex(8);
    hashObj.chercherItem("othmane");
    hashObj.supprimerItem("othmane");
    nbItems = hashObj.nombreItems(8);
    return 0;
}
