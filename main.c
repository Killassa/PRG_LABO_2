/*
-------------------------------------------------------------------------------------
Nom du fichier : main.c
Nom du labo    : Laboratoire no. 2
Auteur(s)      : Eric Peronetti, Grégory Rey-Mermet, Célestin Piccin
Date creation  : 24.05.2022
Description    : ???
Remarque(s)    : ???
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#include "taxeParking.h"
#include "vehicule.h"

int main(void) {

   typedef struct {
      Vehicule vehicule;
      double taxeAnnuelle;
   } VehiculeParking;

   VehiculeParking parking[] = {
      {camionette("FR 123451", "Ford", 3.3)},
      {camionette("BL 267564", "Mercedes-Benz", 3.8)},
      {voitureStandard("BE 88823", "BMW", 1850, 2998, 159)},
      {voitureStandard("ZG 190002", "Dacia", 1321, 1200, 98)},
      {voitureStandard("GE 591356", "Smart", 1500, 1150, 162)},
      {voitureHautDeGamme("VD 119977", "Aston Martin", 1870, 230)},
      {voitureHautDeGamme("ZH 874569", "Porsche", 2010, 678)}
   };

   size_t tailleParking = sizeof(parking) / sizeof(VehiculeParking);

   for (int i = 0; i < tailleParking; ++i) {
      parking[i].taxeAnnuelle = calculTaxeAnnuelle(&parking[i].vehicule);
   }



   return EXIT_SUCCESS;
}
