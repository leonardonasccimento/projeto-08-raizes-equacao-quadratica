#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include<math.h>
#include<complex.h>

void calcularFormaReduzida() {
    float a1, a2, b1, b2, c1, c2;
    a2 = b2 = c2 = 1.0;

voltar:
    printf("\nDigite o valor do coeficiente (a) : ");
    scanf("%f/%f", &a1, &a2);
    printf("Digite o valor do coeficiente (b) : ");
    scanf("%f/%f", &b1, &b2);
    printf("Digite o valor do coeficiente (c) : ");
    scanf("%f/%f", &c1, &c2);

    int op;
    if (a2 == 0 || b2 == 0 || c2 == 0) {
        printf("O valor do denominador nao pode ser (0).");
        printf("\nDigitar (9) para um novo calculo ou (5) para sair : ");
        scanf("%d", &op);

        if (op == 5) {
            exit(0);
        }

        a2 = b2 = c2 = 1.0;

        goto voltar;
    }

    if (a1 == 0) {
        printf("O valor do coeficiente (a) nao pode ser (0).");
        printf("\nDigitar (9) para um novo calculo ou (5) para sair : ");
        scanf("%d", &op);

        if (op == 5) {
            exit(0);
        }

        goto voltar;
    }

    float B, d1, d2, delta;

    d1 = pow(b1, 2) * a2 * c2 - 4 * pow(b2, 2) * a1 * c1;
    d2 = pow(b2, 2) * a2 * c2;
    delta = d1 / d2;
    B = (b1 * a2) / (2 * a1 * b2);

    if (delta < 0) {
        printf("\nDelta = %f", delta);

        // conversao
        B = -B;
        delta = -delta;
        float G = (a2 * sqrt(delta)) / (2 * a1);

        complex parteReal = creal(B);

        complex parteImaginaria = cimag(G * I);

        // impressao
        printf("\nx1 = %f + %f*I", (float)parteReal, (float)parteImaginaria);
        printf("\nx1 = %f - %f*I", (float)parteReal, (float)parteImaginaria);
    }
    else {
        printf("\nDelta = %f", delta);

        B = -B;
        float G = (a2 * sqrt(delta)) / (2 * a1);

        float x1, x2;
        x1 = B + G;
        x2 = B - G;

        // impressao
        printf("\nx1 = %f", x1);
        printf("\nx1 = %f", x2);
    }
}

void calcularFormaFracionaria() {
    int a1, a2, b1, b2, c1, c2;
    a2 = b2 = c2 = 1;

voltar:
    printf("\nDigite o valor do coeficiente (a) : ");
    scanf("%d/%d", &a1, &a2);
    printf("Digite o valor do coeficiente (b) : ");
    scanf("%d/%d", &b1, &b2);
    printf("Digite o valor do coeficiente (c) : ");
    scanf("%d/%d", &c1, &c2);

    int op;
    if (a2 == 0 || b2 == 0 || c2 == 0) {
        printf("O valor do denominador nao pode ser (0).");
        printf("\nDigitar (9) para um novo calculo ou (5) para sair : ");
        scanf("%d", &op);

        if (op == 5) {
            exit(0);
        }

        a2 = b2 = c2 = 1;

        goto voltar;
    }

    if (a1 == 0) {
        printf("O valor do coeficiente (a) nao pode ser (0).");
        printf("\nDigitar (9) para um novo calculo ou (5) para sair : ");
        scanf("%d", &op);

        if (op == 5) {
            exit(0);
        }

        goto voltar;
    }

    int D1, D2, F1, F2, B1, B2, B3, B4;
    float deltaFormaReduzida;
    int f1, f2, d1, d2;
    f2 = d2 = 1;

    d1 = pow(b1, 2) * a2 * c2 - 4 * pow(b2, 2) * a1 * c1;
    d2 = pow(b2, 2) * a2 * c2;
    deltaFormaReduzida = d1 / d2;
    f1 = a2;
    f2 = 2 * a1;

    D1 = d1;
    D2 = d2;
    F1 = f1;
    F2 = f2;
    B1 = b1;
    B2 = b2;

    if (deltaFormaReduzida < 0) {
        //simplificacao
        if (B1 != 0) {
            if ((abs(B1) <= abs(B2)) && (abs(B2) % abs(B1) == 0)) {
                B2 /= B1;
                B1 /= B1;
            }
            else
                if ((abs(B2) < abs(B1)) && (abs(B1) % abs(B2) == 0)) {
                    B1 /= B2;
                    B2 /= B2;
                }
        }

        if ((abs(F1) <= abs(F2)) && F1 != 0 && (abs(F2) % abs(F1) == 0)) {
            F2 /= F1;
            F1 /= F1;
        }
        else
            if ((abs(F2) < abs(F1)) && (abs(F1) % abs(F2) == 0)) {
                F1 /= F2;
                F2 /= F2;
            }

        if (D1 != 0) {
            if ((abs(D1) <= abs(D2)) && (abs(D2) % abs(D1) == 0)) {
                D2 /= D1;
                D1 /= D1;
            }
            else
                if ((abs(D2) < abs(D1)) && (abs(D1) % abs(D2) == 0)) {
                    D1 /= D2;
                    D2 /= D2;
                }
        }

        // fatoracao
        int g = 1;
        double H = __DBL_MAX__;

        if (B1 != 0) {
            if (abs(B2) % abs(B1) != 0) {
                while ((abs(B1) % 2 == 0) && (abs(B2) % 2 == 0)) {
                    B1 /= 2;
                    B2 /= 2;
                }
                g = 3;
                while (g < (int)H) {
                    while ((abs(B1) % g == 0) && (abs(B2) % g == 0)) {
                        B1 /= g;
                        B2 /= g;
                    }
                    g += 2;
                }
            }
        }

        if (D1 != 0) {
            if (abs(D2) % abs(D1) != 0) {
                while (abs(D1) % 2 == 0 && abs(D2) % 2 == 0) {
                    D1 /= 2;
                    D2 /= 2;
                }
                g = 3;
                while (g < (int)H) {
                    while ((abs(D1) % g == 0) && (abs(D2) % g == 0)) {
                        D1 /= g;
                        D2 /= g;
                    }
                    g += 2;
                }
            }
        }

        if ((abs(F1) < abs(F2)) && (abs(F2) % abs(F1) != 0)) {
            while ((abs(F1) % 2 == 0) && (abs(F2) % 2 == 0)) {
                F1 /= 2;
                F2 /= 2;
            }
            g = 3;
            while (g < (int)H) {
                while ((abs(F1) % g == 0) && (abs(F2) % g == 0)) {
                    F1 /= g;
                    F2 /= g;
                }
                g += 2;
            }
        }

        // verificacao de sinais
        if ((b1 < 0 && b2>0) || (b1 > 0 && b2 < 0)) {
            B1 = -abs(B1);
            B2 = abs(B2);
        }
        if (b1 < 0 && b2 < 0) {
            B1 = abs(B1);
            B2 = abs(B2);
        }

        if ((f1 < 0 && f2>0) || (f1 > 0 && f2 < 0)) {
            F1 = -abs(F1);
            F2 = abs(F2);
        }
        if (f1 < 0 && f2 < 0) {
            F1 = abs(F1);
            F2 = abs(F2);
        }

        if ((d1 < 0 && d2>0) || (d1 > 0 && d2 < 0)) {
            D1 = -abs(D1);
            D2 = abs(D2);
        }
        if (d1 < 0 && d2 < 0) {
            D1 = abs(D1);
            D2 = abs(D2);
        }

        printf("\nDelta = %d/%d", D1, D2);

        // conversao
        B1 = -B1;
        if (D1 < 0) {
            D1 = -D1;
        }

        complex parteReal1 = creal(B1);
        complex parteReal2 = creal(B2);
        complex parteImaginaria1 = cimag(D1 * I);
        complex parteImaginaria2 = cimag(D2 * I);

        // impressao
        printf("\nx1 = [ (%d/%d) + (sqrt(%d/%d))*I ] * (%d/%d)", (int)parteReal1, (int)parteReal2, (int)parteImaginaria1, (int)parteImaginaria2, F1, F2);
        printf("\nx1 = [ (%d/%d) - (sqrt(%d/%d))*I ] * (%d/%d)", (int)parteReal1, (int)parteReal2, (int)parteImaginaria1, (int)parteImaginaria2, F1, F2);
    }
    else {
        // simplificacao
        if (B1 != 0) {

            if ((abs(B1) <= abs(B2)) && (abs(B2) % abs(B1) == 0)) {
                B2 /= B1;
                B1 /= B1;
            }
            else
                if ((abs(B2) < abs(B1)) && (abs(B1) % abs(B2) == 0)) {
                    B1 /= B2;
                    B2 /= B2;
                }
        }

        if (D1 != 0) {

            if ((abs(D1) <= abs(D2)) && (abs(D2) % abs(D1) == 0)) {
                D2 /= D1;
                D1 /= D1;
            }
            else
                if ((abs(D2) < abs(D1)) && (abs(D1) % abs(D2) == 0)) {
                    D1 /= D2;
                    D2 /= D2;
                }
        }

        if ((abs(F1) <= abs(F2)) && F1 != 0 && (abs(F2) % abs(F1) == 0)) {
            F2 /= F1;
            F1 /= F1;
        }
        else
            if ((abs(F2) < abs(F1)) && (abs(F1) % abs(F2) == 0)) {
                F1 /= F2;
                F2 /= F2;
            }

        // fatoracao
        int g = 1;
        double H = __DBL_MAX__;

        if (B1 != 0) {
            if (abs(B2) % abs(B1) != 0) {
                while ((abs(B1) % 2 == 0) && (abs(B2) % 2 == 0)) {
                    B1 /= 2;
                    B2 /= 2;
                }
                g = 3;
                while (g < (int)H) {
                    while ((abs(B1) % g == 0) && (abs(B2) % g == 0)) {
                        B1 /= g;
                        B2 /= g;
                    }
                    g += 2;
                }
            }
        }

        if (D1 != 0) {
            if (abs(D2) % abs(D1) != 0) {
                while (abs(D1) % 2 == 0 && abs(D2) % 2 == 0) {
                    D1 /= 2;
                    D2 /= 2;
                }
                g = 3;
                while (g < (int)H) {
                    while ((abs(D1) % g == 0) && (abs(D2) % g == 0)) {
                        D1 /= g;
                        D2 /= g;
                    }
                    g += 2;
                }
            }
        }

        if ((abs(F1) < abs(F2)) && (abs(F2) % abs(F1) != 0)) {
            while ((abs(F1) % 2 == 0) && (abs(F2) % 2 == 0)) {
                F1 /= 2;
                F2 /= 2;
            }
            g = 3;
            while (g < (int)H) {
                while ((abs(F1) % g == 0) && (abs(F2) % g == 0)) {
                    F1 /= g;
                    F2 /= g;
                }
                g += 2;
            }
        }

        // verificacao de sinais
        if ((b1 < 0 && b2>0) || (b1 > 0 && b2 < 0)) {
            B1 = -abs(B1);
            B2 = abs(B2);
        }
        if (b1 < 0 && b2 < 0) {
            B1 = abs(B1);
            B2 = abs(B2);
        }

        if ((f1 < 0 && f2>0) || (f1 > 0 && f2 < 0)) {
            F1 = -abs(F1);
            F2 = abs(F2);
        }
        if (f1 < 0 && f2 < 0) {
            F1 = abs(F1);
            F2 = abs(F2);
        }

        if ((d1 < 0 && d2>0) || (d1 > 0 && d2 < 0)) {
            D1 = -abs(D1);
            D2 = abs(D2);
        }
        if (d1 < 0 && d2 < 0) {
            D1 = abs(D1);
            D2 = abs(D2);
        }

        printf("\nDelta = %d/%d", D1, D2);

        // conversao
        B1 = -B1;
        if (D1 < 0) {
            D1 = -D1;
        }

        // impressao
        printf("\nx1 = [ (%d/%d) + (sqrt(%d/%d)) ] * (%d/%d)", B1, B2, D1, D2, F1, F2);
        printf("\nx2 = [ (%d/%d) - (sqrt(%d/%d)) ] * (%d/%d)", B1, B2, D1, D2, F1, F2);
    }
}

void imprimir() {
    int op;
    printf("Calcular raizes de uma equacao quadratica...");
    do {
        printf("\nDigitar: \n   (7) para calcular forma reduzida \nou (8) para calcular forma Fracionaria \nou (5) para sair : ");
        scanf("%d", &op);

        switch (op) {
        case(7): calcularFormaReduzida();break;
        case(8): calcularFormaFracionaria();break;
        default: continue;
        }

        printf("\nDigitar (9) para um novo calculo ou (5) para sair : ");
        scanf("%d", &op);
    } while (op != 5);
}

int main() {
    setlocale(LC_CTYPE, "ptb");
    imprimir();
    return 0;
}

