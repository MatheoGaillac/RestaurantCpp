#ifndef PLAT_H
#define PLAT_H

#include <vector>
#include <string>

class Plat {
    private:
        std::string m_nom;
        float m_prix;
        std::vector<std::string> m_ingredients;
        bool m_disponible;

    public:
        Plat(const std::string&);
        Plat(const std::string&, float, const std::vector<std::string>&, bool);

        const std::string& getNom() const;
        float getPrix() const;
        const std::vector<std::string> getIngredients() const;
        bool getDiponibilite() const;

        void setNom(const std::string&);
        void setPrix(float);
        void setIngredients(std::vector<std::string>&);
        void setDiponibilite(bool);

        void afficherPlat() const;
};

bool operator==(Plat p1, Plat p2);
bool operator>(Plat p1, Plat p2);

#endif