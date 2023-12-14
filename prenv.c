#include "main.h"

int main(int ac, char **av)
{
    int i = 0;
    (void)ac;
    (void)av;
    (void)env;

    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }

    return (0);
}
