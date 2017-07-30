/*
** active.c for active in /home/zoukie/Desktop/epitech/PSU_2016_myftp/src/cmds
** 
** Made by 
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun May 21 18:05:52 2017 
** Last update Sun May 21 19:39:12 2017 
*/

#include "myftp.h"

char	*parse_ip_cmd(char *cmd)
{
  int	i;
  int	z;

  i = -1;
  z = 0;
  while (cmd[++i])
    {
      if (cmd[i] == ',')
	{
	  z++;
	  cmd[i] = '.';
	}
      if (z == 4)
	{
	  cmd[i] = 0;
	  return (cmd);
	}
    }
  return (cmd);
}

int	parse_port1(char *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(cmd, ',');
  return (atoi(tab[4]));
}

int	parse_port2(char *cmd)
{
  char	**tab;

  tab = my_str_to_wordtab(cmd, ',');
  return (atoi(tab[5]));
}

int	open_active_mode(t_client *cli, int port, char *ip)
{
  struct protoent	*pe;
  struct sockaddr_in	s_in_active;
  int			nw_fd;
  socklen_t		s_size;

  pe = getprotobyname("TCP");
  nw_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  setsockopt(nw_fd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));
  if (nw_fd == -1)
    return (-1);
  s_in_active.sin_family = AF_INET;
  s_in_active.sin_port = htons(port);
  s_in_active.sin_addr.s_addr = inet_addr(ip);
  s_size = sizeof(s_in_active);
  if ((connect(nw_fd, (struct sockaddr *)&s_in_active, s_size)) == -1)
    return (-1);
  cli->passact = ACTIVE;
  cli->data_fd = nw_fd;
  return (0);
}
