/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:23:42 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/02/16 20:23:44 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"

void	ft_ocl_dev_cont_prog(t_ocl *ocl, char *pr_name)
{
	cl_int	err;

	ocl->device = ft_create_device();
	ocl->context = clCreateContext(NULL, 1, &ocl->device, NULL, NULL, &err);
	if (err < 0)
		ft_ocl_err_handler(FT_OCL_CONTEXT_ERR);
	ocl->program = ft_build_program(ocl->context, ocl->device, pr_name);
	ocl->queue = clCreateCommandQueue(ocl->context, ocl->device, 0, &err);
	if (err < 0)
		ft_ocl_err_handler(FT_OCL_QUEUE_ERR);
}
