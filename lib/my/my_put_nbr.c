/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

#include <unistd.h>

void my_putchar(char c);

int maxmin_norm(int nb)
{
    if ( nb < 0 ) {
        my_putchar('-');
        if (nb == -2147483648) {
            my_putchar('2');
            nb = 147483648;
        }
        else
            nb = -nb;
    }
    return (nb);
}

int my_put_nbr(int nb)
{
    int nb_digits_pow10 = 1;
    nb = maxmin_norm(nb);
    int new_nb = nb;
    while (new_nb > 9) {
        new_nb /= 10;
        nb_digits_pow10 *= 10;
    }

    while (nb_digits_pow10 != 0) {
        new_nb = nb / nb_digits_pow10;
        my_putchar(new_nb + 48);
        nb -= new_nb * nb_digits_pow10;
        nb_digits_pow10 /= 10;
    }
    return (0);
}