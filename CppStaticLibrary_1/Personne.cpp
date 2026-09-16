/**
 * \file Personne.cpp
 * \brief Implémentation de la classe Personne
 * \author Dorian
 */

#include <memory>
#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Personne.h"
#include "ValidationFormat.h"
#include "Date.h"
#include "ContratException.h"

using namespace std;

namespace elections{
    Personne::Personne(const string& nas, const string& prenom, const string& nom,
                       const string& adresse, const util::Date& dateNaissance)
        : m_nas(nas), m_prenom(prenom), m_nom(nom), m_adresse(adresse), m_dateNaissance(dateNaissance) {

        PRECONDITION(!nas.empty() && util::ValidationFormat::validerNas(nas));
        PRECONDITION(!prenom.empty());
        PRECONDITION(!nom.empty());
        PRECONDITION(!adresse.empty());
        PRECONDITION(util::Date::validerDate(dateNaissance.reqJour(), 
                                             dateNaissance.reqMois(), 
                                             dateNaissance.reqAnnee()));

        POSTCONDITION(m_nas == nas);
        POSTCONDITION(m_prenom == prenom);
        POSTCONDITION(m_nom == nom);
        POSTCONDITION(m_adresse == adresse);
        POSTCONDITION(m_dateNaissance.reqJour() == dateNaissance.reqJour() &&
                      m_dateNaissance.reqMois() == dateNaissance.reqMois() &&
                      m_dateNaissance.reqAnnee() == dateNaissance.reqAnnee());

        INVARIANTS();
    }

    Personne::~Personne() {}

    std::unique_ptr<Personne> Personne::clone() const {
        return make_unique<Personne>(*this);
    }

    const string& Personne::reqNas() const { 
        return m_nas; 
    }

    const string& Personne::reqPrenom() const { 
        return m_prenom; 
    }

    const string& Personne::reqNom() const { 
        return m_nom; 
    }

    const string& Personne::reqAdresse() const { 
        return m_adresse; 
    }

    const util::Date& Personne::reqDateNaissance() const { 
        return m_dateNaissance; 
    }

    void Personne::changerAdresse(const string& nouvelleAdresse) {
        PRECONDITION(!nouvelleAdresse.empty());
        m_adresse = nouvelleAdresse;
        POSTCONDITION(m_adresse == nouvelleAdresse);
        INVARIANTS();
    }

    bool Personne::operator==(const Personne& autre) const {
        return m_nas == autre.m_nas &&
               m_prenom == autre.m_prenom &&
               m_nom == autre.m_nom &&
               m_adresse == autre.m_adresse &&
               m_dateNaissance == autre.m_dateNaissance;
    }

    string Personne::reqPersonneFormate() const {
        ostringstream os;
        os << "NAS  : " << m_nas << "\n"
           << "Prenom   : " << m_prenom << "\n"
           << "Nom  : " << m_nom << "\n"
           << "Date de naissance    : " << m_dateNaissance.reqDateFormatee() << "\n"
           << "Adresse  : " << m_adresse;
        return os.str();
    }

    void Personne::verifieInvariant() const {
        INVARIANT(!m_nas.empty());
        INVARIANT(util::ValidationFormat::validerNas(m_nas));
        INVARIANT(!m_prenom.empty());
        INVARIANT(!m_nom.empty());
        INVARIANT(!m_adresse.empty());
        INVARIANT(util::Date::validerDate(m_dateNaissance.reqJour(), 
                                          m_dateNaissance.reqMois(), 
                                          m_dateNaissance.reqAnnee()));
    }
}

