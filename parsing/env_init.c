/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:21:14 by abenajib          #+#    #+#             */
/*   Updated: 2025/05/11 18:15:40 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_envinit(char **env)
{
	t_list	*minienv;
	t_list	*new_node;
	char	*key;
	char	*value;
	int		i;

	minienv = NULL;
	if (!env || !*env)
		return (NULL);
	i = 0;
	while (env && env[i])
	{
		if (!ft_parse_env_var(env[i], &key, &value))
		{
			i++;
			continue ;
		}
		new_node = ft_lstnew(key, value);
		if (!new_node)
			return (free(key), free(value), NULL);
		ft_lstadd_back(&minienv, new_node);
		i++;
	}
	return (minienv);
}
