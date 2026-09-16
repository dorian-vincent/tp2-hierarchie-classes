# Hiérarchie de classes - simulation électorale
 
Bibliothèque C++ modélisant un système électoral : candidats, circonscriptions, électeurs, avec validation stricte des données (programmation par contrat).
 
## Contenu
 
- Candidat, Circonscription, Electeur, Personne : hiérarchie de classes du domaine électoral
- Date : classe de gestion de dates avec validation
- ContratException, ValidationFormat : mécanismes de programmation par contrat (préconditions, invariants) pour garantir l'intégrité des objets
- Tests unitaires pour chaque classe (dossier tests/)
 
## Ce que ça démontre
 
Conception orientée objet avec héritage, et rigueur sur la validation des invariants de classe (design by contract).
