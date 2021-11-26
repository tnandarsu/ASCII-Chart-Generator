#include<stdio.h>
#include<stdlib.h>
#define file_size 100
#define ctotal 95

int main()
{   

    FILE *in;
    char input_file[file_size];
    printf("Enter input text file name: ");
    scanf("%s", input_file);
    
    //check the input file
    in = fopen(input_file, "r");
    if(in == NULL)
    {
        printf("Cannot open input file!");
        exit(1);
    }

    int char_count [ctotal];
    int c;

    int i = 0, max = 0;

    for(i = 0; i < ctotal; i++)
    {
      char_count[i]=0;
    }

    /*Frequency of each character*/
    while((c= fgetc(in)))
    {
        if(c == EOF)
            break;
        
        ++char_count[c - 32];   
        
    }

    for(i = 0; i < ctotal; i++)
    {
        if(max < char_count[i])
        {
            max = char_count[i];
        }
    }

    printf("\n");

    /*Printing the Vertical Histogram*/
    for(i = max; i >= 0; --i)
    {
        for(c = 0; c < ctotal; c++)
        {
            if(char_count[c] != 0)
            {
                if(char_count[c]- i < 0)
                {
                    printf("  ");       
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

    /*Printing the Characters below the Histogram for reference*/
    for(i = 0; i < ctotal; i++)
    {
        if(char_count[i] != 0)
        {
            if(i == 0)
            {
                printf("sp "); // sp for space        
            }

            else
            {
                printf("%c ", i+32); 
            }
        }
    
    }printf("\n");

    fclose(in);
    return 0;

}
