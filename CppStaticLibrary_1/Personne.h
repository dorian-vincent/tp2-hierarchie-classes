/**
 * \file Personne.h
 * \brief Déclaration de la classe Personne
 * \author Dorian
 *
 * Ce fichier contient la déclaration de la classe Personne, qui représente une personne
 * dans le cadre d'une application électorale. La classe inclut des informations personnelles
 * telles que le NAS, le prénom, le nom, l'adresse et la date de naissance, ainsi que des méthodes
 * pour accéder et manipuler ces informations.
 */

#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <memory>
#include "Date.h"
#include "ValidationFormat.h"

namespace elections {

    /**
     * \class Personne
     * \brief Classe représentant une personne.
     * 
     * La classe Personne permet de modéliser une personne avec un numéro d'assurance sociale (NAS),
     * un prénom, un nom, une adresse et une date de naissance. Elle permet de manipuler ces informations,
     * de vérifier leur validité, et d'effectuer des opérations telles que la modification de l'adresse
     * et la comparaison de personnes.
     */
    class Personne {
    public:
        /**
         * \brief Constructeur de la classe Personne.
         * 
         * Le constructeur initialise une personne avec les valeurs fournies pour le NAS, le prénom,
         * le nom, l'adresse et la date de naissance.
         * 
         * \param[in] nas Le numéro d'assurance sociale de la personne.
         * \param[in] prenom Le prénom de la personne.
         * \param[in] nom Le nom de la personne.
         * \param[in] adresse L'adresse de la personne.
         * \param[in] dateNaissance La date de naissance de la personne.
         * 
         * \pre Le NAS, le prénom, le nom et l'adresse doivent être non vides. Le NAS doit être valide.
         * \post La personne est correctement initialisée avec les valeurs passées en paramètre.
         */
        Personne(const std::string& nas, const std::string& prenom, const std::string& nom,
                 const std::string& adresse, const util::Date& dateNaissance);

        /**
         * \brief Destructeur de la classe Personne.
         * 
         * Le destructeur nettoie la mémoire allouée pour l'objet Personne.
         */
        virtual ~Personne();

        /**
         * \brief Crée une copie polymorphique de l'objet courant.
         * 
         * Cette méthode retourne une copie unique de la personne actuelle, permettant ainsi de créer
         * un clone exact de l'objet courant.
         * 
         * \return Un pointeur unique vers une copie de l'objet Personne.
         */
        virtual std::unique_ptr<Personne> clone() const;

        /**
         * \brief Accesseur pour le NAS de la personne.
         * 
         * \return Le NAS de la personne.
         */
        const std::string& reqNas() const;

        /**
         * \brief Accesseur pour le prénom de la personne.
         * 
         * \return Le prénom de la personne.
         */
        const std::string& reqPrenom() const;

        /**
         * \brief Accesseur pour le nom de la personne.
         * 
         * \return Le nom de la personne.
         */
        const std::string& reqNom() const;

        /**
         * \brief Accesseur pour l'adresse de la personne.
         * 
         * \return L'adresse de la personne.
         */
        const std::string& reqAdresse() const;

        /**
         * \brief Accesseur pour la date de naissance de la personne.
         * 
         * \return La date de naissance de la personne.
         */
        const util::Date& reqDateNaissance() const;

        /**
         * \brief Modifie l'adresse de la personne.
         * 
         * Cette méthode permet de changer l'adresse de la personne en la remplaçant par une nouvelle.
         * 
         * \param[in] nouvelleAdresse La nouvelle adresse de la personne.
         * 
         * \pre La nouvelle adresse doit être non vide.
         * \post L'adresse de la personne est mise à jour avec la nouvelle valeur.
         */
        void changerAdresse(const std::string& nouvelleAdresse);

        /**
         * \brief Comparaison de deux personnes.
         * 
         * Cette méthode compare deux personnes en vérifiant si tous leurs attributs (NAS, prénom,
         * nom, adresse et date de naissance) sont identiques.
         * 
         * \param[in] autre L'autre personne à comparer avec l'objet courant.
         * \return \c true si les deux personnes sont égales, \c false sinon.
         */
        bool operator==(const Personne& autre) const;

        /**
         * \brief Retourne une représentation formatée de la personne.
         * 
         * Cette méthode génère une chaîne de caractères représentant les informations de la personne,
         * avec un formatage spécifique.
         * 
         * \return Une chaîne formatée contenant les informations de la personne.
         */
        virtual std::string reqPersonneFormate() const;

    protected:
        std::string m_nas;    
        std::string m_prenom; 
        std::string m_nom;    
        std::string m_adresse;
        util::Date m_dateNaissance;

        /**
         * \brief Vérifie les invariants de la classe Personne.
         * 
         * Cette méthode vérifie que l'objet Personne respecte ses invariants, tels que la validité
         * du NAS, du prénom, du nom, de l'adresse et de la date de naissance.
         */
        void verifieInvariant() const;
    };
}

#endif /* PERSONNE_H */

