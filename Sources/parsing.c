/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 14:11:53 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/28 17:44:44 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/computorv1.h"

int					ft_swap_space(char *str, int *cpt, int flagu)
{
	if (flagu)
		(*cpt)++;
	while (str[*cpt] == ' ')
		(*cpt)++;
	return (1);
}

int					ft_final(t_intab *m, float num, int p)
{
	m->tab[p] += num;
	return (1);
}

void				ft_put_error(char *str, int *cpt)
{
	printf(P3);
	printf(": erreur de syntaxe detectee sur |%s|\n",
			str + *cpt);
	exit(0);
}

int					ft_get_operator(int ind, int *cpt, char *str)
{
	char		tmp;

	ft_swap_space(str, cpt, 0);
	tmp = str[*cpt];
	if (tmp == 0)
		return (3);
	if (tmp != '+' && tmp != '-')
	{
		if (ind == 0 && (ft_isdigit(tmp) || tmp == 'x' || tmp == 'X'))
			return (1);
		else
			ft_put_error(str, cpt);
	}
	ft_swap_space(str, cpt, 1);
	return ((tmp == '+') ? 1 : -1);
}

void				ft_parse(t_intab *m, char *str, int flagu)
{
	int		ind;
	int		cpt;
	int		*ptr;
	int		sign;

	cpt = 0;
	ptr = &cpt;
	ind = 0;
	if (flagu)
		ft_strchr(str, '=')[0] = 0;
	if ((ft_strchr(str, '=') || ft_blk(str)) && printf(P3) && printf("\n"))
		exit(0);
	while (42)
	{
		sign = ft_get_operator(ind, ptr, str);
		if (sign == 3)
			break ;
		ind = 1;
		ft_get_operation(sign, m, str, ptr);
	}
	if (flagu)
		ft_strchr(str, 0)[0] = '=';
}
