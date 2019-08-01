#include <stdio.h>
#include <string.h>

void string_reverse1(char *str){

    str++;
    *str = 'q';
    printf("string = %c", *str);
}

int main(void)
{
        char *str = "prashant";
        string_reverse1(str);

        return 0;
}
