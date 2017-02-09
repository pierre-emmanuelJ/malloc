/*
** calloc.c for  in /home/jacqui_p/rendu/PSU_2016_malloc/
**
** Made by Pierre-Emmanuel Jacquier
** Login   <jacqui_p@epitech.eu>
**
** Started on  Thu Feb  9 14:22:05 2017 Pierre-Emmanuel Jacquier
** Last update Thu Feb  9 14:24:01 2017 Pierre-Emmanuel Jacquier
*/

#include "calloc.h"
#include <string.h>

void *calloc(size_t nelem, size_t elsize)
{
	void *ptr;

	ptr = malloc(nelem * elsize);
	if (ptr == 0)
		return (ptr);
	bzero(ptr, nelem * elsize);
	return (ptr);
}
