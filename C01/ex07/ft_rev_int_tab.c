/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelapor <mdelapor@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 20:28:29 by mdelapor          #+#    #+#             */
/*   Updated: 2026/09/30 14:44:48 by mdelapor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_in_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while (i < size / 2)
	{
		swap = tab[i];
		tab[i] = tab[size - i -1];
		tab[size - i - 1] = swap;
		i++;
	}
}
