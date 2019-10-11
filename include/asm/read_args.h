/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleann <jleann@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/06/19 20:08:25 by jleann           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef READ_ARGS_H
# define READ_ARGS_H

typedef struct 	s_flag
{
	int	ftype:1;
	int	fassemble:1;
	int	fdisassemble:1;
}				t_flag;

typedef struct	s_argdata
{
	char	*fname;
	char	*cfname;
	char	*ofname;
	t_flag	flags;
}				t_argdata;

t_argdata	*read_args(int argc, char **argv);

#endif
