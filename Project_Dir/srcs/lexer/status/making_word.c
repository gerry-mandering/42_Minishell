/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minseok2 <minseok2@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:19:19 by minseok2          #+#    #+#             */
/*   Updated: 2022/12/30 14:03:37 by minseok2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"
#include "../../../includes/lexer1.h"

void	making_word(t_status *status, t_data *data, char **line, t_list *buffer_lst)
{
	lst_append(buffer_lst, new_node(*line));
	(*line)++;
	if (**line == '$')
	{
		*status = EXPAND;
		return ;
	}
	if (ft_strchr(" \0|<>\'\"", **line))
		create_token(&data->token_lst, buffer_lst, T_WORD);
	*status = BRANCH;
}
