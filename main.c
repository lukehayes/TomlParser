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

        if( isalpha(*(buf+i)) )
        {
            printf("%c", *(buf+i));
        }else
        {
            switch(*(buf+i))
            {
                case '[':
                    printf("\n[");
                case ']':
                    printf("]\n");
                default:
            }
        }
    }
    printf("\n", *buf);

    fclose(fp);

    return 0;
}
