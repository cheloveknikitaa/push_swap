#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "../libft.h"
# include <stdio.h>

typedef struct s_option
{
	int			error;
	int			flag_minus;
	int			flag_zero;
	int			width;
	int			dot;
	int			precision;
	int			count;
	char		type;
	int			skip;
	int			star_width;
	int			star_precision;
}				t_option;

int		ft_printf(const char *format, ...);
void	init_struct(t_option *options, int len);
void	if_just_dot(t_option *options);
char	*ft_utoa(unsigned int n);
char	*ft_hex(unsigned int num, char x);
char	*ft_ultimate_hex(unsigned long long num, char x);

void	print_num(t_option *options, char *number);
void	print_num2(t_option *options, char *number);
void	print_num3(t_option *options, char *number);

void	pars_flags(char *parsing, t_option *options, va_list ap);
void	pars_width(char *parsing, t_option *options, va_list ap);
void	pars_dot_precision(char *parsing, t_option *options, va_list ap);
void	pars_type(char *parsing, t_option *options, va_list ap);
void	parse_input(char *parsing, t_option *options, va_list ap);

void	reverse(char *s);
void	proc_char(t_option *options, va_list ap);
void	proc_int(t_option *options, va_list ap);
void	proc_percent(t_option *options);
void	proc_pointer(t_option *options, va_list ap);
void	proc_string(t_option *options, va_list ap);
void	proc_uint(t_option *options, va_list ap);
void	proc_hex(t_option *options, va_list ap, char x);
void	proc_notype(t_option *options);
void	proc_n(t_option *options, va_list ap);

#endif