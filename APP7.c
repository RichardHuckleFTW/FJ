#include <stdio.h>
#include "string.h"

#define nHotels 3
#define nMeals 4


typedef struct participant{
  int choixHotel, choixRepas;
  char name[40], surname[40]; 
  int id;
} participant;

int main(void) {
  int hotels[nHotels] = { 0, 15, 35};
  int meals[nMeals] = { 0, 50, 75 , 125 };
  int choix, cin, pos, montant=0, n=0;
  participant p, ps[30]; 
  
  while(1) {
    do{
      printf("---------------------------------\n"
      "1: Ajouter un participant\n"
      "2: Calculer le montant d'un participant\n"
      "3: Afficher Les informations des participants\n"
      "4: Supprimer un participant\n"
      "0: Quitter\n"
      );
      scanf("%d", &choix);
      getchar();
    } while(choix < 0 || choix > 4); 
    switch(choix) {
      case 1:
        printf("Donner le nom: ");
        fgets(p.name, 40, stdin);
        p.name[strlen(p.name)-1] = '\0';
        printf("Donner le prenom: ");
        fgets(p.surname, 40, stdin);
        p.surname[strlen(p.surname)-1] = '\0';
        printf("Donner le cin: ");
        scanf("%d", &(p.id));
        getchar();
        printf("Choisissez un Repas: \n"
        "0: Pas de choix\n" 
        "1: Dejeuner (%d DT)\n"
        "2: Dîner (%d DT)\n"
        "3: Dejeuner et Dîner (%d DT)\n"
        , meals[0], meals[1], meals[2]);
        scanf("%d", &(p.choixRepas));
        getchar();
        printf("Choisissez un Hotel: \n"
        "0: Pas de choix\n" 
        "1: Hotel 4 etoiles (%d DT)\n"
        "2: Hotel 5 etoiles (%d DT)\n"
        , hotels[0], hotels[1]);
        scanf("%d", &(p.choixHotel));
        getchar();
        ps[n++] = p;
        break;
      case 2:
        printf("Donner le cin de participant: ");
        scanf("%d", &cin);
        getchar();
        for(int i=-1; i<n && ps[i].id != cin; pos=++i);
        if(i==n) {
          printf("Le participant n'existe pas\n");
          break;
        }
        int choixRepas = ps[pos].choixRepas;
        int choixHotel = ps[pos].choixHotel;
        montant += meals[choixRepas];
        montant += hotels[choixHotel];
        printf("Le montant Total de %s: %d DT\n", ps[pos].name, montant);
        montant=0;
        break;
      case 3:
        printf("0: Les participants sans critére\n"
        "1: Les participants qui ont choisi l'hotel 4 etoiles:\n"
        "2: Les participants qui ont choisi l'hotel 5 etoiles\n"
        );
        scanf("%d", &choix);
        getchar();
        for(int i=0; i<n; i++) {
          if(ps[i].choixHotel == choix) {
            printf("Name: %s, Hotel: %d\n", ps[i].name, ps[i].choixHotel);
          }
        }  
        break;
      case 4:
        printf("Donner le cin du participant a supprimer: ");
        scanf("%d", &cin);
        getchar();
        for(int i=-1; i<n && ps[i].id!=cin; pos=++i);
        if(i==n) {
          printf("Le participant n'existe pas\n");
          break;
        }
        for(int i=pos+1; i<n; i++) {
          ps[i-1] = ps[i];
        }
        n--;
        break;
      default: return 0;
    }
  }
}
