/**
 * \file PersonneTest.cpp
 * \brief Tests unitaires pour la classe Personne
 * \author Dorian
 * 
 * Ce fichier contient les tests unitaires pour les fonctionnalités
 * de la classe Personne, en utilisant le framework Google Test.
 */
#include <gtest/gtest.h>
#include "Personne.h"
#include "ContratException.h"
#include "Date.h"

using namespace elections;

/**
 * \brief Test du constructeur de la classe Personne avec des valeurs normales.
 * 
 * Ce test vérifie que les attributs de la classe Personne sont correctement
 * initialisés avec des valeurs valides.
 * 
 * \test Vérifie les valeurs initiales des attributs `reqNas`, `reqPrenom`, `reqNom`, 
 * `reqAdresse`, et `reqDateNaissance` après l'initialisation.
 */
TEST(Personne, personneNormal)
{
    util::Date aniv(1, 12, 2003);
    Personne tim("640 454 286", "tim", "paul", "105 av. JP", aniv); 
    
    ASSERT_EQ("640 454 286", tim.reqNas());
    ASSERT_EQ("tim", tim.reqPrenom());
    ASSERT_EQ("paul", tim.reqNom());
    ASSERT_EQ("105 av. JP", tim.reqAdresse());
    ASSERT_EQ(1, tim.reqDateNaissance().reqJour());
    ASSERT_EQ(12, tim.reqDateNaissance().reqMois());
    ASSERT_EQ(2003, tim.reqDateNaissance().reqAnnee());
}

/**
 * \brief Test de la méthode `changerAdresse`.
 * 
 * Ce test vérifie que la méthode `changerAdresse` met à jour l'adresse de la Personne.
 * 
 * \test Vérifie que l'attribut `m_adresse` est correctement mis à jour.
 */
TEST(Personne, TestChangerAdresse) {
    util::Date dateNaissance {1, 12, 2003};
    Personne personne1{"640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance};
    personne1.changerAdresse("200 av. liberte");
    ASSERT_EQ("200 av. liberte", personne1.reqAdresse());
}

/**
 * \brief Test de l'opérateur d'égalité `operator==`.
 * 
 * Ce test vérifie que l'opérateur d'égalité compare correctement deux instances
 * de la classe Personne.
 * 
 * \test Vérifie que deux instances avec les mêmes attributs sont égales, et
 * que deux instances différentes ne le sont pas.
 */
TEST(Personne, TestOperatorEqual) {
    util::Date dateNaissance {1, 12, 2003};
    Personne personne1{"640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance};
    Personne personne2{"640 454 286", "Lolo", "Nime", "10 rue jean jauraise", dateNaissance};
    Personne personne3 = personne1;
    ASSERT_TRUE(personne1 == personne3);
    ASSERT_FALSE(personne1 == personne2);
}

/**
 * \brief Test de la méthode `reqPersonneFormate`.
 * 
 * Ce test vérifie que la méthode `reqPersonneFormate` retourne une chaîne de caractères
 * correctement formatée.
 * 
 * \test Vérifie que la chaîne formatée inclut tous les attributs de la Personne.
 */
TEST(PersonneTest, TestReqPersonneFormate) {
    util::Date dateNaissance {1, 12, 2003};
    Personne personne1{"640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance};
    std::string expectedFormat = "NAS  : 640 454 286\n"
                                 "Prenom   : Tim\n"
                                 "Nom  : Paul\n"
                                 "Date de naissance    : Lundi le 01 decembre 2003\n"
                                 "Adresse  : 105 av. JP";
    ASSERT_EQ(expectedFormat, personne1.reqPersonneFormate());
}

/**
 * \brief Test de la méthode `clone`.
 * 
 * Ce test vérifie que la méthode `clone` retourne une copie conforme de l'objet courant.
 * 
 * \test Vérifie que tous les attributs de l'objet cloné sont identiques à ceux de l'objet d'origine.
 */
TEST(Personne, TestClone) {
    util::Date dateNaissance {1, 12, 2003};
    Personne personne1{"640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance};
    
    Personne* clonePersonne = personne1.clone().release();
    ASSERT_EQ(personne1.reqNas(), clonePersonne->reqNas());
    ASSERT_EQ(personne1.reqPrenom(), clonePersonne->reqPrenom());
    ASSERT_EQ(personne1.reqNom(), clonePersonne->reqNom());
    ASSERT_EQ(personne1.reqAdresse(), clonePersonne->reqAdresse());
    ASSERT_EQ(personne1.reqDateNaissance().reqJour(), clonePersonne->reqDateNaissance().reqJour());
}

