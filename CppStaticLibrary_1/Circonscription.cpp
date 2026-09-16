/**
 * \file Circonscription.cpp
 * \brief Implémentation de la classe Circonscription
 * \author Dorian
 */

#include "Circonscription.h"
#include "ContratException.h"
#include <sstream>
#include <stdexcept>

using namespace std;
namespace elections{

    Circonscription::Circonscription(const string& nomCirconscription, const Candidat& deputeElu)
        : m_nomCirconscription(nomCirconscription), m_deputeElu(deputeElu) {
        PRECONDITION(!nomCirconscription.empty());

        POSTCONDITION(m_nomCirconscription == nomCirconscription);
        POSTCONDITION(m_deputeElu.reqNom() == deputeElu.reqNom());

        INVARIANTS();
    }

    Circonscription::Circonscription(const Circonscription& other)
        : m_nomCirconscription(other.m_nomCirconscription), m_deputeElu(other.m_deputeElu) {
        for (const auto& personne : other.m_inscrits) {
            m_inscrits.push_back(personne->clone());
        }
        INVARIANTS();
    }

    Circonscription& Circonscription::operator=(const Circonscription& other) {
        if (this != &other) {
            m_nomCirconscription = other.m_nomCirconscription;
            m_deputeElu = other.m_deputeElu;
            m_inscrits.clear();

            for (const auto& personne : other.m_inscrits) {
                m_inscrits.push_back(personne->clone());
            }
        }
        INVARIANTS();
        return *this;
    }

    void Circonscription::inscrire(const Personne& p_nouvelInscrit) {
        PRECONDITION(!p_nouvelInscrit.reqNom().empty());
        PRECONDITION(!p_nouvelInscrit.reqPrenom().empty());

        m_inscrits.push_back(p_nouvelInscrit.clone());

        POSTCONDITION(!m_inscrits.empty());
        INVARIANTS();
    }

    string Circonscription::reqCirconscriptionFormate() const {
        INVARIANTS();

        ostringstream os;
        os << "Circonscription : " << m_nomCirconscription << endl
           << "Depute sortant :" << endl
           << m_deputeElu.reqPersonneFormate() << endl
           << "Liste des inscrits :" << endl;

        for (const auto& personne : m_inscrits) {
            os << personne->reqPersonneFormate() << endl;
        }

        return os.str();
    }

    void Circonscription::verifieInvariant() const {
        INVARIANT(!m_nomCirconscription.empty());
        INVARIANT(!m_deputeElu.reqNom().empty());
    };
}

