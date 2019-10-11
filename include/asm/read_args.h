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

#define USAGE "SOME USAGE" // TODO: Rewrite
#define OUTPUT_FNAME_EXPECTED_ERR "Output filename expected!"
#define INCOMPATIBLE_ARG_COMB_ERR "Incompatible arguments combination!"
#define NO_FILE_PROVIDED_ERR "No file provided!"
#define INVALID_FILE_EXT_ERR "Invalid file extension"


typedef struct 	s_flag
{
	int	ftype:1;
	int	fassemble:1;
	int	fdisassemble:1;
}				t_flag;

typedef struct	s_argdata
{
	char	*fname;
	char	*ofname;
	t_flag	flags;
}				t_argdata;

t_argdata	*read_args(int argc, char **argv);

#endif
