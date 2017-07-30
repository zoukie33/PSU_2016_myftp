/*
** liste_cmds1.c for list cmds 1 in /home/zoukie/Desktop/epitech/PSU_2016_myftp/src/cmds
** 
** Made by 
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Thu May 18 20:13:35 2017 
** Last update Mon May 22 20:39:55 2017 
*/

#include "myftp.h"

int	user_cmd(t_client *cli, char *line)
{
  if (!line && cli->status != LOGGED)
    dprintf(cli->fd, "%s\r\n", R530b);
  else
    {
      if (cli->status == LOGGED)
	dprintf(cli->fd, "%s\r\n", R530c);
      else
	{
	  if (strcasecmp(line, "anonymous") == 0)
	    cli->status = SEMI_LOGGED;
	  dprintf(cli->fd, "%s\r\n", R331);
	  cli->cmdUSER = 1;
	}
    }
  return (0);
}

int	pass_cmd(t_client *cli, char *line)
{
  (void)line;
  if (cli->status == SEMI_LOGGED)
    {
      cli->status = LOGGED;
      dprintf(cli->fd, "%s\r\n", R230);
    }
  else if (cli->cmdUSER != 1)
    dprintf(cli->fd, "%s\r\n", R503);
  else if (cli->status == LOGGED)
    dprintf(cli->fd, "%s\r\n", R230b);
  else if (cli->status == NOT_LOGGED)
    dprintf(cli->fd, "530 Login incorrect.\r\n");
  return (0);
}

int	cwd_cmd(t_client *cli, char *line)
{
  if (gest_err(cli) == 0)
    {
      if (!line)
	dprintf(cli->fd, "%s\r\n", R550);
      else
	{
	  if ((strcasecmp(line, "..") == 0) && (cli->bPWD == 0))
	    dprintf(cli->fd, "%s\r\n", R250);
	  else if (chdir(line) == 0)
	    {
	      if (strcasecmp(line, "..") == 0)
		cli->bPWD--;
	      else
		cli->bPWD++;
	      dprintf(cli->fd, "%s\r\n", R250);
	    }
	  else
	    dprintf(cli->fd, "%s\r\n", R550);
	}
    }
  return (0);
}

int	cdup_cmd(t_client *cli, char *line)
{
  (void)line;
  if (gest_err(cli) == 0)
    {
      if (chdir("..") == 0)
	dprintf(cli->fd, "%s\r\n", R250);	
    }
  return (0);
}

int	quit_cmd(t_client *cli, char *line)
{
  (void)line;
  dprintf(cli->fd, "%s\r\n", R221);
  close(cli->fd);
  cli = NULL;
  return (0);
}
