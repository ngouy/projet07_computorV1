/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basics.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 14:59:09 by ngouy             #+#    #+#             */
/*   Updated: 2015/04/04 15:21:13 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/computorv1.h"

int					ft_found(char c, char cc, char *str)
{
	int		ret;

	ret = 0;
	while (str[ret] && str[ret] != c && str[ret] != cc)
	{
		if (str[ret] == '=')
			return (-ret);
		ret++;
	}
	return (ret);
}

int					ft_len_nb(float i)
{
	int		ret;

	ret = 0;
	while (i - (int)i != 0 && ret < 6)
	{
		ret++;
		i *= 10;
	}
	return (ret);
}

void				ft_putfloat(float i)
{
	int		virg;
	int		z;

	virg = (i - (int)i) * 1000000;
	z = 6 - ft_len_nb(virg);
	while (virg % 10 == 0 && virg)
		virg /= 10;
	if ((int)i == 0 && i < 0 && virg)
		ft_putchar('-');
	ft_putnbr((int)i);
	if (virg)
	{
		ft_putchar('.');
		while (z--)
			ft_putchar('0');
		ft_putnbr(virg < 0 ? -virg : virg);
	}
}

int					ft_found_nb(char *str)
{
	int		ret;

	ret = 0;
	while (!ft_isdigit(str[ret]))
		ret++;
	return (ret);
}

float				ft_sqrt(float a)
{
	float		ret;
	float		p;
	int			i;

	i = -50000;
	ret = a / 2.0;
	p = ret * ret - a;
	while (ABS(p) > 0.000001 && i)
	{
		ret = 0.5 * (ret + a / ret);
		p = ret * ret - a;
		i++;
	}
	return (ret);
}
