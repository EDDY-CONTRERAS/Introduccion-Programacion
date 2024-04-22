#include <stdio.h>
#include <math.h>

float calcularPagoMensual(float prestamo, float tasaInteres, int plazoMeses) {
       float tasaInteresMensual = tasaInteres / 12 / 100; // Convertir la tasa de inter�s anual a mensual
 float pagoMensual;

    // Calcular el pago mensual utilizando la f�rmula de amortizaci�n de pr�stamos
    pagoMensual = (prestamo * tasaInteresMensual) / (1 - pow(1 + tasaInteresMensual, -plazoMeses));

    return pagoMensual;
}

void calcular_tabla_amortizacion(float monto_prestamo, float tasa_interes_anual, int numero_cuotas) {
    float tasa_interes_mensual = tasa_interes_anual / 12 / 100;
     float cuota = calcularPagoMensual(monto_prestamo, tasa_interes_anual, numero_cuotas);
    float saldo_pendiente = monto_prestamo;

    printf("%-10s %-10s %-10s %-13s %-10s\n", "Cuota", "Cuota", "Inter�s", "Amortizaci�n", "Saldo");
    printf("%-10s %-10s %-10s %-13s %-10s\n", "", "", "", "del Capital", "Pendiente");

    for (int cuota_num = 1; cuota_num <= numero_cuotas; cuota_num++) {
        float interes = saldo_pendiente * tasa_interes_mensual;
        float amortizacion = cuota - interes;
        saldo_pendiente -= amortizacion;
        printf("%-10d %-10.2f %-10.2f %-13.2f %-10.2f\n", cuota_num, cuota, interes, amortizacion, saldo_pendiente);
    }
}

int main() {
    float prestamo;
    float tasaInteres;
    int plazoMeses;

    printf("Ingrese la cantidad del pr�stamo: ");
     scanf("%f", &prestamo);

     printf("Ingrese la tasa de inter�s anual: ");
    scanf("%f", &tasaInteres);

      printf("Ingrese el plazo del pr�stamo en meses: ");
      scanf("%d", &plazoMeses);

    float pagoMensual = calcularPagoMensual(prestamo, tasaInteres, plazoMeses);

    printf("El pago mensual es: %.2f\n", pagoMensual);

    calcular_tabla_amortizacion(prestamo, tasaInteres, plazoMeses);

    return 0;
}


EXPLICACION:


El c�digo comienza importando dos bibliotecas: stdio.h y math.h. La biblioteca stdio.
h proporciona las funciones necesarias para entrada y salida est�ndar, mientras que
math.h proporciona funciones matem�ticas como pow() para calcular la potencia.

Funci�n calcularPagoMensual()

La funci�n calcularPagoMensual() calcula el pago mensual de un pr�stamo utilizando
la f�rmula de amortizaci�n de pr�stamos. Toma tres par�metros: prestamo (el monto del pr�stamo)
, tasaInteres (la tasa de inter�s anual) y plazoMeses (el plazo del pr�stamo en meses).


Dentro de esta funci�n, se calcula la tasaInteresMensual dividiendo la tasa de inter�s
anual por 12 y por 100 para convertirla en una tasa mensual. Luego, se utiliza la f�rmula
de amortizaci�n de pr�stamos para calcular el pagoMensual. Finalmente, se devuelve el resultado.

Funci�n calcular_tabla_amortizacion()

La funci�n calcular_tabla_amortizacion() muestra una tabla de amortizaci�n para el pr�stamo.
Toma tres par�metros: monto_prestamo (el monto del pr�stamo), tasa_interes_anual (la tasa de inter�s anual)
y numero_cuotas (el n�mero de cuotas o plazo del pr�stamo en meses).


Dentro de esta funci�n, se calcula la tasa_interes_mensual dividiendo la tasa de inter�s anual por 12 y por 100
para convertirla en una tasa mensual. Luego, se llama a la funci�n calcularPagoMensual()
para obtener el valor de la cuota mensual.


A continuaci�n, se inicializa el saldo_pendiente con el monto_prestamo. Se utiliza un bucle for para calcular
los valores de cada cuota de la tabla de amortizaci�n. Dentro del bucle, se calculan el interes y la amortizacion
correspondientes a cada cuota utilizando las f�rmulas adecuadas. Luego, se actualiza el saldo_pendiente restando
la amortizacion de este. Finalmente, se muestra la informaci�n de cada cuota en la
tabla de amortizaci�n utilizando la funci�n printf().


Funci�n main()

La funci�n main() es el punto de entrada del programa. Aqu� se solicita al usuario que ingrese el prestamo,
la tasaInteres y el plazoMeses. Luego, se llama a la funci�n calcularPagoMensual() para obtener el valor del
pagoMensual y se muestra en pantalla utilizando la funci�n printf(). A continuaci�n, se llama a la funci�n
calcular_tabla_amortizacion() para mostrar la tabla de amortizaci�n. Por �ltimo, se retorna 0 para indicar
que el programa se ha ejecutado correctamente.
