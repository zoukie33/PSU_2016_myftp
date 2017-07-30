/*
** gest_cmds.c for gest cmds in /home/zoukie/Desktop/epitech/PSU_2016_myftp/src
** 
** Made by 
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Thu May 18 19:52:08 2017 
** Last update Sun May 21 21:34:30 2017 
*/

#include "myftp.h"
#include <ctype.h>

static const t_cmds	g_cmds[15] =
  {
    { "USER", &user_cmd },
    { "PASS", &pass_cmd },
    { "CWD", &cwd_cmd },
    { "CDUP", &cdup_cmd },
    { "QUIT", &quit_cmd },
    { "DELE", &dele_cmd },
    { "PWD", &pwd_cmd },
    { "PASV", &pasv_cmd },
    { "PORT", &port_cmd },
    { "HELP", &help_cmd },
    { "NOOP", &noop_cmd },
    { "RETR", &retr_cmd },
    { "STOR", &stor_cmd },
    { "LIST", &list_cmd },
    { NULL, NULL }
  };

int	gest_cmds(t_client *client, char *line)
{
  char	**res;
  int	i;
  int	ok;

  i = 0;
  ok = 0;
  res = my_str_to_wordtab(line, ' ');
  printf("%s\n", line);
  while ((g_cmds[i].cmd != NULL) && (ok == 0))
    {
      if (strcasecmp(g_cmds[i].cmd, res[0]) == 0)
	{
	  ok = 1;
	  g_cmds[i].cmds(client, res[1]);
	}
      i++;
    }
  if (strcasecmp(line, "") == 0)
    ok = 1;
  if (ok == 0)
    dprintf(client->fd, "%s\r\n", R500);
  return (0);
}
