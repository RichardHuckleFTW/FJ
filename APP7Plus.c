#include "stdio.h"
#include "string.h"

#define nDeps 20

typedef struct {
  char ville[20], type[30], resp[20];
  int nbr[100];
  int id, ray;
} dep;

int main() {
  int choix, n=0, id, posDep, max=0, sum=0, posMax=0, pos, m, test, posRay;
  char ville[20], type[30], resp[20];
  dep deps[nDeps];
  while(1) {
    do{
      printf(
          "------------------------------------------------------------------------------------------------\n"
          "1: Ajouter un nouveau dépot\n"
          "2: Ajouter des produits dans le rayon vide\n"
          "3: lister les depots de type saisie\n"
          "4: Afficher le nom de responsable et ville du depot avec le plus de produits\n"
          "5: Modifier le responsable d'un depot\n"
          "6: calculer le nombre de depots situés a une ville\n"
          "7: Afficher les depots ou le nombre de produits dans chaque rayon est inferieur a un seuil max\n"
          "8: Supprimer le premier depot vide\n"
          "0: Quittez\n\n"
          "Donner Votre Choix: "
          );
      scanf("%d", &choix);
      getchar();
    }while(choix > 8 || choix < 0);
    switch(choix){
      case 1:
        printf("Donner l'identifiant de depot: ");
        scanf("%d", &deps[n].id);
        getchar();
        do{
          printf("Donner la ville de depot (Tunis, Sousse, Bizerte): ");
          fgets(ville, 20, stdin);
          ville[strlen(ville) - 1] = '\0';
        } while(strcmp(ville, "Tunis") && strcmp(ville, "Sousse") && strcmp(ville, "Bizerte"));
        strcpy(deps[n].ville, ville);
        do{
          printf("Donner le type de depot (vest, alim, pdr): ");
          fgets(type, 30, stdin);
          type[strlen(type) - 1] = '\0';
        }while(strcmp(type, "vest") && strcmp(type, "alim") && strcmp(type, "pdr"));
        strcpy(deps[n].type, type);
        printf("Donner le Nombre de rayon: ");
        scanf("%d", &deps[n].ray);
        getchar();
        for(int i=0; i<n; deps[n].nbr[i++]=0);
        printf("Donner le nom de responsable: ");
        fgets(resp, 20, stdin);
        resp[strlen(resp) - 1] = '\0';
        strcpy(deps[n].resp, resp);
        n++;
        printf("Depot Crée!\n");
        printf("Total Depot: %d\n", n);
      break;
      case 2:
        printf("Donner id de depot: ");
        scanf("%d", &id);
        getchar();
        for(int i=-1; i<n && deps[i].id != id; posDep=++i);
        if(posDep == n) {
          printf("Depot n'existe pas\n");
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
          printf("Tous les Rayons sont remplis\n");
          break;
        }
        do{
          printf("Donner la quantité (moins que 200): ");
          scanf("%d", &(deps[posDep].nbr[posRay]));
          getchar();
        } while(deps[posDep].nbr[posRay] > 200 || deps[posDep].nbr[posRay] <= 0);
      break;
      case 3:
        do{
          printf("Donner le critere de type: ");
          fgets(type, 30, stdin);
          type[strlen(type) - 1] = '\0';
        }while(strcmp(type, "vest") && strcmp(type, "alim") && strcmp(type, "pdr"));
        for(int i=0; i<n; i++) {
          if(!strcmp(deps[i].type, type))
            printf("Responsable: %s, Depot id: %d\n",deps[i].resp, deps[i].id);
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
        printf("Responsable: %s, Ville: %s, Quantité: %d\n", deps[posMax].resp, deps[posMax].ville, max);
        max=0;
        break;
      case 5:
        printf("Donner id de depot: ");
        scanf("%d", &id);
        getchar();
        for(int i=-1; i<n && deps[i].id != id; pos=++i);
        if(pos == n) {
          printf("Depot n'existe pas\n");
          break;
        }
        printf("Donner le nouveau responsable: ");
        fgets(resp, 20, stdin);
        resp[strlen(resp) - 1] = '\0';
        strcpy(deps[pos].resp, resp);
      break;
      case 6:
        printf("Donner la ville: ");
        fgets(ville, 20, stdin);
        ville[strlen(ville)-1] = '\0';
        for(int i=0; i<n; i++) {
          if(strcmp(deps[i].ville, ville)) {
            printf("Id: %d, Ville: %s\n", deps[i].id, deps[i].ville);
          }
        }
      break;
      case 7:
        printf("Donner la seuil max: ");
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
            printf("Id: %d\n", deps[i].id);
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
            printf("Depot d'identificateur %d va etre supprimé\n", deps[i].id);
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
