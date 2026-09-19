#include <stdio.h>
#include <stdlib.h>

void afficheTab (int *tab,int n){
    int i;
    for (i=0;i<n;i++){
        printf("t[%d] = %d\n",i,tab[i]);

    }
}

void saisirTab (int *tab,int n){
    int i;
    for (i=0;i<n;i++){
        printf("tab[%d] = ",i);
        scanf("%d",&tab[i]);

    }
}

int recherche (int *tab,int n,int x){
    int i;
    for (i=0;i<n;i++){
        if (tab[i]==x){
            return i;
        }
    }
    return -1;
}


void ajouteAlaFin (int *tab,int *n,int x){
    tab[*n] = x;
    (*n)++;

}

void inserer (int *tab,int *n,int x,int pos){
    int i;
    (*n)++;
    for (i=*n-1;i>pos;i--){
        tab[i]=tab[i-1];
    }
    tab[pos] = x;
}

void supprimer (int *tab,int *n,int x){
    int i;
    if (recherche (tab,*n,x)==-1) {
        printf("x n´existe pas");
    }else {
        for (i=recherche (tab,*n,x);i<*n-1;i++){
            tab[i]=tab[i+1];
        }
        (*n)--;
    }
}

void supprimerTouT (int *tab,int *n,int x){
    int i,j;
    for (i=0;i<*n;i++){
        if (tab[i]==x){
            for (j=i;j<*n-1;j++){
                tab[j]=tab[j+1];
            }
            (*n)--;
            i--;
        }
    }
}

int main (){
    int n,o,x,pos;
    int t[100];
    printf ("taper le nombre de element = ");
    scanf("%d",&n);
    printf("1-afficher le tableau\n");
    printf("2-saisir le tableau\n");
    printf("3-rechercher un element\n");
    printf("4-ajouter un element à la fin\n");
    printf("5-inserer un element\n");
    printf("6-supprimer un element\n");
    printf("7-supprimer tous les elements\n");
    do{
        printf ("taper le numero de operation = ");
        scanf("%d",&o);
        if (o==1){afficheTab(t,n);
         } else if (o==2){saisirTab(t,n);
         }else if (o==3){printf ("taper le valeur de x = ");
                scanf("%d",&x);
                printf("L'indice de %d est %d\n",x,recherche(t,n,x));
         } else if (o==4){printf ("taper le valeur de x = ");
                scanf("%d",&x);
                ajouteAlaFin(t,&n,x);
        } else if (o==5){printf ("taper le valeur de x = ");
                scanf("%d",&x);
                printf ("taper le position = ");
                scanf("%d",&pos);
                inserer(t,&n,x,pos);
        } else if (o==6){printf ("taper le valeur de x = ");
             scanf("%d",&x);
             supprimer(t,&n,x);
        } else {printf ("taper le valeur de x = ");
             scanf("%d",&x);
             supprimerTouT(t,&n,x);}
    }while (o!=-1);
    return 0;
}


