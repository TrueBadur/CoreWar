/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_time_to_die_nuke.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 18:38:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/11/14 13:42:51 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	show_nuke_top(WINDOW *win)
{
	wprintw(win,
	"\n"
	"\n"
	"                              ,;|^^|;-                              \n"
	"                         ,1C$WWMM0gM&WW@U(-                         \n"
	"                       <XWgqezfnnYnnnfyw#M0h!                       \n"
	"                     vM0HunnnnnYYnYnnnnYnnfeM$~                     \n"
	"              ,;|^<^CQEnnnnYYnjYYYYnnnnYY}tYfqWy`                   \n"
	"          .1PgWQeHm$eiYnYnYYYjnYYYYYYYniJ}YYnYyM$;;;;-              \n"
	"        ;UW@#ynnJJmhiYnnYYYjjYYYYYYYYY}JiYYYjYYu0W0Q@MWRf;          \n"
	"      `z&$ynnnnnn@$nYYYYYYiYYYYYYYYYY]tiYYYYYYYYxMqYnnxwQW5;        \n"
	"     :Q0hnnYYjYYe&xYYYYjiiYYYjYYYYYij{jYYYYYYYjijw&nYYnnny$&]       \n"
	"    ;M$fnnnYYjYYQmYYYYYiiijYYjjjjYiiiijYYYYjYYiijYSnYYnYnYYU&y      \n"
	"    $@fnnYYYYYjjMCYYYYijjjijjjiijiiiiiiYjjjYjijYjiYYYYYYYYYnh&v     \n"
	"   (&znnYYYYYYYj#nYYiijjijiiiiii}iiiiii}iijiijjYjYYYYYYjYnYnnEM,    \n"
	"   X$nnYYYYYYYYYYijiiiiiiiiii}}}}}}}}}}i}}}iiiijjjYYYjiYYzynnn0}    \n"
	"   0EnYYYYYYYjYYjj}}iiii}}}}}t}}}}}}}}}}}{}iiiiiijjjiiYYYzGg5fqq    \n"
	"   &CjYYYYYYYjjjiiii}}}}}}}t{{tt{{{{ttt{{}}t}}}iiiiiijYYYYYfX0$$    \n"
	"   0#ReYYYYYjjjiiii}}{t}tt{J{{{{{{{{{{J{{{tt{t}}}}}iijjjYYYYYz@@`   \n"
	"   RMEYYYYYjji}ii}}}}t{J{JJJJJJJJJJJJ]JJJ{{{{{np}}}iiijjYYYYiYu@2   \n"
	"  \\MyYYYYjjii}i}}}}t{{{PhJJJJ]]]]]]LL]JJJJJJ{P00z}}}iiijjjj}YYYu0n \n"
	" `$EYYYjjjj}inx}}t{{{}hM&Sz]LLLLLLvLLLLL]]{h$&M&QY}}}}iiiiijiYYYeM_ \n"
	" +@YYYYjji}i}HM$#ePh#dQM&&&@#yn{v)vvvL}xCm0&&&&&&@ut}}}}}ijjjijYYSt \n"
	" p#YYYjjiii}z0MMMMM$$gMMMMMMMMMMg@@Q@0MQpXXGMMMMMM0Uit}t}iijjYiYYeq \n"
	" 0hYYYjjiiiP0MMMMM@$gMMMMMMMMM0MMMMMMM0PSX#qRMMMMMMMg#yY}iiiijnhyy@.\n");
}

void	show_nuke_mid(WINDOW *win)
{
	wprintw(win,
	".MyfuYYuh#@MMMMM0RQMMMMMMMMMM0MMMMMMMM0eXmRXOMMMMMMMMMMM@RmdS$g$ChM_\n"
	"`MCh000MMMMMMMMQ$Q0M00MMMMM00MMMMMMMMMMm5pX$0MMMMM00MMMMMMMMM@RQhe0`\n"
	" mXYQMMMMMMMM0$$@$iXM00MMM00MMMMMMMMMMMMM0MMMMM0M00MMMMMMMMM$$Q$YOq \n"
	" +@xzgMMMMM000$MQif}fd0000MMMMMMMM000MMMMMMMM@e{e0MMMMMMM000$0Quz0^ \n"
	"  X$fxm00000@g0p}vY$y(iUR0000000000@@00000gqzv{x)nd0000000g@0XfzQz  \n"
	"  .HQy}fhE5EezJvJv)}q$h{+]xeXG$Qg0@0QRdHhj(LzXQz((viCX$Q$RqeYiU@i   \n"
	"    v$#Cu{JJJYhXqJ)](Y5@Rwzt(1111+++11+]uemgGhJ{J(zqeu{]J{tfU$p|    \n"
	"     `+HQ@$$@@XzJh$g$h((feSg@Q#qXXXqG$ggRHz{+z$0gXnjeRQ$$$Q@h^      \n"
	"        `<$pY{zHQ0Q@005+n(^\\1){iYnnY}L+\\^^]+P000000$ex}y0t;       \n"
	"          <Q}XgggQg@@gg{z5^^^^^^^+^^^^^^^+m1Qgggggg@@X}Re           \n"
	"           U#YEQQggg@Qgh}Q\\~^^^^^d<^^^^^^YG1mgggggQ$hnRH.          \n"
	"           `xQCYCq$@@QOz(@(~~~~~^@)~~t^~~fQ({2#RXCfi2Qt             \n"
	"             ~5QphYtJvJnzQu|||||\\@i||X+||zgXjLL{fCq$x:             \n"
	"               :+z5R$$dCipP!!^!!<@x!!$L!!hhLhEpwyJ|`                \n"
	"                         iX!!U!!rQh!|Q}!!U{                         \n"
	"                         1$!~Q1!1Q5!<Qz!!XL                         \n"
	"                         ^Q^LQx!xQ$+zQ#<!d+                         \n"
	"                    `-!\\1zQC$$$$QQQQQQQQX5e+\\!-                   \n"
	"                 _+tedpeyxn}JLv(++111+++({YuhUXGC(;                 \n"
	"               1XEf}(1)tnxzheEHpXqqqq5PCwPyxiv11JzXH~               \n"
	"              n$z+{h5R$$$$$$$$$#$$$$$2R$$$$$$$SHu(+z$1              \n"
	"             `$2(U$RR$Y<!($!\\$x;+$$EX$e!~$\\!<qGU$#j(UR            \n"
	"              #RxSGJYdP<:\\$:;$L:;RR!rR]:!$<<ymnLH$H}q2             \n"
	"              ;H$$$PY{zUXSR::d+::#m:!$<:!$Ehu{YhR$R$w_              \n");
}

void	show_nuke_bot(WINDOW *win)
{
	wprintw(win,
	"                !{e##m5EeH$:_2<_:52_:$^_!$X5OR$$dh);                \n"
	"                   `;^1Lty$__C\\__UP__m!_!mtr\\|;,                  \n"
	"                         !R__x^__Ch_-5;_;#;                         \n"
	"                         ;R_-Y!--yz--e_-;R;                         \n"
	"                         ;m_,L;,,uf,,z,,;R;                         \n"
	"                         _#_,<_,,Yj,,},,;#;                         \n"
	"                         -#:.;...}t..+..;#;                         \n"
	"                         .S:.....vv.._..;S;                         \n"
	"                         `G;.....((....._U:                         \n"
	"                         `m;`````11`````-h:                         \n"
	"                          d;`````r<`````.w:                         \n"
	"                          O;`````\\^``````e:                        \n"
	"                          O;`````!!``````h:                         \n"
	"                          X:     `.     `X;                         \n"
	"                          q-             H;                         \n"
	"                          X`             h-                         \n"
	"                          ~              <                          \n"
	"                                                                    \n"
	"                                                                    \n"
	"                                                                    \n");
}

void	show_nuke(WINDOW *win)
{
	show_nuke_top(win);
	show_nuke_mid(win);
	show_nuke_bot(win);
}
