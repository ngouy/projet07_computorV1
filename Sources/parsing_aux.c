/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 17:32:40 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/28 17:43:22 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/computorv1.h"

int					ft_swap_numbr(char *str, int *cpt, float *num)
{
	*num = atof(str + *cpt);
	while (ft_isdigit(str[*cpt]))
		(*cpt)++;
	if (str[*cpt] == '.')
		*cpt += ft_len_nb(*num) + 1;
	return (1);
}

int					ft_get_operation(int sign, t_intab *m, char *str, int *cpt)
{
	float		num;
	int			p;
	char		c;

	num = sign;
	p = 0;
	ft_swap_space(str, cpt, 0);
	c = str[*cpt];
	if (c == 'x' || c == 'X' || ft_isdigit(c))
	{
		if (ft_isdigit(c))
		{
			if (ft_aux1(str, cpt, m, &num) == 1)
				return (1);
		}
		if (str[*cpt] == 'x' || str[*cpt] == 'X')
		{
			if (ft_aux2(str, cpt, m, (float)sign * num) == 1)
				return (1);
		}
		ft_put_error(str, cpt);
	}
	ft_put_error(str, cpt);
	return (0);
}

int					ft_aux1(char *str, int *cpt, t_intab *m, float *num)
{
	int			sign;
	int			p;
	char		c;

	sign = (int)*num;
	*num = 1;
	p = 0;
	ft_swap_numbr(str, cpt, num);
	if ((str[*cpt] == ' ' || str[*cpt] == 0) && ft_swap_space(str, cpt, 0))
	{
		c = str[*cpt];
		if (c == '-' || c == '+' || c == 0)
			return (ft_final(m, (float)sign * *num, p));
		else if (c == '*')
			ft_swap_space(str, cpt, 1);
		else
			ft_put_error(str, cpt);
	}
	else if (str[*cpt] == '*')
		ft_swap_space(str, cpt, 1);
	else if (((str[*cpt] == '-' || str[*cpt] == '+')) || str[*cpt] == 0)
		return (ft_final(m, (float)sign * *num, p));
	return (0);
}

int					ft_aux2(char *str, int *cpt, t_intab *m, float num)
{
	int			p;

	p = 0;
	(*cpt)++;
	if (str[*cpt] == '^')
	{
		if (ft_isdigit(str[*cpt + 1]))
		{
			(*cpt)++;
			p = atoi(str + *cpt);
			while (ft_isdigit(str[*cpt]))
				(*cpt)++;
			m->tab[p] += num;
			return (1);
		}
	}
	else
	{
		p = 1;
		m->tab[p] += num;
		return (1);
	}
	return (0);
}

int					ft_blk(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
	{
		printf(P3);
		printf(": l'un des deux membres est vide.\n");
		exit(0);
	}
	return (0);
}
