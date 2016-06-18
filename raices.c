#include "header.h"
#include "prototipos.h"
#define FUNC "x*x*x-x*x"

void raices_c()
{
    float xl,xu, es,ea,raiz,xr;
    int imax, iter, metodo;
    printf("Elegir el metodo\n");
    printf("1.- Biseccion\n");
    printf("2.- Falsa posicion\n");
    scanf("%d",&metodo);
    printf("\nDar el valor inical XL: ");
    scanf("%f",&xl);
    printf("\nDar el valor inical XU: ");
    scanf("%f",&xu);
    printf("\nDar el valor maximo del error es: ");
    scanf("%f",&es);
    printf("\nDar el numero max de iteraciones imax: ");
    scanf("%d",&imax);
    xr = xl;
    system("cls");
    switch(metodo)
    {
    case 1:
        raiz = Bisect(xl,xu,es,imax,xr,&iter,&ea);
        break;
    case 2:
        raiz = falsa_posicion(xl,xu,es,imax,xr,&iter,&ea);
        break;
    default:
        system("cls");
        printf("Opcion incorrecta, introducir una opcion correcta");
        raices();
        break;
    }
    printf("\nLa raiz es: %f",raiz);
    printf("\nEl error es: %f",ea);
    printf("\nEn %d iteraciones",iter);
}
float Bisect (float xl, float xu, float es, int imax,
              float xr, int *apiter, float *apea)
{
    float xrold, test,xlold=xl,xuold=xu;
    *apiter = 0;
    FILE *raices=fopen("bisecc.dat","w");
    do
    {
        xrold = xr;
        xr = (xl + xu)/2.0;
        *apiter = *apiter + 1;
        if(xr != 0)
        {
            *apea = fabs((xr-xrold)/xr)*100;
        }
        printf("\n %2d | %f | %f",*apiter,xr,*apea);
        fprintf(raices,"%f\t%f\n",xr,f(xr));
        test = f(xl)*f(xr);
        if(test < 0)
        {
            xu = xr;
        }
        else if(test > 0)
        {
            xl = xr;
        }
        else
        {
            *apea = 0;
        }
    }
    while(*apea >= es && *apiter <= imax);

    fclose(raices);
    graficador(FUNC,"\'bisecc.dat\'","points",xlold,xuold);

    return xr;
}

float falsa_posicion(float xl, float xu, float es, int imax,
                     float xr, int *apiter, float *apea)
{
    float xrold, test, fl, fu, fr,xlold=xl,xuold=xu;
    int iu=0, il=0;
    FILE *raices=fopen("falsa.dat","w");
    *apiter = 0;
    fl = f(xl);
    fu = f(xu);
    do
    {
        xrold = xr;
        xr = xu - (fu * (xl - xu))/(fl-fu);
        fr = f(xr);
        *apiter = *apiter + 1;
        if(xr != 0)
        {
            *apea = fabs((xr-xrold)/xr)*100;
        }
        printf("\n %2d | %f | %f",*apiter,xr,*apea);
        fprintf(raices,"%f\t%f\n",xr,f(xr));
        test = f(xl)*f(xr);
        if(test < 0)
        {
            xu = xr;
            fu = f(xu);
            iu=0;
            il= il +1;
            if(il>=2)
                fl=fl/2;
        }
        else if(test > 0)
        {
            xl = xr;
            fl=f(xl);
            il=0;
            iu=iu+1;
            if (iu>=2)
                fu=fu/2;
        }
        else
        {
            *apea = 0;
        }
    }
    while(*apea >= es && *apiter <= imax);

    fclose(raices);
    graficador(FUNC,"\'bisecc.dat\'","points",xlold,xuold);

    return xr;
}

float f(float x)

{
    return x*x*x-x*x;
}
