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

#define FORMAT "%-*s : "

const char* const TVEHICULE[] = {"Camionette", "Voiture"};
const char* const TVOITURE[]  = {"Standard", "Haut de gamme"};

const size_t NOMBRE_CARACTERE = 24;

void afficherVehicule(const Vehicule* vehicule) {

   printf(FORMAT "%s\n", NOMBRE_CARACTERE, "Type de vehicule", TVEHICULE[vehicule->tVehicule]);
   printf(FORMAT "%s\n", NOMBRE_CARACTERE, "Plaque", vehicule->numeroPlaque);
   printf(FORMAT "%s\n", NOMBRE_CARACTERE, "Marque", vehicule->marque);

   if (vehicule->tVehicule == CAMIONETTE) {
      printf(FORMAT "%.2lf\n",
             NOMBRE_CARACTERE,
             "Volume de transport [m3]",
             vehicule->typeVehicule.camionette.volTransport);
   } else {
      printf(FORMAT "%" PRIu16 "\n",
             NOMBRE_CARACTERE,
             "Poids [kg]",
             vehicule->typeVehicule.voiture.poids);

      printf(FORMAT "%s\n",
             NOMBRE_CARACTERE,
             "Categorie de voiture",
             TVOITURE[vehicule->typeVehicule.voiture.tVoiture]);

      if (vehicule->typeVehicule.voiture.tVoiture == STANDARD) {
         printf(FORMAT "%" PRIu16 "\n",
                NOMBRE_CARACTERE,
                "Cylindree [cm3]",
                vehicule->typeVehicule.voiture.typeVoiture.voitureStd.cylindree);

         printf(FORMAT "%" PRIu16 "\n",
                NOMBRE_CARACTERE,
                "Rejet CO2 [g/km2]",
                vehicule->typeVehicule.voiture.typeVoiture.voitureStd.rejetCO2);
      } else {
         printf(FORMAT "%" PRIu16 "\n",
                NOMBRE_CARACTERE,
                "Puissance [CV]",
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

const char* obtenirNomTVehicule(TVehicule tVehicule) {
   return TVEHICULE[tVehicule];
}

const char* obtenirNomTVoiture(TVoiture tVoiture) {
   return TVOITURE[tVoiture];
}