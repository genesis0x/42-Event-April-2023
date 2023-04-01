#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main(int ac, char **av) 
{
    int i, j, len;
    char buffer[4096];
    
    if (ac == 1)
        return (0);
    
    // Find the length of the longest string
    int max_len = 0;
    for (i = 1; i < ac; i++) 
    {
        len = strlen(av[i]);
        if (len > max_len)
            max_len = len;
    }
    
    // Print the top border
    for (i = 0; i < max_len + 4; i++)
        printf("*");
    printf("\n");
    
    // Print the strings in a frame
    for (i = 1; i < ac; i++) {
        len = strlen(av[i]);
        printf("* ");
        strcpy(buffer, av[i]);
        for (j = len; j < max_len; j++)
            strcat(buffer, " ");
        printf("%s ", buffer);
        printf("*\n");
    }
    
    // Print the bottom border
    for (i = 0; i < max_len + 4; i++)
        printf("*");
    printf("\n");
    return (0);
}
