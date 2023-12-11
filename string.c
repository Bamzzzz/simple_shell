#include "shell.h"
/**
 * _strcat - strings to be concentrated
 * @dest: the destination of string
 * @src: the string source
 * Return: always (0) success
 */
char *_strcat(char *dest, char *src)
{
char *s = dest;
while (*dest != '\0')
{
dest++;
}
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
return (s);
}

/**
 * _strncmp - function that compares n amount of characters of two strings
 * @s1: first string
 * @s2: second string
 * @n: amount of characters to compare
 * Return: 1 if the strings don't match otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;

if (s1 == NULL)
return (-1);

for (i = 0; i < n && s2[i]; i++)
{
if (s1[i] != s2[i])
{
return (1);
}
}
return (0);
}
/**
 * _strchr - function that locates character in a string
 * @s: string to be searched
 * @c: character to be located
 * Return: pointer to character
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
{
break;
}
} while (*s++);
return (s);
}
/**
 * _strcpy - function that copies a string
 * @dest: destination
 * @src: source
 * Return: destination
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
