#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argv, char *argc[])
{
    FILE *fin;
    FILE *fout;

    unsigned int i,j,width,height;

    char *pixels;

    if(argv<3) {
        printf("Usage: %s input.bmp output.c\n",argc[0]);
        return;
    }
    if((fin=fopen(argc[1],"r"))==NULL) {
        printf("Error loading input file.\n");
        return;
    }
    fseek(fin,0x1c,SEEK_SET);
    if(fgetc(fin)!=1) {
        printf("Bitmap must have 2 colours.\n");
        fclose(fin);
        return;
    }
    if((fout=fopen(argc[2],"w"))==NULL) {
        printf("Output file not found. Creating it now...");
        fclose(fin);
        return;
    }


    fseek(fin,0x12,SEEK_SET);
    fread(&width,4,1,fin);
    fseek(fin,0x16,SEEK_SET);
    fread(&height,4,1,fin);

    pixels = calloc( width*height, sizeof(char) );

    if( pixels == NULL ) {
        printf("Can't allocate memory space.");
        return;
    }

    fseek(fin,0x436,SEEK_SET);
    for(j=0; j<height; j++) {
        for(i=0; i<width; i++)
            fprintf(fout,"%#.4x, ",fgetc(fin));
        fprintf(fout,"\n");
    }

    fclose(fin);
    fclose(fout);
    return 0;
}

/* EOF */

