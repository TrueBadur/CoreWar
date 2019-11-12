/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/01 18:38:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		game_set_job_param(t_stats *st, int from_user)
{
	if (from_user != 'f' && from_user != 'r'
		&& from_user != 'q' && from_user != 'w'
		&& from_user != 'e')
		return (0);

	if (from_user == 'f')
		st->rate -= 1000;
	else if (from_user == 'r')
		st->rate += 1000;
	if (st->rate < 0)
		st->rate = 0;
	if (st->rate > 1000000)
		st->rate = 1000000;
	if (from_user == 'q')
		st->game_mod = G_MOD_PAUSE_ALL;
	if (from_user == 'w')
		st->game_mod = G_MOD_PAUSE_SELECT;
	if (from_user == 'e')
		st->game_mod = G_MOD_NO_PAUSE;
	return (1);
}

int		game_set_param(int from_user)
{
	t_stats *st;

	st = get_stats();
	return (game_set_job_param(st, from_user));
}

void	rate_control(t_stats *st)
{
	int 	cmd;

	cbreak();
	nodelay(stdscr, TRUE);
	cmd = getch();
	if(game_set_job_param(st, cmd))
		update_side_cntr();
	nodelay(stdscr, FALSE);
}

void	pause_or_wait_mem_change(t_stats *st)
{
	int from_user;

	if (st->game_mod == G_MOD_PAUSE_ALL)
	{
		nodelay(stdscr, FALSE);
		from_user = getchar();
		if(game_set_job_param(st, from_user))
			update_side_cntr();
	}
	else
	{
		rate_control(st);
		usleep(st->rate);
	}
}

void	pause_or_wait_reshow(t_stats *st)
{
	int from_user;

	if (st->game_mod != G_MOD_NO_PAUSE)
	{
		nodelay(stdscr, FALSE);
		from_user = getchar();
		if(game_set_job_param(st, from_user))
			update_side_cntr();
	}
	else
	{
		rate_control(st);
		usleep(st->rate);
	}
}

/*
void	pause_or_wait(t_stats *st)
{
	pause_or_wait_mem_change(st);
}
*/