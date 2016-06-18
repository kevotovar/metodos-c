#include "header.h"
#include "prototipos.h"

void init_lineal()
{
    double *X,*Y, a1, a0, syx, r2;
    int n;
    printf("Regresion Lineal\n");
    printf("Introduce el numero de puntos: ");
    scanf("%d",&n);
    X = crear_vector(n);
    Y = crear_vector(n);
    printf("\n Introduce X[i]: \n");
    lee_vector(X,n);
    printf("\n INTRODUCE Y[i]: \n");
    lee_vector(Y,n);
    lineal(X,Y,n, &a1, &a0, &syx, &r2);
    printf("\n Error: %lf",syx);
    printf("\n Coeficiente de determinacion: %lf",fabs(r2));
    destruye_vector(X);
    destruye_vector(Y);
}

void lineal(double *X, double *Y, int n, double *a1, double *a0, double *syx, double *r2)
{
    double sumx = 0, sumy = 0,sumxy = 0,vad;
    double sumx2 = 0, st = 0, sr = 0,cdd;
    double xm, ym;
    int i;

    for(i=0;i<n;i++)
    {
        sumx = sumx + X[i];
        sumy = sumy + Y[i];
        sumxy = sumxy + X[i]*Y[i];
        sumx2 = sumx2 + X[i]*X[i];
    }

    xm = sumx/n;
    ym = sumy/n;
    *a1 = (n*sumxy - sumx*sumy)/(n*sumx2 - sumx*sumx);
    *a0 = ym - *a1 * xm;
printf("\n       Xi       |        Yi       |     (Yi-Ym)^2     |      (Yi-ao-a1X1)^2   |");
    for(i=0;i<n;i++)
    {
        vad = (Y[i]-*a1*X[i]-*a0)*(Y[i]- *a1*X[i] - *a0);
        cdd = (Y[i]-ym)*(Y[i]-ym);
        st = st + cdd;
        sr = sr + vad;
printf("\n    %8.4lf    |     %8.4lf    |     %8.4lf      |         %8.4lf      |",X[i],Y[i],cdd,vad);
    }

    *syx = sqrt(sr/(n-2));
    *r2 = (st-sr)/st;
printf("\n      sum       |     %8.4lf    |     %8.4lf      |         %8.4lf      |",sumy,st,sr);
}

void init_polinomial()
{
    int n;
    double *x, *y, a1, a0, syx, r2;
    printf("\n\t\tREGRESION POR MINIMOS CUADRADOS POLINOMINAL");
    printf("\nDar el valor de puntos: ");
    scanf(" %d",&n);
    x = crear_vector(n);
    y = crear_vector(n);
    printf("\nDar los valores de X \n ");
    lee_vector(x,n);
    printf("\nDar los valores de Y \n ");
    lee_vector(y,n);
    polinomial(x,y,n,&a1,&a0,&syx,&r2);
    printf("\nLa ecuacion es: y= %lf + %lfx",a0,a1);
    printf("\nEl error estandar es: %lf",syx);
    printf("\nEl coeficiente de determinacion es: %lf",fabs(r2)*100);
}

void polinomial(double *x, double *y, int n, double *a1, double *a0,double *syx,double *r2)
{

    double sumx=0, sumxy=0, st=0, sumy=0, sumx2=0, sr=0,ym,xm;
        int i;
    for(i=0; i<n; i++)
    {
        sumx=sumx+x[i];
        sumy=sumy+y[i];
        sumxy=sumxy+(x[i]*y[i]);
        sumx2=sumx2+(x[i]*y[i]);
    }

    xm=sumx/n;
    ym=sumy/n;
    *a1=(n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
    *a0=ym-*a1 * xm;

    for(i=0; i<n; i++)
    {
        st=st+((y[i]-ym)*(y[i]-ym));
        sr=sr+((y[i]-(*a1*x[i])-*a0)*(y[i]-(*a1*x[i])-*a0));

    }
    *syx=sqrt(sr*(n-2));
    *r2=(st-sr)/st;
}
