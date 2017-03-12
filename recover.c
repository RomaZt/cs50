#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
 
    // open input file 
    FILE* inFile = fopen(argv[1], "r");
    
    if (inFile == NULL || argc == 0 )
    {
        fprintf(stderr, "Could not open.\n");
        return 1;
    }
    
    unsigned char block[512];
    
    int count = 0; 
    
    bool jpegStarted = false;
    
    // open output file
    FILE* outFile;
    while(fread(block, 512, 1, inFile) != 0){
    
        //Check if the first four bytes are a JPEG
        if ( block[0] == 0xff && block[1] == 0xd8 
            && block[2] == 0xff && ( block[3] == 0xe0 
            || block[3] == 0xe1))
        {
            if (jpegStarted)
            {
                fclose(outFile); 
            }else{
                jpegStarted = true;
            }
            
            char fileName[4];
            if (count < 10)
            {
                sprintf(fileName, "00%i.jpg", count);
            }
            else
            {
                sprintf(fileName, "0%i.jpg", count);
            }
            
            outFile = fopen(fileName, "w");
            if (outFile == NULL)
            {
                fclose(inFile);
                fprintf(stderr, "Could not create %s.\n", fileName);
                return 3;
            }
            
    
            count++;
            
        }
        if (jpegStarted)
        {
            fwrite(&block, 512, 1, outFile);
        }
    }
    
    fclose(outFile);
    
    fclose(inFile);   
    return 0;
}