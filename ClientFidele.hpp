#ifndef CLIENTFIDELE_H
#define CLIENTFIDELE_H

#include <string>
#include "Client.hpp"

class ClientFidele : public Client{
    private:
        float m_remise;

    public:
        ClientFidele(const std::string& nom, const std::string& numero, float remise);

        float getRemise() const;
        
        void setRemise(float remise);
        
        void afficherDetails() const override;
};

#endif