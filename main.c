#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

#define MAX 100

int main() {
  int choix;

  while(1) {
    do{
      printf("-----------------------------------------------\n"
      "1: Afficher les mots d'une phrase\n"
      "2: Afficher les voyelles et leur nombre dans un mot\n"
      "3: Construire une phrase\n"
      "0: Quitter\n"); 
      scanf("%d", &choix);
      getchar();
    }while(choix < 0 || choix > 3);
    if(!choix) return 0; 


    switch(choix) {
      case 1:{
        printf("Donner une phrase: ");
        char str[MAX];
        fgets(str, MAX, stdin);
        str[strlen(str)-1] = '\0';
        printf("%s\n", str);
        char currentWord[] = "";
        int start = 0, finish = 0;
        int count = 0, l = 0, status = 0;
        for(int i=0; str[i] != '.'; i++) {
          if(status){
            if(str[i] == ' ') {
              printf("Mot %d: ", count);
              for(int k=start; k<=finish; k++) printf("%c", str[k]);
              printf("\n");
              status = !status;
            } else {
              finish++;
            }
          } else if(!status && str[i] != ' ') {
            start=finish=i;
            count++; 
            status = !status;
          }
        }

        printf("Mot %d: ", count);
        for(int k=start; k<=finish; k++) printf("%c", str[k]);
        printf("\n");
        break;
      }
      case 2:{
        char str[MAX];
        char voyels[] = "aeiuoy";
        int count = 0;
        printf("Donner un mot: ");
        scanf("%s", str);
        for(int i=0; i<strlen(str); i++) {
          if(strchr(voyels, str[i])){
            printf("%-3c", str[i]);
            count++;
          }
        } 
        printf("\nle nombre de voyelles dans %s est: %d\n", str, count);
        break;
      }
      case 3:{
        int pos, last = 7, len = 7;
        char s[] = "c'est notre sixieme prosit pour cette annee";
        char list[MAX][MAX] = {"c'est", "notre", "sixieme", "prosit", "pour", "cette", "annee"};
        char randomList[MAX][MAX] = {}, orders[MAX][MAX], str[MAX], aux[MAX];
        char reponse[MAX];

        printf("Votre list de mot: ");
        srand(time(NULL));
        for(int i=0; i<len; i++ ){
          pos = (rand() % ((len - 1) - i + 1)) + i;
          strcpy(randomList[i], list[pos]);
          printf("%s ", list[pos]);
          strcpy(aux, list[pos]);
          strcpy(list[pos], list[i]);
          strcpy(list[i], aux);
        }
        printf("\n");
        int order;
        for(int i=0; i<len; i++) {
          printf("Donner l'order du mot %s dans la phrase: ", randomList[i]);
          scanf("%d", &order);
          strcpy(orders[order-1], randomList[i]);
        }
        for(int i=0; i<len; i++){
          strcat(reponse, orders[i]);   
          strcat(reponse, " ");
        }
        reponse[strlen(s)] = '\0';
        printf("Votre reponse: %s\n", reponse);
        if(!strcmp(reponse, s)) printf("Bravo c'est la bonne reponse %s\n", s);
        else printf("La phrase %s n'a pas de sense\n", reponse); 
        break; 
      }
    }
  }
}
