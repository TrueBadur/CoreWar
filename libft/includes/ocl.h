/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:26:24 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/02/16 20:26:27 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OCL_H
# define FT_OCL_H
# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif
# include <stdio.h>
# include <unistd.h>
# include "../libft.h"
# define FT_OCL_CONTEXT_ERR "Couldn't create a context"
# define FT_OCL_BUFFER_ERR "Couldn't create a buffer"
# define FT_OCL_QUEUE_ERR "Couldn't create a command queue"
# define FT_OCL_KERNEL_ERR "Couldn't create a kernel"
# define FT_OCL_KERNEL_ARG_ERR "Couldn't create a kernel argument"
# define FT_OCL_ENQUEUE_KERNEL_ERR "Couldn't enqueue the kernel"
# define FT_OCL_READ_BUF_ERR "Couldn't read the buffer"

typedef struct	s_ocl
{
	cl_context			context;
	cl_device_id		device;
	cl_program			program;
	cl_kernel			*kern;
	cl_command_queue	queue;
}				t_ocl;

cl_device_id	ft_create_device(void);
cl_program		ft_build_program(cl_context ctx, cl_device_id dev,
		const char *fname);
void			ft_ocl_err_handler(const char *message);
void			ft_ocl_dev_cont_prog(t_ocl *ocl, char *pr_name);
#endif
