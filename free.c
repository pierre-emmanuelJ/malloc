/*
** free.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 11:07:14 2017 Pierre-Emmanuel Jacquier
** Last update Thu Feb  9 14:38:22 2017 Pierre-Emmanuel Jacquier
*/

#include "free.h"

void	free(void *ptr)
{
  t_memblock *tmp;

  if (!ptr)
    return ;
  if (ptr > sbrk(0) || ptr < (void*)g_head)
    return ;
  tmp = (t_memblock *)ptr;
  tmp = tmp -1;
  tmp->isfree = 1;
  block_fusion(tmp);
}

void	block_fusion(t_memblock *block)
{
  if (block->prev && block->prev->isfree)
  {
    block->prev->memsize = (block->memsize + block->prev->memsize + sizeof(t_memblock));
    block->prev->next = block->next;
    if (block->next)
    block->next->prev = block->prev;
    block = block->prev;
  }
  if (block->next && block->next->isfree)
  {
    block->memsize = block->memsize + block->next->memsize + sizeof(t_memblock);
    block->next = block->next->next;
    if (block->next)
    block->next->prev = block;
  }
}
