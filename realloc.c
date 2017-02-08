/*
** realloc.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 11:07:21 2017 Pierre-Emmanuel Jacquier
** Last update Wed Feb  8 13:19:40 2017 Pierre-Emmanuel Jacquier
*/

#include <string.h>
#include "realloc.h"

void	*realloc(void *ptr, size_t size)
{
  t_memblock  *new_ptr;
  size_t      sizeblock;

  if (!ptr)
    {
      ptr = malloc(size);
      return (ptr);
    }
  if (ptr && !size)
    return (ptr);
  new_ptr = (t_memblock*)ptr;
  new_ptr = new_ptr -1;
  sizeblock = new_ptr->memsize;
  if (!(new_ptr = malloc(sizeblock + size)))
    return (NULL);
  memmove(new_ptr, ptr, sizeblock);
  free(ptr);
  return (new_ptr);
}

void *calloc(size_t nelem, size_t elsize)
{
	void *ptr;

	ptr = malloc(nelem * elsize);
	if (ptr == 0)
		return (ptr);
	bzero(ptr, nelem * elsize);
	return (ptr);
}
