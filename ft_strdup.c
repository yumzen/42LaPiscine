char *ft_strdup(char *src)
{
	char *p;

	p = (char *)malloc(strlen(src) + 1);
	if (p != 0)
		strcpy(p, src);
	return (p);
}
