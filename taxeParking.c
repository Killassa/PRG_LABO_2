/*
-------------------------------------------------------------------------------------
Nom du fichier : taxe.c
Nom du labo    : Laboratoire no. 2
Auteur(s)      : Eric Peronetti, Grégory Rey-Mermet, Célestin Piccin
Date creation  : 24.05.2022
Description    : ???
Remarque(s)    : Utilisation des "double" pour les constantes des prix car on veut
                 garder le même type de données pour chacune des variables étant
                 donné que l'une d'entre elle à la valeur 0.05.
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#include <stdint.h>  //uint

#include "taxeParking.h"

//Taxe de base
const double BASE_PRIX_CAMIONNETTE = 700;
const double BASE_PRIX_VOITURE 	 = 400;

//Taxe spécifique
//Taxe camionette
const double SPEC_PRIX_CAMIONNETTE = 10;

//Taxe voiture standard
const uint16_t SPEC_STD_SEUIL_CYLINDREE                   = 1400;
const uint16_t SPEC_STD_SEUIL_REJET_CO2                   = 130;
const double   SPEC_STD_PRIX_PETITE_CYLINDREE_PETIT_REJET = 0;
const double   SPEC_STD_PRIX_PETITE_CYLINDREE_GROS_REJET  = 50;
const double 	SPEC_STD_PRIX_GROSSE_CYLINDREE             = 0.05;

//Taxe voiture haut de gamme
const uint16_t SPEC_HG_SEUIL_PUISSANCE   = 250;
const double 	SPEC_HG_PRIX_PETIT_MOTEUR = 200;
const double   SPEC_HG_PRIX_GROS_MOTEUR  = 300;
const double 	SPEC_HG_PRIX_POIDS		  = 20;

double calculTaxeAnnuelle(const Vehicule* vehicule) {
   return calculTaxeBase(vehicule) + calculTaxeSpecifique(vehicule);
}

double calculTaxeBase(const Vehicule* vehicule) {
   if (vehicule->tVehicule == VOITURE)
      return BASE_PRIX_VOITURE;
   return BASE_PRIX_CAMIONNETTE;
}

double calculTaxeSpecifique(const Vehicule* vehicule) {
   //Taxe d'une caminonette
   if (vehicule->tVehicule == CAMIONETTE)
      return SPEC_PRIX_CAMIONNETTE * vehicule->typeVehicule.camionette.volTransport;

   //Taxe d'une voiture standard
   if (vehicule->typeVehicule.voiture.tVoiture == STANDARD) {
      uint16_t cylindree = vehicule->typeVehicule.voiture.typeVoiture.voitureStd.cylindree;
      uint16_t rejetCO2  = vehicule->typeVehicule.voiture.typeVoiture.voitureStd.rejetCO2;

      if (cylindree < SPEC_STD_SEUIL_CYLINDREE) {
         if (rejetCO2 < SPEC_STD_SEUIL_REJET_CO2)
            return SPEC_STD_PRIX_PETITE_CYLINDREE_PETIT_REJET;
         return SPEC_STD_PRIX_PETITE_CYLINDREE_GROS_REJET;
      }

      return SPEC_STD_PRIX_GROSSE_CYLINDREE * cylindree;
   }

   //Taxe d'une voiture haut de gamme
   uint16_t puissance = vehicule->typeVehicule.voiture.typeVoiture.voitureHg.puissance;
   if (puissance <= SPEC_HG_SEUIL_PUISSANCE)
      return SPEC_HG_PRIX_PETIT_MOTEUR;

   //Poids en tonne
   uint16_t poids = vehicule->typeVehicule.voiture.poids / 1000;
   return SPEC_HG_PRIX_GROS_MOTEUR + SPEC_HG_PRIX_POIDS * poids;
}