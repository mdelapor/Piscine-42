/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelapor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 14:35:12 by mdelapor          #+#    #+#             */
/*   Updated: 2026/09/16 19:44:55 by mdelapor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a / *b;
	*b = *a % *b;
	*a = c;
}
/*#include <stdio.h>
int	main()
{
	
	int	a = 17;
	int	b = 5;
	
	int	*ptr_a = &a;
	int	*ptr_b = &b;
	ft_ultimate_div_mod(ptr_a, ptr_b);
	printf("a / b = %i\na mod b = %i", a, b);
}*/
