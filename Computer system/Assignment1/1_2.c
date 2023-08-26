#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
int main()
{
    DIR *directory;
    struct dirent *entry;
    directory=opendir(".");
    if(directory==NULL){
        return 1;
    }
    while((entry=readdir(directory))!=NULL){
        // printf("%s\n",entry->d_name);
        if(entry->d_type == DT_REG){
            printf("File : %s\n",entry->d_name);
        }
        else if(entry->d_type==DT_DIR){
            printf("Directory : %s\n",entry->d_name);
        }
        else{
            printf("None %s : \n",entry->d_name);
        //     printf("None INFO %s : \n",entry->d_ino);
        }
    }
    closedir(directory);
    return 0;
}