#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

/**Funciones de raices**/
float g(float x);
float dg(float x);
float f(float x);
float Bisect (float xl, float xu, float es, int imax,
              float xr, int *apiter, float *apea);
float falsa_posicion (float xl, float xu, float es, int imax,
                      float xr, int *apiter, float *apea);
float punto_fijo(float x0, float es, float imax, int *apiter, float *apea);
void raices(void);
void raices_c(void);
void raices_a(void);
double pfijo(double x0, double es, double *ea, int imax, int *iter);
double newtonrap(double x0, double es, double *ea, int imax, int *iter);
double secante(double x0, double x1, double es, double *ea, int imax, int *iter);

/**Funciones de matrices**/

void matrices();
double ** crear_matriz(int filas, int columnas);
void destruye_matriz(double **m, int filas, int columnas);
void lee_matriz(double **m, int filas, int columnas);
void imprime_matriz ( double **m, int filas, int columnas );
/**Funciones de Vectores**/
void imprime_vector ( double *v, int tam );
void destruye_vector ( double *v );
void lee_vector ( double *v, int tam );
double * crear_vector (int tam);
/** Operaciones de matrices **/
void matriz_mult();
void mat_mult(double **A, double **B,double **C, int n, int l, int m);
/**Gauss**/
void gauss(void);
void eliminacion(double **a, double *x, int filas, double *b);
void imprime_matriz_aumentada ( double **a, double *b, int tam );
void pivot(double **a, double *b, double *s, int n, int k);
void init_gauss_mod(void);
void gauss_mod(double **a, double *b, int n, double *x, double tol);
void sustitucion(double **a, double *x, int filas, double *b);
void eliminate_mod(double **a, double *s, int n, double *b, double tol, int *er);
void init_gauss_seid(void);
void gauss_seidel(double **m,double *r,double *s,int n, int imax, double es);

/**Descomposicion LU**/
void init_lu();
void lu_decomp(double **a,double *b,int n, double *x);
void lu_decompose(double **a,int n, double *O, double *S);
void lu_sustitucion(double **a, double *o, int filas, double *b, double *x);
void lu_pivot(double **a, double *o, double *s, int n, int k);

/**Interpolacion**/

void interpolacion(void);
void dif_divididas(double*,double*,int,double,double*,double*);
double lagrange(double*,double*,int,double);

/**Minimos Cuadrados**/

void minimos(void);
void init_lineal();
void lineal(double*,double*,int,double*,double*,double*,double*);
void init_polinomial(void);
void polinomial(double *x, double *y, int n, double *a1, double *a0,double *syx,double *r2);

/**Integracion**/

double fun_int(double);
void trapecio_multiple(void);
void simpson_13(void);
void simposn_combinado(void);
double sim_int(double ,double ,int, double *);
double sim_13(double, int, double*);
double sim_38(double , double, double, double, double);
double comb_trap(double,double,double);

/**EDO**/

void euler(void);

/**Graficador**/

void graficador (char*,char*,char*,double,double);

#endif // PROTOTIPOS_H_INCLUDED
