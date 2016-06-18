#include "header.h"
#include "prototipos.h"

/**Metodo del trapecio simple **/

void trapecio_multiple()
{
    system ("cls");
	printf("\t\tMETODO DE INTEGRACION DEL TRAPECIO MULTIPLE\n\n");
	float a,b,n=3,h,x0,x3,x1,x2,r;
	printf("La integral que se va a realizar es  de la siguiente funcion: \n f(x)=0.2+25x-200x^2+675x^3-900x^4+400x^5\n\n");
	printf("Dame el valor de a:\n");scanf("%f",&a);
	printf("Dame el valor de b:\n");scanf("%f",&b);
	h=(b-a)/n;

	x0=(.2+25*a-200*pow(a,2)+675*pow(a,3)-900*pow(a,4)+400*pow(a,5));
	x1=(.2667+25*h-200*pow(h,2)+675*pow(h,3)-900*pow(h,4)+400*pow(h,5));
	x2=(.2+25*(2*h)-200*pow((2*h),2)+675*pow((2*h),3)-900*pow((2*h),4)+400*pow((2*h),5));
	x3=(.2+25*b-200*pow(b,2)+675*pow(b,3)-900*pow(b,4)+400*pow(b,5));
	r=h/2*(x0+2*(x1+x2)+x3);
	printf("El resultado de la integral es:\n %f+2*(%f+%f)+%f=%f",x0,x1,x2,x3,r);
	system("pause");
}

/**Simpson 1/3**/
void simpson_13()
{
	system ("cls");
    double xi,xf,xm,fxi,fxf,fxm,r;
    printf("\n\t\t REGLA DE SIMPSON 1/3");
    printf("\n\n\n Digite el punto inicial (xi) = ");
    scanf("%lf",&xi);
    printf("\n\n\n Digite el punto final (xf) = ");
    scanf("%lf",&xf);
    xm=(xi+xf)/2;
    fxi=fun_int(xi);
    fxf=fun_int(xf);
    fxm=fun_int(xm);
    r=((xf-xi)/6)*(fxi+(4*fxm)+fxf);
    printf("\n\n\t El resultado de la integral es: %f",r);
    system("pause");
}

void simpson_combinado()
{
	double h,a,b,*f,sum;
	int n,i;
	printf("SIMPSON COMBINADO\n");
	printf("Ingrese el inicio del intervalo\n");
	scanf("%lf",&a);
	printf("Ingrese el fin del intervalo\n");
	scanf("%lf",&b);
	printf("Ingrese el valor de pasos\n");
	scanf("%d",&n);

	h=(b-a)/n;
	f=crear_vector(n+1);
	sum=a;
	for (i = 0; i <= n; ++i)
	{
		f[i]= fun_int(h*i);
	}

	printf("El resultado es %.5lf\n", sim_int(a,b,n,f));
}

double sim_int(double a,double b, int n, double *f)
{
	double h=(b-a)/n;
	double f0,f1,f01,f11,f2,f3,sum;
	if (n==1)
	{
		f0=f[n-1];
		f1=f[n];
		return comb_trap(h,f0,f1);
	}
	else
	{
		int m=n;
		double odd,s38;
		odd=n/2;
		sum=0;
		if (odd > 0 && n > 1)
		{
			f01=f[n-3];
			f11=f[n-2];
			f2=f[n-1];
			f3=f[n];
			s38=sim_38(h,f01,f11,f2,f3);
			sum=sum+s38;
			m=n-3;
		}
		if (m>1)
		{
			double s13;
			s13=sim_13(h,m,f);
			sum=sum+s13;
		}
		return sum;
	}
}

double sim_13(double h, int n, double *f)
{
	double sum=f[0];
	int i;
	for (i=1; i<=n-2; i=i+2)
	{
		sum = sum + 4*f[i]+2*f[i+1];
	}
	sum = sum + 4*f[n-1]+f[n];
	return (h*sum)/3;
}

double sim_38(double h ,double f01,double f11,double f2,double f3)
{
	return 3*h*(f01+3*(f11+f2)+f3)/8;
}

double comb_trap(double h ,double f0,double f1)
{
	return h*(f0+f1);
}

double fun_int(double x)
{
	return(.2+(25*x)+(200*(pow(x,2)))+(675*(pow(x,3)))-(900*(pow(x,4)))+(400*(pow(x,5))));
}
