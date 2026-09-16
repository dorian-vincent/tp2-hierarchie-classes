/**
 * \file Candidat.h
 * \brief Déclaration de la classe Candidat
 * \author Dorian
 * 
 * Ce fichier contient la déclaration de la classe `Candidat`, représentant un candidat dans une élection. 
 * La classe hérite de la classe `Personne` et inclut des informations supplémentaires telles que le parti politique du candidat.
 */

#ifndef CANDIDAT_H_
#define CANDIDAT_H_

#include "Personne.h"
#include <string>
#include "Date.h"

/**
 * \enum PartisPolitiques
 * \brief Représente les partis politiques d'un candidat.
 * 
 * Cette énumération définit les différents partis politiques auxquels un candidat peut appartenir. 
 * Elle inclut des partis tels que le Bloc Québécois, le Parti Conservateur, le Parti Libéral, etc.
 */
namespace elections {
    enum PartisPolitiques {
        BLOC_QUEBECOIS,
        CONSERVATEUR,
        INDEPENDANT,
        LIBERAL,
        NOUVEAU_PARTI_DEMOCRATIQUE
    };

    /**
     * \class Candidat
     * \brief Classe représentant un candidat pour une élection.
     * 
     * La classe `Candidat` est une extension de la classe `Personne`, et inclut des informations supplémentaires 
     * comme le parti politique du candidat. Elle permet d'instancier un candidat avec des informations complètes 
     * telles que son numéro d'assurance sociale (NAS), prénom, nom, adresse, date de naissance et affiliation politique.
     */
    class Candidat : public Personne {
    public:
        /**
         * \brief Constructeur avec paramètres.
         * 
         * Le constructeur initialise un candidat avec toutes les informations nécessaires, y compris le parti politique.
         * 
         * \param[in] nas Le numéro d'assurance sociale du candidat.
         * \param[in] prenom Le prénom du candidat.
         * \param[in] nom Le nom du candidat.
         * \param[in] adresse L'adresse du candidat.
         * \param[in] dateNaissance La date de naissance du candidat.
         * \param[in] partiPolitique Le parti politique du candidat.
         * 
         * \pre Le paramètre `partiPolitique` doit être une valeur valide dans l'énumération `PartisPolitiques`.
         * \post L'objet `Candidat` est correctement initialisé avec les valeurs fournies.
         */
        Candidat(const std::string& nas, const std::string& prenom, const std::string& nom,
                 const std::string& adresse, const util::Date& dateNaissance, PartisPolitiques partiPolitique);

        /**
         * \brief Retourne le nom du parti politique du candidat.
         * 
         * Cette méthode retourne une chaîne de caractères représentant le nom du parti politique auquel le candidat appartient.
         * 
         * \return Le nom du parti politique sous forme de chaîne.
         * \post La chaîne retournée contient le nom du parti politique formaté correctement.
         */
        std::string reqPartiPolitique() const;

        /**
         * \brief Retourne une copie polymorphique de l'objet courant.
         * 
         * Cette méthode crée et retourne une nouvelle instance de `Candidat`, une copie exacte de l'objet courant.
         * 
         * \return Un pointeur unique vers une copie du candidat.
         */
        std::unique_ptr<Personne> clone() const override;

        /**
         * \brief Retourne une chaîne formatée contenant les informations du candidat.
         * 
         * Cette méthode génère une chaîne de caractères qui contient les informations formatées du candidat,
         * incluant son NAS, prénom, nom, date de naissance, adresse et le nom de son parti politique.
         * 
         * \return Une chaîne formatée avec les informations complètes du candidat.
         */
        std::string reqPersonneFormate() const override;

    private:
        PartisPolitiques m_partiPolitique; ///< Le parti politique du candidat.

        /**
         * \brief Vérifie les invariants de la classe.
         * 
         * Cette méthode vérifie que l'objet `Candidat` respecte les invariants de la classe, garantissant ainsi
         * la validité des données.
         * 
         * \post Les invariants de la classe sont respectés.
         */
        void verifieInvariant() const;
    };
}

#endif /* CANDIDAT_H_ */

