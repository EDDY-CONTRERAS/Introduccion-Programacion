#include <stdio.h>
#include <ctype.h>

void quitarAcentos(char *cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        switch (cadena[i]) {
            case 'á':
            case 'Á':
                cadena[i] = 'a';
                break;
            case 'é':
            case 'É':
                cadena[i] = 'e';
                break;
            case 'í':
            case 'Í':
                cadena[i] = 'i';
                break;
            case 'ó':
            case 'Ó':
                cadena[i] = 'o';
                break;
            case 'ú':
            case 'Ú':
                cadena[i] = 'u';
                break;
            case 'ñ':
            case 'Ñ':
                cadena[i] = 'n';
                break;
            default:
                break;
        }
        i++;
    }
}

int main(void) {
    char cad[50];
    int i = 0, mi = 0, ma = 0;
    printf("\nIngrese la cadena de caracteres (máximo 50 caracteres): ");
    gets(cad);

    quitarAcentos(cad);

    while (cad[i] != '\0') {
        if (islower(cad[i]))
            mi++;
        else if (isupper(cad[i]))
            ma++;
        i++;
    }
    printf("\n\nNúmero de letras minúsculas: %d", mi);
    printf("\nNúmero de letras mayúsculas: %d", ma);

    return 0;
}
