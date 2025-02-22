void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	swap;

	i = 0;
	while(i < size /2)
	{
		swap = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = swap;
		i++;
	}
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = 6;
    int i = 0;

    ft_rev_int_tab(arr, size);

    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");

    return 0;
}
