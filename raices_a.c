#include "header.h"
#include "prototipos.h"
#define FUNC "sin(x)"
void raices_a()
{
    double x0,es,ea,xl=0,raiz;
    int imax, iter, metodo;
    printf("Elegir el metodo\n");
    printf("1.- Puntofijo\n");
    printf("2.- Newton Rapson\n");
    printf("3.- Secante \n");
    scanf("%d",&metodo);
    printf("\nDar el valor inical X0: ");
    scanf("%lf",&x0);
    printf("\nDar el valor maximo del error es: ");
    scanf("%lf",&es);
    printf("\nDar el numero max de iteraciones imax: ");
    scanf("%d",&imax);
    system("cls");
    switch(metodo)
    {
    case 1:
        raiz = pfijo(x0,es,&ea,imax,&iter);
        break;
    case 2:
        raiz = newtonrap(x0,es,&ea,imax,&iter);
        break;
    case 3:
        printf("\nDar el valor inical X0: ");
        scanf("%lf",&x0);
        raiz = secante(x0,xl,es,&ea,imax,&iter);
        break;
    default:
        system("cls");
        printf("Opcion incorrecta, introducir una opcion correcta");
        raices_a();
        break;
    }
}
double pfijo(double x0, double es, double *ea, int imax, int *iter)
{
    double xr=x0, xrold;
    FILE *raices=fopen("pfijo.dat","w");

        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");

    *iter = 0;
    do{
        xrold = xr;
        xr = g(xrold);
        *iter=*iter+1;
        if(xr!=0)
        {
            *ea=fabs((xr-xrold)/xr)*100;
        }
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, xr, *ea, g(xr) );
            fprintf(raices,"%lf\t%lf\n",xr,g(xr));

    }while(es < *ea && *iter <= imax);

        fclose(raices);
        graficador(FUNC,"\'pfijo.dat\'","points",-3.1416,3.1416);
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",xr,*iter);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",*ea);
        return xr;
}

double newtonrap(double x0, double es, double *ea, int imax, int *iter)
{
    double x1=x0;
    FILE *raices=fopen("newtonrap.dat","w");

        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");

    *iter = 0;
    do{
        x0 = x1;
        x1 = x0-(g(x0)/dg(x0));
        *iter=*iter+1;
        if(x1!=0)
        {
            *ea=fabs((x1-x0)/x1)*100;
        }
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, x1, *ea, g(x1) );
            fprintf(raices,"%lf\t%lf\n",x1,g(x1));
    }while(es < *ea && *iter <= imax);

        fclose(raices);
        graficador(FUNC,"\'newtonrap.dat\'","points",-3.1416,3.1416);
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",x1,*iter);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",*ea);
        return x1;
}

double secante(double x0, double x1, double es, double *ea, int imax, int *iter)
{
    double x2=x0;
    FILE *raices=fopen("secante.dat","w");

        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");

    *iter = 0;
    do{
        x0 = x1;
        x1 = x2;
        x2 = x1 - (g(x1) * (x0-x1)) / (g(x0)-g(x1));
        *iter=*iter+1;
        if(x1!=0)
        {
            *ea=fabs((x1-x0)/x1)*100;
        }
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, x2, *ea,g(x2) );
            fprintf(raices,"%lf\t%lf\n",x2,g(x2));

    }while(es < *ea && *iter <= imax);

        fclose(raices);
        graficador(FUNC,"\'secante.dat\'","points",-3.1416,3.1416);
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",x2,*iter);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",*ea);
        return x2;
}
float g(float x)
{
    return sin(x);
}
float dg(float x)
{
    return cos(x);
}
