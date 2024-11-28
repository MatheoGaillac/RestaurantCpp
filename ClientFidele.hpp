#ifndef CLIENTFIDELE_H
#define CLIENTFIDELE_H

#include <string>
#include "Client.hpp"

class ClientFidele : public Client{
    private:
        float m_remise;

    public:
        ClientFidele(const std::string& nom, const std::string& numero, float remise);
        
        void setRemise(float remise);
      
        //Surchage des méthodes pour les modifier dans la sous-classe
        float getRemise() const override;
        void afficherDetails() const override;
};

#endif