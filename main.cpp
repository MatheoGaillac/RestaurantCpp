#include <iostream>
#include "Client.hpp"
#include "ClientFidele.hpp"
#include "Plat.hpp"
#include "Commande.hpp"

int main() {
    Plat* plat1 = new Plat("Pizza Margherita", 15.0, {"tomates", "mozzarella", "basilic"}, true);
    Plat* plat2 = new Plat("Spaghetti bolognaise", 15.0, {"pates", "sauce bolognaise", "parmesan"}, true);

    Client* client1 = new Client("Jean Dupuis", "06 11 22 33 44");
    ClientFidele* clientFidele1 = new ClientFidele("Claire Bernard", "06 78 90 12 34", 10.5);

    Commande commande1(101, client1);
    std::vector<Plat*> platsCommandes1 = {plat1, plat2};
    commande1.setPlatsCommandes(platsCommandes1);

    Commande commande2(102, clientFidele1);
    commande2.addPlatsCommandes(plat2);

    std::cout << "=== Affichage de la commande 1 ===" << std::endl;
    commande1.afficherCommande();

    std::cout << "\n=== Affichage de la commande 2 ===" << std::endl;
    commande2.afficherCommande();

    delete plat1;
    delete plat2;
    delete client1;
    delete clientFidele1;

    return 0;
}