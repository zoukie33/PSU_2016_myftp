/*
** init_ftp.c for init ftp in /home/zoukie/epitech/PSU_2016_myftp/src
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Wed May 10 16:41:27 2017 zoukie
** Last update Sun May 21 19:31:38 2017 
*/

#include "myftp.h"

int	create_client(t_client *client, t_serveur *serveur)
{
  close(serveur->fd);
  client->connected = 1;
  client->status = NOT_LOGGED;
  client->fd = serveur->fd_client;
  client->defPWD = serveur->defPWD;
  client->bPWD = 0;
  return (0);
}

int	gest_client(t_serveur *serveur, char *client_ip)
{
  t_client	*client;
  char		*s;
  FILE		*fd;
  size_t	len;
  ssize_t	read;

  s = NULL;
  if ((client = malloc(sizeof(t_client))) == NULL)
    return (1);
  dprintf(1, "%s\n", client_ip);
  fd = fdopen(serveur->fd_client, "r+");
  create_client(client, serveur);
  dprintf(serveur->fd_client, "%s\r\n", R220);
  while ((read = getline(&s, &len, fd)) != -1)
    gest_cmds(client, s);
  return (0);
}

int	get_clients(t_serveur *serv, struct sockaddr_in s_in_cli, socklen_t s_in_s)
{
  int		pid;

  while (42)
    {
      serv->fd_client = accept(serv->fd, (struct sockaddr *)&s_in_cli, &s_in_s);
      if ((pid = fork()) == 0)
	{
	  gest_client(serv, inet_ntoa(s_in_cli.sin_addr));
	  close(serv->fd);
	  close(serv->fd_client);
	  return (0);
	}
      if (pid > 0)
	{
	  waitpid(-1, &serv->x, WNOHANG);
	  close(serv->fd_client);
	}
      if (serv->fd_client == -1)
	{
	  if (close(serv->fd) == -1)
	    return (1);
	  return (1);
	}
    }
  return (0);
}
