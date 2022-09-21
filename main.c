#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// structure    

typedef struct {
char nom[20];
char code[20];
int quantite;
float prix;
} Produit; 
// variables Utilises
Produit tableDeProduit[70];
int i, j;
int nbrDeProduit = 0;
int choix;

Produit prixTotal[50];
int nobrAchat = 0;

// fonction pour ajouter un nouveau produit
void ajouterUnNouveauProduit(){
    printf("\nAjouter un nouveau produit\n");
    printf("entrer le nom de produit: ");
    scanf("%s",tableDeProduit[nbrDeProduit].nom);
    printf("entrer le code de produit: ");
    scanf("%s",tableDeProduit[nbrDeProduit].code);
    printf("entrer la quantite de produit: ");
    scanf("%d",&tableDeProduit[nbrDeProduit].quantite);
    printf("entrer le prix de produit: ");
    scanf("%f",&tableDeProduit[nbrDeProduit].prix);
    nbrDeProduit++;
    there:
    printf("\n-> Tapez 1 Pour retourner au menu principale");
    printf("\n-> Tapez 2 Pour quitter\n");
    printf("======> Votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there;
    }

// fonction pour ajouter plusieurs produits
void ajouterPlusieursProduits() {
    int n;
    printf("combien de produit voulez vous ajoutter: ");
    scanf("%d",&n);
    printf("\nAjouter plusieurs produits\n");
    for (i = 0; i < n; i++) {
        printf("entrer le nom de produit: ");
        scanf("%s",tableDeProduit[nbrDeProduit].nom);
        printf("entrer le code de produit: ");
        scanf("%s",tableDeProduit[nbrDeProduit].code);
        printf("entrer la quantite de produit: ");
        scanf("%d",&tableDeProduit[nbrDeProduit].quantite);
        printf("entrer le prix de produit: ");
        scanf("%f",&tableDeProduit[nbrDeProduit].prix);
        nbrDeProduit++;
        printf("_____________\n");
    }
    there:
    printf("\n-> Tapez 1 Pour retourner au menu principale");
    printf("\n-> Tapez 2 Pour quitter\n");
    printf("======> Votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there;
    }

    // Pour lister les produit selon l'ordre du prix
    void listerPrixProduit() {
        printf("\n *****Les produits valable dans la pharmacie*****\n");
        
        for ( i = 0; i < nbrDeProduit; i++) {
            for (j = 0; j < nbrDeProduit - 1; j++) {
                if ( tableDeProduit[j].prix < tableDeProduit[j+1].prix) {
                    Produit swap;
                    swap = tableDeProduit[j];
                    tableDeProduit[j] = tableDeProduit[j+1];
                    tableDeProduit[j+1] = swap;
                }
            }
        }
        for (i = 0; i < nbrDeProduit; i++){
               printf("Le nom de produit: %s\n", tableDeProduit[i].nom);
               printf("Le prix de produit: %.2f\n", tableDeProduit[i].prix);
               printf("Le prix TTC de produit %.2f\n", tableDeProduit[i].prix + tableDeProduit[i].prix * 0.15);
               printf("__________________\n");
    }
        there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
            case 1 : 
             main(); 
             break;
            case 2 : 
             exit(0); 
             break;
            default :
             printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there;
    }

    // Pour lister les produit selon l'ordre alphabetique
    void listerNomProduit() {
      printf("\n *****Les produits valable dans la pharmacie*****\n");
        
        for ( i = 0; i < nbrDeProduit; i++) {
            for (j = 0; j < nbrDeProduit - 1; j++) {
                if ( strcmp(tableDeProduit[j].nom ,tableDeProduit[j+1].nom) > 0 ) {

                    Produit swap;
                    swap = tableDeProduit[j];
                    tableDeProduit[j] = tableDeProduit[j+1];
                    tableDeProduit[j+1] = swap;
                }
            }
        }
        for (i = 0; i < nbrDeProduit; i++){
               printf("Le nom de produit: %s\n", tableDeProduit[i].nom);
               printf("Le prix de produit: %.2f\n", tableDeProduit[i].prix);
               printf("Le prix TTC de produit %.2f\n", tableDeProduit[i].prix + tableDeProduit[i].prix * 0.15);
               printf("__________________\n");
    }   
        there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
       {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
       }
       goto there;
    }
    
    // fonction pour lister tous les produits
    void listerTousLesProduits() { 
        there:
        printf("\n-> Tapez 1 pour afficher les produits selon l'ordre du prix \n");
        printf("\n-> Tapez 2 Pour afficher les produits selon l'ordre alphabétique\n");
        printf("Entrez votre choix: ");
        scanf("%d",&choix);
        switch (choix) {
        case 1:
        listerPrixProduit();
        break;
        case 2:
        listerNomProduit();
        break;
        default:
        printf(" votre choix n'est pas valide. merci de refaire votre choix \n");
        goto there;
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    }
  }

  // fonction pour acheter un produit
    void acheterUnProduit() {
    char produitCode[10];
    printf("Entrer le code de produit que vous voulez l'acheter: ");
    scanf("%s", produitCode);
    printf("Entrer la quantite que vous voulez acheter: ");
    scanf("%d", &prixTotal[nobrAchat].quantite);
    for (i = 0; i < nbrDeProduit; i++) {
        if (strcmp (produitCode , tableDeProduit[i].code) == 0) {
            tableDeProduit[i].quantite = tableDeProduit[i].quantite - prixTotal[nobrAchat].quantite;
            printf("La quantite valable dans le stock apres l'achat est: %d\n", tableDeProduit[i].quantite);
            prixTotal[nobrAchat].prix = (tableDeProduit[i].prix + tableDeProduit[i].prix*0.15) * prixTotal[nobrAchat].quantite;
            printf("Le prix total de cette opperation est: %.2f\n", prixTotal[nobrAchat].prix);
            nobrAchat++;
        }
    }
        // ajouter la date
        time_t myTime;
        struct tm *todaytest;
        char test[30] ;
        time(&myTime);
        todaytest = localtime( &myTime);
        strftime(test, 30, "%x - %I:%M%p", todaytest);
        printf("L'opperation est effectuer le %s\n",test) ;

        printf("_________________________\n");
        there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
     goto there;   
  }

  // fonction pour rechercher un produit par code
  void rechercherUnProduitParCode() {
    char produitCode[10];
    printf("Entrez le code de produit: ");
    scanf("%s", produitCode);
    for (i = 0; i < nbrDeProduit; i++) {
        if (strcmp(tableDeProduit[i].code , produitCode ) == 0) {
            printf("Le code de produit: %s\n",tableDeProduit[i].code);
            printf("Le nom de produit: %s\n",tableDeProduit[i].nom);
            printf("Le prix de produit: %.2f\n",tableDeProduit[i].prix);
            printf("La quantite de produit: %d\n",tableDeProduit[i].quantite);
            printf("_________________________\n\n");
        } 
    }
        there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there;
  }
  // fonction pour rechercher un produit par nom
  void rechercherUnProduitParNom() {
    char produitNom[10];
    printf("Entrez le nom de produit: ");
    scanf("%s", produitNom);
    for (i = 0; i < nbrDeProduit; i++) {
        if (strcasecmp(tableDeProduit[i].nom, produitNom) == 0) {
            printf("Le nom de produit: %s\n",tableDeProduit[i].nom);
            printf("Le code de produit: %s\n",tableDeProduit[i].code);
            printf("Le prix de produit: %.2f\n",tableDeProduit[i].prix);
            printf("La quantite de produit: %d\n",tableDeProduit[i].quantite);
            printf("_________________________\n\n");
        }
    }
        there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there;
  }

  // fonction pour afficher l'etat de stock
  void etatDeStock() {
    printf("L'etat de stock\n");
    printf("les produits dont la quantite est inferieure a 3\n______________________\n\n");
    for (i = 0; i < nbrDeProduit; i++) {
        if (tableDeProduit[i].quantite < 3) {
            printf("Dans le stock, concernant %s, il y a %d unitees\n", tableDeProduit[i].nom, tableDeProduit[i].quantite);
        }
    }
    there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there;
  }

  // fonction pour alimenter le stock
  void alimenterLeStock() {
    printf("Alimenter le stock\n");
    printf("_______________________\n");
    char produitCode[10];
    int unite;
    printf("Entrez le code du produit dont vous voulez alimenter la quantite: ");
    scanf("%s",produitCode);
    printf("Combien d'uniter voulez vous ajouter: ");
    scanf("%d", &unite);
    for (i = 0; i < nbrDeProduit; i++) {
        if (tableDeProduit[i].code == produitCode) { 
            tableDeProduit[i].quantite = tableDeProduit[i].quantite + unite; 
        }
        printf("Apres l'alimentation, la quantite de %s devient %d\n", tableDeProduit[i].nom, tableDeProduit[i].quantite + unite);
        printf("______________________\n");
    }
    there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there; 
  }   

//fonction pour supprimer un produit
  void supprimerUnProduit () {
    printf("Supprimer un produit\n__________________\n");
    char produitCode[10];
    THERE:
    printf("Entrez le code de l'element a supprimer\n: "); 
    scanf("%s", produitCode);
    for (i = 0; i < nbrDeProduit; i++) {
        if (strcmp(tableDeProduit[i].code , produitCode) > 0 ) {
        printf("Entrer un code valable a un produit!!");
        goto THERE;
      }
      else {
        for (i = 0; i < nbrDeProduit; i++) {
            tableDeProduit[i] = tableDeProduit[i+1];            
        }
        nbrDeProduit--;
      }
    }
     printf("Supprime avec succes");
     printf("______________________\n");
     there:
        printf("\n-> Tapez 1 Pour retourner au menu principale");
        printf("\n-> Tapez 2 Pour quitter\n");
        printf("======> Votre choix : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1 : 
         main(); 
         break;
        case 2 : 
         exit(0); 
         break;
        default :
         printf(" votre choix n'est pas valide. merci de refaire votre choix ");
    }
    goto there; 
  }

  // fonction de statistique
  void statistique () {
    printf("Le prix total de tous les produits vendus dans la journee\n");
    printf("__________________________________________\n");
    for (i = 0; i < nobrAchat; i++) {

    }

  }

  int main(){
    printf("\n ___________Gestion de Pharmacie___________\n");
    there:
    printf("-> Tapez 1 pour ajouter un nouveau produit\n");
    printf("-> Tapez 2 Pour ajouter plusieurs nouveaux produits\n");
    printf("-> Tapez 3 Pour afficher les produits\n");
    printf("-> Tapez 4 Pour acheter un produit\n");
    printf("-> Tapez 5 Pour rechercher un produit par code\n");
    printf("-> Tapez 6 Pour rechercher un produit par nom\n");
    printf("-> Tapez 7 Pour afficher les produits dont la quantite est inferieure a 3\n");
    printf("-> Tapez 8 pour alimenter le stock\n");
    printf("-> Tapez 9 pour supprimer un produit\n");
    printf("======> Votre choix : ");
    scanf("%d",&choix);
    switch (choix) {
        case 1: 
        ajouterUnNouveauProduit ();
        break;
        case 2:
        ajouterPlusieursProduits();
        break;
        case 3:
        listerTousLesProduits();
        break;
        case 4:
        acheterUnProduit();
        break;
        case 5:
        rechercherUnProduitParCode();
        break;
        case 6:
        rechercherUnProduitParNom();
        break;
        case 7:
        etatDeStock();
        break;
        case 8:
        alimenterLeStock();
        break;
        case 9:
        supprimerUnProduit();
        break;
        case 10:
        statistique();
        break;
        default:
        goto there;;
        }
    }