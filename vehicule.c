/*
-------------------------------------------------------------------------------------
Nom du fichier : vehicule.c
Nom du labo    : Laboratoire no. 2
Auteur(s)      : Eric Peronetti, Grégory Rey-Mermet, Célestin Piccin
Date creation  : 24.05.2022
Description    : ???
Remarque(s)    : ???
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <inttypes.h> //uint
#include <string.h>

#include "vehicule.h"

const char* const TVEHICULE[] = {"Camionette", "Voiture"};
const char* const TVOITURE[]  = {"Standard", "Haut de gamme"};

void afficherVehicule(const Vehicule* vehicule) {
   printf("Type de vehicule : %s\n", TVEHICULE[vehicule->tVehicule]);
   printf("Plaque : %s\n", vehicule->numeroPlaque);
   printf("Marque : %s\n", vehicule->marque);

   if (vehicule->tVehicule == CAMIONETTE) {
      printf("Volume de transport [m3] : %lf\n",
             vehicule->typeVehicule.camionette.volTransport);
   } else {
      printf("Poids [kg] : %" PRIu16 "\n", vehicule->typeVehicule.voiture.poids);
      printf("Categorie de voiture : %s\n",
             TVOITURE[vehicule->typeVehicule.voiture.tVoiture]);

      if (vehicule->typeVehicule.voiture.tVoiture == STANDARD) {
         printf("Cylindree [cm3] : %" PRIu16 "\n",
                vehicule->typeVehicule.voiture.typeVoiture.voitureStd.cylindree);
         printf("Rejet CO2 [g/km2] : %" PRIu16 "\n",
                vehicule->typeVehicule.voiture.typeVoiture.voitureStd.rejetCO2);
      } else {
         printf("Puissance [CV] : %" PRIu16 "\n",
                vehicule->typeVehicule.voiture.typeVoiture.voitureHg.puissance);
      }
   }
}

Vehicule voitureStandard(const char* numeroPlaque,
                         const char* marque,
                         uint16_t poids,
                         uint16_t cylindree,
                         uint16_t rejetCO2) {
   Vehicule v = {
      .tVehicule=VOITURE,
      .numeroPlaque="",
      .marque="",
      .typeVehicule={
         .voiture={
            .tVoiture=STANDARD,
            .poids=poids,
            .typeVoiture={
               .voitureStd={
                  .cylindree=cylindree,
                  .rejetCO2=rejetCO2
               }
            }
         }
      }
   };

   strncpy(v.numeroPlaque, numeroPlaque, TAILLE_MAX_NUMERO_PLAQUE);
   strncpy(v.marque, marque, TAILLE_MAX_MARQUE);

   return v;
}

Vehicule voitureHautDeGamme(const char* numeroPlaque,
                            const char* marque,
                            uint16_t poids,
                            uint16_t puissance) {

   Vehicule v = {
      .tVehicule=VOITURE,
      .numeroPlaque="",
      .marque="",
      .typeVehicule={
         .voiture={
            .tVoiture=HAUT_GAMME,
            .poids=poids,
            .typeVoiture={
               .voitureHg={
                  .puissance = puissance
               }
            }
         }
      }
   };

   strncpy(v.numeroPlaque, numeroPlaque, TAILLE_MAX_NUMERO_PLAQUE);
   strncpy(v.marque, marque, TAILLE_MAX_MARQUE);

   return v;
}

Vehicule camionette(const char* numeroPlaque, const char* marque, double volTransport) {
   Vehicule v = {
      .tVehicule=CAMIONETTE,
      .numeroPlaque="",
      .marque="",
      .typeVehicule={
         .camionette={
            .volTransport=volTransport
         }
      }
   };

   strncpy(v.numeroPlaque, numeroPlaque, TAILLE_MAX_NUMERO_PLAQUE);
   strncpy(v.marque, marque, TAILLE_MAX_MARQUE);

   return v;
}