#include "stdio.h"

int verifyClient(int height, float weight, int dob, int ic, int at, int dsv) {
  float imc = (float) weight / (float) (height * height); if(ic == 1 || at == 1 || dsv >= 2) {
    return 0;
  } else if(2020 - dob >= 50 || dsv == 1 || (imc < 16.5 || imc > 30)) {
    return 1;
  }
}

int main(void) {
  int height, dob, ic, at, dsv, budget;
  float weight;
  //dob: Date of birth;
  //ic : intercantion chirugical;
  //at : arret de travail;
  //dsv: sepistage de serologies;

  printf("Taille: ");
  scanf("%d", &height);
  getchar();
  
  printf("Poids: ");
  scanf("%f", &weight);
  getchar();
  
  printf("Année de naissance: ");
  scanf("%d", &dob);
  getchar();

  
  printf("Antécédent medicaux: \n");
  printf("Intercention chirugicale lors des 10 derniéres années(1 si oui, 0 si non): ");
  scanf("%d", &ic);

  printf("Un arrêt de trtavail de plus d'un mois lors des 5 derniéres années(1 si oui, 0 si non): ");
  scanf("%d", &at);


  printf("Depistage de sérologies virales (0 si aucun, 1 si VHA, 2 si vhb, 3 si VHC, 4 si VIH");
  scanf("%d", &dsv);


  printf("Budget maximal: ");
  scanf("%d", &budget);

  //level:
    //0: refusé
    //1: risque moyen
    //2: faible risque

  //solution avec fonction
    int level = verify_client(height, weight, dob, ic, at, dsv);
    
  //solution sans fonction:
  /*

  
    int level = 2;
    float imc = (float) weight / (float) (height * height);
    if(ic == 1 || at == 1 || dsv >= 2) {
      level =  0;
    } else if(2020 - dob >= 50 || dsv == 1 || (imc < 16.5 || imc > 30)) {
      level =  1;
  }
    

  */

  float tarif_final1 = 1500, tarif_final2 = 1800, tarif_final3 = 2100;
  int choix;

  if(level == 0) {
    printf("Demande d'adhésion rejetée\n");
    return 0;
  } else if (level == 1){
    tarif_final1 *= 1.15;
    tarif_final2 *= 1.15; 
    tarif_final3 *= 1.15;
  }

  if(tarif_final1 <= budget) {
    printf("Niveau 1: maximum de prestatoins remboursées = 3000 DT, tarif de cotisation total = %f\n", tarif_final1);
  } else if(tarif_final2 <= budget) {
    printf("Niveau 2: maximum de prestatoins remboursées = 3500, tarif de cotisation total = %f\n", tarif_final2);
  } else if(tarif_final3 <= budget) {
    printf("Niveaux 3: maximu de prestatoins rembooursées = 5000, tarif de cotisation total =  %f\n", tarif_final3);
  } else {
    printf("Pas d'option");
  }

  printf("\nVeuillez choisir le niveau de prestations souhaité: ");
  scanf("%d", &choix);
  getchar();
  
  switch(choix){
    case 1:printf("Niveau 1 : détails des plafonds de remboursement : "
                  "Consultations :20 DT / acte"
                  "Médicaments : 400 DT"
                  "Analyses : 150 DT"
                  "Radiologie : 180 DT"
                  "Chirurgie : 1500 DT"
                  "Maximum de prestations remboursées = 3000 DT par prestataire et par an");
           break;
    case 2:printf("Niveau 2 : détails des plafonds de remboursement : "
                  "Consultations :30 DT / acte"
                  "Médicaments : 600 DT"
                  "Analyses : 200 DT"
                  "Radiologie : 250 DT"
                  "Chirurgie : 1800 DT"
                  "Maximum de prestations remboursées = 3500DT par prestataire et par an");
            break;
    case 3: printf("Niveau 3 : détails des plafonds de remboursement :"
                   "Consultations :40 DT / acte"
                   "Médicaments : 600 DT"
                   "Analyses : 300 DT"
                   "Radiologie : 300 DT"
                   "Chirurgie : 2000 DT"
                   "Maximum de prestations remboursées = 5000 DT par prestataire et par an.");
            break;
  }
  return 0;
}
