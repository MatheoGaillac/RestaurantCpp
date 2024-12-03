#include <iostream>
#include <fstream>
#include <cassert>
#include "Commande.hpp"

Commande::Commande(int numeroCommande, Client* client)
{
    m_numeroCommande = numeroCommande;
    m_client = client;
    m_total = 0;
    m_estServie = false;
}

int Commande::getNumeroCommande() const { return m_numeroCommande; }
std::vector<Plat*> Commande::getPlatsCommandes() const { return m_platsCommandes; }
float Commande::getTotal() const { return m_total; }
bool Commande::getEstServie() const { return m_estServie; }
Client* Commande::getClient() const { return m_client; }

void Commande::setNumeroCommande(int numeroCommande)
{
    m_numeroCommande = numeroCommande;
}

void Commande::setPlatsCommandes(const std::vector<Plat*>& platsCommandes)
{
    m_platsCommandes = platsCommandes;
    calculerTotal();
}

void Commande::setTotal(float total)
{
    m_total = total;
}

void Commande::setEstServie(bool estServie)
{
    m_estServie = estServie;
}

void Commande::calculerTotal(){
    //Calcul du total de la commande sans remise
    m_total = 0;
    for (const auto& plat: m_platsCommandes){
        m_total += plat->getPrix();
    }

    //Ajout de la remise au total, 0 si c'est un Client classique et sinon la valeur pour ClientFidele
    float remise = m_client->getRemise();
    m_total -= (m_total * remise / 100.0);
}

void Commande::addPlatsCommandes(Plat* plat)
{
    m_platsCommandes.push_back(plat);
    calculerTotal();
}

void Commande::afficherCommande() const {
    std::cout << "Numero de la commande : " << m_numeroCommande << std::endl;
    m_client->afficherDetails();
    std::cout << "Plats commandes : " << std::endl;
    for (const auto& plat: m_platsCommandes){
        plat->afficherPlat();
    }
    std::cout << "Montant remise : " << m_client->getRemise() << "%" << std::endl;
    std::cout << "Total : " << m_total << "euros" << std::endl;
    std::cout << "Statut : " << (m_estServie ? "Servie" : "En preparation") << std::endl;//Ternaire pour afficher le statut
}

void Commande::sauvegarderDansFichier(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    assert(fichier.is_open());

    fichier << "Numero de la commande : " << m_numeroCommande << std::endl;
    fichier << "Client : " << m_client->getNom() << " (" << m_client->getNumero() << ")" << std::endl;
    fichier << "Plats commandes :" << std::endl;
    for (const auto& plat : m_platsCommandes) {
        fichier << "\tNom : " << plat->getNom() << std::endl;
        fichier << "\tDisponibilite : " << (plat->getDiponibilite() ? "Oui" : "Non") << std::endl;
    }
    fichier << "Montant remise : " << m_client->getRemise() << "%" << std::endl;
    fichier << "Total : " << m_total << " euros" << std::endl;
    fichier << "Statut : " << (m_estServie ? "Servie" : "En preparation") << std::endl;

    fichier.close();
}