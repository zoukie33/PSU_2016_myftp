/*
** myftp.h for myftp h in /home/zoukie/epitech/PSU_2016_myftp/inc
** 
** Made by zoukie
** Login   <romain.gadrat@epitech.eu>
** 
** Started on  Thu May  4 17:16:23 2017 zoukie
** Last update Sun May 21 21:10:38 2017 romain gadrat
*/

#ifndef MYFTP_H_
# define MYFTP_H_

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>

/*
** Reponses define
*/

# define R120 "120 Service ready in nnn minutes."
# define R125 "125 Data connection already open; transfer starting."
# define R150 "150 File status okay; about to open data connection."
# define R150b "150 Here comes the directory listing."
# define R200 "200 Command okay."
# define R200b "200 PORT command successful. Consider using PASV."
# define R220 "220 Bienvenue dans un monde merveilleux."
# define R221 "221 Goodbye."
# define R226 "226 Closing data connection.\nRequested file action successful"
# define R226b "226 Directory send OK."
# define R227 "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2)."
# define R230 "230 User logged in, proceed."
# define R230b "230 Already logged in."
# define R250 "250 Requested file action okay, completed."
# define R250b "250 Failed to change directory."
# define R257 "257 \"PATHNAME\" created."
# define R331 "331 User name okay, need password."
# define R332 "332 Need account for login."
# define R425 "425 Use PORT or PASV first."
# define R450 "450 File unavaible."
# define R500 "500 Unknown command."
# define R500b "500 Illegal PORT command."
# define R503 "503 Login with USER first."
# define R530 "530 Please login with USER and PASS."
# define R530c "530 Can't change from guest user."
# define R530b "530 Permission denied."
# define Rxxx "xxx Error (RFC compliant)"
# define R550b "550 File unavaible."
# define R550 "550 Failed to change directory."
# define R214 "214 Help OK."
# define R214b "214-The following commands are recognized.\n"
# define R214c " ABOR ACCT ALLO APPE CDUP CWD  DELE EPRT EPSV FEAT HELP LIST\n"
# define R214d " MODE NLST NOOP OPTS PASS PASV PORT PWD  QUIT REIN REST RETR\n"
# define R214e " RNTO SITE SIZE SMNT STAT STOR STOU STRU SYST TYPE USER XCUP\n"
# define R214f " XPWD XRMD"


/*
** enums
*/

typedef enum		e_status
{
  NOT_LOGGED = 0,
  SEMI_LOGGED = 1,
  LOGGED = 2
}			t_status;

typedef enum		e_passact
{
  NONE = 0,
  ACTIVE = 1,
  PASSIVE = 2
}			t_passact;

/*
** structs
*/

typedef struct		s_serveur
{
  struct protoent	*pe;
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  int			fd;
  int			fd_client;
  int			port;
  int			x;
  char			*defPWD;
}			t_serveur;

typedef struct		s_client
{
  int			fd;
  int			data_fd;
  int			cmdUSER;
  int			connected;
  t_status		status;
  t_passact		passact;
  char			*defPWD;
  int			bPWD;
}			t_client;

typedef struct s_cmds
{
  char	*cmd;
  int	(*cmds)(t_client *, char *);
}	t_cmds;

/*
** fcts client
*/

int	create_client(t_client *, t_serveur *);
int	gest_client(t_serveur *, char *);
int	client_accept(t_serveur *, struct sockaddr_in, socklen_t);
int	get_clients(t_serveur *, struct sockaddr_in, socklen_t);

/*
** fcts  init
*/

int	init_server(int, char *);
int	init_bind(int, struct sockaddr_in);
int	init_listen(int);
int	init_struct_serv(t_serveur *, int, char *);

/*
** fcts commandes
*/
int	gest_cmds(t_client *, char *);

int	user_cmd(t_client *, char *);
int	pass_cmd(t_client *, char *);
int	cwd_cmd(t_client *, char *);
int	cdup_cmd(t_client *, char *);
int	quit_cmd(t_client *, char *);
int	dele_cmd(t_client *, char *);
int	pwd_cmd(t_client *, char *);
int	pasv_cmd(t_client *, char *);
int	port_cmd(t_client *, char *);
int	help_cmd(t_client *, char *);
int	noop_cmd(t_client *, char *);
int	retr_cmd(t_client *, char *);
int	stor_cmd(t_client *, char *);
int	list_cmd(t_client *, char *);

/*
** fcts divs
*/

char	**my_str_to_wordtab(char *, char);
int	gest_err(t_client *cli);

/*
** active mode
*/

char	*parse_ip_cmd(char *);
int	parse_port1(char *);
int	parse_port2(char *);
int	open_active_mode(t_client *, int, char *);

/*
** ls
*/

int	do_ls(t_client *);

#endif /* !MYFTP_H_ */
