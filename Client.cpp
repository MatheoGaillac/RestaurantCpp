#include <iostream>
#include "Client.hpp"

Client::Client(){
    m_nom = "";
    m_numero = "";
}

Client::Client(const std::string &nom, const std::string &numero)
{
    m_nom = nom;
    m_numero = numero;
}

const std::string &Client::getNom() const { return m_nom; }
const std::string &Client::getNumero() const { return m_numero; }
float Client::getRemise() const { return 0.0; } //Return 0 car les clients de base n'ont pas de remise

void Client::setNom(const std::string &nom)
{
    m_nom = nom;
}

void Client::setNumero(const std::string &numero)
{
    m_numero = numero;
}

void Client::afficherDetails() const
{
    std::cout << "Nom du client : " << m_nom << std::endl;
    std::cout << "Numero du client : " << m_numero << std::endl;
}