#include "./libft/libft.h"

int	ft_printf(const char *format, ...)
{
	int				sum;
	va_list		 	VaList;
	long long		PrintInteger;
	char	 		*pPrintString;
	char			*IntegerString;
	//unsigned char	PrintChar;
	//size_t			HexaPrint;


	sum = 0;
	va_start(VaList, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if(*format == 'x')
				ft_putnbro_rtn(va_arg(VaList, int), 16, "0123456789abcdef", &sum);	
			else if(*format == 'X')
				ft_putnbro_rtn(va_arg(VaList, int), 16, "0123456789ABCDEF", &sum);	
			else if(*format == 'u')
			{
				PrintInteger = va_arg(VaList, long long);
				if (PrintInteger < 0)
					PrintInteger = (4294967296 + PrintInteger);
				IntegerString = ft_itoa(PrintInteger);
				ft_putstring(IntegerString);
				sum +=  ft_strlen(IntegerString);
				free (IntegerString);
			}
			else if(*format =='c')
				sum += ft_putchar_rtn(va_arg(VaList, int));
			else if(*format == 's')
			{
				pPrintString = va_arg(VaList, char *);
				ft_putstring(pPrintString);
				sum += ft_strlen(pPrintString);
			}
			else if(*format ==  'd' || *format == 'i')
			{
				PrintInteger = va_arg(VaList, int);
				IntegerString = ft_itoa(PrintInteger);
				ft_putstring(IntegerString);
				sum += ft_strlen(IntegerString);
				free (IntegerString);
			}
			else if(*format == 'p')
			{
				ft_putstring("0x");
				sum +=2;
				ft_putnbro_rtn(va_arg(VaList, size_t), 16 , "0123456789abcdef", &sum);
			}
			else if(*format =='%')
				sum += ft_putchar_rtn('%');

			else if(*format == '\0')
					break;
			else
			{
				sum += ft_putchar_rtn('%');
				sum += ft_putchar_rtn(*format);
			}
		}
		else
			sum += ft_putchar_rtn(*format);

		format++;
	}
	va_end(VaList);	
	return (sum);
}