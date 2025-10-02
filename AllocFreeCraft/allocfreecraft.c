#include "allocfreecraft.h"

static t_ptr	*ft_lstlast(t_ptr *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back(t_ptr **lst, t_ptr *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

static t_ptr	*ft_lstnew(void *content)
{
	t_ptr	*node;

	node = malloc(sizeof(t_ptr));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

static void	allocfreecraft_array(t_ptr **alloc_stock, char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		ft_lstadd_back(alloc_stock, ft_lstnew(ptr[i]));
		i++;
	}
	ft_lstadd_back(alloc_stock, ft_lstnew(ptr));
}

void	*allocfreecraft(size_t size, void *ptr, short flag)
{
	static t_ptr	*alloc_stock;
	t_ptr			*tmp;
	void			*alloc;

	alloc = NULL;
	if (flag == 1 && !ptr)
	{
		alloc = malloc(size);
		if (!alloc)
			return (NULL);
		ft_lstadd_back(&alloc_stock, ft_lstnew(alloc));
	}
	else if (flag == 2 && ptr)
		ft_lstadd_back(&alloc_stock, ft_lstnew(ptr));
	else if (flag == 3 && ptr)
		allocfreecraft_array(&alloc_stock, (char **)ptr);
	else if (!flag && !ptr)
	{
		while (alloc_stock)
		{
			tmp = alloc_stock;
			free(alloc_stock->content);
			alloc_stock = alloc_stock->next;
			free(tmp);
		}
	}
	return (alloc);
}
