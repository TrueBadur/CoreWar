//
// Created by Jasper Leann on 11/10/2019.
//

#include "writer.h"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <libft.h>
#include <errno.h>
#include <stdint.h>

void    write_uint16_to_bin(int fd, uint16_t num)
{
    uint8_t buff[2];

    buff[1] = ((uint8_t *)(&num))[0];
    buff[0] = ((uint8_t *)(&num))[1];
    write(fd, buff, 2);
}

void    write_uint32_to_bin(int fd, uint32_t num)
{
    write_uint16_to_bin(fd, ((uint16_t *)(&num))[1]);
    write_uint16_to_bin(fd, ((uint16_t *)(&num))[0]);
}

int     create_new_file(const char *src_path)
{
    char    *bin_path;
    char    *dot;
    int     res;

    dot = ft_strrchr(src_path, '.');
    if (dot && ft_strcmp(dot, "s") == 0)
    {
        bin_path = malloc(ft_strlen(src_path) + 3);
        ft_strcpy(bin_path, src_path);
        ft_strcpy(bin_path + ft_strlen(src_path) - 1, "cor");
    }
    else
    {
        bin_path = malloc(ft_strlen(src_path) + 5);
        ft_strcpy(bin_path, src_path);
        ft_strcpy(bin_path + ft_strlen(src_path), ".cor");
    }
    res = (open(bin_path, O_CREAT | O_WRONLY, S_IRWXU));
    free(bin_path);
    return (res);
}

//void    write_champ_data(t_champdata *data)
//{
//    int fd;
//    fd = create_new_file(data->path);
//    write_uint32_to_bin(fd,0xea83f3);
//    write(fd, data->name, 128);
//    write(fd, "\0\0\0\0", 4);
//    write_uint32_to_bin(fd,data->exec_size);
//    write(fd, data->comment, 2048);
//    write(fd, "\0\0\0\0", 4);
//    write(fd, data->exec_code, data->exec_size);
//    close(fd);
//}

void	write_champ(t_champdata *champdata, t_argdata *args)
{
    (void)champdata;
    (void)args;
}
