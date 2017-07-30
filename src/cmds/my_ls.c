/*
** my_ls.c for my ls in /home/zoukie/Desktop/epitech/PSU_2016_myftp/src/cmds
** 
** Made by 
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sun May 21 19:22:46 2017 
** Last update Sun May 21 19:27:52 2017 
*/

#include "myftp.h"

int	do_ls(t_client *cli)
{
  dprintf(cli->data_fd, "hello\r\n");
  return (0);
}
