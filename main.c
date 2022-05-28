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
#include <math.h>

#include "taxeParking.h"
#include "vehicule.h"

typedef struct {
   Vehicule vehicule;
   double taxeAnnuelle;
} VehiculeParking;

typedef struct {
   double somme;
   double moyenne;
   double mediane;
   double ecartType;
} Statistiques;

/**
 * Vide le buffer
 */
void viderBuffer(void);

/**
 * Tri décroissant en fonction de la taxe annuelle
 *
 * @param parking       Parking à trier
 * @param tailleParking Taille du parking
 */
void triDecroissantParkingTaxe(const VehiculeParking* parking, size_t tailleParking);

/**
 * Compare les taxes
 *
 * @param v1    VehiculeParking 1
 * @param v2    VehiculeParking 2
 * @return      Vrai : v1 < v2 // Faux : v1 >= v2
 */
int comparaisonTaxe(const void* v1, const void* v2);

/**
 * Compare deux double
 *
 * @param d1    Double 1
 * @param d2    Double 2
 * @return      Vrai : d1 < d2 // Faux : d1 >= d2
 */
int comparaisonDouble(const void* d1, const void* d2);

/**
 * Affiche les caractéristiques et taxe annuelle due de chacun des véhicules d'un
 * parking
 *
 * @param parking       Parking à afficher
 * @param tailleParking Taille du parking
 */
void afficherParking(const VehiculeParking* parking, size_t tailleParking);

/**
 *
 * @param stats
 * @param vehicule
 * @param voiture
 */
void afficherStatistiques(const Statistiques* stats, TVehicule vehicule, TVoiture voiture);

/**
 *
 * @param parking
 * @param tailleParking
 * @param vehicule
 * @param voiture
 * @return
 */
Statistiques obtenirStatistiques(const VehiculeParking* parking,
                                 size_t tailleParking,
                                 TVehicule vehicule,
                                 TVoiture voiture);

int main(void) {
   //Création du parking
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

   triDecroissantParkingTaxe(parking, tailleParking);

   //Affichage du parking
   afficherParking(parking, tailleParking);

   //Affichage somme, moyenne, médiane, écart-type par type de véhicule
   //Utilisation de "STANDARD" avec une caminonette car le type de la camionette
   //n'est pas important et donc non utilisé
   Statistiques statsCamionette = obtenirStatistiques(parking, tailleParking, CAMIONETTE, STANDARD);
   Statistiques statsVoitureStd = obtenirStatistiques(parking, tailleParking, VOITURE, STANDARD);
   Statistiques statsVoitureHG  = obtenirStatistiques(parking, tailleParking, VOITURE, HAUT_GAMME);
   afficherStatistiques(&statsCamionette, CAMIONETTE, STANDARD);
   printf("\n");
   afficherStatistiques(&statsVoitureStd, VOITURE, STANDARD);
   printf("\n");
   afficherStatistiques(&statsVoitureHG, VOITURE, HAUT_GAMME);

   //Fin du programme
   printf("%s", "\nPresser ENTER pour quitter...");
   viderBuffer();

   return EXIT_SUCCESS;
}

void viderBuffer(void) {
   int c;

   do {
      c = getchar();
   } while(c != '\n' && c != EOF);
}

void triDecroissantParkingTaxe(const VehiculeParking* parking, size_t tailleParking) {
   qsort((void*)parking, tailleParking, sizeof(VehiculeParking), comparaisonTaxe);
}

int comparaisonTaxe(const void* v1, const void* v2) {
   return ((VehiculeParking*)v1)->taxeAnnuelle < ((VehiculeParking*)v2)->taxeAnnuelle;
}

int comparaisonDouble(const void* d1, const void* d2) {
   return *((double*)d1) < *((double*)d2);
}

void afficherParking(const VehiculeParking* parking, size_t tailleParking) {
   for (size_t i = 0; i < tailleParking; ++i) {
      printf("------------------------------------------------\n");
      afficherVehicule(&parking[i].vehicule);
      printf("\n");
      printf("Taxe annuelle : %.2lf CHF\n", parking[i].taxeAnnuelle);
      printf("------------------------------------------------\n");
      printf("\n");
   }
}

void afficherStatistiques(const Statistiques* stats, TVehicule vehicule, TVoiture voiture) {
   printf("%s", obtenirNomTVehicule(vehicule));
   if (vehicule != CAMIONETTE) {
      printf(" %s", obtenirNomTVoiture(voiture));
   }
   printf("\n");

   printf("Somme      : %.2lf\n", stats->somme);
   printf("Moyenne    : %.2lf\n", stats->moyenne);
   printf("Mediane    : %.2lf\n", stats->mediane);
   printf("Ecart-type : %.2lf\n", stats->ecartType);
}

Statistiques obtenirStatistiques(const VehiculeParking* parking,
                                 size_t tailleParking,
                                 TVehicule vehicule,
                                 TVoiture voiture) {
   double* tab;
   size_t tailleTab = 0;
   Statistiques stats = {};

   //Allocation dynamique
   tab = (double*) calloc(tailleParking, sizeof(double));

   if (tab) {
      //Cree un tableau avec le type de véhicule désiré et fait le calcul de la somme
      //de ses éléments
      for (size_t i = 0; i < tailleParking; ++i) {
         if (vehicule == CAMIONETTE &&
             (&parking[i])->vehicule.tVehicule == CAMIONETTE ||
             vehicule == VOITURE &&
             (&parking[i])->vehicule.typeVehicule.voiture.tVoiture == voiture) {
            tab[tailleTab++] = parking[i].taxeAnnuelle;
            stats.somme += tab[tailleTab - 1];
         }
      }

      tab = (double*) realloc(tab, tailleTab * sizeof(double));
      if (tab) {
         //Tri le tableau de façon décroissante car le tableau peut ne pas être encore
         //trié
         qsort((void*)tab, tailleTab, sizeof(double), comparaisonDouble);

         //Calcul de la moyenne
         stats.moyenne = stats.somme / (double)tailleTab;

         //Calcul de la médianne
         if(tailleTab % 2) {
            stats.mediane = tab[(tailleTab - 1) / 2];
         } else {
            stats.mediane = (tab[(tailleTab - 1)  / 2] + tab[(tailleTab - 1) / 2 + 1]) / 2;
         }

         //Calcul de l'écart-type
         double ecartMoyenne = 0;
         for (size_t i = 0; i < tailleTab; ++i) {
            ecartMoyenne += pow(tab[i] - stats.moyenne, 2);
         }
         stats.ecartType = sqrt(ecartMoyenne / (double)tailleTab);
      }

      //Libération de la mémoire
      free(tab);
   }

   return stats;
}