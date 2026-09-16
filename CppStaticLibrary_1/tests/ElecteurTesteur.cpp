/**
 * \file ElecteurTest.cpp
 * \brief Tests unitaires pour la classe Electeur
 * \author Dorian
 * 
 * Ce fichier contient les tests unitaires pour les fonctionnalités
 * de la classe Electeur, utilisant le framework Google Test.
 */

#include <gtest/gtest.h>
#include "Electeur.h"
#include "Date.h"

using namespace elections;

/**
 * \brief Test de la méthode `reqPersonneFormate` de la classe Electeur.
 * 
 * Ce test vérifie que la méthode retourne une chaîne de caractères formatée
 * avec les informations correctes pour un Electeur.
 * 
 * \test Vérifie que la chaîne retournée inclut les attributs `NAS`, `Prenom`,
 * `Nom`, `Date de naissance`, et `Adresse`.
 */
TEST(ElecteurTest, TestReqPersonneFormate) {
    util::Date dateNaissance(1, 12, 2003);
    Electeur electeur1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance);

    std::string expectedFormat = "Electeur\n"
                                 "----------------------------------------------\n"
                                 "NAS  : 640 454 286\n"
                                 "Prenom   : Tim\n"
                                 "Nom  : Paul\n"
                                 "Date de naissance    : Lundi le 01 decembre 2003\n"
                                 "Adresse  : 105 av. JP";
    ASSERT_EQ(expectedFormat, electeur1.reqPersonneFormate());
}

/**
 * \brief Test de la méthode `changerAdresse`.
 * 
 * Ce test vérifie que la méthode met à jour l'adresse de l'Electeur.
 * 
 * \test Vérifie que l'attribut `m_adresse` est correctement modifié après l'appel.
 */
TEST(ElecteurTest, TestChangerAdresse) {
    util::Date dateNaissance(1, 12, 2003);
    Electeur electeur1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance);

    electeur1.changerAdresse("200 av. Cartier");
    ASSERT_EQ("200 av. Cartier", electeur1.reqAdresse());
}

/**
 * \brief Test de l'opérateur d'égalité `operator==`.
 * 
 * Ce test vérifie que deux Electeurs sont considérés égaux si tous leurs attributs
 * sont identiques, et différents sinon.
 * 
 * \test Compare deux instances d'Electeur identiques et une instance différente.
 */
TEST(ElecteurTest, TestOperatorEqual) {
    util::Date dateNaissance(1, 12, 2003);
    Electeur electeur1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance);
    Electeur electeur2("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance);
    Electeur electeur3("046 454 385", "Johny", "Dab", "200 av. Miche", dateNaissance);

    ASSERT_TRUE(electeur1 == electeur2);
    ASSERT_FALSE(electeur1 == electeur3);
}

/**
 * \brief Test de la méthode `clone`.
 * 
 * Ce test vérifie que la méthode retourne une copie conforme de l'Electeur courant.
 * 
 * \test Vérifie que tous les attributs de l'Electeur cloné sont identiques à ceux
 * de l'Electeur original.
 */
TEST(ElecteurTest, TestClone) {
    util::Date dateNaissance(1, 12, 2003);
    Electeur electeur1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance);

    auto cloneElecteur = electeur1.clone();

    ASSERT_EQ(electeur1.reqNas(), cloneElecteur->reqNas());
    ASSERT_EQ(electeur1.reqPrenom(), cloneElecteur->reqPrenom());
    ASSERT_EQ(electeur1.reqNom(), cloneElecteur->reqNom());
    ASSERT_EQ(electeur1.reqAdresse(), cloneElecteur->reqAdresse());
    ASSERT_EQ(electeur1.reqDateNaissance().reqJour(), cloneElecteur->reqDateNaissance().reqJour());
    ASSERT_EQ(electeur1.reqDateNaissance().reqMois(), cloneElecteur->reqDateNaissance().reqMois());
    ASSERT_EQ(electeur1.reqDateNaissance().reqAnnee(), cloneElecteur->reqDateNaissance().reqAnnee());
}

