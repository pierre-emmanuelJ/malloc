/*
** free.h for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Mon Jan 30 11:06:09 2017 Pierre-Emmanuel Jacquier
** Last update Wed Feb  1 11:31:06 2017 Pierre-Emmanuel Jacquier
*/

#ifndef FREE_H_
# define FREE_H_

# include <unistd.h>
#include "malloc.h"

void	block_fusion(t_memblock *block);
void	_free(void *ptr);

#endif /* !FREE_H_ */
