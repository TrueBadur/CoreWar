//
// Created by Jasper Leann on 11/10/2019.
//

#include <libstd.h>
#include "lexer.h"

int		get_fd(char *fname)
{
	int fd;

	if (fname && (fd = open(fname, O_RDONLY)) > 0)
		return (fd);
	return (0);
}

void		init_setup(t_lexdata *setup)
{
	setup->debug_fd = 1;
	setup->debug_comment = 1;
	setup->debug_name = 1;
}

int		check_comment(t_lexdata *setup, char *line, char *cur) // with_free
{
	if (*cur == COMMENT_CHAR)
	{
		if (setup->debug_comment)
			ft_printf("\t ✂️  ✂️  ✂️  ✂️  COMMENT_CHAR=%s\n", cur);
		free(line);
		return (1);
	}
	return (0);
}

int		end_line(char *line, char *cur)
{
	if (*cur == '\0')
	{
		free(line);
		return (1);
	}
	return (0);
}

/*
** 0  - is_start
** -1 - fail char
** 1  - skip char
** 2  - skip line
*/

int		start_name(t_lexdata *setup, char *line, char *cur, char **start)
{
	//ft_printf("\t*cur=%c\n", *cur);
	if (*cur == ARG_CMD_START)
	{
		*start = cur;
		return (0);
	}
	else if (*cur == ' ') 						// char allow to skip
		return (1);
	else if (check_comment(setup, line, cur)) 	// with_free
		return (2);
	else if (end_line(line, cur)) 				// with_free
		return (2);
	else
	{
		free(line);
		return (-1);
	}
}

void 	init_stack_list(t_list *lst)
{
	lst->begin = NULL;
	lst->end = NULL;
	lst->len = 0;
}

int		short_arg_cmd_name(t_lexdata *setup, char *line)
{
	int		idx;
	int		start;
	int		end;
	char	*out;

	start = -1;
	end = -1;
	idx = -1;
	while (line[++idx])
	{
		if (start == -1 && line[idx] == ARG_CMD_START)
			start = idx;
		else if (end == -1 && line[idx] == ARG_CMD_START)
			end = idx;
		else if (start != -1 && end != -1 && line[idx] == '#')
		{
			if (setup->debug_comment)
				ft_printf("\t ✂️  ✂️  ✂️  ✂️  COMMENT_CHAR=%s\n", line + idx);
			break ;
		}
		else if (start != -1 && end != -1 && line[idx] != ' ') //allow char
		{
			return (ERROR_LEX_NAME_END_INVALIDE);
		}
	}
	out = ft_strnew(end - start - 1);
	if (!out)
		return (ERROR_LEX_MALLOC_STR);
	ft_strncpy(out, line + start + 1, end - start - 1);
	setup->champ_name = out;
	free(line);
	return (0);
}

int		get_cmd_name(t_lexdata *setup, char *start, t_list *lines)
{
	t_list_node	*node;
	int len;
	int tmp;
	int idx;
	char *line;
	char *out;
	(void)setup;

	//len_first
	len = 0;
	len += ft_strlen(start + 1) + 1;
	node = lines->begin;
	node->content_size = len;
	ft_printf(">>>>>>>> tmp = %d\n", len);
	
	//len_mid
	node = node->next;
	while (node->next != NULL)
	{
		tmp = ft_strlen((char *)(node->content));
		node->content_size = tmp;
		len += tmp + 1;
		node = node->next;
		ft_printf(">>>>>>>> tmp = %d\n", tmp);
	}

	// len_of_last
	idx = 0;
	line = (char *)(node->content);
	while (*(line + idx) != ARG_CMD_START)
		++idx;
	len += idx;

	ft_printf(">>>>>>>> out_len = %d\n", len);
	// malloc
	out = ft_strnew(len);
	if (!out)
		return (ERROR_LEX_MALLOC_STR);
	
	//copy_first
	len = 0;
	node = lines->begin;
	ft_strncpy(out, start + 1, node->content_size);
	len += node->content_size;
	out[len] = '\n';
	ft_printf(">>>>>>>> out_len = %d\n", len);
	//copy_mid
	while (node->next != NULL)
	{
		node = node->next;
		ft_strncpy(out + len + 1, (char *)(node->content), node->content_size);
		len += node->content_size;
		out[len] = '\n';
	}

	//copy_last
	ft_strncpy(out + len + 1, (char *)(node->content), idx);
	if (setup->debug_name)
			ft_printf("\t 🗣  🗣️  🗣️  🗣️  NAME=%s\n", out);
	return (0);
}

int		process_cmd_name(t_lexdata *setup, char *line, char *cur, int fd)
{
	t_list		lines;
	t_list_node	*node;
	char		*start;
	int			rls;
	char		*gnl;

	init_stack_list(&lines);
	start = NULL;
	gnl = line;
	// search START
	while (start == NULL)
	{
		rls = start_name(setup, line, cur, &start);
		if (rls == 0 || rls == 1)
			cur += 1;
		else if (rls == 2)
		{
			if (get_next_line(fd, &line) != 1)
				return (ERROR_LEX_NAME_START);
		}
		else if (rls == -1)
			return (ERROR_LEX_NAME_START);
	}

	// search END
	while (*cur != ARG_CMD_START)
	{
		if (*cur != '\0')
		{
			cur += 1;
			continue ;
		}
		node = ft_lstnew_node(NULL, 0);
		node->content = line;
		ft_lstaddend(&lines, node);
		if (get_next_line(fd, &line) != 1)
			return (ERROR_LEX_NAME_START);
		cur = line;
	}
	// check END
	cur += 1;
	while (*cur != '\0')
	{
		if (*cur == '#')
		{
			if (setup->debug_comment)
				ft_printf("\t ✂️  ✂️  ✂️  ✂️  COMMENT_CHAR=%s\n", cur);
			break ;
		}
		else if (*cur != ' ') //allow char
		{
			return (ERROR_LEX_NAME_END_INVALIDE);
		}
		cur += 1;
	}

	if (lines.len != 0)
	{
		node = ft_lstnew_node(NULL, 0);
		node->content = line;
		ft_lstaddend(&lines, node);
	}
	ft_printf(">>>>>>>> num_node = %d\n", lines.len);
	// search CALC
	if (lines.len == 0)
	{
		if ((rls = short_arg_cmd_name(setup, line)))
		{
			return (rls);
			free(line);
		}
		if (setup->debug_name)
			ft_printf("\t 🗣  🗣️  🗣️  🗣️  NAME=%s\n", setup->champ_name);
		return (0);
	}
	else
	{
		get_cmd_name(setup, start, &lines);
	}
	

	return (0);
}


int		process_cmd(t_lexdata *setup, char *line, int fd)
{
	char	*cur;

	if ((cur = ft_strstr(line, NAME_CMD_STRING)))
	{
		//ft_printf("process_cmd_name START\n");
		process_cmd_name(setup, line, cur + ft_strlen(NAME_CMD_STRING), fd);
		return (0);
	}
	else if ((cur = ft_strstr(line, COMMENT_CMD_STRING)))
	{
		return (0);
	}
	return (1);
}

int		check_line(t_lexdata *setup, char *line, int fd)
{
	int		idx;
	char	*cur;

	idx = -1;
	while (line[++idx])
	{
		cur = idx + line;
		if (*cur == CMD_START)
		{
			//ft_printf("CMD_START\n");
			process_cmd(setup, line, fd);
		}
		else if (check_comment(setup, line, cur))	// with_free
			return (0);
	}
	return (0);
}




t_lexdata	*run_lexer(char *fname)
{
	t_lexdata		setup;
	char			*line;
	int 			fd;
	int				rlt;

	if ((fd = get_fd(fname)) == 0)
		return (NULL);
	init_setup(&setup);
	if (setup.debug_fd)
		ft_printf("lexer_ds = %d\n", fd);

	while ((rlt = get_next_line(fd, &line)))
	{
		ft_printf("gnl = %s\n", line);
		check_line(&setup, line, fd);
	}
	if (rlt == -1) //TODO error gnl
		return (NULL);

	return (NULL);
}
void		free_lexdata(t_lexdata *data)
{
	(void)data;
}