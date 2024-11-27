#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client{
    protected:
        std::string m_nom;
        std::string m_numero;

    public:
        Client (const std::string& nom, std::string& numero);

        const std::string& getNom() const;
        const std::string& getNumero() const;

        void setNom(const std::string& nom);
        void setNumero(const std::string& numero);

        virtual void afficherDetails() const;
};

#endif