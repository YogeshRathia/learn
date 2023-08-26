#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    // Open the current directory
    DIR *dir = opendir(".");
    
    if (dir == NULL) {
        perror("Unable to open directory");
        return 1;
    }
    
    struct dirent *entry;
    
    // Read directory entries
    while ((entry = readdir(dir)) != NULL) {
        struct stat file_stat;
        
        // Get the file status
        if (stat(entry->d_name, &file_stat) == 0) {
            if (S_ISREG(file_stat.st_mode)) {
                printf("File: %s\n", entry->d_name);
            } else if (S_ISDIR(file_stat.st_mode)) {
                printf("Directory: %s\n", entry->d_name);
            }
        }
    }
    
    // Close the directory
    closedir(dir);
    
    return 0;
}
