/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:52:21 by ymouchta          #+#    #+#             */
/*   Updated: 2025/07/21 23:26:45 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execute_commands(t_shell *val)
{
	signal(SIGINT, SIG_IGN);
	if (!process_heredocs(val))
		return ;
	if (is_builtin(val->list->cmd[0]) && !val->list->next)
	{
		init_shell_fds(val);
		if (!handle_redirections(val->list))
			return ;
		if (!duplicate_standard_fds(val->list))
			return (restore_standard_input(val), close_fd(&val->list->fd_herdoc[0]));
		execute_builtin(val->list->cmd, val);
		restore_standard_input(val);
	}
	else
		execute_with_fork(val);
}
