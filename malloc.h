/*
** malloc.h for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 11:05:54 2017 Pierre-Emmanuel Jacquier
** Last update Tue Feb  7 20:32:20 2017 Pierre-Emmanuel Jacquier
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
#include <stdio.h>

typedef struct          s_memblock
{
  size_t                memsize;
  struct s_memblock     *next;
  struct s_memblock     *prev;
  size_t                isfree;
}                       t_memblock;

extern t_memblock *g_head;

void    *malloc(size_t size);
void    *calloc(size_t nelem, size_t elsize);
size_t  to_alloc(size_t size);
void    *add_block(t_memblock *head, size_t size);
void    *check_block(t_memblock *head, size_t size);

#endif /* !MALLOC_H_ */
