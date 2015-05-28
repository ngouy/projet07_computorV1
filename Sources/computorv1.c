/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 08:02:56 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/28 17:41:58 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../Includes/computorv1.h"

int					ft_solve_2(float a, float b, float c)
{
	float		d;
	float		x1;
	float		x2;

	d = b * b - 4 * a * c;
	if (a == 0)
		return (ft_solve_1(b, c));
	if (d == 0 && printf(P6))
		return (printf(P8, P7(-b / (2.0 * a))));
	else if (d > 0 && printf(" : delta = %.*f, %s", ft_len_nb(d), d, P9))
	{
		x1 = (-b - ft_sqrt(d)) / (2.0 * a);
		x2 = (-b + ft_sqrt(d)) / (2.0 * a);
		x2 = x2 == -0.000000 ? 0 : x2;
		x1 = x1 == -0.000000 ? 0 : x1;
		printf(P10, ft_len_nb(x1), x1);
		printf(P11, ft_len_nb(x2), x2);
	}
	else
		ft_im(a, b, c, d);
	return (1);
}

void				ft_put_solutions(t_intab *m, int i)
{
	if (i != 0)
		i--;
	printf("\033[4mCe polynome est de degre\033[0m = \033[47;30m%d\033[0m",
			i);
	if (i >= 3 && printf(P1) && printf(P2))
		return ;
	else
	{
		if (ft_check_spec(m->tab[0], i))
			return ;
		if (i == 2 && ft_solve_2(m->tab[2], m->tab[1], m->tab[0]))
			return ;
		ft_solve_1(m->tab[1], m->tab[0]);
	}
}

t_intab				*ft_membre_resultat(char *str)
{
	t_intab	*m1;
	t_intab	*m2;
	int		i;

	i = 0;
	m1 = ft_init_m(str, -1);
	m2 = ft_init_m(NULL, m1->len);
	if (!ft_strchr(str, '=') && printf(P3) && printf("\n"))
		exit(0);
	ft_parse(m1, str, 1);
	ft_parse(m2, str + ft_found('=', 0, str) + 1, 0);
	ft_sub(m1, m2, m2->len);
	ft_putab(m1->tab, m1->len);
	ft_put_solutions(m1, m1->len);
	return (m1);
}

int					main(int argc, char **argv)
{
	t_intab	*mr;

	if ((argc == 1 || (!ft_strchr(argv[1], 'X') && !ft_strchr(argv[1], 'x')))
			&& printf(P3))
		return (printf(P4));
	mr = ft_membre_resultat(argv[1]);
	return (0);
}
