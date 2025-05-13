/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenajib <abenajib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:00:00 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/09 10:02:41 by abenajib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_cmdlist(t_cmdarg *cmdarg_list)
{
	t_cmdarg	*tmp;

	while (cmdarg_list)
	{
		tmp = cmdarg_list;
		cmdarg_list = cmdarg_list->next;
		ft_free_node(tmp);
	}
}

void	ft_free_tokenlist(t_token *token_list)
{
	t_token	*tmp;

	while (token_list)
	{
		tmp = token_list;
		token_list = token_list->next;
		free(tmp->value);
		free(tmp);
	}
}

void	ft_free_token(t_token *token)
{
	if (token)
	{
		free(token->value);
		free(token);
	}
}

void	ft_free_node(t_cmdarg *node)
{
	int	i;

	i = 0;
	if (node)
	{
		if (node->cmd)
		{
			while (i < node->cmdsize)
				free(node->cmd[i++]);
			free(node->cmd);
		}
		ft_free_redi_list(node->input);
		ft_free_redi_list(node->output);
		free(node);
	}
}

void	ft_free_redi_list(t_redi_list *redi)
{
	t_redi_list	*tmp;

	while (redi)
	{
		tmp = redi;
		redi = redi->next;
		free(tmp);
	}
}
