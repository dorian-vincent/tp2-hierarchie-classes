/**
 * \file Candidat.cpp
 * \brief Implémentation de la classe Candidat
 * \author Dorian
 */

#include "Candidat.h"
#include "ContratException.h"
#include <sstream>
#include <stdexcept>

using namespace std;
namespace elections{

    Candidat::Candidat(const string& nas, const string& prenom, const string& nom,
                       const string& adresse, const util::Date& dateNaissance, PartisPolitiques partiPolitique)
        : Personne(nas, prenom, nom, adresse, dateNaissance), m_partiPolitique(partiPolitique) {

        PRECONDITION(partiPolitique >= BLOC_QUEBECOIS && partiPolitique <= NOUVEAU_PARTI_DEMOCRATIQUE);

        POSTCONDITION(m_partiPolitique == partiPolitique);

        INVARIANTS();
    }

    string Candidat::reqPartiPolitique() const {
        switch (m_partiPolitique) {
            case BLOC_QUEBECOIS: return "Bloc Québécois";
            case CONSERVATEUR: return "Conservateur";
            case INDEPENDANT: return "Indépendant";
            case LIBERAL: return "Liberal";
            case NOUVEAU_PARTI_DEMOCRATIQUE: return "Nouveau Parti Démocratique";
            default: return "Inconnu";
        }
    }

    unique_ptr<Personne> Candidat::clone() const {
        return make_unique<Candidat>(*this);
    }

    string Candidat::reqPersonneFormate() const {
        ostringstream os;
        os << "Candidat\n"
           << "----------------------------------------------\n"
           << Personne::reqPersonneFormate() << "\n"
           << "Parti politique  : " << reqPartiPolitique();
        return os.str();
    }

    void Candidat::verifieInvariant() const {
        INVARIANT(m_partiPolitique >= BLOC_QUEBECOIS && m_partiPolitique <= NOUVEAU_PARTI_DEMOCRATIQUE);
    };

}

