/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oshell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:13:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/02/15 13:08:29 by oriabenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OSHELL_H
# define OSHELL_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_token
{
	char			*tokens;
	int				full;
	int				numberpipe;
	struct s_token	*next;
}	t_token;

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
}	t_data;

/*
функції для запуску команд

*/

char	*find_path(char *cmd, char **envp);
void	run_command(char *argv, char **envp);

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
t_token	*add_token_after(t_token	*list, t_token	*add_in_list);

/*
*/

void	run_in_pipe(t_data *data);
void	execute_command(t_data *data);

#endif