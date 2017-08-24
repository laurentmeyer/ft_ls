#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_vfprintf(FILE * stream, const char * format, va_list ap)
{
	char	*str;
	int		ret;

	if ((ret = ft_vasprintf(&str, format, ap)) == ERR)
		return (ERR);
	write(stream, str, ret);
	free(str);
	return (ret);
}

int		ft_fprintf(FILE * stream, const char * format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vfprintf(stream, format, ap);
	va_end(ap);
	return (ret);
}
