#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ft_printf.h"

void					ft_process_flags(const char *fmt, interface *fsi);
int						ft_process_fmt(const char *fmt, interface *fsi);
interface				*ft_create_interface(void);
void					ft_destroy_interface(interface *fsi);
printlst				*ft_create_printlist(void);
void					ft_destroy_printlist(printlst *prnt);
unsigned int			ft_fmt_fwd(int arg);

int						main(void)
{
		//char *fmt = "%0+-20.4hhld";
;
		ft_printf("Test: %s\n", "passed");
		/*
		printf("Format: %s\n", fmt);
		if (ft_process_fmt(fmt, fsi))
				printf("Format specifier isn't valid\n");
		else
		{
				printf(" Type: %u\n", fsi->type);
				printf(" Flag: %u\n", fsi->typeflag);
				printf("Field: %d\n", fsi->field);
				printf(" Prec: %d\n", fsi->prec);
				printf(" Zero: %u\n", fsi->zero);
				printf(" Plus: %u\n", fsi->plus);
				printf(" Hash: %u\n", fsi->hash);
				printf("Space: %u\n", fsi->space);
				printf("  Len: %u\n", fsi->fmtlen);
		}
		*/
		return (0);
}

int						ft_printf(const char *fmt, ...)
{
		va_list 	ap;
		char		*res;
		int			len;
		interface	*fsi;

		fsi = ft_create_interface();
		if (!fsi)
				return (1);
		va_start(ap, fmt);
		while (*fmt)
		{
				while (*fmt != '%')
				{
						ft_putchar(*fmt);
						len++;
						fmt++;
				}
				//if (ft_process_fmt(fmt, fsi))
				//		return (0);
				ft_process_fmt(fmt, fsi);
				printf("va_arg = %s\n", va_arg(ap, char *));
				res = ft_conversion_interface(fsi, va_arg(ap, void *));
				printf("res in printf = %s\n", res);
				ft_putres(res, fsi);
				len += fsi->fmtlen;
				fmt++;
		}
		ft_destroy_interface(fsi);
		return (len);
}

interface				*ft_create_interface(void)
{
		interface *fsi;

		fsi = (interface *)malloc(sizeof(interface));
		if (!fsi)
				return (NULL);
		fsi->type = 0;
		fsi->typeflag = 0;
		fsi->field = 1;
		fsi->zero = 0;
		fsi->prec = 0;
		fsi->ast = 0;
		fsi->hash = 0;
		fsi->space = 0;
		fsi->plus = 0;
		fsi->fmtlen = 2;
		return (fsi);
}

void					ft_destroy_interface(interface *fsi)
{
		fsi->type = 0;
		fsi->typeflag = 0;
		fsi->field = 0;
		fsi->zero = 0;
		fsi->prec = 0;
		fsi->ast = 0;
		fsi->hash = 0;
		fsi->space = 0;
		fsi->plus = 0;
		fsi->fmtlen = 0;
		free(fsi);
		fsi = NULL;
}

printlst				*ft_create_printlst(void)
{
		printlst *prnt;

		prnt = (printlst *)malloc(sizeof(printlst));
		if (!prnt)
				return (NULL);
		prnt->str = NULL;
		prnt->next = NULL;
		return (prnt);
}

void					ft_destroy_printlst(printlst *prnt)
{
		free(prnt->str);
		prnt->str = NULL;
		prnt->next = NULL;
		free(prnt);
		prnt = NULL;
}

unsigned int			ft_fmt_fwd(int arg)
{
		unsigned int len;

		if (arg < 0)
				arg *= -1;
		len = 0;
		while (arg)
		{
				len++;
				arg /= 10;
		}
		return (len);
}

void					ft_process_flags(const char *fmt, interface *fsi)
{
		fmt++;
		fsi->fmtlen++;
		while (*fmt == '0' || *fmt == '#' || \
						*fmt == ' ' || *fmt == '+' || *fmt == '-')
		{
				if (*fmt == '0' && fsi->field == 1)
						fsi->zero = 1;
				if (*fmt == '#')
						fsi->hash = 1;
				if (*fmt == ' ')
						fsi->space = 1;
				if (*fmt == '+')
						fsi->plus = 1;
				if (*fmt == '-')
				{
						fsi->zero = 0;
						fsi->field = -1;
				}
				fmt++;
		}
		fsi->fmtlen += fsi->zero + fsi->hash + fsi->space + fsi->plus + 1;
		fsi->field *= ft_atoi((char *)fmt);
		fmt += ft_fmt_fwd(fsi->field);
		fsi->prec = ft_atoi((char *)++fmt);
		fsi->fmtlen += ft_fmt_fwd(fsi->field) + ft_fmt_fwd(fsi->prec);;
}

int						ft_process_fmt(const char *fmt, interface *fsi)
{
		char			int_types[6];
		char			oth_types[10];

		/* lol */
		int_types[0] = 'd';
		int_types[1] = 'i';
		int_types[2] = 'u';
		int_types[3] = 'x';
		int_types[4] = 'X';
		int_types[5] = '\0';

		oth_types[0] = 'c';
		oth_types[1] = 's';
		oth_types[2] = 'p';
		oth_types[3] = '%';
		oth_types[4] = 'n';
		oth_types[5] = 'f';
		oth_types[6] = 'g';
		oth_types[7] = 'e';
		oth_types[8] = '%';
		oth_types[9] = '\0';
		/* lol */

		ft_process_flags(fmt, fsi);
		fmt += fsi->fmtlen;
		/* ll && hh flags do not compile @ home */
		/* try l == ++typeflag && h == ++typeflag + 1 ? */
		while ((*fmt == 'l' || *fmt == 'h') && ++fsi->fmtlen)
		{
				if (*fmt == 'l')
						fsi->typeflag++; /* 1 == l, 2 == ll */
				if (*fmt == 'h')
				{
						fsi->typeflag *= 10;
						fsi->typeflag++; /* 10 == h, 11 == hh */
				}
				fmt++;
		}
		printf("fmt in smw = %s\n", fmt);
		if (ft_strchr(int_types, *fmt))
				fsi->type = (unsigned int)*fmt;
		if (ft_strchr(oth_types, *fmt) && !fsi->typeflag && !fsi->hash)
				fsi->type = (unsigned int)*fmt;
		if (fsi->type && fsi->typeflag <= 11 && ++fsi->fmtlen)
				return (0);
		return (1);
}
