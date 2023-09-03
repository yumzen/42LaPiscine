char *ft_strjoin(int size, char **strs, char *sep)
{
	 
}

#include <stdio.h>

int main(int argc, char **strs)
{
    char *sep = "___";
    if (argc > 1)
    {
        char *result = ft_strjoin(argc -1, strs + 1, sep);
        printf("result: %s\n", result);
    }
    return (0);
}

