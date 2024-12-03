#include <iostream>
#include "Plat.hpp"

Plat::Plat(const std::string &nom)
{
    m_nom = nom;
    m_prix = 0.0;
    m_ingredients = {""};
    m_disponible = false;
}

Plat::Plat(const std::string &nom, float prix, const std::vector<std::string> &ingredients, bool disponible)
{
    m_nom = nom;
    m_prix = prix;
    m_ingredients = ingredients;
    m_disponible = disponible;
}

const std::string &Plat::getNom() const { return m_nom; }
float Plat::getPrix() const { return m_prix; }
const std::vector<std::string> Plat::getIngredients() const { return m_ingredients; }
bool Plat::getDiponibilite() const { return m_disponible; }

void Plat::setNom(const std::string &nom)
{
    m_nom = nom;
}

void Plat::setPrix(float prix)
{
    m_prix = prix;
}

void Plat::setIngredients(std::vector<std::string> &ingredients)
{
    m_ingredients = ingredients;
}

void Plat::setDiponibilite(bool disponible)
{
    m_disponible = disponible;
}

void Plat::afficherPlat() const
{
    std::cout << "\tNom du plat : " << m_nom << std::endl;
    std::cout << "\tPrix du plat : " << m_prix << std::endl;
    std::cout << "\tIngredients : ";
    for (const auto& ingredient : m_ingredients){
        std::cout << ingredient << ", ";
    }
    std::cout << "\n\tDisponibilite : " << (m_disponible ? "Oui\n" : "Non\n") << std::endl;//Ternaire pour afficher la réponse
}

bool operator==(Plat p1, Plat p2)
{
    return (p1.getPrix() == p2.getPrix());
}

bool operator>(Plat p1, Plat p2)
{
    return (p1.getPrix() > p2.getPrix());
}