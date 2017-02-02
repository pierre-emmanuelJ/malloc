
/*
** malloc.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 10:57:50 2017 Pierre-Emmanuel Jacquier
** Last update Thu Feb  2 15:57:53 2017 Pierre-Emmanuel Jacquier
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

size_t        count_blocks(t_memblock *head)
{
  t_memblock  *tmp;
  size_t      i;

  i = 0;
  if (!head)
    return 0;
  tmp = head;
  while(tmp)
    {
      tmp = tmp->next;
      i++;
      //my_printf("count b = %s\n", "momo");
    }
  return i;
}

void          *check_block(t_memblock *head, size_t size)
{
  t_memblock  *tmp;

  if (!head)
    return (NULL);
  tmp = head;
  while(tmp)
    {
      if (tmp->momo != 'A')
        {
          write(1, "char in memory : \n", 18);
          write(1, &(tmp->momo), 1);
	        write(1, "\n", 1);
          write(1, "2 memory corupted\n", 18);
        }
      if (tmp->memsize >= size && tmp->isfree)
        return (tmp);
      tmp = tmp->next;
    //  write(1, "1 hello\n", 8);
    }
  return (NULL);
}

void	split_block(t_memblock *block, size_t size)
{
  char *new_data_block;
  size_t old_size;

  //my_printf("size = %d\n", size);
  old_size = block->memsize;
  new_data_block = (char *)block;
  new_data_block += (size + sizeof(t_memblock));
  ((t_memblock *)new_data_block)->next = block->next;
  ((t_memblock *)new_data_block)->prev = block;
  block->isfree = 0;
  block->next = (t_memblock *)new_data_block;
  block->next->isfree = 1;
  block->memsize = size;
  block->next->memsize  = old_size - size;
  block->next->momo = 'A';

  // char *new_data_block;
  // t_memblock new_block;
  //
  // new_block.memsize = block->memsize - size;
  // new_block.next = block->next;
  // new_block.prev = block;
  // new_block.isfree = 1;
  // new_block.momo = 'A';
  //
  // block->memsize = size;
  // block->isfree = 0;
  // new_data_block = ((char *)block) + (size + sizeof(t_memblock));
  // *((t_memblock *)new_data_block) = new_block;

}

void          *add_block(t_memblock *head, size_t size)
{
  t_memblock  *tmp;
  //size_t toloc = to_alloc(size);
  //printf("to_alloc = %lu\n", to_alloc(size));

  tmp = head;
  if (!tmp)
    {
      tmp = sbrk(0);
      if (sbrk(sizeof(t_memblock) + size) == (void*)-1)
        return (NULL);
      tmp->next = NULL;
      tmp->prev = NULL;
      tmp->memsize = size;
      tmp->momo = 'A';
      tmp->isfree = 0;
    //  split_block(tmp, size);
      return (tmp + 1);
    }
  while(tmp->next)
    {
    //  write(1, "2 hello\n", 8);
      if (tmp->momo != 'A')
	      {
	        write(1, "char in memory : \n", 18);
	        write(1, &(tmp->momo), 1);
	        write(1, "\n", 1);
	        write(1, "1 memory corupted\n", 18);
	      }
      tmp = tmp->next;
    }
  tmp->next = sbrk(0);
  if (sbrk(sizeof(t_memblock) + to_alloc(size)) == (void*)-1)
    return (NULL);
  tmp->next->prev = tmp;
  tmp->next->next = NULL;
  tmp->next->memsize = size;
  tmp->momo = 'A';
  tmp->next->isfree = 0;
  //split_block((tmp->next), size);
  return ((tmp->next) + 1);
}

void			*malloc(size_t size)
{
  t_memblock *block;

  block = NULL;
  if (!size)
    return (NULL);
  //size = (size - 1) / 4 * 4 + 4;
  if (!g_head)
    {
      block = add_block(g_head, size);
      g_head = block - 1;
      return (block);
    }
  if ((block = check_block(g_head, size)))
    {
      if (block->memsize == size)
	      {
	        block->isfree = 0;
	        return (block + 1);
	      }
      if ((block->memsize - size) <= sizeof(t_memblock))
	      {
	        block->isfree = 0;
	        return (block + 1);
	      }
      split_block(block, size);
      if (block->momo != 'A')
	{
	  write(1, "1 block pourrit\n", 16);
	}
  if (block->next->momo != 'A')
{
	    write(1, "2 block pourrit\n", 16);
}
      return block + 1;
    }
  return (add_block(g_head, size));
}
