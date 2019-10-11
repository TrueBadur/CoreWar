/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_build_program.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:54:51 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/03/19 16:54:51 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"

static size_t	ft_get_program(char **program_buffer, const char *filename)
{
	FILE	*program_handle;
	size_t	pr_s;

	if (!(program_handle = fopen(filename, "r")))
	{
		perror("Couldn't find the program file");
		exit(1);
	}
	fseek(program_handle, 0, SEEK_END);
	pr_s = ftell(program_handle);
	rewind(program_handle);
	(*program_buffer) = (char*)malloc(pr_s + 1);
	(*program_buffer)[pr_s] = '\0';
	fread(*program_buffer, sizeof(char), pr_s, program_handle);
	fclose(program_handle);
	return (pr_s);
}

static void		ft_build_err_handle(cl_program pr, cl_device_id dev)
{
	char	*pr_log;
	size_t	log_s;

	clGetProgramBuildInfo(pr, dev, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_s);
	pr_log = (char*)malloc(log_s + 1);
	pr_log[log_s] = '\0';
	clGetProgramBuildInfo(pr, dev, CL_PROGRAM_BUILD_LOG,
			log_s + 1, pr_log, NULL);
	write(1, pr_log, log_s);
	free(pr_log);
	exit(1);
}

cl_program		ft_build_program(cl_context ctx, cl_device_id dev,
		const char *fname)
{
	cl_program	pr;
	size_t		pr_s;
	char		*pr_buf;
	int			err;

	pr_s = ft_get_program(&pr_buf, fname);
	pr = clCreateProgramWithSource(ctx, 1, (const char**)&pr_buf, &pr_s, &err);
	if (err < 0)
	{
		perror("Couldn't create the program");
		exit(1);
	}
	free(pr_buf);
	err = clBuildProgram(pr, 0, NULL, NULL, NULL, NULL);
	if (err < 0)
		ft_build_err_handle(pr, dev);
	return (pr);
}
