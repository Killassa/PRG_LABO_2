#include <stdio.h>
#include <stdlib.h>
//#include "taxe.c"
#include "vehicule.h"

const Vehicule PARKING[] = {
        {CAMIONETTE, "FR 123451", "Ford", {{3.3}}},
        {VOITURE, "BE 88823", "BMW", {.voiture = {STANDARD, 1850, {{2998, 159}}}}},
        {VOITURE, "VD 119977", "Aston Martin", {.voiture = {HAUT_GAMME, 1870, {.voitureHg = {528}}}}},
        {CAMIONETTE, "BL 267564", "Mercedes-Benz", {{3.8}}},
        {VOITURE, "ZG 190002", "Dacia", {.voiture = {STANDARD, 1321, {{1460, 98}}}}},
        {VOITURE, "ZH 874569", "Porsche", {.voiture = {HAUT_GAMME, 2010, {.voitureHg = {678}}}}}
};

int main(void) {
    afficherVehicule(&PARKING[4]);

   return EXIT_SUCCESS;
}
