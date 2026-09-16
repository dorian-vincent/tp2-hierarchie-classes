/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 28 novembre 2024, 05 h 29
 */

#include <iostream>
#include "Circonscription.h"
#include "Candidat.h"
#include "Electeur.h"
#include "Date.h"
#include "ValidationFormat.h"

using namespace std;
using namespace elections;

string saisieNas() {
    string nas;
    do {
        cout << "Entrez un NAS valide (format xxx xxx xxx) : ";
        getline(cin, nas);
    } while (!util::ValidationFormat::validerNas(nas));
    return nas;
}

util::Date saisieDate() {
    int jour, mois, annee;
    do {
        cout << "Entrez une date valide (jour mois annee) : ";
        cin >> jour >> mois >> annee;
    } while (!util::Date::validerDate(jour, mois, annee));
    return util::Date(jour, mois, annee);
}

string saisieTexte(const string& message) {
    string texte;
    do {
        cout << message << " (non vide) : ";
        getline(cin, texte);
    } while (texte.empty());
    return texte;
}

int main() {
    util::Date dateSortant(1, 1, 2000);
    Candidat candidatSortant("000 000 000", "Inconnu", "Inconnu", "Adresse inconnue", dateSortant, PartisPolitiques::INDEPENDANT);

    Circonscription circonscription("Circonscription n°1", candidatSortant);

    cout << "--------------------------------------------\n" 
            "Bienvenue a l'outil de gestion des listes électorales\n"
            "--------------------------------------------\n"<< std::endl; 

    cout << "\nInscription d'un candidat\n";
    cin.ignore();
    cout << "Choisissez un parti politique :\n";
    cout << "0: Bloc Québécois, 1: Conservateur, 2: Indépendant, 3: Libéral, 4: Nouveau Parti Démocratique\n";
    int choixParti;
    do {
        cout << "Votre choix (0-4) : ";
        cin >> choixParti;
    } while (choixParti < 0 || choixParti > 4);

    string nasCandidat = saisieNas();
    string prenomCandidat = saisieTexte("Entrez le prénom du candidat");
    string nomCandidat = saisieTexte("Entrez le nom du candidat");
    string adresseCandidat = saisieTexte("Entrez l'adresse du candidat");
    util::Date dateNaissanceCandidat = saisieDate();
    Candidat nouveauCandidat(nasCandidat, prenomCandidat, nomCandidat, adresseCandidat, dateNaissanceCandidat, static_cast<PartisPolitiques>(choixParti));
    circonscription.inscrire(nouveauCandidat);

    cout << "\nAjout d'un électeur :\n";
    cin.ignore();
    string nasElecteur = saisieNas();
    string prenomElecteur = saisieTexte("Entrez le prénom de l'électeur");
    string nomElecteur = saisieTexte("Entrez le nom de l'électeur");
    string adresseElecteur = saisieTexte("Entrez l'adresse de l'électeur");
    util::Date dateNaissanceElecteur = saisieDate();
    Electeur nouvelElecteur(nasElecteur, prenomElecteur, nomElecteur, adresseElecteur, dateNaissanceElecteur);
    circonscription.inscrire(nouvelElecteur);

    cout << "\nContenu de la circonscription :\n";
    cout << circonscription.reqCirconscriptionFormate();
    cout << "fin" << std::endl; 
    return 0;
}



