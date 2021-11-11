/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbro_rtn_neg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:08:03 by pirichar          #+#    #+#             */
/*   Updated: 2021/11/10 12:52:50 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putcharo_rtn(char c, int *sum);

void	ft_putnbro_rtn_neg(int nb, int *sum)
{
	long	n;

	n = nb;
	if (n < 0 )
	{
		ft_putcharo_rtn('-', sum);
		ft_putnbro_rtn_neg(-n, sum);
	}
	else if (n > 9)
	{
		ft_putnbro_rtn_neg(n / 10, sum);
		ft_putnbro_rtn_neg(n % 10, sum);
	}
	else
		ft_putcharo_rtn(n + '0', sum);
}

void	ft_putcharo_rtn(char c, int *sum)
{
	write(1, &c, 1);
	(*sum)++;
}