/*
** free.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 11:07:14 2017 Pierre-Emmanuel Jacquier
** Last update Wed Feb  1 10:46:29 2017 Pierre-Emmanuel Jacquier
*/

#include "free.h"

void	_free(void *ptr)
{
  t_memblock *tmp;

  tmp = (t_memblock *)ptr;
  tmp = tmp -1;
  printf("%s\n", "je free ta mere");
  tmp->isfree = 1;
}
