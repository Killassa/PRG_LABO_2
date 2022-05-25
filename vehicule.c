//
// Created by grego on 24.05.2022.
//

#include <stdio.h>
#include <inttypes.h> //uint
#include "vehicule.h"

const char* const TVEHICULE[] = {"Camionette", "Voiture"};
const char* const TVOITURE[] = {"Standard", "Haut de gamme"};

/*
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
} Vehicule;*/


void afficherVehicule(const Vehicule* vehicule){
    printf("Type de vehicule : %s\n", TVEHICULE[vehicule->tVehicule]);
    printf("Plaque : %s\n", vehicule->numeroPlaque);
    printf("Marque : %s\n", vehicule->marque);
    if(vehicule->tVehicule == CAMIONETTE){
        printf("Volume de transport [m3] : %lf\n", vehicule->typeVehicule.camionette.volTransport);
    }
    else{
        printf("Poids [kg] : %" PRIu16 "\n", vehicule->typeVehicule.voiture.poids);
        printf("Categorie de voiture : %s\n", TVOITURE[vehicule->typeVehicule.voiture.tVoiture]);
        if(vehicule->typeVehicule.voiture.tVoiture == STANDARD){
            printf("Cylindree [cm3] : %" PRIu16 "\n", vehicule->typeVehicule.voiture.typeVoiture.voitureStd.cylindree);
            printf("Rejet CO2 [g/km2] : %" PRIu16 "\n", vehicule->typeVehicule.voiture.typeVoiture.voitureStd.rejetCO2);
        }
        else{
            printf("Puissance [CV] : %" PRIu16 "\n", vehicule->typeVehicule.voiture.typeVoiture.voitureHg.puissance);
        }
    }
}
