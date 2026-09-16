/**
 * \file CandidatTest.cpp
 * \brief Tests unitaires pour la classe Candidat
 * \author Dorian
 * 
 * Ce fichier contient les tests unitaires pour valider les fonctionnalités de la classe
 * Candidat en utilisant le framework Google Test.
 */

#include <gtest/gtest.h>
#include "Candidat.h"
#include "Date.h"

using namespace elections;

/**
 * \brief Test de la méthode `reqPersonneFormate` de la classe Candidat.
 * 
 * Ce test vérifie que la méthode retourne une chaîne correctement formatée contenant
 * les informations d'un candidat.
 * 
 * \test Compare la chaîne retournée avec un format attendu.
 */
TEST(CandidatTest, TestReqPersonneFormate) {
    util::Date dateNaissance(1, 12, 2003);
    Candidat candidat1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance, PartisPolitiques::BLOC_QUEBECOIS);
    
    std::string expectedFormat = "Candidat\n"
                                 "----------------------------------------------\n"
                                 "NAS  : 640 454 286\n"
                                 "Prenom   : Tim\n"
                                 "Nom  : Paul\n"
                                 "Date de naissance    : Lundi le 01 decembre 2003\n"
                                 "Adresse  : 105 av. JP\n"
                                 "Parti politique  : Bloc Québécois";
    ASSERT_EQ(expectedFormat, candidat1.reqPersonneFormate());
}

/**
 * \brief Test de l'opérateur `==` de la classe Candidat.
 * 
 * Ce test vérifie que deux candidats sont considérés égaux si leurs informations
 * sont identiques, et différents dans le cas contraire.
 * 
 * \test Compare deux candidats identiques et deux candidats différents.
 */
TEST(CandidatTest, TestOperatorEqual) {
    util::Date dateNaissance(1, 12, 2003);
    Candidat candidat1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance, PartisPolitiques::LIBERAL);
    Candidat candidat2("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance, PartisPolitiques::LIBERAL);
    Candidat candidat3("046 454 385", "Lolo", "Nime", "10 rue Jean Jauraise", dateNaissance, PartisPolitiques::CONSERVATEUR);

    ASSERT_TRUE(candidat1 == candidat2);
    ASSERT_FALSE(candidat1 == candidat3);
}

/**
 * \brief Test de la méthode `clone` de la classe Candidat.
 * 
 * Ce test vérifie que la méthode retourne une copie polymorphique correcte
 * de l'objet courant.
 * 
 * \test Compare les attributs du clone avec ceux de l'objet original.
 */
TEST(CandidatTest, TestClone) {
    util::Date dateNaissance(1, 12, 2003);
    Candidat candidat1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance, PartisPolitiques::INDEPENDANT);

    auto cloneCandidat = candidat1.clone();
    
    ASSERT_EQ(candidat1.reqNas(), cloneCandidat->reqNas());
    ASSERT_EQ(candidat1.reqPrenom(), cloneCandidat->reqPrenom());
    ASSERT_EQ(candidat1.reqNom(), cloneCandidat->reqNom());
    ASSERT_EQ(candidat1.reqAdresse(), cloneCandidat->reqAdresse());
    ASSERT_EQ(candidat1.reqDateNaissance().reqJour(), cloneCandidat->reqDateNaissance().reqJour());
}

/**
 * \brief Test de la méthode `changerAdresse` de la classe Candidat.
 * 
 * Ce test vérifie que la méthode modifie correctement l'adresse du candidat.
 * 
 * \test Compare l'adresse après modification avec une adresse attendue.
 */
TEST(CandidatTest, TestChangerAdresse) {
    util::Date dateNaissance(1, 12, 2003);
    Candidat candidat1("640 454 286", "Tim", "Paul", "105 av. JP", dateNaissance, PartisPolitiques::LIBERAL);
    
    candidat1.changerAdresse("200 av. yaahh");

    ASSERT_EQ("200 av. yaahh", candidat1.reqAdresse());
}

