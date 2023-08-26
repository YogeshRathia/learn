#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

void listFilesRecursively(const char *basePath);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    listFilesRecursively(argv[1]);

    return 0;
}

void listFilesRecursively(const char *basePath) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileInfo;

    if (!(dir = opendir(basePath))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);

        if (stat(path, &fileInfo) < 0) {
            perror("stat");
            continue;
        }

        printf("%s %ld %s %s %lld %s %s\n",
               (S_ISDIR(fileInfo.st_mode)) ? "d" : "-",
               fileInfo.st_nlink,
               getpwuid(fileInfo.st_uid)->pw_name,
               getgrgid(fileInfo.st_gid)->gr_name,
               fileInfo.st_size,
               strtok(ctime(&fileInfo.st_mtime), "\n"),
               entry->d_name);

        if (S_ISDIR(fileInfo.st_mode)) {
            listFilesRecursively(path);
        }
    }

    closedir(dir);
}
