/*
-------------------------------------------------------------------------------------
Nom du fichier : taxeParking.h
Nom du labo    : Laboratoire no. 2
Auteur(s)      : Eric Peronetti, Grégory Rey-Mermet, Célestin Piccin
Date creation  : 24.05.2022
Description    : Fichier contenant les structures et les déclarations nécessaires
                 pour les taxes du parking
Remarque(s)    : -
Compilateur    : Mingw-w64 g++ 11.2.0
-------------------------------------------------------------------------------------
*/

#ifndef PRG_LABO_2_TAXEPARKING_H
#define PRG_LABO_2_TAXEPARKING_H

#include "vehicule.h"

/**
 * Calcul de la taxe annuelle d'un véhicule
 *
 * @param vehicule  Le véhicule
 * @return          La taxe annuelle du véhicule
 */
double calculTaxeAnnuelle(const Vehicule* vehicule);

/**
 * Taxe de base d'un véhicule
 *
 * @param vehicule  Le véhicule
 * @return          La taxe de base du véhicule
 */
double calculTaxeBase(const Vehicule* vehicule);

/**
 * Taxe de spécifique d'un véhicule
 *
 * @param vehicule  Le véhicule
 * @return          La taxe spécifique du véhicule
 */
double calculTaxeSpecifique(const Vehicule* vehicule);

/**
 * Calcul de la taxe spécifique pour une camionette
 *
 * @param camionette La camionette
 * @return           La taxe spécifique
 */
double calculTaxeCamionette(const Camionette* camionette);

/**
 * Calcul de la taxe spécifique pour une voiture standard
 *
 * @param voitureStd La voiture standard
 * @return           La taxe spécifique
 */
double calculTaxeVoitureStd(const Voiture* voitureStd);

/**
 * Calcul de la taxe spécifique pour une voiture haut de gamme
 *
 * @param voitureHg La voiture haut de gamme
 * @return          La taxe spécifique
 */
double calculTaxeVoitureHg(const Voiture* voitureHg);

#endif //PRG_LABO_2_TAXEPARKING_H
