/*
** EPITECH PROJECT, 2019
** CPool_Day03_2019
** File description:
** No file there, just an epitech header example
*/

int my_strlen(char const *str);

char to_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) != my_strlen(s2))
        return 1;
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (to_lowercase(s1[i]) != to_lowercase(s2[i]))
            return (to_lowercase(s1[i]) - to_lowercase(s2[i]));
    }

    if (s1[i] != '\0' || s2[i] != '\0')
        return (to_lowercase(s1[i]) > to_lowercase(s2[i]));
    return (to_lowercase(s1[i]) - to_lowercase(s2[i]));
}