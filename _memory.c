#include "shell.h"
/**
 * _realloc -  reallocates a memory block
 *@ptr: pointer
 *@old_size: old size of the pointer
 *@new_size: new size of the pointer
 *Return: return reallocated memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
void *result;

if (new_size == old_size)
return (ptr);
if (new_size == 0 && ptr)
{
free(ptr);
return (NULL);
}
result = malloc(new_size);
if (result == NULL)
{
free(result);
return (NULL);
}
if (ptr == NULL)
{
fill_an_array(result, '\0', new_size);
free(ptr);
}
else
{
_memcpy(result, ptr, old_size);
free(ptr);
}
return (result);
}
/**
 * _calloc - allocates memory for an array using malloc
 *@size: size
 *Return: void pointer
 */
void *_calloc(unsigned int size)
{
unsigned int i;
char *a;
if (size == 0)
return (NULL);
a = malloc(size);
if (a == NULL)
return (NULL);
for (i = 0; i < size; i++)
{
a[i] = '\0';
}
return (a);
}
/**
 * free_all - free all memory allocated
 * @cmd: command
 * @line: line pointer
 * Return: return
 */
void free_all(char **cmd, char *line)
{
free(cmd);
free(line);
cmd = NULL;
line = NULL;
}
/**
 * _memcpy - copy memory from source to destination
 *@dest: destination
 *@src: source
 *@n: number size to be copied
 *Return: to destination
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
dest[i] = src[i];
}
return (dest);
}
/**
 *fill_an_array - fill an array
 *@a: void pointer
 *@el: int
 *@len: length
 *Return: void pointer
 */
void *fill_an_array(void *a, int el, unsigned int len)
{
char *p = a;
unsigned int i = 0;

while (i < len)
{
*p = el;
p++;
i++;
}
return (a);
}
