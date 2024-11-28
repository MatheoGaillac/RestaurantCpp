#ifndef COMMANDE_H
#define COMMANDE_H

#include <vector>
#include "Plat.hpp"
#include "Client.hpp"

class Commande{
    private:
        int m_numeroCommande;
        std::vector<Plat*> m_platsCommandes; //Vecteur de la classe Plat afin d'éviter les copies inutiles
        float m_total;
        bool m_estServie;
        Client* m_client; //Même raison que les plats

        void calculerTotal();

    public:
        Commande(int numeroCommande, Client* client);

        int getNumeroCommande() const;
        std::vector<Plat*> getPlatsCommandes() const;
        float getTotal() const;
        bool getEstServie() const;
        Client* getClient() const;

        void setNumeroCommande(int numeroCommande);
        void setPlatsCommandes(const std::vector<Plat*>& platsCommandes);
        void setTotal(float total);
        void setEstServie(bool estServie);

        void addPlatsCommandes(Plat* plat); //Différents du setter, ici c'est pour ajouter
        void afficherCommande() const;
};

#endif