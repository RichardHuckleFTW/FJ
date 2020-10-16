#include "stdio.h"
#include "stdlib.h"
#include "math.h"


int main() {
  int nbr_prise;
  float temperature[], humidite[];
  int choix;

  do{
    printf("Donner Le Nombre de prise: ");
    scanf("%d", &nbr_prise);
  } while( nbr_prise > 15 || nbr_prise <= 0 );

  for(int i=0; i< nbr_prise; i++) {
    printf("Donner la temperature: ");
    scanf("%f", &temperature[i]);
  }



  for(int i=0; i< nbr_prise; i++) {
    printf("Donner la humidité: ");
    scanf("%f", &humidite[i]);
  }

  while(1) {
    do{
      printf("1: Afficher les mesures de température\n");
      printf("2: Afficher les mesures de l'humidité\n");
      printf("3: Modifier la valeur d'une prise donnée par son numéro\n");
      printf("4: Calculer et afficher l'humidité maximale et minimale et leurs numéros de prise associée\n");
      printf("5: Calculer et afficher la moyenne humidité et température\n");
      printf("6: Calculer l'ecart type de l'humidité\n");
      scanf("%d", &choix);
    } while(choix < 0 || choix > 6);


    if(!choix) break;

    switch (choix) {
      case 1:
        printf("Mesures de Temperature: \n")
        for(int i=0; i< nbr_prise; i++) {
          printf("Mesure N°%d: %d\n", i+1, temperature[i]);
        }
        break;
      case 2:
        printf("Mesures de Humidité: \n")
        for(int i=0; i< nbr_prise; i++) {
          printf("Mesure N°%d: %d\n", i+1, humidite[i]);
        }
        break;
      
      case 3:
        printf("Les Mesures de Temperature: \n")
        for(int i=0; i< nbr_prise; i++) {
          printf("Mesure N°%d: %d\n", i+1, temperature[i]);
        }

        
        printf("Les Mesures de Humidité: \n")
        for(int i=0; i< nbr_prise; i++) {
          printf("Mesure N°%d: %d\n", i+1, humidite[i]);
        }

        
        int numero;
        do{
          printf("Donner le numero de prise: ");
          scanf("%d", &numero);
        } while(numero > nbr_prise || numero < 0);

        printf("Donner la nouvelle valeur du temperature: ");
        scanf("%f", &temperature[numero]);
        printf("Donner la nouvelle valeur d'humidité: ");
        scanf("%f", &humidite[numero]);
        break;
      case 4:
        float max, min = humidite[0];
        int priseMax, priseMin = 0;
        for(int i=1; i<nbr_prise; i++) {
          if(humidite[i] > max) {
            max = humidite[i];
            priseMax = i+1;
          }
          if(humidite[i] < min) {
            min = humidite[i];
            priseMin = i+1;
          }
        }
        printf("Humidité Maximale: %d (Numéro de Prise: %d), Humidité Minimale: %d (Numéro de Prise: %d)\n", max,priseMax, min, priseMin);

      case 5:
        float result = 0;
        for(int i=0; i<nbr_prise; result+= temperature[i], i++);
        printf("La moyenne de Températures: %f\n", result/nbr_prise); 

        
        for(i=result=0; i<nbr_prise; result+= humidite[i], i++);
        printf("La moyenne d'Humidité: %f\n", result/nbr_prise); 
        break;

      case 6:
        double s;
        int moy = 0;
        for(int i=0; i<nbr_prise; moy+= humidite[i], i++);
        moy /= nbr_humidite;
    
        for(int i=0; i<nbr_prise; i++) {
          float x = humidite[i];
          float t = (x - moy);
          s += t*t;
        }
        s/=n;
        s = sqrt(s);
    
        printf("L'ecart type de l'humidité: %lf\n", s);
        break;
    }
  }
  return 0;
}

