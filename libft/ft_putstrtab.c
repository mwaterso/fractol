/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstrtab.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: agiordan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/13 18:56:42 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/13 19:15:36 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab(char **tab, size_t length)
{
	size_t i;

	i = -1;
	while (++i < length)
		ft_putendl(tab[i]);
}
