//
// Created by grego on 24.05.2022.
//

#include <stdint.h>  //uint

typedef enum {CAMIONETTE, VOITURE} TVehicule;
typedef enum {STANDARD, HAUT_GAMME} TVoiture;

const char* const TVEHICULE[] = {"Camionette", "Voiture"};
const char* const TVOITURE[] = {"Standard", "Haut de gamme"};

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
   TypeVoiture typeVoiture;
} ChoixVoiture;

typedef struct {
   ChoixVoiture choixVoiture;
   uint16_t poids;
} Voiture;

//Vehicule
typedef union {
   Camionette camionette;
   Voiture voiture;
} TypeVehicule;

typedef struct {
   char* canton;
   uint16_t numero;
} NumeroPlaque;

typedef struct {
   TVehicule tVehicule;
   TypeVehicule typeVehicule;
} ChoixVehicule;

typedef struct {
   ChoixVehicule choixVehicule;
   NumeroPlaque numeroPlaque;
   char* marque;
} Vehicule;
