/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarustam < aarustam@student.42yerevan.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:04:02 by mgraaf            #+#    #+#             */
/*   Updated: 2025/02/16 22:35:26 by aarustam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_tools	tools;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(0);
	}
	tools.envp = ft_arrdup(envp);
	find_pwd(&tools);
	implement_tools(&tools);	
	minishell_loop(&tools);
	return (0);
}
