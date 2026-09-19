#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int isbn;
    char titre[50];
    char auteur[50];
    int annee;
}livre;
typedef struct node {
    livre l;
    struct node *next;
}node;
int nb_isbnrecherche(node *head,int isbn){
    node *current=head->next;
    int count=0;
    while (current!=NULL) {
        if (current->l.isbn==isbn) {
            count++;
        }
        current=current->next;
    }
    return count;
}
void ajouter_livre(livre l,node *head){
    printf("saisir le isbn : ");
    scanf("%d",&l.isbn);
    while (nb_isbnrecherche(head,l.isbn)>0) {
        printf("isbn deja existe, saisir un autre isbn : ");
        scanf("%d",&l.isbn);
    }
    while (l.isbn<0) {
        printf("isbn invalide, saisir un isbn valide : ");
        scanf("%d",&l.isbn);
    }
    printf("saisir le titre : ");
    scanf("%s",l.titre);
    printf("saisir le auteur : ");
    scanf("%s",l.auteur);
    printf("saisir le annee : ");
    scanf("%d",&l.annee);
    while (l.annee<0) {
        printf("annee invalide, saisir une annee valide : ");
        scanf("%d",&l.annee);
    }
    node *new_node=(node*)malloc(sizeof(node));
    if (new_node==NULL) {
        printf("erreur d'allocation de memoire\n");
        exit(1);
    }
    new_node->l.isbn=l.isbn;
    strcpy(new_node->l.titre,l.titre);
    strcpy(new_node->l.auteur,l.auteur);
    new_node->l.annee=l.annee;
    new_node->next=NULL;
    if (head->next==NULL) {
        head->next=new_node;
        printf("livre ajoute\n");
    } else {
        node *current=head->next;
        while (current->next!=NULL) {
            current=current->next;
        }
        current->next=new_node;
        printf("livre ajoute\n");
    }
}
void rechercher_livre(node *head,int isbn){
    node *current=head->next;
    while (current!=NULL) {
        if (current->l.isbn==isbn) {
            printf("isbn : %d\n",current->l.isbn);
            printf("titre : %s\n",current->l.titre);
            printf("auteur : %s\n",current->l.auteur);
            printf("annee : %d\n",current->l.annee);
            return;
        }
        current=current->next;
    }
    printf("livre non trouve\n");
}
void supprimer_livre(node *head,int isbn){
    node *current=head->next;
    node *prev=head;
    while (current!=NULL) {
        if (current->l.isbn==isbn) {
            prev->next=current->next;
            free(current);
            printf("livre supprime\n");
            return;
        }
        prev=current;
        current=current->next;
    }
    printf("livre non trouve\n");
}
void afficher_livres(node *head){
    node *current=head->next;
    while (current!=NULL) {
        printf("isbn : %d\n",current->l.isbn);
        printf("titre : %s\n",current->l.titre);
        printf("auteur : %s\n",current->l.auteur);
        printf("annee : %d\n",current->l.annee);
        current=current->next;
    }
}
int main(){
    node *head=(node*)malloc(sizeof(node));
    if (head==NULL) {
        printf("erreur d'allocation de memoire\n");
        exit(1);
    }
    head->next=NULL;
    livre l;
    int o,isbn;
    printf("1- ajouter un livre\n");
    printf("2- rechercher un livre par isbn\n");
    printf("3- supprimer un livre par isbn\n");
    printf("4- afficher tous les livres\n");
    printf("5- quitter\n");
    do {
        printf("choisir une option : ");
        scanf("%d",&o);
        switch(o){
            case 1:
                ajouter_livre(l,head);
                break;
            case 2:
                printf("saisir le isbn : ");
                scanf("%d",&isbn);
                rechercher_livre(head,isbn);
                break;
            case 3:
                printf("saisir le isbn : ");
                scanf("%d",&isbn);
                supprimer_livre(head,isbn);
                break;
            case 4:
                afficher_livres(head);
                break;
            case 5:
                break;
            default:
                printf("option invalide\n");
        }
    } while (o!=5);
    return 0;


}