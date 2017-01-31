
/*
** malloc.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 10:57:50 2017 Pierre-Emmanuel Jacquier
** Last update Tue Jan 31 15:03:46 2017 Pierre-Emmanuel Jacquier
*/

#include "malloc.h"

#include <stdio.h>

size_t to_alloc(size_t size)
{
  size_t	nb;
  size_t page_alloc;

  page_alloc = sysconf(_SC_PAGESIZE);
  if (size < page_alloc);
  else
    {
      nb = size / page_alloc;
      if ((size % page_alloc) > 0)
        page_alloc = page_alloc * (nb + 1);
      else
        page_alloc = page_alloc * nb;
    }
  return page_alloc;
}

void          *check_block(t_memblock *head, size_t size)
{
  t_memblock  *tmp;

  tmp = head;
  while(tmp->next)
    {
      if (tmp->memsize >= size && tmp->isfree)
        return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

void	split_block(t_memblock *block, size_t size)
{
  char *new_data_block;
  size_t old_size;

  old_size = block->memsize;
  new_data_block = (char *)block;
  new_data_block += (size + sizeof(t_memblock));
  ((t_memblock *)new_data_block)->next = block->next;
  ((t_memblock *)new_data_block)->prev = block;
  block->next = (t_memblock *)new_data_block;
  block->memsize = size;
  block->next->memsize  = old_size - size;
}

void          *add_block(t_memblock *head, size_t size)
{
  t_memblock  *tmp;

  tmp = head;
  if (!tmp)
    {
      tmp = sbrk(0);
      if (sbrk(sizeof(t_memblock) + size) == (void*)-1)
        return (NULL);
      tmp->next = NULL;
      tmp->prev = NULL;
      tmp->memsize = size;
      tmp->isfree = 0;
      return (tmp + 1);
    }
  while(tmp->next)
    tmp = tmp->next;
  tmp->next = sbrk(0);
  if (sbrk(sizeof(t_memblock) + size) == (void*)-1)
    return (NULL);
  tmp->next->prev = tmp;
  tmp->next->next = NULL;
  tmp->next->memsize = size;
  tmp->next->isfree = 0;
  return ((tmp->next) + 1);
}

void			*_malloc(size_t size)
{
  static	t_memblock *head = NULL;

  if (!head)
    {
    }
  return NULL;
}

int main()
{
  char *test = _malloc(sizeof(char) * 5);
  test[0] = 't';
  test[1] = 'e';
  test[2] = 's';
  test[3] = 't';
  test[4] = 0;
  // test[5] = 0;
  // test[6] = 0;


//  printf("%s\n", test);
}
