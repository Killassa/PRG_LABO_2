/*
-------------------------------------------------------------------------------------
Nom du fichier : taxe.h
Nom du labo    : Laboratoire no. 2
Auteur(s)      : Eric Peronetti, Grégory Rey-Mermet, Célestin Piccin
Date creation  : 24.05.2022
Description    : ???
Remarque(s)    : ???
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef PRG_LABO_2_TAXEPARKING_H
#define PRG_LABO_2_TAXEPARKING_H

#include "vehicule.h"

/**
 * Calcul de la taxe annuelle d'un véhicule
 * @param vehicule  Le véhicule
 * @return          La taxe annuelle du véhicule
 */
double calculTaxeAnnuelle(const Vehicule* vehicule);

/**
 * Taxe de base d'un véhicule
 * @param vehicule  Le véhicule
 * @return          La taxe de base du véhicule
 */
double calculTaxeBase(const Vehicule* vehicule);

/**
 * Taxe de spécifique d'un véhicule
 * @param vehicule  Le véhicule
 * @return          La taxe spécifique du véhicule
 */
double calculTaxeSpecifique(const Vehicule* vehicule);

#endif //PRG_LABO_2_TAXEPARKING_H
