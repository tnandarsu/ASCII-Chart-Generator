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


    int count [256] = {0};
    int c;

    while((c= fgetc(in)))
    {
        if(c == EOF)
            break;
        
        count[c] += 1;
        
    }


    int k;
    for(k=0; k<256; k++) 
    {
        if(count[k] > 0) 
        {
            printf("char %c: %d times\n", k, count[k]);
        }
    }

    // to be continued
    /*
    out = fopen("output_text.txt", "w");
    if(out == NULL)
    {
        printf("Cannot open destination file");
        exit(1);
    }
    */

}