//
//  main.c
//  checksum
//
//  Created by Sebastian Gilarranz on 7/16/18.
//  Copyright © 2018 Sebastian Gilarranz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    char* fname1 = argv[1];
    int checksumSize = atoi(argv[2]);
    char array1[1000] = "";
    char c;
    int characterCnt=0;
    long checksum = 0;
    
    FILE *file1 = fopen(fname1,"r+");
   
    if (file1 == 0){ // file pointer will return 0 if file could not be opened.
        printf("Could not open file\n");
    }
    else { // else if will cointunue to create array with contents.
        for (int a = 0; a < 1000; a ++){
            int i = 0;
            while (EOF != (c=fgetc( file1 ))){
                    array1[ i ] = c;
                    i++;
            }
        }
        fclose (file1);
    }
    
    if (checksumSize == 8){ // if checksumsize is 8 ...
            for (int q = 0 ; q<1000; q++){ // for loop to get character count of input file.
                    if((int)array1[q]>0){
                        characterCnt++;
                    }
            }
            for (int q = 0 ; q<characterCnt; q++){ // print characters from array with input file contents.
                if(q%80 == 0){printf( "\n");
                }
                printf ("%c", array1[q]);
            }
        printf ("\n");
            for (int q = 0 ; q<characterCnt; q++){ // algorithm to get correct checksum number.
                checksum += (int)(array1[q]);
            }
            checksum = checksum & 0xFF; // trim number to desired bits.
            
            printf("%2d bit checksum is %8lx for all %4d chars\n",
                   checksumSize, checksum, characterCnt);
    }
    
    else if (checksumSize== 16){// if checksumsize is 16 ...
        
        long test1;
        long test2;
        long test3;

        for (int q = 0 ; q<1000; q++){// for loop to get character count of input file.
            if((int)array1[q]>0){
                characterCnt++;
            }
        }
        while(characterCnt % 2 != 0){ // inputs X depending if character count is even or not.
            array1[characterCnt] = 'X';
            characterCnt++;
        }
        for (int q = 0 ; q<characterCnt; q++){// print characters from array with input file contents.
            if(q%80 == 0){printf ("\n");
            }
            printf ("%c", array1[q]);
        }
        printf ("\n");
        for (int q = 0 ; q<=characterCnt; q+=2){// algorithm to get correct checksum number.
                test1 = array1[q];
                test2 = array1[q+1];
                test3 = test1 <<8 | test2;
                checksum += test3;
        }
        checksum = checksum & 0xFFFF;// trim number to desired bits.
            
        printf("%2d bit checksum is %8lx for all %4d chars\n",
               checksumSize, checksum, characterCnt);
        
    }
    
    else if (checksumSize==32){// if checksumsize is 32 ...
        long test1;
        long test2;
        long test3;
        long test4;
        long test5;
        long test6;
        long test7;
        for (int q = 0 ; q<1000; q++){// for loop to get character count of input file.
            if((int)array1[q]>0){
                characterCnt++;
            }
        }
        while(characterCnt % 4 != 0){// inputs X depending if character count is divisible by 4 or not.
            array1[characterCnt] = 'X';
            characterCnt++;
            
        }
        for (int q = 0 ; q<characterCnt; q++){// print characters from array with input file contents.
            if(q%80 == 0){printf( "\n");
            }
            printf ("%c", array1[q]);
        }
        printf ("\n");

        for (int q = 0 ; q<characterCnt; q+=4){// algorithm to get correct checksum number.
            test1 = array1[q];
            test2 = array1[q+1];
            test3 = array1[q+2];
            test4= array1[q+3];
            test5 = test1 << 8 | test2;
            test6 = test3 << 8 | test4;
            test7 = test5 << 16 | test6;
            checksum += test7;
        }
        checksum = checksum & 0xFFFFFFFF;
        
        printf("%2d bit checksum is %8lx for all %4d chars\n",
               checksumSize, checksum, characterCnt);
        
    }
    else{ // if checksum size isnt 8 16 or 32
            fprintf( stderr, "Valid checksum sizes are 8, 16, or 32\n" );
    }
    
    return 0;
    
}

    


