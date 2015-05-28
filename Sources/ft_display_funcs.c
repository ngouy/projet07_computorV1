/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 15:17:22 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/28 16:28:14 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/computorv1.h"

void				ft_putab(float *tab, int i)
{
	int		j;

	printf(P5, "la forme reduite de ce polynome est la suivante :");
	j = 0;
	if (i == 0 && tab[j] == 0.000000)
		printf("\033[36;1m0\033[0m * \
\033[34;1mX^0\033[0m \033[41m=\033[0m 0\n");
	else
	{
		while (j < i)
		{
			if (j == 0 && tab[j] < 0)
				printf("- ");
			if (tab[j] == 0.000000)
				printf("\033[36;1m0\033[0m");
			else
				printf("\033[36;1m%.*f\033[0m", ft_len_nb(tab[j]), ABS(tab[j]));
			printf(" * \033[34;1mX^%d\033[0m", j);
			j++;
			if (j != i)
				printf(tab[j] >= 0 ? " + " : " - ");
		}
		printf(" \033[41m=\033[0m 0\n\n");
	}
}

int					ft_check_spec(float j, int i)
{
	if (i == 0 && j != 0.000000)
		return (printf(" et il n'y a aucune solution\n"));
	else if (i == 0 && j == 0.000000)
		return (printf(" et l'ensemble des Reels sont solutions\n"));
	return (0);
}

int					ft_solve_1(float a, float b)
{
	if (b == 0)
		printf(" : la solution est donc X = \033[32;4m0\n\n");
	else
		printf(" : la solution est donc X = \033[32;4m%.*f\n\n",
				ft_len_nb(-b / a), -b / a);
	return (1);
}

void				ft_put_im(float r, float i)
{
	if (r != 0.000000)
		printf("%.*f", ft_len_nb(r), r);
	if (i != 0.000000)
	{
		if (r && i >= 0)
			printf(" + ");
		else if (r)
			printf(" - ");
		if (ABS(i) == 1)
			printf("i");
		else
			printf("%.*fi", ft_len_nb(i), ABS(i));
	}
}

void				ft_im(float a, float b, float c, float d)
{
	float		x1_i;
	float		x1_r;
	float		x2_i;
	float		x2_r;

	(void)c;
	printf(" : delta = %.*f, %s", ft_len_nb(d), d, P12);
	x1_r = -b / 2.0 * a;
	x2_r = -b / 2.0 * a;
	x1_i = (0 - ft_sqrt(-d)) / (2.0 * a);
	x2_i = 0 + ft_sqrt(-d) / (2.0 * a);
	printf(P13);
	ft_put_im(x1_r, x1_i);
	printf(P14);
	ft_put_im(x2_r, x2_i);
	printf("\n");
}
