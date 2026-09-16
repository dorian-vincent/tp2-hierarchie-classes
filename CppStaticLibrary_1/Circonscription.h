/**
 * \file Circonscription.h
 * \brief Déclaration de la classe Circonscription
 * \author Dorian
 * 
 * Ce fichier contient la déclaration de la classe `Circonscription`, représentant une circonscription
 * électorale. Cette classe permet de gérer les informations de la circonscription, du député élu et
 * des personnes inscrites sur la liste électorale.
 */

#ifndef CIRCONSCRIPTION_H_
#define CIRCONSCRIPTION_H_

#include <string>
#include <vector>
#include <memory>
#include "Candidat.h"
#include "Personne.h"

namespace elections {

    /**
     * \class Circonscription
     * \brief Représente une circonscription électorale.
     * 
     * La classe `Circonscription` contient des informations sur le nom de la circonscription, le député élu
     * et la liste des personnes inscrites dans cette circonscription. Elle permet d'ajouter des électeurs et
     * d'obtenir des informations formatées sur la circonscription.
     */
    class Circonscription {
    public:
        /**
         * \brief Constructeur avec paramètres.
         * 
         * Le constructeur initialise une circonscription avec le nom de la circonscription et le député élu.
         * 
         * \param[in] nomCirconscription Le nom de la circonscription.
         * \param[in] deputeElu Le candidat élu comme député pour cette circonscription.
         * 
         * \pre Le nom de la circonscription ne doit pas être vide.
         * \pre Le candidat élu doit être valide.
         * \post La circonscription est correctement initialisée.
         */
        Circonscription(const std::string& nomCirconscription, const Candidat& deputeElu);

        /**
         * \brief Constructeur de copie.
         * 
         * Le constructeur de copie crée une nouvelle instance de `Circonscription` avec les mêmes données qu'une
         * autre instance existante.
         * 
         * \param[in] other L'instance de `Circonscription` à copier.
         * \post L'objet est correctement copié.
         */
        Circonscription(const Circonscription& other);

        /**
         * \brief Opérateur d'assignation.
         * 
         * L'opérateur d'assignation permet de copier les données d'une instance de `Circonscription` dans une autre.
         * 
         * \param[in] other L'instance de `Circonscription` à copier.
         * \return L'instance actuelle après l'assignation.
         * \post Les données sont correctement copiées.
         */
        Circonscription& operator=(const Circonscription& other);

        /**
         * \brief Inscrit une nouvelle personne dans la circonscription.
         * 
         * Cette méthode permet d'ajouter une personne (électeur ou autre) à la liste des inscrits de la circonscription.
         * 
         * \param[in] p_nouvelInscrit La personne à inscrire dans la circonscription.
         * 
         * \pre La personne à inscrire doit être valide.
         * \post La personne est inscrite et ajoutée à la liste des inscrits.
         */
        void inscrire(const Personne& p_nouvelInscrit);

        /**
         * \brief Retourne une chaîne formatée contenant les informations de la circonscription.
         * 
         * Cette méthode génère un résumé de la circonscription, incluant son nom, son député élu et la liste des
         * personnes inscrites.
         * 
         * \return Une chaîne contenant les informations de la circonscription.
         */
        std::string reqCirconscriptionFormate() const;

        // **Ajout des accesseurs manquants**
        /**
         * \brief Retourne le nom de la circonscription.
         * 
         * \return Le nom de la circonscription.
         */
        const std::string& reqNomCirconscription() const { return m_nomCirconscription; }

        /**
         * \brief Retourne le député élu de la circonscription.
         * 
         * \return Le député élu.
         */
        const Candidat& reqDeputeElu() const { return m_deputeElu; }

        /**
         * \brief Retourne le nombre d'électeurs inscrits dans la circonscription.
         * 
         * \return Le nombre d'électeurs inscrits.
         */
        size_t reqNombreElecteurs() const { return m_inscrits.size(); }

    private:
        /**
         * \brief Vérifie les invariants de la classe.
         * 
         * Cette méthode vérifie les conditions qui doivent être respectées pour garantir la validité de l'objet.
         * 
         * \post Les invariants sont respectés.
         */
        void verifieInvariant() const;

        std::string m_nomCirconscription;
        Candidat m_deputeElu;
        std::vector<std::unique_ptr<Personne>> m_inscrits; 
    };
}

#endif /* CIRCONSCRIPTION_H_ */

