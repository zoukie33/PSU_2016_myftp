/*
** liste_cmds3.c for list cmds in /home/zoukie/Desktop/epitech/PSU_2016_myftp/src/cmds
** 
** Made by 
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Thu May 18 20:22:22 2017 
** Last update Sun May 21 19:39:54 2017 
*/

#include "myftp.h"

int	noop_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {
      dprintf(cli->fd, "%s\r\n", R200);
    }
  return (0);
}

int	retr_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {

    }
  return (0);
}

int	stor_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {

    }
  return (0);
}

int	list_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {
      if (cli->passact == ACTIVE || cli->passact == PASSIVE)
	{
	  dprintf(cli->fd, "%s\r\n", R150b);
	  do_ls(cli);
	  close(cli->data_fd);
	  dprintf(cli->fd, "%s\r\n", R226b);
	}
      else
	dprintf(cli->fd, "%s\r\n", R425);
    }
  return (0);
}

int	gest_err(t_client *cli)
{
  if (cli->status == NOT_LOGGED)
    {
      dprintf(cli->fd, "%s\r\n", R530);
      return (1);
    }
  return (0);
}
