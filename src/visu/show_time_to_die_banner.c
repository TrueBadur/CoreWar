/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_time_to_die_banner.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	show_time_banner(WINDOW *win)
{
	wprintw(win,
	" /$$$$$$$$ /$$                                 /$$                  "
	"   /$$$$$$$  /$$          \n"
	"|__  $$__/|__/                                | $$                  "
	"  | $$__  $$|__/          \n"
	"   | $$    /$$ /$$$$$$/$$$$   /$$$$$$        /$$$$$$    /$$$$$$     "
	"  | $$  \\ $$ /$$  /$$$$$$ \n"
	"   | $$   | $$| $$_  $$_  $$ /$$__  $$      |_  $$_/   /$$__  $$    "
	"  | $$  | $$| $$ /$$__  $$\n"
	"   | $$   | $$| $$ \\ $$ \\ $$| $$$$$$$$        | $$    | $$  \\ $$ "
	"     | $$  | $$| $$| $$$$$$$$\n"
	"   | $$   | $$| $$ | $$ | $$| $$_____/        | $$ /$$| $$  | $$    "
	"  | $$  | $$| $$| $$_____/\n"
	"   | $$   | $$| $$ | $$ | $$|  $$$$$$$        |  $$$$/|  $$$$$$/    "
	"  | $$$$$$$/| $$|  $$$$$$$\n"
	"   |__/   |__/|__/ |__/ |__/ \\_______/         \\___/   \\______/  "
	"     |_______/ |__/ \\_______/\n\n");
}
