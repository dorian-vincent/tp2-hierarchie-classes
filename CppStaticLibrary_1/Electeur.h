/**
 * \file Electeur.h
 * \brief Déclaration de la classe Electeur
 * \author Dorian
 * 
 * Ce fichier contient la déclaration de la classe `Electeur`, une classe dérivée de `Personne`
 * représentant un électeur dans un système électoral. La classe permet de gérer les informations
 * spécifiques d'un électeur, tout en héritant des informations générales d'une personne.
 */

#ifndef ELECTEUR_H_
#define ELECTEUR_H_

#include "Personne.h"
#include <string>
#include <memory>

namespace elections {

    /**
     * \class Electeur
     * \brief Classe dérivée de Personne représentant un électeur.
     *
     * La classe `Electeur` est une extension de la classe `Personne`. Elle ajoute la fonctionnalité
     * de représenter un électeur, c'est-à-dire une personne enregistrée pour voter dans un système
     * électoral. L'électeur hérite des attributs d'une personne et inclut des méthodes pour cloner
     * l'objet et obtenir une représentation formatée de ses informations.
     */
    class Electeur : public Personne {
    public:
        /**
         * \brief Constructeur avec paramètres.
         * 
         * Le constructeur initialise un électeur avec les informations fournies, comme le NAS, le prénom,
         * le nom, l'adresse et la date de naissance. Ces informations sont transmises au constructeur de
         * la classe de base `Personne`.
         * 
         * \param[in] nas Le numéro d'assurance sociale de l'électeur.
         * \param[in] prenom Le prénom de l'électeur.
         * \param[in] nom Le nom de l'électeur.
         * \param[in] adresse L'adresse de l'électeur.
         * \param[in] dateNaissance La date de naissance de l'électeur.
         * 
         * \pre Les paramètres doivent respecter les préconditions de la classe de base `Personne`.
         * \post L'objet `Electeur` est construit avec succès.
         */
        Electeur(const std::string& nas, const std::string& prenom, const std::string& nom,
                 const std::string& adresse, const util::Date& dateNaissance);

        /**
         * \brief Retourne une copie polymorphique de l'objet courant.
         * 
         * Cette méthode retourne une copie de l'objet courant en utilisant un pointeur unique vers
         * un nouvel objet `Electeur` contenant les mêmes informations.
         * 
         * \return Un pointeur unique vers une copie de l'objet `Electeur`.
         */
        std::unique_ptr<Personne> clone() const override;

        /**
         * \brief Retourne une chaîne formatée contenant les informations de l'électeur.
         * 
         * Cette méthode retourne une chaîne formatée représentant les informations d'un électeur,
         * incluant son NAS, prénom, nom, date de naissance et adresse.
         * 
         * \return Une chaîne formatée contenant les informations de l'électeur.
         * \post La chaîne retournée inclut les informations de la classe de base `Personne`.
         */
        std::string reqPersonneFormate() const override;
    };

}

#endif /* ELECTEUR_H_ */

