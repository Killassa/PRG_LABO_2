/*
-------------------------------------------------------------------------------------
Nom du fichier : vehicule.h
Nom du labo    : Laboratoire no. 2
Auteur(s)      : Eric Peronetti, Grégory Rey-Mermet, Célestin Piccin
Date creation  : 24.05.2022
Description    : ???
Remarque(s)    : ???
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef PRG_LABO_2_VEHICULE_H
#define PRG_LABO_2_VEHICULE_H
#include <stdint.h>

//La taille maximum des différents pays semblait être 10
#define TAILLE_MAX_NUMERO_PLAQUE 10

//La plus grande marque trouvée étant "International Harvester"
#define TAILLE_MAX_MARQUE 25

typedef char NumeroPlaque[TAILLE_MAX_NUMERO_PLAQUE + 1];
typedef char Marque[TAILLE_MAX_MARQUE + 1];

typedef enum {CAMIONETTE, VOITURE} TVehicule;
typedef enum {STANDARD, HAUT_GAMME} TVoiture;

//Camionette
typedef struct {
   double volTransport;
} Camionette;

//Voiture
typedef struct {
   uint16_t cylindree;
   uint16_t rejetCO2;
} VoitureStd;

typedef struct {
   uint16_t puissance;
} VoitureHG;

typedef union {
   VoitureStd voitureStd;
   VoitureHG voitureHg;
} TypeVoiture;

typedef struct {
   TVoiture tVoiture;
   uint16_t poids;
   TypeVoiture typeVoiture;
} Voiture;

//Vehicule
typedef union {
   Camionette camionette;
   Voiture voiture;
} TypeVehicule;

typedef struct {
   TVehicule tVehicule;
   NumeroPlaque numeroPlaque;
   Marque marque;
   TypeVehicule typeVehicule;
} Vehicule;

void afficherVehicule(const Vehicule* vehicule);

/**
 * Initialisation d'un objet véhicule de type voiture standard
 *
 * @param numeroPlaque  Numéro de plaque
 * @param marque        Marque de la voiture
 * @param poids         Poids de la voiture
 * @param cylindree     Cylindrée de la voiture
 * @param rejetCO2      Quantité de rejet de CO2
 * @return              La voiture
 */
Vehicule voitureStandard(const char* numeroPlaque, const char* marque, uint16_t poids, uint16_t cylindree, uint16_t rejetCO2);

/**
 * Initialisation d'un objet véhicule de type voiture haut de gamme
 *
 * @param numeroPlaque  Numéro de plaque
 * @param marque        Marque de la voiture
 * @param poids         Poids de la voiture
 * @param puissance     Puissance de la voiture
 * @return              La voiture
 */
Vehicule voitureHautDeGamme(const char* numeroPlaque, const char* marque, uint16_t poids, uint16_t puissance);

/**
 * Initialisation d'un objet véhicule de type camionette
 *
 * @param numeroPlaque  Numéro de plaque
 * @param marque        Marque de la camionette
 * @param volTransport  Volume de transport de la camionette
 * @return              La camionette
 */
Vehicule camionette(const char* numeroPlaque, const char* marque, double volTransport);

/**
 *
 * @param tVehicule
 * @return
 */
const char* obtenirNomTVehicule(TVehicule tVehicule);

/**
 *
 * @param tVoiture
 * @return
 */
const char* obtenirNomTVoiture(TVoiture tVoiture);

#endif //PRG_LABO_2_VEHICULE_H
