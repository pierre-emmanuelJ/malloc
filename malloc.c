
/*
** malloc.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 10:57:50 2017 Pierre-Emmanuel Jacquier
** Last update Wed Feb  8 14:45:39 2017 Pierre-Emmanuel Jacquier
*/

#include "malloc.h"

t_memblock *g_head = NULL;

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

  if (!head)
    return (NULL);
  tmp = head;
  while(tmp)
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

  if (block->memsize == size || (block->memsize - size) <= sizeof(t_memblock))
    {
      block->isfree = 0;
      return ;
    }
  old_size = block->memsize;
  new_data_block = (char *)block;
  new_data_block += (size + sizeof(t_memblock));
  ((t_memblock *)new_data_block)->next = block->next;
  ((t_memblock *)new_data_block)->prev = block;
  block->isfree = 0;
  block->next = (t_memblock *)new_data_block;
  block->next->isfree = 1;
  block->memsize = size;
  block->next->memsize  = old_size - size - sizeof(t_memblock);
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
      return (tmp);
    }
  while(tmp->next)
    tmp = tmp->next;

  tmp->next = sbrk(0);
  if (sbrk(sizeof(t_memblock) + to_alloc(size)) == (void*)-1)
    return (NULL);
  tmp->next->prev = tmp;
  tmp->next->next = NULL;
  tmp->next->memsize = size;
  tmp->next->isfree = 0;
  return (tmp->next);
}

void			*malloc(size_t size)
{
  t_memblock *block;
  size_t     alloc_size;

  if (!size)
    return (NULL);
  size = (size -1) / 4 * 4 + 4;
  alloc_size = to_alloc(size);
  block = NULL;
  if (!g_head)
    {
      block = add_block(g_head, alloc_size);
      split_block(block, size);
      g_head = block;
      return (block + 1);
    }
  if ((block = check_block(g_head, size)))
    {
      split_block(block, size);
      return block + 1;
    }
    block = add_block(g_head, alloc_size);
    split_block(block, size);
    return (block + 1);
}
