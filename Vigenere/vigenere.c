//
//  main.c
//  HW1
//
//  Created by Sebastian Gilarranz on 6/10/18.
//  Copyright © 2018 Sebastian Gilarranz. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main (int argc, char **argv){
    printf ("\ncommand line arguments including program name:\n\n");
    
    char array1[512] = "";
    char array2[512] = "";
    char array3[512] = "";
    char c;
    
    
   for (int i = 0; i < argc; i++){
        printf ("argument %d:%s\n", i , argv[i]);
    }
    printf ("\n");
    
    char* fname1 = argv[1];
    FILE *file1 = fopen(fname1,"r");
    
    if (file1 == 0){
        printf("Could not open file\n");
        
    }
    else {
        printf ("File opened successfully \n");
        int nullcount = 0;
        
        for (int a = 0; a < 512; a ++){
            int i = nullcount;
            while (EOF != (c=fgetc( file1 ))){
                if(isalpha(c) != 0 ){
                    array1[ i ] = c;
                    i++;
                }
            }
            if (array1[a]=='\0'){
                nullcount = a;
            }
            rewind(file1);
        }
      fclose (file1);
    }

    char* fname2 = argv[2];
    FILE *file2 = fopen(fname2,"r");
    
    if (file2 == 0){
        printf("Could not open file\n");
    }
    else {
        printf ("File opened successfully \n");
        int i = 0 ;
        while (EOF != (c=fgetc( file2 ))){
            if(isalpha(c) != 0 ){
                array2[ i ] = c;
                i++;
            }
        }
        fclose (file2);
    }
    for (int q = 0; q<512; q++){
        array1[q] =tolower(array1[q]);
    }
    for (int q = 0; q<512; q++){
        array2[q] =tolower(array2[q]) ;
    }
    for (int i = 0; i<512;i++){
        if ( array2[i] == '\0'){
            array2[i] = 'x';
        }
    }
    printf ("\n\nVigenere Key:\n\n");
    for (int i = 0 ; i < 512 ; i ++){
        printf ("%c",array1[i]);
    }
    
    printf ("\n\nPlaintext:\n\n");
    for (int i = 0 ; i < 512 ; i ++){
        printf ("%c",array2[i]);
    }
    
    
    for (int i = 0; i < 512 ; i ++){
        int  buff;
        buff = (int)array1[i]-97 + (int)array2[i]-97;
        array3[i] = buff %26 + 97;
    }
    
    printf ("\n\nCiphertext:\n");
    for (int i = 0 ; i < 512 ; i++){
        if( i %80 == 0 ){
            printf ("\n");
        }
        printf ("%c", array3[i]);
    }
    
    
    printf ("\n");
    
    return 0 ;
}
