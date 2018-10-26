#include "ft_printf.h"

void	initbuffer(t_buffer *buffer)
{
	buffer->buf_charsize = 1;
	if (!(buffer->chr = ft_memalloc(buffer->buf_charsize)))
		return ;
	buffer->buf_usedchars = 0;
}

int		checkbuffer(t_buffer *buffer, int size)
{
	if  ((buffer->buf_usedchars + size) <= buffer->buf_charsize)
		return (buffer->buf_usedchars);
    else if (((buffer->buf_usedchars + size) > buffer->buf_charsize) && size > buffer->buf_charsize)
    {
    	write(1, buffer->chr, buffer->buf_usedchars);
		free(buffer->chr);
		if (size > buffer->buf_charsize)
		{
			buffer->chr = ft_strnew(sizeof(char) * size);
			buffer->buf_charsize = size;
		}
    	else
			buffer->chr = ft_strnew(sizeof(char) * buffer->buf_charsize);
    }
	else if ((buffer->buf_usedchars + size > buffer->buf_charsize) && size <= buffer->buf_charsize)
	{
		write(1, buffer->chr, buffer->buf_usedchars);
		buffer->chr = (char*)ft_memset(buffer->chr, '\0', buffer->buf_usedchars);
	}
	buffer->buf_usedchars = 0;
	return (0);
}

int		ft_savechar(t_buffer *buffer, char s, int repeat)
{
	int		pos;
	int		ret;

	if (!s)
		return (0);
	if (repeat == 0)
		return (0);
	pos = checkbuffer(buffer, repeat);
	ret = repeat;
	while (repeat > 0)
	{
		buffer->chr[pos] = s;
		buffer->buf_usedchars += 1;
		pos++;
		repeat--;
	}
	return (ret);
}

int		ft_savestr(t_buffer *buffer, char *s)
{
	int		pos;
	int		i;

	i = 0;
	if (!s)
		return (ft_savestr(buffer, "(null)"));
	pos = checkbuffer(buffer, (int)ft_strlen(s));
	while (s[i] != '\0')
	{
		buffer->chr[pos] = s[i];
		i++;
		pos++;
		buffer->buf_usedchars += 1;
	}
	return (i);
}
