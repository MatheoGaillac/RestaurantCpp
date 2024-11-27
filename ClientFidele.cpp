#include <iostream>
#include "ClientFidele.hpp"

ClientFidele::ClientFidele(const std::string& nom, const std::string& numero, float remise)
{
    m_nom = nom;
    m_numero = numero;
    m_remise = remise;
}

float ClientFidele::getRemise() const { return m_remise;}

void ClientFidele::setRemise(float remise)
{
    m_remise = remise;
}

void ClientFidele::afficherDetails() const
{
    Client::afficherDetails();
    std::cout << "Remise accordée : " << m_remise << "%" << std::endl;
}