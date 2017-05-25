/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhervy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:57:09 by dhervy            #+#    #+#             */
/*   Updated: 2015/11/28 21:34:01 by dhervy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *s1, const char *s2)
{
	int d;
	int s;

	d = 0;
	s = 0;
	while (s1[d] != '\0')
		d++;
	while (s2[s] != '\0')
	{
		s1[d] = s2[s];
		d++;
		s++;
	}
	s1[d] = '\0';
	return (s1);
}