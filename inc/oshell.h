/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oshell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:13:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/03/01 14:08:48 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSHELL_H
# define OSHELL_H

# include "../libft/libft.h"
# include <fcntl.h>

# define HEREDOC_PROMPT "<<> "
# define NORMAL_PROMPT "ohell> "

typedef struct s_token
{
	char			*tokens;
	char			*extend;
	int				full;
	int				numberpipe;
	int				is_heredoc;
	int				is_variable;
	int				is_quotes;
	int				is_file;
	int				is_redirect;
	struct s_token	*next;
}	t_token;

/*
Структури для запуску виконання
*/

typedef struct s_io
{
	char	*infile_name;
	char	*outfile_name;
	int		fd_infile;
	int		fd_outfile;
	int		stdin_copy;
	int		stdout_copy;
}	t_io;

/*
структура для збререження цілого рядка команди
name - ім'я команди
path - шлях виконання
args - масив аргументів команди
is_piped - запускаєтья як пайп
is_heredoc - містить введення з командної строки
is_redirect - містить перенаправлення 
*/

typedef struct s_command
{
	char				*name;
	char				*path;
	char				**args;
	int					is_piped;
	int					is_heredoc;
	int					is_redirect;
	char				*eof;
	int					*pipe_fd;
	t_io				*io;
	struct s_command	*next;
}	t_command;

/*
що до чого
env - зберігає оточення
pid - слугує для інформації по пайпам
piped - для відображення чи потрібно робити це все в підпроцесах
heredoc - наявність heredoc в командній строці
redirect - наявність операторів переадресації
user_input - початкова строка, яка була введена
begin_token - початок командної строки
stdin_copy - якщо є переадресація то тут зберігається інформація про звідки
stdout_copy - місце про переадресацію куди
exit_status - інформація про статус виконання команд
cmd - зберігає лист команд (об'єднання токенів)
*/

typedef struct s_data
{
	char		**env;
	pid_t		pid;
	int			piped;
	int			heredoc;
	int			redirect;
	char		*user_input;
	t_token		*begin_token;
	int			stdin_copy;
	int			stdout_copy;
	int			exit_status;
	t_command	*cmd;
}	t_data;

/*
функції для запуску команд
*/

char	*find_path(char *cmd, char **envp);
void	run_command(char *argv, char **envp);
void	run_in_pipe(t_data *data);
void	execute_command(t_data *data);

/*
команди що перенесені з проекту Тіони
*/

void	init_io(t_command *cmd);

/*
функції початкової ініціалізації програми
*/

int		init_env(t_data *data, char **env);
int		init_data(t_data *data, char **env);
void	handle_signals_global(void);

/*
функції для виходу з програми
*/

void	free_all(t_data *data);
void	free_all_exit(t_data *data);
void	exit_shell(t_data *data, int exit_number);

/*
функції для обробки помилок
*/

void	exit_invalid_input(void);
void	error_allocate_list(void);

/*
функції для обробки строки
*/

void	process_execute(t_data *data);
int		is_valid_input(char *string);
int		is_opened_bracket(char *string, int position);
int		is_correct_substring(char *line, int i);

/*
функції для роботи з листом
*/

void	init_list(t_data *data);
int		split_on_substring(t_data *data);
int		split_on_pipe(t_data *data);
int		split_on_redirect(t_data *data);
int		split_on_herdoc(t_data *data);
int		split_on_meta(t_data *data);
t_token	*extract_token(t_token *d, int pos, char symbol);
t_token	*split_token(t_token *data, int position, int size);
t_token	*create_list(char *string);
t_token	*create_token(char *string, int fulls);
t_token	*delete_token(t_token *token);
t_token	*add_token_after(t_token	*list, t_token	*add_in_list);
void	make_cmd(t_data *data);
void	*mark_data(t_data *d);
t_token	*create_cmd(t_token	*tock, t_data *data);

/*

*/
void	extend_variable(t_data *data);
int		extend_heredoc(t_data *data);
#endif