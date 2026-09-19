#include <stdio.h>
int main () {
    int n,nt,i,ad,s,max,nmax;
    float m;
    char e;
    char  noms [100][50];
    float note [100];
    do {
        printf("entrer le nombre d'etudiants: ");
        scanf("%d",&n);
    }
    while (n<1 || n>100);
    for (i=0;i<n;i++) {
        printf("entrer le nom de l'etudiant %d: ",i+1);
        scanf("%s",&noms[i]);
        
    }
    for (i=0;i<n;i++) {
        do {
        printf("entrer la note de l'etudiant %d: ",i+1);
        scanf("%f",&note[i]);
        }while (note[i]<0 || note[i]>20);
        
    }
    ad=0;
    s=0;
    for (i=0;i<n;i++) {
        if (note[i]>=10) {
            ad++;

        }
        s=s+note[i];
            
        
        
    }
    m=s/n;
    max=note[0];
    nmax=0;
    for (i=0;i<n;i++) {
        if (note[i]>max) {
            max=note[i];
            nmax=i;
            
        }
        
        
    }
    for (i=0;i<n;i++) {
        printf("l'etudiant %s a la note de %f\n",noms[i],note[i]);
        
    }
    printf("le nombre d'admis est: %d\n",ad);
    printf("le nombre de non admis est: %d\n",(n-ad));
    printf("la moyenne de la classe est: %f\n",m);
    printf("l eleve %s a la note meilleure de %d",noms[nmax],max);


}