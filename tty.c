#include <unistd.h>
#include <stdio.h>
int		ft_tlen(char **s)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;

	while (s[i] != NULL)
	{
		if (s[i][0] == '<' || s[i][0] == '>' || s[i][0] == '|')
			j++;
		i++;
	}
	if (j != 0)
		k = j * 2;
	else
		k = 1;
	return (i);
}

int main() {
    // Example usage
    char *strings[] = {"Hello", "World", "ChatGPT", NULL};
	printf("im her");
    int numberOfStrings = ft_tlen(strings);

    printf("Number of strings: %d\n", numberOfStrings);

    return 0;
}
