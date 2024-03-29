/*
** show_alloc_mem.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Feb  9 15:01:35 2017 Pierre-Emmanuel Jacquier
** Last update Fri Feb 10 16:01:57 2017 Pierre-Emmanuel Jacquier
*/

#include "malloc.h"
#include <stdio.h>

void            show_alloc_mem()
{
  t_memblock    *block;

  printf("break : %p\n", sbrk(0));
  block = g_head;
  while (block)
    {
      printf("%p - %p : %lu bytes\n", block + 1,
	     (char *)(block) + block->memsize + META_DATA_SIZE,
	     block->memsize);
      block = block->next;
    }
}
