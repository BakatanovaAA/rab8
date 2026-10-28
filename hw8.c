#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>

double product_series(int n);
int main(void)
{
    int N;
    double p;

    setlocale(LC_ALL, "");

    printf("Вычисление произведения 1.1 * 1.2 * 1.3 * ... * 1.N\n");
    printf("Введите целое N: ");
    scanf("%d", &N);

    if (N < 1)
        printf("Ошибка: N должно быть больше 0\n");
    else
    {
        p = product_series(N);
        printf("Произведение = %.6f\n", p);
    }

    return 0;
}

double product_series(int n)
{
    double p = 1;
    int i;

    for (i = 1; i <= n; i++)
        p = p * (1 + i / 10.0);

    return p;
}