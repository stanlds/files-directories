#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
void strmode(mode_t mode, char * buf) {
  const char chars[] = "rwxrwxrwx";
  for (size_t i = 0; i < 9; i++) {
    buf[i] = (mode & (1 << (8-i))) ? chars[i] : '-';
  }
  buf[9] = '\0';
}
int main(int argc, char* argv[]){
    struct dirent *direntp;
    struct stat file;
    if(argc == 1){
        DIR *dp = opendir(".");
        printf("name\n");
        while ((direntp = readdir(dp)) != NULL) {
            printf("%s\n", direntp->d_name);
        }
        closedir(dp);
    }else if(argc == 2){
        if(strcmp(argv[1], "-l") == 0){
            char buf[10];
            DIR *dp = opendir(".");
            printf("owner\tgroup\tpermissions\tname\n");
            while ((direntp = readdir(dp)) != NULL) {
                stat(direntp->d_name, &file);
                strmode(file.st_mode, buf);
                printf("%d\t%d\t%s\t%s\n", file.st_uid,file.st_gid, buf, direntp->d_name);
            }
            closedir(dp);
        }else{
            DIR *dp = opendir(argv[1]);
            printf("name\n");
            while ((direntp = readdir(dp)) != NULL) {
                printf("%s\n", direntp->d_name);
            }
            closedir(dp);
        }
    }else{
        DIR *dp = opendir(argv[2]);
        char buf[10];
        printf("owner\tgroup\tpermissions\tname\n");
        while ((direntp = readdir(dp)) != NULL) {
            stat(direntp->d_name, &file);
            strmode(file.st_mode, buf);               
            printf("%d\t%d\t%s\t%s\n", file.st_uid,file.st_gid, buf, direntp->d_name);
        }
        closedir(dp);
    }
    return 0;
}
