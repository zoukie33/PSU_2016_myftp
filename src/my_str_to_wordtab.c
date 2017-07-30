/*
** my_str_to_wordtab.c for mystrtowrdt in /home/zoukie/Desktop/epitech/PSU_2016_myftp/src
** 
** Made by 
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Sat May 20 15:21:35 2017 
** Last update Sun May 21 17:01:46 2017 
*/
#include "myftp.h"

char	*clean_str(char *str, char separator)
{
  int	i;
  char	*tmp;
  int	j;

  i = -1;
  j = 0;
  tmp = malloc(sizeof(char) * strlen(str) + 1);
  while (str[++i] != '\0')
    {
      if (str[i] == '\r')
	str[i] = 0;
      while (str[i] == separator && str[i + 1] && str[i + 1] == separator)
	i++;
      tmp[j++] = str[i];
    }
  tmp[j++] = 0;
  return (tmp);
}

int	find_words(char *str, char separator, int func, int atC)
{
  int	nb;
  int	i;

  i = -1;
  nb = 0;
  if (func == 1)
    {
      while (str[++i] != 0)
	if (str[i] == separator)
	  {
	    nb++;
	  }
    }
  else if (func == 2)
    while (str[atC] != separator && str[atC])
      {
	nb++;
	atC++;
      }
  return (nb);
}

char	**my_str_to_wordtab(char *str, char separator)
{
  char	**final;
  int	nbWords;
  int	i;
  int	j;
  int	a;
  int	b;

  i = -1;
  j = 0;
  a = 0;
  str = clean_str(str, separator);
  nbWords = find_words(str, separator, 1, 0);
  final = malloc(sizeof(char *) * (nbWords + 2));
  while (nbWords-- >= 0)
    {
      a += find_words(str, separator, 2, a) + 1;
      final[++i] = malloc(sizeof(char) * (a + 2));
      b = 0;
      while (j < a - 1)
	final[i][b++] = str[j++];
      final[i][b] = '\0';
      j = a;
    }
  final[i + 1] = NULL;
  return (final);
}
