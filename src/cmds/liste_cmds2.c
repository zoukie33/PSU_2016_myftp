/*
** liste_cmds2.c for list cmds in /home/zoukie/Desktop/epitech/PSU_2016_myftp/src/cmds
** 
** Made by 
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Thu May 18 20:17:20 2017 
** Last update Sun May 21 21:10:47 2017 romain gadrat
*/

#include "myftp.h"

int	dele_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {
      if (access(line, F_OK) == 0)
	{
	  if (unlink(line) == 0)
	    dprintf(cli->fd, "%s\r\n", R250);
	  else
	    dprintf(cli->fd, "%s\r\n", R550b);
	}
      else
	dprintf(cli->fd, "%s\r\n", R550b);
    }
  return (0);
}

int	pwd_cmd(t_client *cli, char *line)
{
  char	buff[4096];

  (void)line;
  if (gest_err(cli) == 0)
    {
      dprintf(cli->fd, "257 \"%s\"\r\n", getcwd(buff, 4096));
    }
  return (0);
}

int	pasv_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {

    }
  return (0);
}

int	port_cmd(t_client *cli, char *line)
{
  int	port1;
  int	port2;
  char	*ip;
  int	new_port;

  (void)line;
  if (gest_err(cli) == 0)
    {
      if (line)
	{
	  port1 = parse_port1(line);
	  port2 = parse_port2(line);
	  ip = parse_ip_cmd(line);
	  new_port = (port1 * 256) + port2;
	  open_active_mode(cli, new_port, ip);
	  dprintf(cli->fd, "%s\r\n", R200b);
	}
      else
	dprintf(cli->fd, "%s\r\n", R500b);
    }
  return (0);
}

int	help_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {
      dprintf(cli->fd, "%s", R214b);
      dprintf(cli->fd, "%s", R214c);
      dprintf(cli->fd, "%s", R214d);
      dprintf(cli->fd, "%s", R214e);
      dprintf(cli->fd, "%s\r\n", R214f);
      dprintf(cli->fd, "%s\r\n", R214);
    }
  return (0);
}
