/**
 * \file ValidationFormat.h
 * \brief Déclaration des fonctions de validation de format.
 * \author Dorian
 */

#ifndef VALIDATIONFORMAT_H
#define VALIDATIONFORMAT_H

#include <string>

namespace util {
    
    /**
     * \class ValidationFormat
     * \brief Classe utilitaire contenant des fonctions pour la validation des formats.
     * 
     * Cette classe fournit des méthodes statiques pour valider différents formats, 
     * comme le format d'un numéro d'assurance sociale (NAS). Elle permet d'assurer 
     * que les données saisies respectent un format correct avant leur utilisation.
     */
    class ValidationFormat {
    public:
        /**
         * \brief Valide un numéro d'assurance sociale (NAS).
         * 
         * Cette méthode vérifie que le NAS est bien constitué de neuf chiffres et qu'il 
         * respecte l'algorithme de validation de Luhn.
         * 
         * \param[in] nas Le numéro d'assurance sociale sous forme de chaîne de caractères.
         * \return \c true si le NAS est valide, \c false sinon.
         * 
         * \pre Le NAS doit être une chaîne de caractères non vide.
         * \post La validité du NAS est déterminée selon l'algorithme de Luhn.
         */
        static bool validerNas(const std::string& nas);
    };

}

#endif /* VALIDATIONFORMAT_H */

