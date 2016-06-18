#include "header.h"
#include "prototipos.h"

void euler()
{
    FILE *datos = fopen("euler.dat","w");
    double x,xi,xf,dx,y,nc,dydx;
    int i;
    printf("Solucion EDO (Euler)\n");
    printf("Asigna el valor a Y: ");
    scanf("%lf",&y);
    printf("Asigna el valor a XI: ");
    scanf("%lf",&xi);
    printf("Asigna el valor a XF: ");
    scanf("%lf",&xf);
    printf("Asigna el valor a DX: ");
    scanf("%lf",&dx);
    nc=(xf-xi)/dx;
    x=xi;
    printf("Condiciones iniciales\n");
    fprintf(datos,"#\tX\tY\n");
    fprintf(datos,"%10.4lf\t%10.4lf \n",x,y);
    printf("%10.4lf | %10.4lf \n",x,y);
    printf("Comienzo del ciclo\n");
    for (i=1;i<=nc ;i++ )
    {
        dydx = -2*pow(x,3)+12*pow(x,2)-20*x+8.5;
        y = y + dydx*dx;
        x = x + dx;
        printf("%10.4lf | %10.4lf \n",x,y);
        fprintf(datos,"%10.4lf\t%10.4lf \n",x,y);
    }
    fclose(datos);
    graficador("-2*(x*x*x)+12*(x*x)-20*x+8.5","\'euler.dat\'","linespoints",xi,xf);
    system("pause");
    system("cls");
}
