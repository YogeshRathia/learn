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
int rec_dic(char base[],int *files,int *directories,int t_depth,int *depth) {
    if(t_depth>*depth){
        *depth=t_depth;
    }
    struct dirent *entry;
    DIR *dir = opendir(base);

    if (dir == NULL) {
        return 1;
    }
        while ((entry = readdir(dir)) != NULL)
        {
            struct stat st;
            stat(entry->d_name, &st);
            int cmp=(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0);
            if(!cmp)
            {
                char path[1000]="";
                find_next(base,entry->d_name,path);
                struct stat file_stat;
                if (stat(path, &file_stat) == 0)
                {
                    if (S_ISREG(file_stat.st_mode))
                    {
                        *files=*files+1;
                        // printf("File: %s\n", path);
                    }
                    else if (S_ISDIR(file_stat.st_mode))
                    {
                        *directories=*directories+1;
                        // printf("Directory: %s\n", path);
                        // printf("Path: %s \n",path);
                        rec_dic(path,files,directories,t_depth+1,depth);
                    }
                    
                }
            }
        }
        
    closedir(dir);
    return 0;
}
char* new_base(char*fnd){
    printf("Directory is : %s\n",fnd);
        DIR *dir;
        struct dirent *entry;
        dir = opendir(".");

        if (dir == NULL) {
            return 0;
        }
        while ((entry = readdir(dir)) != NULL) {
            if(strcmp(fnd,entry->d_name)){
                return fnd;
            }
        }
        closedir(dir);
    return fnd;
}
int main(){
    // char base[1000]="./New folder (2)";
    char fnd[1000];
    scanf("%s",fnd);
    // printf("val= %s",fnd);
    char base2[1000];
    strcpy(base2,new_base(fnd));
    // base=".";
    int files=0;
    int directories=0;
    int depth=0;
    if(base2){
        printf("\nfind");
        rec_dic(base2,&files,&directories,0,&depth);
    }
    else{
        printf("Directory not found");
    }
    printf("Total normal files : %d \nTotal folders : %d\nMaximum level : %d",files,directories,depth);
    return 0;
}