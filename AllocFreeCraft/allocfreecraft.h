/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocfreecraft.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkannouf <wkannouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:46:28 by wkannouf          #+#    #+#             */
/*   Updated: 2025/10/05 18:46:31 by wkannouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
