/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgiovana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:05:52 by mgiovana          #+#    #+#             */
/*   Updated: 2023/01/17 15:26:36 by mgiovana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	errors(char *message)
{
	printf("\033[31;1;4m" " Error\n    %s\n" "\033[0m", message);
	return (0);
}

void	*null_erro(char *message)
{
	printf("\033[31;1;4m" " Error\n    %s\n" "\033[0m", message);
	return (0);
}

void	warning(char *message)
{
	printf("\033[0;33m" " Warning\n %s\n" "\033[0m", message);
}
