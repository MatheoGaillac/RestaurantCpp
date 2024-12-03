#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Client.hpp"
#include "ClientFidele.hpp"
#include "Plat.hpp"
#include "Commande.hpp"

//Fonction de lecture d'un fichier CSV contenant des plats
std::vector<Plat*> readCSVPlats(const std::string &nomFichier)
{
    std::ifstream fichier("Plats.csv");
    std::string ligne, nom, ingredient, disponibilite;
    std::vector<std::string> ingredients;
    double prix;
    std::vector<Plat*> plats;

    assert(fichier.is_open() && "Impossible d'ouvrir le fichier");

    std::getline(fichier, ligne);

    while (std::getline(fichier, ligne))
    {
        std::istringstream iss(ligne);
        ingredients.clear();
        std::getline(iss, nom, ',');
        iss >> prix;
        iss.ignore();

        std::string ingredientStr;
        std::getline(iss, ingredientStr, ',');
        std::istringstream issIngredients(ingredientStr);
        while (std::getline(issIngredients, ingredient, ';'))
        {
            ingredients.push_back(ingredient);
        }

        std::getline(iss, disponibilite);

        Plat* plat = new Plat(nom, prix, ingredients, disponibilite == "TRUE" ? true : false);
        plats.push_back(plat);
    }
    fichier.close();
    return plats;
}

int main()
{
    //Création d'objet pour manipuler les différentes fonctionnalités du programme
/*  Plat* plat1 = new Plat("Pizza Margherita", 17.0, {"tomates", "mozzarella", "basilic"}, true);
    Plat* plat2 = new Plat("Spaghetti bolognaise", 15.0, {"pates", "sauce bolognaise", "parmesan"}, true);

    Client* client1 = new Client("Jean Dupuis", "06 11 22 33 44");
    ClientFidele* clientFidele1 = new ClientFidele("Claire Bernard", "06 78 90 12 34", 10);

    Commande commande1(101, client1);
    std::vector<Plat*> platsCommandes1 = {plat1, plat2};
    commande1.setPlatsCommandes(platsCommandes1);

    Commande commande2(102, clientFidele1);
    commande2.addPlatsCommandes(plat2);

    std::cout << "=== Affichage de la commande 1 ===" << std::endl;
    commande1.afficherCommande();

    std::cout << "\n=== Affichage de la commande 2 ===" << std::endl;
    commande2.afficherCommande();

    std::cout << plat1->getNom() << std::endl;
    std::cout << plat2->getNom() << std::endl;

    if (*plat1 == *plat2){
        std::cout << "Le prix de " << plat1->getNom() << " est egal au prix de " << plat2->getNom() << std::endl;
    } else if (*plat1 > *plat2){
        std::cout << plat1->getNom() << " est plus cher que " << plat2->getNom() << std::endl;
    } else {
        std::cout << plat1->getNom() << " est moins cher que " << plat2->getNom() << std::endl;
    }

    //Supression dynamique de l'allocation mémoire des objets
    delete plat1;
    delete plat2;
    delete client1;
    delete clientFidele1; */



    // Utilisation du programme pour lire un csv et créer des objets Plats
/*    std::vector<Plat*> plats = readCSVPlats("Plats.csv");

    // Création d'un fichier texte pour chaque commande passée
    Client *client1 = new Client("Jean Dupuis", "06 11 22 33 44");
    ClientFidele *clientFidele1 = new ClientFidele("Claire Bernard", "06 78 90 12 34", 10);

    Commande commande1(101, client1);
    commande1.addPlatsCommandes(plats[0]);
    
    Commande commande2(102, clientFidele1);
    commande2.addPlatsCommandes(plats[1]);
    commande2.addPlatsCommandes(plats[2]);

    commande1.sauvegarderDansFichier("Commande_101.txt");
    commande2.sauvegarderDansFichier("Commande_102.txt");

    for (auto& plat : plats) {
        delete plat;
    }
    delete client1;
    delete clientFidele1; */

    return 0;
}