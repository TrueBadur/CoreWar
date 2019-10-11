/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_create_device.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehugh-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:51:59 by ehugh-be          #+#    #+#             */
/*   Updated: 2019/03/19 16:51:59 by ehugh-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ocl.h"

cl_device_id	ft_create_device(void)
{
	cl_platform_id	platform;
	cl_device_id	dev;
	int				err;

	err = clGetPlatformIDs(1, &platform, NULL);
	if (err < 0)
	{
		perror("Couldn't identify a platform");
		exit(1);
	}
	err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &dev, NULL);
	if (err == CL_DEVICE_NOT_FOUND)
		err = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &dev, NULL);
	if (err < 0)
	{
		perror("Couldn't access any devices");
		exit(1);
	}
	return (dev);
}
