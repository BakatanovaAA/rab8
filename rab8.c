#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

/* ---------- Объявления функций ---------- */
char get_symbol(int pos, int count, char first, char second);
long long sum_range(int m, int n);
int count_terms(int m, int n);
unsigned long long power_of_two(int k);
double f(double x);
int count_points(double a, double b, double h);

/* ---------- Главная функция ---------- */
int main(void)
{
    int count, i;
    char sym, sym2;
    int m, n;
    long long sum;
    int terms;
    int max_pow;
    unsigned long long p;
    double a = 0.1, b = 2.1;   /* интервал варианта 1 */
    double h, x, y;
    int points;

    setlocale(LC_ALL, "");

    /*  Задание 0. Печать символов циклом for  */
    printf("=== Задание 0 ===\n");
    printf("Введите количество символов: ");
    scanf("%d", &count);
    printf("Введите символ: ");
    scanf(" %c", &sym);

    for (i = 1; i <= count; i++)
        putchar(sym);
    printf("\n");

    putchar('+');
    for (i = 1; i <= count; i++)
        putchar(sym);
    putchar('+');
    printf("\n");

    printf("Введите второй символ: ");
    scanf(" %c", &sym2);
    for (i = 1; i <= count; i++)
        putchar(get_symbol(i, count, sym, sym2));
    printf("\n");

    for (i = 1; i <= count; i++)
    {
        putchar(sym);
        putchar('!');
    }
    printf("\n\n");

    /*  Задание 1. Сумма целых чисел от m до n  */
    printf("=== Задание 1 ===\n");
    printf("Введите m и n: ");
    scanf("%d %d", &m, &n);

    sum = sum_range(m, n);
    terms = count_terms(m, n);

    printf("Выполнено итераций: %d\n", terms);
    printf("Результат: %lld\n\n", sum);

    /* Задание 1А. Степени двойки в столбик */
    printf("=== Задание 1А ===\n");
    printf("Введите максимальную степень n (0..63): ");
    scanf("%d", &max_pow);

    if (max_pow < 0 || max_pow > 63)
        printf("Ошибка: n должно быть от 0 до 63\n\n");
    else
    {
        for (i = 0; i <= max_pow; i++)
        {
            p = power_of_two(i);
            printf("2^%-2d = %20llu\n", i, p);
        }
        printf("\n");
    }

    /* Задание 2. Табулирование функции (вариант 1) */
    printf("=== Задание 2 ===\n");
    printf("Функция: y = x^2 + sin(5x), x на отрезке [%.1f; %.1f]\n", a, b);
    printf("Введите шаг: ");
    scanf("%lf", &h);

    if (h <= 0)
        printf("Ошибка: шаг должен быть больше 0\n");
    else
    {
        points = count_points(a, b, h);

        printf("+----------+------------+\n");
        printf("|    x     |    f(x)    |\n");
        printf("+----------+------------+\n");
        for (i = 0; i < points; i++)
        {
            x = a + i * h;
            y = f(x);
            printf("| %8.3f | %10.4f |\n", x, y);
        }
        printf("+----------+------------+\n");
    }

    return 0;
}

char get_symbol(int pos, int count, char first, char second)
{
    char result;
    result = (pos <= count / 2) ? first : second;
    return result;
}


long long sum_range(int m, int n)
{
    long long s = 0;
    int i, tmp;

    if (m < n) 
    {
        tmp = m;
        m = n;
        n = tmp;
    }

    for (i = m; i >= n; i--)
        s += i;

    return s;
}

int count_terms(int m, int n)
{
    int k;
    k = (m > n) ? (m - n + 1) : (n - m + 1);
    return k;
}

unsigned long long power_of_two(int k)
{
    unsigned long long p = 1;
    int i;

    for (i = 1; i <= k; i++)
        p *= 2;

    return p;
}

/* Функция варианта 1: y = x^2 + sin(5x) */
double f(double x)
{
    double y;
    y = x * x + sin(5 * x);
    return y;
}

int count_points(double a, double b, double h)
{
    int k;
    k = (int)((b - a) / h + 1e-9) + 1;
    return k;
}