/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oshell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oriabenk <oriabenk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:13:17 by oriabenk          #+#    #+#             */
/*   Updated: 2025/01/26 15:00:06 by oriabenk         ###   ########.fr       */
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
	struct s_token	*next;
}	t_token;

typedef struct s_data
{
	char		**env;
	pid_t		pid;
	char		*user_input;
	t_token		*begin_token;
}	t_data;

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
t_token *split_token(t_token *data, int position, char symbol);
t_token	*create_list(char *string);
t_token	*create_token(char *string, int fulls);
t_token	*add_token_after(t_token	*list, t_token	*add_in_list);

#endif