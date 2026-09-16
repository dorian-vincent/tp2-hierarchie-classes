/**
 * \file CirconscriptionTest.cpp
 * \brief Tests unitaires pour la classe Circonscription
 * \author Dorian
 * 
 * Ce fichier contient les tests unitaires pour valider les fonctionnalités de la classe
 * Circonscription, en utilisant le framework Google Test.
 */

#include <gtest/gtest.h>
#include "Circonscription.h"
#include "Electeur.h"
#include "Candidat.h"
#include "Date.h"

using namespace elections;

/**
 * \brief Test du constructeur de la classe Circonscription.
 * 
 * Ce test vérifie que la circonscription est correctement initialisée avec
 * un nom et un député élu, et que la liste d'inscrits est vide à l'initialisation.
 * 
 * \test Vérifie les valeurs des attributs `nomCirconscription`, `deputeElu` et `nombreElecteurs`.
 */
TEST(CirconscriptionTest, TestConstructeur) {
    util::Date dateNaissance(12, 5, 1979);
    Candidat deputeElu("046 454 286", "Jean", "Paul", "235, rue de l'Université, Québec", dateNaissance, PartisPolitiques::BLOC_QUEBECOIS);

    Circonscription circonscription("Circonscription n°1", deputeElu);

    ASSERT_EQ("Circonscription n°1", circonscription.reqNomCirconscription());
    ASSERT_EQ("Jean", circonscription.reqDeputeElu().reqPrenom());
    ASSERT_EQ(0, circonscription.reqNombreElecteurs());
}

/**
 * \brief Test de la méthode `inscrire`.
 * 
 * Ce test vérifie que la méthode ajoute un nouvel électeur à la liste
 * des inscrits de la circonscription.
 * 
 * \test Vérifie que `reqNombreElecteurs` retourne 1 après l'ajout.
 */
TEST(CirconscriptionTest, TestInscription) {
    util::Date dateNaissance(12, 5, 1979);
    Candidat deputeElu("046 454 286", "Jean", "Paul", "235, rue de l'Université, Québec", dateNaissance, PartisPolitiques::BLOC_QUEBECOIS);

    Circonscription circonscription("Circonscription n°1", deputeElu);

    Electeur electeur("640 454 286", "Joe", "Blot", "235, rue de l'Université, Québec", dateNaissance);

    circonscription.inscrire(electeur);

    ASSERT_EQ(1, circonscription.reqNombreElecteurs());
}

/**
 * \brief Test de l'inscription de plusieurs électeurs.
 * 
 * Ce test vérifie que plusieurs électeurs peuvent être ajoutés à la liste
 * des inscrits d'une circonscription.
 * 
 * \test Vérifie que `reqNombreElecteurs` retourne 2 après deux ajouts.
 */
TEST(CirconscriptionTest, TestInscriptionMultiple) {
    util::Date dateNaissance(12, 5, 1979);
    Candidat deputeElu("046 454 286", "Jean", "Paul", "235, rue de l'Université, Québec", dateNaissance, PartisPolitiques::BLOC_QUEBECOIS);

    Circonscription circonscription("Circonscription n°1", deputeElu);

    Electeur electeur1("640 454 286", "Joe", "Blot", "235, rue de l'Université, Québec", dateNaissance);
    Electeur electeur2("046 454 385", "Marie Anette", "Girard", "805, Av Trunbull, Québec", dateNaissance);

    circonscription.inscrire(electeur1);
    circonscription.inscrire(electeur2);

    ASSERT_EQ(2, circonscription.reqNombreElecteurs());
}

/**
 * \brief Test de la méthode `reqCirconscriptionFormate`.
 * 
 * Ce test vérifie que la méthode retourne une chaîne formatée contenant les
 * informations de la circonscription, du député élu, et des inscrits.
 * 
 * \test Compare la chaîne retournée avec un format attendu.
 */
TEST(CirconscriptionTest, TestReqCirconscriptionFormate) {
    util::Date dateNaissance(12, 5, 1979);
    Candidat deputeElu("046 454 286", "Jean", "Paul", "235, rue de l'Université, Québec", dateNaissance, PartisPolitiques::BLOC_QUEBECOIS);

    Circonscription circonscription("Circonscription n°1", deputeElu);

    Electeur electeur1("640 454 286", "Joe", "Blot", "235, rue de l'Université, Québec", dateNaissance);
    Electeur electeur2("046 454 385", "Marie Anette", "Girard", "805, Av Trunbull, Québec", dateNaissance);

    circonscription.inscrire(electeur1);
    circonscription.inscrire(electeur2);

    std::string expectedFormat =
        "Circonscription : Circonscription n°1\n"
        "Depute sortant :\n"
        "Candidat\n"
        "----------------------------------------------\n"
        "NAS  : 046 454 286\n"
        "Prenom   : Jean\n"
        "Nom  : Paul\n"
        "Date de naissance    : Samedi le 12 mai 1979\n"
        "Adresse  : 235, rue de l'Université, Québec\n"
        "Parti politique  : Bloc Québécois\n"
        "Liste des inscrits :\n"
        "Electeur\n"
        "----------------------------------------------\n"
        "NAS  : 640 454 286\n"
        "Prenom   : Joe\n"
        "Nom  : Blot\n"
        "Date de naissance    : Samedi le 12 mai 1979\n"
        "Adresse  : 235, rue de l'Université, Québec\n"
        "Electeur\n"
        "----------------------------------------------\n"
        "NAS  : 046 454 385\n"
        "Prenom   : Marie Anette\n"
        "Nom  : Girard\n"
        "Date de naissance    : Samedi le 12 mai 1979\n"
        "Adresse  : 805, Av Trunbull, Québec\n";

    ASSERT_EQ(expectedFormat, circonscription.reqCirconscriptionFormate());
}

/**
 * \brief Test du constructeur par copie.
 * 
 * Ce test vérifie que la copie d'une circonscription contient les mêmes informations
 * que l'original, y compris les inscrits.
 * 
 * \test Compare les attributs d'une circonscription originale avec sa copie.
 */
TEST(CirconscriptionTest, TestConstructeurParCopie) {
    util::Date dateNaissance(12, 5, 1979);
    Candidat deputeElu("046 454 286", "Jean", "Louis", "235, rue de l'Université, Québec", dateNaissance, PartisPolitiques::BLOC_QUEBECOIS);

    Circonscription circonscriptionOriginale("Circonscription n°1", deputeElu);

    Electeur electeur1("640 454 286", "Joe", "Blo", "235, rue de l'Université, Québec", dateNaissance);
    circonscriptionOriginale.inscrire(electeur1);

    Circonscription circonscriptionCopie(circonscriptionOriginale);

    ASSERT_EQ(circonscriptionOriginale.reqNomCirconscription(), circonscriptionCopie.reqNomCirconscription());
    ASSERT_EQ(circonscriptionOriginale.reqNombreElecteurs(), circonscriptionCopie.reqNombreElecteurs());
}

