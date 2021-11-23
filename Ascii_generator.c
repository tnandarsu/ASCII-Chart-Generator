#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *in, *out;
    char filename[100];
    printf("Enter file name: ");
    scanf("%s", filename);

    in = fopen(filename, "r");
    if(in == NULL)
    {
        printf("Cannot open input file!");
        exit(1);
    }


    int char_count [95];
    int c;

    int i = 0, max = 0;

    for(i = 0; i < 95; i++)
    {
      char_count[i]=0;
    }


    while((c= fgetc(in)))
    {
        if(c == EOF)
            break;
        
        ++char_count[c - 32];   
        
    }

    for(i = 0; i < 95; i++)
    {
        if(max < char_count[i])
        {
            max = char_count[i];
        }
    }

    printf("\n");

    for(i = max; i >= 0; --i)
    {
        for(c = 0; c < 95; c++)
        {
            if(char_count[c] != 0)
            {
                if(char_count[c]- i < 0)
                {
                    printf(" ");
                }

                else if(i == 0)
                {
                    printf("==");
                }

                else
                {
                    printf(" #");
                }
            }
        }
        printf("\n");
    }


    for(i = 0; i < 95; i++)
    {
        if(char_count[i] != 0)
        {
            if(i == 0)
            {
                printf("sp ");
            }

            else
            {
                printf("%c ", i+32);
            }
        }
    
    }printf("\n");
}

//to be continued
