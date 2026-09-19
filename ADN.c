#include <stdio.h>
int main () {
    int n,i;
    char tso[100];
    char tsc[100];
    do {
        printf("le nombre de sequence de la ADN:");
        scanf("%d",&n);
    }while (n<1 || n>100);
    for (i=0;i<n;i++) {
        printf("entrer la sequence %d de l'ADN:",i+1);
        scanf("%s",&tso[i]);
       
    }
    for (i=0;i<n;i++){
        if (tso[i]=='A'){
            tsc[i]='T';
        }else if (tso[i]=='T'){
            tsc[i]='A';
        }else if (tso[i]=='C'){
            tsc[i]='G';
        }else if (tso[i]=='G'){
            tsc[i]='C';
        }else {
            tsc[i]='?';
        }
    }
    printf("la sequence complementaire est: ");
    for (i=0;i<n;i++) {
        printf("%c",tsc[i]);
    }
    

        

    

}