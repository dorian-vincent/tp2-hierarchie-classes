/**
 * \file Personne.cpp
 * \brief Implémentation de la validation du format NAS.
 * \author Dorian
 */

#include "ValidationFormat.h"
#include <string>

using namespace std;

namespace util
{

    bool ValidationFormat::validerNas(const string& nas) 
    {
        string copie;
        int cmp = 0;
        
        for (char i : nas) 
        {
            if (i != '-' && i != ' ' && isdigit(i)) 
            {
                copie += i;
                cmp++;
            }
        }
        
        if (cmp != 9) 
        {
            return false;
        }

        int sum = 0;
        
        for (int i = 0; i < 9; i++) 
        {
            int x = copie[i] - '0';
            if (i % 2 == 1)
            {
                x *= 2;
                if (x > 9) x -= 9;
            }
            sum += x;
        }
        
        return sum % 10 == 0;
    }
}

