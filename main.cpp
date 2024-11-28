#include <iostream>
#include <fstream>
#include <cassert>
#include "Client.hpp"
#include "ClientFidele.hpp"
#include "Plat.hpp"
#include "Commande.hpp"

int main() {
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

    //Utilisation du programme par lecture d'un fichier texte (Liste des plats) puis création d'un fichier texte pour chaque commande
    Client* client1 = new Client("Jean Dupuis", "06 11 22 33 44");
    ClientFidele* clientFidele1 = new ClientFidele("Claire Bernard", "06 78 90 12 34", 10);

    std::vector<std::string> listePlats;
    std::string str;

    std::ifstream read_file("Plats.txt");
    assert(read_file.is_open());

    while (getline(read_file, str)){
        listePlats.push_back(str);
    }

    for (const auto& plat: listePlats){
        std::cout << plat << "\n";
    }

    return 0;
}