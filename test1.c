#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#pragma warning(disable : 4996)

#define MAX_ETD 100 /* ETD pour Etudiant*/
#define MAX_LONG_NOM 31 /* Longueur max de caractères pour le nom d'un étudiant*/
#define MAX_LONG_JUSTIF 51 /*Longueur max des justificatifs*/
#define MAX_ABSENCES 1000 // Max d'absences qui peuvent être stockés//
#define MAX_JOURS 40 /*Max jour étiquetant l'absence*/

typedef struct {

    int id; //identifiant unique de l'étudiant//
    int nom[MAX_LONG_NOM]; //stocker le nom de l'étudiant avec la limite de caractère//
    int groupe; //stocke le numéro de l'étudiant, utilisé pour organiser et trier les étudiants/groupe//
    int absences; //Compte le nombre total d'absences de l'étudiant//
} Etudiant;

typedef struct {

    int id; //identifiant unique de l'étudiant, fait le lien avec au dessus//
    int etdgroupeid; //permet de relier l'étudiant avec son groupe//
    int jour; //jour d'absence//
    char moitjour; //demi journée d'absence//
    bool justifie; //si l'absence a été justifiée ou non//
    char justifiee[MAX_LONG_JUSTIF]; //stock la justification avec le nb de caractère défini plus haut//
    bool validenatt; //Prend valeur booléenne, si validation est true, cela siginifique que la validation a été transmise mais doit être validé//
} Absence;

int main() {
    Etudiant etudiants[MAX_ETD];  // Tableau pour stocker les étudiants
    int nbEtudiants = 0;  // Compteur du nombre d'étudiants inscrits
    int groupe;
    char nom[MAX_LONG_NOM];

    while (1) {
        printf("Entrez le groupe et le nom de l'etudiant : \n");
        scanf("%d %s", &groupe, nom);

        // Vérifier si le nom existe déjà dans le même groupe
        int nomExiste = 0;
        for (int i = 0; i < nbEtudiants; i++) {
            if (etudiants[i].groupe == groupe && strcmp(etudiants[i].nom, nom) == 0) {
                nomExiste = 1;
                break;
            }
        }

        if (nomExiste) {
            printf("Nom incorrect : un etudiant dans ce groupe porte deja ce nom.\n");
        }
        else {
            // Ajouter un nouvel étudiant
            etudiants[nbEtudiants].id = nbEtudiants + 1;  // L'ID est le numéro de l'étudiant (1, 2, 3, ...)
            etudiants[nbEtudiants].groupe = groupe;
            strcpy(etudiants[nbEtudiants].nom, nom);

            printf("Inscription enregistree : %s (%d)\n", etudiants[nbEtudiants].nom, etudiants[nbEtudiants].id);

            // Incrémenter le compteur d'étudiants
            nbEtudiants++;
        }

        // Vous pouvez ajouter une condition de sortie pour terminer la boucle si nécessaire
    }

    return 0;
}
