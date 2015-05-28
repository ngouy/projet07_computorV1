/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 14:59:58 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/28 17:42:39 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/computorv1.h"

int					get_max_deg(char *str)
{
	int		ret;
	int		tmp;
	int		i;

	i = 0;
	ret = 0;
	if (strchr(str, 'X') || strchr(str, 'x'))
		ret++;
	while (str[i])
	{
		if (str[i] == '^' && (str[i - 1] == 'X' || str[i - 1] == 'x'))
		{
			tmp = ft_atoi(str + i + 1);
			ret = (tmp != 0 && tmp > ret) ? tmp : ret;
		}
		i++;
	}
	return (ret + 1);
}

t_intab				*ft_init_m(char *str, int i)
{
	t_intab	*ret;
	int		j;

	j = 0;
	if (str)
		i = get_max_deg(str);
	ret = malloc(sizeof(*ret));
	ret->len = i;
	ret->tab = malloc(sizeof(float) * i);
	while (j < i)
	{
		ret->tab[j] = 0;
		j++;
	}
	return (ret);
}

void				ft_sub(t_intab *m1, t_intab *m2, int i)
{
	int		j;
	int		ind;

	ind = 0;
	j = 0;
	while (j < i)
	{
		m1->tab[j] -= m2->tab[j];
		if (m1->tab[j] != 0.000000)
			ind = j + 1;
		j++;
	}
	m1->len = ind;
}
