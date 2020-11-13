#include "stdio.h"
#include "string.h"

#define nDeps 20
#define RED  "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

typedef struct {
  char ville[20], type[30], resp[20];
  int nbr[100];
  int id, ray;
} dep;

int main() {
  int choix, n=3, id, posDep, max=0, sum=0, posMax=0, pos, m, test, posRay;
  char ville[20], type[30], resp[20];
  dep deps[nDeps]={
    {.id=1, .ville="Tunis", .ray = 4, .type = "vestimentaires", .resp = "Firas", .nbr = {1,1,1,1}},
    {.id=2, .ville="Tunis", .ray = 4, .type = "vestimentaires", .resp = "Sarra", .nbr = {0,0,0,0}},
    {.id=3, .ville="Sousse", .ray = 4, .type = "alimentaires", .resp = "Rafik", .nbr = {0,0,0,0}}
  };
  while(1) {
    do{
      printf(GREEN
          "------------------------------------------------------------------------------------------------\n"
          "1: Ajouter un nouveau dépot\n"
          "2: Ajouter des produits dans le rayon vide\n"
          "3: lister les depots de type saisie\n"
          "4: Afficher le nom de responsable et ville du depot avec le plus de produits\n"
          "5: Modifier le responsable d'un depot\n"
          "6: calculer le nombre de depots situés a une ville\n"
          "7: Afficher les depots ou le nombre de produits dans chaque rayon est inferieur a un seuil max\n"
          "8: Supprimer le premier depot vide\n"
          "0: Quittez\n"BLUE
          "Donner Votre Choix: "RESET
          );
      scanf("%d", &choix);
      getchar();
    }while(choix > 8 || choix < 0);
    switch(choix){
      case 1:
        printf(BLUE"Donner l'identifiant de depot: "RESET);
        scanf("%d", &deps[n].id);
        getchar();
        do{
          printf(BLUE"Donner la ville de depot (Tunis, Sousse, Bizerte): "RESET);
          fgets(ville, 20, stdin);
          ville[strlen(ville) - 1] = '\0';
        } while(strcmp(ville, "Tunis") && strcmp(ville, "Sousse") && strcmp(ville, "Bizerte"));
        strcpy(deps[n].ville, ville);
        do{
          printf(BLUE"Donner le type de depot (Vestimentaires, Alimentaires, Pieces de rechanges): "RESET);
          fgets(type, 30, stdin);
          type[strlen(type) - 1] = '\0';
        }while(strcmp(type, "vestimentaires") && strcmp(type, "alimentaires") && strcmp(type, "pieces de rechanges"));
        strcpy(deps[n].type, type);
        printf(BLUE"Donner le Nombre de rayon: "RESET);
        scanf("%d", &deps[n].ray);
        getchar();
        for(int i=0; i<n; deps[n].nbr[i++]=0);
        printf(BLUE"Donner le nom de responsable: "RESET);
        fgets(resp, 20, stdin);
        resp[strlen(resp) - 1] = '\0';
        strcpy(deps[n].resp, resp);
        n++;
        printf(MAGENTA"Depot Crée!\n"RESET);
        printf(MAGENTA"Total Depot: %d\n"RESET, n);
      break;
      case 2:
        printf(BLUE"Donner id de depot: "RESET);
        scanf("%d", &id);
        getchar();
        for(int i=-1; i<n && deps[i].id != id; posDep=++i);
        if(posDep == n) {
          printf(RED"Depot n'existe pas\n"RESET);
          break;
        }
        posRay = -1;
        for(int i=0; i<deps[posDep].ray; i++) {
          if(deps[posDep].nbr[i] == 0) {
            posRay=i;
            break;
          }
        }

        if(posRay == -1) {
          printf(YELLOW"Tous les Rayons sont remplis\n"RESET);
          break;
        }
        do{
          printf(BLUE"Donner la quantité (moins que 200): "RESET);
          scanf("%d", &(deps[posDep].nbr[posRay]));
          getchar();
        } while(deps[posDep].nbr[posRay] > 200 || deps[posDep].nbr[posRay] <= 0);
      break;
      case 3:
        do{
          printf(BLUE"Donner le critere de type: "RESET);
          fgets(type, 30, stdin);
          type[strlen(type) - 1] = '\0';
        }while(strcmp(type, "vestimentaires") && strcmp(type, "alimentaires") && strcmp(type, "pieces de rechanges"));
        for(int i=0; i<n; i++) {
          if(!strcmp(deps[i].type, type))
            printf(MAGENTA"Responsable: %s, Depot id: %d\n"RESET,deps[i].resp, deps[i].id);
        }
      break;
      case 4:
        for(int i=0; i<deps[0].ray; i++)
          max += deps[0].nbr[i];

        for(int i=1; i<n; i++) {
          sum=0;
          for(int j=0; j<deps[i].ray; j++)
            sum += deps[i].nbr[j]; 
          if(sum > max) {
            max=sum;
            posMax = i;
          }
        }  
        printf(MAGENTA"Responsable: %s, Ville: %s, Quantité: %d\n"RESET, deps[posMax].resp, deps[posMax].ville, max);
        max=0;
        break;
      case 5:
        printf(BLUE"Donner id de depot: "RESET);
        scanf("%d", &id);
        getchar();
        for(int i=-1; i<n && deps[i].id != id; pos=++i);
        if(pos == n) {
          printf(RED"Depot n'existe pas\n"RESET);
          break;
        }
        printf(BLUE"Donner le nouveau responsable: "RESET);
        fgets(resp, 20, stdin);
        resp[strlen(resp) - 1] = '\0';
        strcpy(deps[pos].resp, resp);
      break;
      case 6:
        printf(BLUE"Donner la ville: "RESET);
        fgets(ville, 20, stdin);
        ville[strlen(ville)-1] = '\0';
        for(int i=0; i<n; i++) {
          if(strcmp(deps[i].ville, ville)) {
            printf(MAGENTA"Id: %d, Ville: %s\n"RESET, deps[i].id, deps[i].ville);
          }
        }
      break;
      case 7:
        printf(BLUE"Donner la seuil max: "RESET);
        scanf("%d", &m);
        getchar();
        for(int i=0; i<n; i++) {
          test=1;
          for(int k=0; k<deps[i].ray; k++) {
            if(deps[i].nbr[k] > m){
              test = 0;
              break;
            }
          }
          if(test) {
            printf(MAGENTA"Id: %d\n"RESET, deps[i].id);
            break;
          }
        }
      break;
      case 8:
        for(int i=0; i<n; i++) {
          test=1;
          for(int k=0; k<deps[i].ray; k++) {
            if(deps[i].nbr[k]) {
              test=0;
              break;
            }
          }
          if(test) {
            printf(MAGENTA"Depot d'identificateur %d va etre supprimé\n"RESET, deps[i].id);
            for(int c=i+1; c<n; c++) {
              deps[c-1] = deps[c];
            }
            n--;
            break;
          }
        }
        break;
      default: return 0;
    }
  }
}
