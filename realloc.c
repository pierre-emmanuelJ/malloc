/*
** realloc.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 11:07:21 2017 Pierre-Emmanuel Jacquier
** Last update Thu Feb  9 14:21:19 2017 Pierre-Emmanuel Jacquier
*/

#include <string.h>
#include "realloc.h"

void            *realloc(void *ptr, size_t size)
{
  t_memblock    *new_ptr;
  size_t        sizeblock;

  if (!ptr)
    {
      ptr = malloc(size);
      return (ptr);
    }
  if (ptr && !size)
    return (ptr);
  new_ptr = (t_memblock*)ptr;
  new_ptr = new_ptr - 1;
  sizeblock = new_ptr->memsize;
  if (!(new_ptr = malloc(sizeblock + size)))
    return (NULL);
  memmove(new_ptr, ptr, sizeblock);
  free(ptr);
  return (new_ptr);
}
