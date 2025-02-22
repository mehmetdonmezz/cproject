/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdonmez <mdonmez@student.42kocaeli.com.tr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:15:10 by ahtuncay          #+#    #+#             */
/*   Updated: 2023/02/17 15:18:02 by ahtuncay         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	while(size >= 0)
	{
		i = 0;
		while(i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
		size--;
	}
}

int main()
{
    int arr[] = {5, 3, 8, 1, 2};
    int size = 5;
    
    ft_sort_int_tab(arr, size);
    
    int i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
    
    return 0;
}
