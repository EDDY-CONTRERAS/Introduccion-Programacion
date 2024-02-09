#include <stdio.h>
#include <math.h>

/* Suma cuadros.
El programa, al recibir como dato un grupo de entero positivos, obtiene el cuadrado de los mismos y la suma
correspondiente a dichos cuadros. */

void main(void)
{
int NUM;
long CUA, SUC = 0;
printf ("\nIngrese un numero entero -0 para terminar-:\t");
scanf ("%d", &NUM);
while (NUM)
/* Observa que la condicion es verdadera mientras el entero es diferente de cero. */
{
    CUA = pow (NUM, 2);
    printf ("%d al cubo es %d", NUM, CUA);
    SUC = SUC + CUA;
    printf ("\nIngrese un numero entero -0 para determinar-:\t");
    scanf ("%d", &NUM);
}
printf ("\nLa suma de los cuadros es %1d", SUC);
}
