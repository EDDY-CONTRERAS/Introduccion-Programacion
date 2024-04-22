#include <stdio.h>
#include <math.h>

float calcularPagoMensual(float prestamo, float tasaInteres, int plazoMeses) {
       float tasaInteresMensual = tasaInteres / 12 / 100; // Convertir la tasa de interés anual a mensual
 float pagoMensual;

    // Calcular el pago mensual utilizando la fórmula de amortización de préstamos
    pagoMensual = (prestamo * tasaInteresMensual) / (1 - pow(1 + tasaInteresMensual, -plazoMeses));

    return pagoMensual;
}

void calcular_tabla_amortizacion(float monto_prestamo, float tasa_interes_anual, int numero_cuotas) {
    float tasa_interes_mensual = tasa_interes_anual / 12 / 100;
     float cuota = calcularPagoMensual(monto_prestamo, tasa_interes_anual, numero_cuotas);
    float saldo_pendiente = monto_prestamo;

    printf("%-10s %-10s %-10s %-13s %-10s\n", "Cuota", "Cuota", "Interés", "Amortización", "Saldo");
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

    printf("Ingrese la cantidad del préstamo: ");
     scanf("%f", &prestamo);

     printf("Ingrese la tasa de interés anual: ");
    scanf("%f", &tasaInteres);

      printf("Ingrese el plazo del préstamo en meses: ");
      scanf("%d", &plazoMeses);

    float pagoMensual = calcularPagoMensual(prestamo, tasaInteres, plazoMeses);

    printf("El pago mensual es: %.2f\n", pagoMensual);

    calcular_tabla_amortizacion(prestamo, tasaInteres, plazoMeses);

    return 0;
}


EXPLICACION:


El código comienza importando dos bibliotecas: stdio.h y math.h. La biblioteca stdio.
h proporciona las funciones necesarias para entrada y salida estándar, mientras que
math.h proporciona funciones matemáticas como pow() para calcular la potencia.

Función calcularPagoMensual()

La función calcularPagoMensual() calcula el pago mensual de un préstamo utilizando
la fórmula de amortización de préstamos. Toma tres parámetros: prestamo (el monto del préstamo)
, tasaInteres (la tasa de interés anual) y plazoMeses (el plazo del préstamo en meses).


Dentro de esta función, se calcula la tasaInteresMensual dividiendo la tasa de interés
anual por 12 y por 100 para convertirla en una tasa mensual. Luego, se utiliza la fórmula
de amortización de préstamos para calcular el pagoMensual. Finalmente, se devuelve el resultado.

Función calcular_tabla_amortizacion()

La función calcular_tabla_amortizacion() muestra una tabla de amortización para el préstamo.
Toma tres parámetros: monto_prestamo (el monto del préstamo), tasa_interes_anual (la tasa de interés anual)
y numero_cuotas (el número de cuotas o plazo del préstamo en meses).


Dentro de esta función, se calcula la tasa_interes_mensual dividiendo la tasa de interés anual por 12 y por 100
para convertirla en una tasa mensual. Luego, se llama a la función calcularPagoMensual()
para obtener el valor de la cuota mensual.


A continuación, se inicializa el saldo_pendiente con el monto_prestamo. Se utiliza un bucle for para calcular
los valores de cada cuota de la tabla de amortización. Dentro del bucle, se calculan el interes y la amortizacion
correspondientes a cada cuota utilizando las fórmulas adecuadas. Luego, se actualiza el saldo_pendiente restando
la amortizacion de este. Finalmente, se muestra la información de cada cuota en la
tabla de amortización utilizando la función printf().


Función main()

La función main() es el punto de entrada del programa. Aquí se solicita al usuario que ingrese el prestamo,
la tasaInteres y el plazoMeses. Luego, se llama a la función calcularPagoMensual() para obtener el valor del
pagoMensual y se muestra en pantalla utilizando la función printf(). A continuación, se llama a la función
calcular_tabla_amortizacion() para mostrar la tabla de amortización. Por último, se retorna 0 para indicar
que el programa se ha ejecutado correctamente.
