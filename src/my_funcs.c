/*
** myFuncs.c for myFuncs in /home/zoukie/epitech/PSU_2016_myftp/src
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Tue May  9 18:20:11 2017 zoukie
** Last update Sun May 21 17:01:33 2017 
*/

#include "myftp.h"

int	init_struct_serv(t_serveur *serveur, int port, char *path)
{
  serveur->port = port;
  serveur->defPWD = path;
  printf("%s\n", serveur->defPWD);
  serveur->pe = getprotobyname("TCP");
  if (!serveur->pe)
    return (1);
  serveur->fd = socket(AF_INET, SOCK_STREAM, serveur->pe->p_proto);
  setsockopt(serveur->fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
  if (serveur->fd == -1)
    return (1);
  return (0);
}

int	init_bind(int fd, struct sockaddr_in s_in)
{
  if (bind(fd, (const struct sockaddr*)&s_in, sizeof(s_in)) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  return (0);
}

int	init_listen(int fd)
{
  if (listen(fd, 42) == -1)
    {
      if (close(fd) == -1)
	return (1);
      return (1);
    }
  return (0);
}
