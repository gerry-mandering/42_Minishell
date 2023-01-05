/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_check_set_err.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:13:52 by jincpark          #+#    #+#             */
/*   Updated: 2023/01/05 16:37:28 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"

int	is_redir(t_type type)
{
	if (type == T_LESS || type == T_GREAT || type == T_DLESS || type == T_DGREAT)
		return (1);
	return (0);
}

int	is_redir_form(t_data *data, t_node *node)
{
	if (node->content == NULL)
		return (0);
	if (is_redir(((t_token *)node->content)->type))
	{
		if ((t_token *)node->next->content)
			return (1);
		data->syntax_err_flag = E_NEAR_NEWLINE;
	}
	return (0);
}

void	set_redir_err_flag(t_data *data, t_token *token)
{
	if (token->type == T_GREAT)
		data->syntax_err_flag = E_NEAR_GREAT;
	else if (token->type == T_LESS)
		data->syntax_err_flag = E_NEAR_LESS;
	else if (token->type == T_DGREAT)
		data->syntax_err_flag = E_NEAR_DGREAT;
	else if (token->type == T_DLESS)
		data->syntax_err_flag = E_NEAR_DLESS;
}

void	set_redir_type(t_redir *redir, t_type type)
{
	if (type == T_LESS)
		redir->type = T_LESS;
	else if (type == T_GREAT)
		redir->type = T_GREAT;
	else
		redir->type = T_DGREAT;
}
