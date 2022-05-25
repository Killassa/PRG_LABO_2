//
// Created by celes on 25.05.2022.
//

#ifndef PRG_LABO_2_VEHICULE_H
#define PRG_LABO_2_VEHICULE_H
#include <stdint.h>

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
    const char* numeroPlaque;
    const char* marque;
    TypeVehicule typeVehicule;
} Vehicule;

void afficherVehicule(const Vehicule* vehicule);

#endif //PRG_LABO_2_VEHICULE_H
