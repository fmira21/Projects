#include "get_next_line.h"

# include <fcntl.h>
# include <stdio.h>
/*
int main() //Standard reading procedure
{
	int fd = open("file", O_RDONLY);
    char *line;
    int i;
    while ((i = get_next_line(fd, &line)))
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
   printf("i = %d %s\n", i, line);
   free(line);
   return (0); 
}
*/

int main() //Empty file
{
	int fd = open("emfile", O_RDONLY);
    char *line;
    int i;
    while ((i = get_next_line(fd, &line)))
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
   printf("i = %d %s\n", i, line);
   free(line);
   return (0); 
}

/*
int main() //STDIN
{
    char *line;
    int i;
    while ((i = get_next_line(0, &line)))
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
   printf("i = %d %s\n", i, line);
   free(line);
   return (0); 
}
*/
/*
int main() //Big file
{
	int fd = open("bigfile", O_RDONLY);
    char *line;
    int i;
    while ((i = get_next_line(fd, &line)))
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
   printf("i = %d %s\n", i, line);
   free(line);
   return (0); 
}
*/
/*
int main() //Very big file
{
	int fd = open("ochenbolshoyfile", O_RDONLY);
    char *line;
    int i;
    while ((i = get_next_line(fd, &line)))
    {
        printf("i = %d %s\n", i, line);
        free(line);
    }
   printf("i = %d %s\n", i, line);
   free(line);
   return (0); 
}
*/
/*
int main() //Descriptor change
{
	int fd = open("file", O_RDONLY);
    char *line;
    int i;
    
    i = get_next_line(fd, &line);
    printf("i = %d %s\n", i, line);
    fd = 0;
    i = get_next_line(fd, &line);
    printf("i = %d %s\n", i, line); 

   printf("i = %d %s\n", i, line);
   free(line);
   return (0); 
}
*/
