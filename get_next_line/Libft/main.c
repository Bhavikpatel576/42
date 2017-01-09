/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:35:33 by bpatel            #+#    #+#             */
/*   Updated: 2016/11/29 15:43:20 by bpatel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(void)
{
	//char *test_function;
	//char test_function1[] = "  once two three four five";

	char array[4] = {'1','2','3','4'};

	/*test the swap function*/

	printf("%d\n", array[0]);
	printf("%d\n", array[1]);
	printf("%d\n", array[2]);
	printf("%d\n", array[3]);

	ft_swap(&array[0], &array[1]);

	printf("%d\n", array[0]);
	printf("%d\n", array[1]);
	printf("%d\n", array[2]);
	printf("%d\n", array[3]);

	/*test the countl function*/


	/*test the reverse_bits*/


	/*test the swap bits*/


	/*print last word*/
}
