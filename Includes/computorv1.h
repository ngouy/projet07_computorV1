/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngouy <ngouy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 08:01:32 by ngouy             #+#    #+#             */
/*   Updated: 2015/05/28 17:39:09 by ngouy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H

# define COMPUTORV1_H
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include <stdio.h>

/*
** typedef
*/

typedef struct		s_intab
{
	float			*tab;
	int				len;
}					t_intab;

/*
** defines
*/
# define P1 " : La resolution de ce genre de polynome n'est pas encore"
# define P2 " prise en compte\n"
# define P3 "\033[31;1mCeci n'est \033[4mpas\033[0m\033[31;1m un polynome "
# define P4 "ou n'as pas besoin d'etre resolu\n"
# define P5 "\n\033[32m%s\033[00m\n"
# define P6 " : delta = 0, il y a une seule solution dans R qui est :"
# define P7(a) ft_len_nb(a), a
# define P8 "\n\t- \033[35;1mx_0\033[0m = %.*f\n"
# define P9 " il y a donc deux solutions dans R qui sont :"
# define P10 "\n\t- \033[35;1mx_1\033[0m = %.*f\n"
# define P11 "\t- \033[35;1mx_2\033[0m = %.*f\n"
# define P12 " il y a donc deux solutions dans C qui sont :"
# define P13 "\n\t- \033[35;1mx_1\033[0m = "
# define P14 "\n\t- \033[35;1mx_2\033[0m = "
# define ABS(a) (a > 0 ? a : -a)

/*
** Prototypes
*/

/*
** ft_basics.c
*/

int					ft_found(char c, char cc, char *str);
int					ft_len_nb(float i);
void				ft_putfloat(float i);
int					ft_found_nb(char *str);
float				ft_sqrt(float a);

/*
** ft_init.c
*/

int					get_max_deg(char *str);
t_intab				*ft_init_m(char *str, int i);
void				ft_sub(t_intab *m1, t_intab *m2, int i);
/*
** ft_display_func.c
*/

void				ft_putab(float *tab, int i);
int					ft_check_spec(float j, int i);
int					ft_solve_1(float a, float b);
void				ft_put_im(float r, float i);
void				ft_im(float a, float b, float c, float d);

/*
** computorv1.c
*/

int					ft_solve_2(float a, float b, float c);
void				ft_put_solutions(t_intab *m, int i);
t_intab				*ft_membre_resultat(char *str);

/*
** parsing, parsing aux
*/

int					ft_swap_space(char *str, int *cpt, int flagu);
int					ft_final(t_intab *m, float num, int p);
void				ft_put_error(char *str, int *cpt);
int					ft_get_operator(int ind, int *cpt, char *str);
void				ft_parse(t_intab *m, char *str, int i);
int					ft_swap_numbr(char *str, int *cpt, float *num);
int					ft_get_operation(int sign, t_intab *m, char *str, int *cpt);
int					ft_aux1(char *str, int *cpt, t_intab *m, float *num);
int					ft_aux2(char *str, int *cpt, t_intab *m, float num);
int					ft_blk(char *str);
#endif
