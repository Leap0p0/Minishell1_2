/*
** EPITECH PROJECT, 2021
** find next prime
** File description:
** pow
*/

int strtoi(const char *s)
{
    int sum = 0;
    char ch;
    char sign = *s;

    if (*s == '-' || *s == '+')
        s++;
    while ((ch = *s++) >= '0' && ch <= '9') {
        sum = sum * 10 - (ch - '0');
    }
    if (sign != '-') {
        sum = -sum;
    }
    return (sum);
}
