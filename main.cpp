#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include "Client.hpp"
#include "ClientFidele.hpp"
#include "Plat.hpp"
#include "Commande.hpp"

int main()
{
    // //Création d'objet pour manipuler les différentes fonctionnalités du programme
    // Plat* plat1 = new Plat("Pizza Margherita", 15.0, {"tomates", "mozzarella", "basilic"}, true);
    // Plat* plat2 = new Plat("Spaghetti bolognaise", 15.0, {"pates", "sauce bolognaise", "parmesan"}, true);

    // Client* client1 = new Client("Jean Dupuis", "06 11 22 33 44");
    // ClientFidele* clientFidele1 = new ClientFidele("Claire Bernard", "06 78 90 12 34", 10);

    // Commande commande1(101, client1);
    // std::vector<Plat*> platsCommandes1 = {plat1, plat2};
    // commande1.setPlatsCommandes(platsCommandes1);

    // Commande commande2(102, clientFidele1);
    // commande2.addPlatsCommandes(plat2);

    // std::cout << "=== Affichage de la commande 1 ===" << std::endl;
    // commande1.afficherCommande();

    // std::cout << "\n=== Affichage de la commande 2 ===" << std::endl;
    // commande2.afficherCommande();

    // //Supression dynamique de l'allocation mémoire des objets
    // delete plat1;
    // delete plat2;
    // delete client1;
    // delete clientFidele1;

    // Utilisation du programme par lecture d'un fichier csv (Liste des plats) puis création d'un fichier texte pour chaque commande
    Client *client1 = new Client("Jean Dupuis", "06 11 22 33 44");
    ClientFidele *clientFidele1 = new ClientFidele("Claire Bernard", "06 78 90 12 34", 10);

    std::ifstream fichier("Plats.csv");
    std::string ligne, nom, ingredient, disponibilite;
    std::vector<std::string> ingredients;
    double prix;

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
        while (std::getline(issIngredients, ingredient, ';')){
            ingredients.push_back(ingredient);
        }

        std::getline(iss, disponibilite);

        std::cout << "Nom: " << nom << std::endl;
        std::cout << "Prix: " << prix << " euros" << std::endl;
                std::cout << "Ingredients: ";
        for (const auto& ing : ingredients) {
            std::cout << ing << ", ";
        }
        std::cout << std::endl;
        std::cout << "Disponible: " << (disponibilite == "TRUE" ? "Oui" : "Non") << std::endl;
    }
    fichier.close();

    return 0;
}