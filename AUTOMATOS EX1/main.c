#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int estado = 0;
    int i;

    printf("Digite um numero: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];

        switch (estado) {
            case 0:
                if (c == '+' || c == '-') estado = 1;
                else if (isdigit(c)) estado = 3;
                else estado = -1;
                break;

            case 1:
                if (isdigit(c)) estado = 3;
                else estado = -1;
                break;

            case 3:
                if (isdigit(c)) estado = 3;
                else if (c == '.') estado = 4;
                else if (c == 'E') estado = 5;
                else estado = -1;
                break;

            case 4:
                if (isdigit(c)) estado = 4;
                else if (c == 'E') estado = 5;
                else estado = -1;
                break;

            case 5:
                if (c == '+' || c == '-') estado = 6;
                else if (isdigit(c)) estado = 7;
                else estado = -1;
                break;

            case 6:
                if (isdigit(c)) estado = 7;
                else estado = -1;
                break;

            case 7:
                if (isdigit(c)) estado = 7;
                else estado = -1;
                break;
        }

        if (estado == -1) break;
    }

    if (estado == 3 || estado == 4 || estado == 7)
        printf("Valido\n");
    else
        printf("Invalido\n");

    return 0;
}
