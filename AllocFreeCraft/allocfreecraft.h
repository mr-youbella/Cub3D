#ifndef ALLOCFREECRAFT_H
# define ALLOCFREECRAFT_H

# include <stdlib.h>

void	*allocfreecraft(size_t size, void *ptr, short flag);

typedef struct s_ptr
{
	void			*content;
	struct s_ptr	*next;
}	t_ptr;

#endif
