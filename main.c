#include <string.h>
#include <stdio.h>
void foo(char *bar)
{
    char c[12];
    printf("%p\n", c);
    strcpy(c, bar); // no bounds checking
}

int main(int argc, char **argv)
{
    printf("%d\n", argc);
    if (argc == 1)
    {
        foo("hey");
    }
    else
    {
        foo(argv[1]);
    }
    return 0;
}