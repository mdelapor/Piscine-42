/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achtouro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 12:49:49 by achtouro          #+#    #+#             */
/*   Updated: 2026/09/12 15:34:52 by dpricope         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
int verb = 0;

void	ft_putchar(char c);

int	is_corner(int i, int j, int n, int m)
{
	if(verb) printf("\n checking corner\n");
	int is_corner = 0;

	if (!i && !j) 
		is_corner = 1;
	
	if ((i == n-1) && (j == m-1))
		if (n != 1)
			is_corner = 1;
	return is_corner;
}

int is_opposite_corner(int i, int j, int n, int m)
{
	if(verb) printf("\n checking opposite corner\n");
	int cond = 0;

	if ((i == 0) && (j == m-1))
		cond = 1;

	if ((i == n-1) && (j==0))
		if (m != 1)		
			cond = 1;
	return cond;
}

int is_top(int i, int j, int n, int m)
{
	if(verb) printf("\n checking top\n");
	int cond = 0;
	if ((i == 0) && (j>0) && (j < m-1))
		cond = 1;
	if ((i == n-1) && (j>0) && (j < m-1))
		cond = 1;
	return cond;
}

int is_side(int i, int j, int n, int m)
{
	if(verb) printf("\n checking side\n");
	int cond = 0;
	if ((j == 0) && (i>=1) && (i<n-1))
		cond = 1;
	if ((j == m-1) && (i>=1) && (i<n-1))
		cond = 1;
	return cond;
}

void	print_cell(int i, int j, int n, int m)
{
	if(verb) printf("\nchecking i=%d j=%d n=%d m=%d \n", i, j, n, m);
	if (is_corner(i, j, n, m))
		{ ft_putchar('/'); return; }
    
	if (is_opposite_corner(i, j, n, m))
        { ft_putchar('\\'); return; }	
	
	if (is_top(i, j, n, m))
		{ ft_putchar('-'); return; }
	
	if (is_side(i, j, n, m))
		{ ft_putchar('|'); return; }

	ft_putchar('0');	
}

void	rush(int m, int n)
{
	printf("\n\nprinting (%d,%d)\n", n, m);
	int	i;
	int	j;

	if (m <= 0 || n <= 0)
		return ;
	i = 0;
	while (i <= (n -1))
	{
		j = 0;
		while (j <= (m - 1))
		{
			print_cell(i, j, n, m);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}
