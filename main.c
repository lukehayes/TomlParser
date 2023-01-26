#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int SIZE = 100;
    const char* toml_file = "data.toml";
    char buf[SIZE];

    FILE* fp = fopen(toml_file, "r");

    fread(buf,4, SIZE, fp);

    for(int i = 0; i<= SIZE; i++) {
        /*printf("%c", *(buf+i))*/

        if( isalpha(*(buf+i)) )
        {
            printf("%c", *(buf+i));
        }else
        {
            switch(*(buf+i))
            {
                case '[':
                    /*printf("LEFT_BRACE\n");*/
                    printf("\n[");
                case ']':
                    /*printf("RIGHT_BRACE\n");*/
                    printf("]\n");
                default:
                    /*printf("\nDEFAULT\n");*/
            }
        }

        /*switch(*(buf + i))*/
        /*{*/
            /*case '[':*/
                /*printf("LEFT BRACE\n");*/
            /*case ']':*/
                /*printf("RIGHT BRACE\n");*/

            /*case isalpha():*/
                /*printf("RIGHT BRACE\n");*/

            /*default:*/
                /*printf("EMPTY");*/
        /*}*/
    }
    printf("\n", *buf);

    fclose(fp);

    return 0;
}
