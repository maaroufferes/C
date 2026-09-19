#include <stdio.h>
#include <math.h>
void saisir (double *a,double *b,double *c){
    printf("ax^2+bx+c=0 : \n");
do{
        printf("a=");
        scanf("%lf",a);
}while(*a==0);
printf("b=");
scanf("%lf",b);
printf("c=");
scanf("%lf",c);}
double calculdelta (double a,double b,double c){
return(b*b-4*a*c);}
void resoudre (double a,double b,double d,double *x1,double *x2,double *s){
if (d<0){
    *s=0;
}else if (d==0){
    *x1=-b/(2*a);
    *s=1;
}else{
    *x1=(-b+sqrt(d))/(2*a);
    *x2=(-b-sqrt(d))/(2*a);
    *s=2;
    }}
void affiche (double s,double x1,double x2){
if (s==0){
    printf("il n y a pas des sols \n");
}else if (s==1){
    printf("il existe un seule sol : x=%f \n",x1);
}else{
    printf("il existe deux sols : x1=%f et x2=%f \n",x1,x2);
}
}
void main (){
double a,b,c,x1,x2,d,s;
saisir(&a,&b,&c);
d=calculdelta(a,b,c);
resoudre(a,b,d,&x1,&x2,&s);
affiche(s,x1,x2);
}
