#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    if(argc == 3){
        char line[201];
       
        int lineNumber = 0;
        FILE *iF = fopen(argv[2],"r");
        while(fgets(line,201,iF)!=NULL){
            lineNumber++;
        }
        printf("%d, ", lineNumber);
        int lin = (lineNumber - atoi(argv[1]));
        printf("%d\n", lin);
        fflush(iF);
        fseek(iF,0,SEEK_SET);
        int lineNumber2=0;
        while(fgets(line,201,iF)!=NULL){
            if(lineNumber2 == lin){
                while(lin<lineNumber){
                printf("%s",line);
                fgets(line,201,iF);
                lin++;
                }
                exit(1);
            }
         lineNumber2++;
        }
        fclose(iF);
    }else{
        printf("Inserte número de lineas \n");
	printf("Inserte nombre o ruta del archivo \n");
    }
    return 0;
}
