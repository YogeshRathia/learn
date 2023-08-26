#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
void find_next(char *base,char*add,char*new){
    strcat(new,base);
    strcat(new,"/");
    strcat(new,add);
}
void listFilesRecursively(char *basePath) {
    printf("Path is: %s \n",basePath);
    DIR *dir = opendir(basePath);
    if (!dir) {
        perror("Unable to open directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { 
            continue;
        }
            char path[1000]="";
            find_next(basePath,entry->d_name,path);
            struct stat file_stat;
            if (stat(path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    printf("File: %s\n", path);
                } else if (S_ISDIR(file_stat.st_mode)) {
                    printf("Directory: %s\n", path);
                    printf("Path: %s \n",path);
                    listFilesRecursively(path);
                }
            }
    }

    closedir(dir);
}

int main() {
    listFilesRecursively("./New folder (4)");
    return 0;
}
