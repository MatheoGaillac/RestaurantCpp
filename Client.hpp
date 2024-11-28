#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client{
    protected:
        std::string m_nom;
        std::string m_numero;

    public:
        Client();
        Client (const std::string& nom, const std::string& numero);

        const std::string& getNom() const;
        const std::string& getNumero() const;

        void setNom(const std::string& nom);
        void setNumero(const std::string& numero);

        //Méthodes virtuelles pour surcharger les méthodes  dans la sous-classe
        virtual float getRemise() const; //Application d'une remise pour les clients fidèles puisque sinon il était compliqué de l'appliquer sachant que les clients de base n'ont pas de remise
        virtual void afficherDetails() const; //Affichage de détails différents selon le type de client
};
#endif