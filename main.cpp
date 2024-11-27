#include <iostream>
#include "Plat.hpp"
#include "Client.hpp"
#include "Commande.hpp"

int main() {
    // Creation d'un client
    Client client1("Alice Dupont", "06 12 34 56 78");

    // Creation de quelques plats
    Plat plat1("Pizza Margherita", 12.5, {"tomates", "mozzarella", "basilic"}, true);
    Plat plat2("Spaghetti Bolognaise", 15.0, {"pates", "sauce bolognaise", "parmesan"}, true);
    Plat plat3("Tiramisu", 6.5, {"cafe", "mascarpone", "biscuit"}, true);

    // Creation de la commande
    Commande commande1(101, &client1);

    // Ajout des plats a la commande
    commande1.addPlatsCommandes(&plat1);
    commande1.addPlatsCommandes(&plat2);
    commande1.addPlatsCommandes(&plat3);

    // Affichage de la commande
    std::cout << "=== Commande 1 ===" << std::endl;
    commande1.afficherCommande();

    // Modification du statut de la commande
    commande1.setEstServie(true);

    // Affichage apres modification du statut
    std::cout << "\n=== Commande 1 apres modification du statut ===" << std::endl;
    commande1.afficherCommande();

    return 0;
}
