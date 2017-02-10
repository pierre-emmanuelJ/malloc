/*
** malloc.h for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 11:05:54 2017 Pierre-Emmanuel Jacquier
** Last update Fri Feb 10 17:22:52 2017 Pierre-Emmanuel Jacquier
*/

#ifndef MALLOC_H_
# define MALLOC_H_

# include <unistd.h>
# include <stdio.h>

typedef struct          s_memblock
{
  size_t                memsize;
  struct s_memblock     *next;
  struct s_memblock     *prev;
  size_t                isfree;
}                       t_memblock;

extern t_memblock       *g_head;

void    *malloc(size_t size);
size_t  to_alloc(size_t size);
void    *add_block(t_memblock *head, size_t size);
void    *check_block(t_memblock *head, size_t size);
void    show_alloc_mem();

# define META_DATA_SIZE (sizeof(t_memblock))
# define SBRK_ERROR ((void*)-1)

# define MULTIPLE_OF(num, mul) (((num) | (mul - 1)) + 1)

# define PAGE_SIZE (sysconf(_SC_PAGESIZE))
# define WORD sizeof(void*)

# define ALIGN_TO_PAGESIZE(size) MULTIPLE_OF(size, PAGE_SIZE)
# define ALIGN_BLOCK(size) MULTIPLE_OF(size, WORD)

#endif /* !MALLOC_H_ */
