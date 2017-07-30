/*
** my_ftp.c for  in /home/zoukie/epitech/PSU_2016_myftp/src
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Thu May  4 17:37:47 2017 zoukie
** Last update Sun May 21 17:01:17 2017 
*/

#include "myftp.h"

int	init_server(int	port, char *path)
{
  t_serveur		*serveur;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;

  if ((serveur = malloc(sizeof(t_serveur))) == NULL)
    return (1);
  init_struct_serv(serveur, port, path);
  s_in_size = sizeof(s_in_client);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = INADDR_ANY;
  if (init_bind(serveur->fd, s_in) == 1)
    return (1);
  if (init_listen(serveur->fd) == 1)
    return (1);
  get_clients(serveur, s_in_client, s_in_size);
  if (close(serveur->fd) == -1)
    return (1);
  if (close(serveur->fd_client) == -1)
    return (1);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc != 3)
    {
      printf("Usage: ./server [port] [path]\n");
      return (0);
    }
  else if (chdir(argv[2]) != 0)
    {
      printf("Error: Bad path.\n");
      return (0);
    }
  else
    init_server(atoi(argv[1]), argv[2]);
  return (0);
}
