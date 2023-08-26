#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
// char* find_next(char base[],char add[]){
//     strcat(base,add);
//     return *base;
// }
int rec_dic(char base[]) {
    printf("cwd : %s\n ",base);
    struct dirent *entry;
    DIR *dir = opendir(base);

    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

        while ((entry = readdir(dir)) != NULL) {
            // Get the entry's type
            struct stat st;
            stat(entry->d_name, &st);
            if (S_ISREG(st.st_mode)) {
                printf("File: %s\n", entry->d_name);
            } else if (S_ISDIR(st.st_mode)) {
                printf("Directory: %s\n", entry->d_name);
                // char new_base=find_next(base,entry->d_name);
                // printf("next base is : %s \n",new_base);
            }
    }
    closedir(dir);
    return 0;

}
int main(){
    char base[]="./New folder (4)";
    rec_dic(base);
    return 0;
}