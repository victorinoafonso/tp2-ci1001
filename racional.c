/*
 * Tipos Abstratos de Dados - TADs
 * Arquivo de implementação para TAD racional.
 * Feito em 20/09/2024 para a disciplina CI1001 - Programação 1.
 *
 * Este arquivo deve conter as implementações das funções cujos protótipos
 * foram definidos em racional.h. Neste arquivo também podem ser definidas
 * funções auxiliares para facilitar a implementação daquelas funções.
 */

#include <stdio.h>
#include <stdlib.h>
#include "racional.h"

/*Retorna o numerador de uma rcaional r*/
long numerador_r(struct racional r)
{

    return r.num;
}

/*Retorna o denominador de racional r*/
long denominador_r(struct racional r)
{

    return r.den;
}

/*Cria um número racional com o numerador e denominador indicados*/
struct racional cria_r(long numerador, long denominador)
{

    struct racional r;

    r.num = numerador;
    r.den = denominador;

    return r;
}

/*Retorna 1 se o racional r for válido ou 0 se for inválido*/
int valido_r(struct racional r)
{

    if (r.den == 0)
        return 0;

    return 1;
}

/* retorna um número aleatório entre min e max, inclusive. */
long aleat(long min, long max)
{

    return rand() % (max - min) + min;
}

/* Máximo Divisor Comum entre a e b      */
/* calcula o MDC pelo método de Euclides */
long mdc(long a, long b)
{
    a = labs(a);
    b = labs(b);
    long resto;

    while (b != 0)
    {

        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}

/* Mínimo Múltiplo Comum entre a e b */
/* mmc = (a * b) / mdc (a, b)        */
long mmc(long a, long b)
{

    return (a * b) / mdc(a, b);
}

/* Recebe um número racional e o simplifica.
 * Por exemplo, ao receber 10/8 deve retornar 5/4.
 * Se ambos numerador e denominador forem negativos, deve retornar um positivo.
 * Se o denominador for negativo, o sinal deve migrar para o numerador.
 * Se r for inválido, devolve-o sem simplificar. */
struct racional simplifica_r(struct racional r)
{

    if (!valido_r(r))
        return r;

    if (r.den < 0)
    {

        r.num = r.num * (-1);
        r.den = r.den * (-1);
    }

    long divisor = mdc(r.num, r.den);

    r.num = numerador_r(r) / divisor;
    r.den = denominador_r(r) / divisor;

    return r;
}

/*Retorna um número racional aleatório na forma simplificada*/
struct racional sorteia_r(long min, long max)
{

    struct racional r;

    r.num = aleat(min, max);
    r.den = aleat(min, max);

    return simplifica_r(r);
}

/*Imprime um racional r*/
void imprime_r(struct racional r)
{

    if (!valido_r(r))
    {
        printf("NaN");
        return;
    }

    r = simplifica_r(r);

    if (r.num == 0)
    {
        printf("0");
    }
    else if (r.num == r.den)
    {
        printf("1");
    }
    else if (r.den == 1)
    {
        printf("%ld", r.num);
    }
    else
    {
        printf("%ld/%ld", r.num, r.den);
    }
}

/*Compara dois racionais*/
int compara_r(struct racional r1, struct racional r2)
{

    if ((!valido_r(r1)) || (!valido_r(r2)))
        return -2;

    r1 = simplifica_r(r1);
    r2 = simplifica_r(r2);

    long racional1 = r1.num * r2.den;
    long racional2 = r2.num * r1.den;

    if (racional1 < racional2)
        return -1;

    if (racional1 > racional2)
        return 1;

    return 0;
}

/*Soma dois racionais r1 e r2 e retorna em r3*/
int soma_r(struct racional r1, struct racional r2, struct racional *r3)
{

    if ((r3 == NULL) || (!valido_r(r1)) || (!valido_r(r2)))
        return 0;

    if (r1.den == r2.den)
    {

        r3->num = r1.num + r2.num;
        r3->den = r1.den;
    }
    else
    {

        long den_comun = mmc(r1.den, r2.den);

        r3->num = ((den_comun / r1.den) * r1.num) + ((den_comun / r2.den) * r2.num);
        r3->den = den_comun;
    }

    *r3 = simplifica_r(*r3);

    return 1;
}

/*Subtari dois racionais r1 e r2 e retorma em r3*/
int subtrai_r(struct racional r1, struct racional r2, struct racional *r3)
{

    if ((r3 == NULL) || (!valido_r(r1)) || (!valido_r(r2)))
        return 0;

    if (r1.den == r2.den)
    {

        r3->num = r1.num - r2.num;
        r3->den = r1.den;
    }
    else
    {

        long den_comun = mmc(r1.den, r2.den);

        r3->num = ((den_comun / r1.den) * r1.num) - ((den_comun / r2.den) * r2.num);
        r3->den = den_comun;
    }

    *r3 = simplifica_r(*r3);

    return 1;
}

/*Multiplica dois racionais r1 e r2 e retorna em r3*/
int multiplica_r(struct racional r1, struct racional r2, struct racional *r3)
{

    if ((r3 == NULL) || (!valido_r(r1)) || (!valido_r(r2)))
        return 0;

    r3->num = r1.num * r2.num;
    r3->den = r1.den * r2.den;

    *r3 = simplifica_r(*r3);

    return 1;
}

/*Divede dois racionais r1 e r2 e retorna em r3*/
int divide_r(struct racional r1, struct racional r2, struct racional *r3)
{

    if ((r3 == NULL) || (!valido_r(r1)) || (!valido_r(r2)) || (r2.num == 0))
        return 0;

    r3->num = r1.num * r2.den;
    r3->den = r1.den * r2.num;

    *r3 = simplifica_r(*r3);

    return 1;
}
