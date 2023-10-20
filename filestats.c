#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>

void printFileStats(const char *filename, struct stat fileStat) 
{
    // Print the file name
    printf("File name: %s\n", filename);

    // Print the inode number
    printf("inode number: %ld\n", (long)fileStat.st_ino);

    // Print the number of links
    printf("number of links: %ld\n", (long)fileStat.st_nlink);

    // Prin the User ID of owner
    printf("User ID of owner: %d\n", fileStat.st_uid);

    // Print the Group ID of owner
    printf("Group ID of owner: %d\n", fileStat.st_gid);

    // Print the size in bytes
    printf("Size in bytes: %ld bytes\n", (long)fileStat.st_size);

    // Print the last access time
    printf("Last access: %s", ctime(&fileStat.st_atime));

    // Print the last modification time
    printf("Last modification: %s", ctime(&fileStat.st_mtime));

    // Print the last status cgange time
    printf("Last status change: %s", ctime(&fileStat.st_ctime));

    // Print the number of disk blocks allocated
    printf("Number of disk blocks allocated: %ld\n", (long)fileStat.st_blocks);
    
    // Access mode in octal and flags
    printf("Access mode in octal: %o\n", (unsigned int)(fileStat.st_mode & (int)4095));
    printf("Access mode flags: ");
    
    if (S_ISREG(fileStat.st_mode)) 
    {
        // File is a regular file
        putchar('r');
        putchar((fileStat.st_mode & S_IRUSR) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    } 
    else if (S_ISDIR(fileStat.st_mode)) 
    {
        // File is a directory
        putchar('r');
        putchar((fileStat.st_mode & S_IRUSR) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    } 
    else if (S_ISLNK(fileStat.st_mode)) 
    {
        // File is a symbolic link
        putchar('r');
        putchar((fileStat.st_mode & S_IRUSR) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    } 
    else if (S_ISCHR(fileStat.st_mode)) 
    {
        // File is a character device
        putchar('r');
        putchar((fileStat.st_mode & S_IRUSR) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    } 
    else if (S_ISBLK(fileStat.st_mode)) 
    {
        // File is a block device
        putchar('r');
        putchar((fileStat.st_mode & S_IRUSR) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    } 
    else if (S_ISFIFO(fileStat.st_mode)) 
    {
        // File is a FIFO/pipe
        putchar('r');
        putchar((fileStat.st_mode & S_IRUSR) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    }
    else if (S_ISSOCK(fileStat.st_mode))
    {
        // File is a socket
        putchar('r');
        putchar((fileStat.st_mode & S_IRUSR) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
        putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
        putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
        putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
    }
    
    printf("\n\n");
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) 
    {
        // Check for the correct number of command line arguments
        fprintf(stderr, "usage: %s directory_name\n", argv[0]);
        return 1;
    }
    
    const char *dirName = argv[1];
    DIR *dir = opendir(dirName);
    
    if (dir == NULL) 
    {
        // Check if the directory can be opened
        fprintf(stderr, "can't open %s\n", dirName);
        return 1;
    }
    
    struct dirent *dp;
    struct stat fileStat;
    
    while ((dp = readdir(dir)) != NULL) 
    {
        
        char filePath[1024];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirName, dp->d_name);
        
        if (stat(filePath, &fileStat) == -1) 
        {
            // Attempt to get file stats, print error if failed
            perror("stat");
            continue;
        }
        
        printFileStats(dp->d_name, fileStat);
    }
    
    closedir(dir);
    return 0;
}
