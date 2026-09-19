#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    int mart;
    char nom[20];
    date date;
    char ville[20];
    float salaire;
} emp;

int recherche(emp *tab, int mart, int n) {
    int i;
    for (i=0;i<n;i++) {
        if(tab[i].mart==mart) {
            return i;
        }
    }
    return -1;
}

void saisir(emp *e) {
    printf("saisir le matricule : ");
    scanf("%d",&e->mart);
    printf("saisir le nom : ");
    scanf("%19s",e->nom);
    printf("saisir la date de naissance (jour mois annee) : ");
    scanf("%d %d %d",&e->date.jour,&e->date.mois,&e->date.annee);
    printf("saisir la ville : ");
    scanf("%s",e->ville);
    printf("saisir le salaire : ");
    scanf("%f",&e->salaire);
}
void afficher(emp e){
    printf("matricule : %d\n",e.mart);
    printf("nom : %s\n",e.nom);
    printf("date de naissance : %d/%d/%d\n",e.date.jour,e.date.mois,e.date.annee);
    printf("ville : %s\n",e.ville);
    printf("salaire : %.2f\n",e.salaire);
}
void initialiser(emp *e){
    e=realloc(e,0*sizeof(emp));
    if (e==NULL) {
        printf("erreur d'allocation de memoire\n");
        exit(1);
    }
}
void ajouter(emp *tab, int n, int mart){
    if (n>=100) {
        printf("tableau plein\n");
        return;
    }else if (recherche(tab, mart, n)!=-1) {
        printf("matricule deja existe\n");
        return;
    }else{
        tab=realloc(tab,(n+1)*sizeof(emp));
        if (tab==NULL) {
            printf("erreur d'allocation de memoire\n");
            exit(1);
        }

        saisir(&tab[n]);
    }
}void afficher_tous(emp *tab, int n){
    int i;
    for(i=0;i<n;i++){
        afficher(tab[i]);
    }
}
void rech_annee(emp *tab, int annee, int n){
    int i;
    for(i=0;i<n;i++){
        if(tab[i].date.annee==annee){
            afficher(tab[i]);
        }else{
            printf("aucun employe trouve\n");
        }
    }
}
void total_salaire(emp *tab, int n){
    int i;
    float total=0;
    for(i=0;i<n;i++){
        total+=tab[i].salaire;
    }
    printf("total des salaires : %.2f\n",total);
}
void mod_salaire(emp *tab, int mart, float salaire, int n){
    int i;
    for(i=0;i<n;i++){
        if(tab[i].mart==mart){
            tab[i].salaire=salaire;
            return;
        }
    }
}
void supprimer(emp *tab, int mart, int *n){
    int i;
    int j;
    for(i=0;i<*n;i++){
        if(tab[i].mart==mart){
            for(j=i;j<*n-1;j++){
                tab[j]=tab[j+1];
            }
            (*n)--;
            printf("employe supprime\n");
            return;
        }else{
            printf("employe non trouve\n");
        }
    }
}
int main(){
    emp *tab=malloc(100*sizeof(emp));
    if (tab==NULL) {
        printf("erreur d'allocation de memoire\n");
        exit(1);
    }
    int n,i;
    printf("saisir le nombre d'employes : ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        saisir(&tab[i]);
    }
    int o,mart,annee,salaire;
    do{
        printf("1- ajouter un employe\n");
        printf("2- afficher tous les employes\n");
        printf("3- rechercher un employe par matricule\n");
        printf("4- rechercher un employe par annee de naissance\n");
        printf("5- calculer le total des salaires\n");
        printf("6- modifier le salaire d'un employe\n");
        printf("7- supprimer un employe\n");
        printf("8- quitter\n");
        printf("choisir une option : ");
        scanf("%d",&o);
        switch(o){
            case 1:
                ajouter(tab, n, n+1);
                n++;
                break;
            case 2:
                afficher_tous(tab, n);
                break;
            case 3:
                printf("saisir le matricule : ");
                scanf("%d",&mart);
                int i=recherche(tab, mart, n);
                if(i!=-1){
                    afficher(tab[i]);
                }else{
                    printf("employe non trouve\n");
                }
                break;
            case 4:
                printf("saisir l'annee de naissance : ");
                scanf("%d",&annee);
                rech_annee(tab, annee, n);
                break;
            case 5:
                total_salaire(tab, n);
                break;
            case 6:
                printf("saisir le matricule : ");
                scanf("%d",&mart);
                printf("saisir le nouveau salaire : ");
                scanf("%f",&salaire);
                mod_salaire(tab, mart, salaire, n);
                break;
            case 7:
                printf("saisir le matricule : ");
                scanf("%d",&mart);    
                supprimer(tab, mart, &n);
                break;
            case 8:
                break;
            default:
                printf("option invalide\n");
                break;
        }
    }while(o!=8);
    free(tab);
    return 0;
}
