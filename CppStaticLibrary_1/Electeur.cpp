/**
 * \file Electeur.cpp
 * \brief Implémentation de la classe Electeur
 * \author Dorian
 */
#include "Personne.h"
#include "Electeur.h"
#include "ContratException.h"
#include <sstream>
#include <stdexcept>

using namespace std;
namespace elections{

    Electeur::Electeur(const string& nas, const string& prenom, const string& nom,
                       const string& adresse, const util::Date& dateNaissance)
        : Personne(nas, prenom, nom, adresse, dateNaissance) {
    }


    unique_ptr<Personne> Electeur::clone() const {
        return make_unique<Electeur>(*this);
    }


    string Electeur::reqPersonneFormate() const {
        ostringstream os;
        os << "Electeur\n"
           << "----------------------------------------------\n"
           << Personne::reqPersonneFormate();
        return os.str();
    };
}
