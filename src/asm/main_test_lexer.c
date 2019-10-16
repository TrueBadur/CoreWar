/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:39:02 by jleann            #+#    #+#             */
/*   Updated: 2019/10/16 17:06:18 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "read_args.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_lexdata	*lexdata;
	int rls;

	(void)argc;
	rls = run_lexer (argv[1], &lexdata);
	ft_printf("rls= %d\n", rls);
    return (rls);
}
