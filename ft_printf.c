#include "ft_printf.h"

//problem calling libft library
void ft_putchar(int c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10 ;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		numlen;
	long	num;

	num = n;
	numlen = ft_numlen(n);
	ret = malloc(sizeof(char) * (numlen + 1));
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	ret[numlen] = 0;
	if (n < 0)
	{
		ret[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		ret[--numlen] = num % 10 + '0';
		num = num / 10;
	}
	return (ret);
}

static int	ft_unumlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i = 1;
	if (n < 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10 ;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	char	*ret;
	int		numlen;
	unsigned long	num;

	num = n;
	numlen = ft_unumlen(n);
	ret = malloc(sizeof(char) * (numlen + 1));
	if (!ret)
		return (0);
	if (n == 0)
		ret[0] = '0';
	ret[numlen] = 0;
	if (n < 0)
	{
		ret[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		ret[--numlen] = num % 10 + '0';
		num = num / 10;
	}
	return (ret);
}


// %c Prints a single character or percent.
int print_char(int c, char format)
{
    if (format == 'c')
        ft_putchar(c);
    if (format == '%')
        ft_putchar('%');
    return(1);
}


// %s Prints a string
int print_str(const char *str)
{
    int len = ft_strlen(str);
    while(*str)
    {
        ft_putchar(*str);
        str++;
    }
    return(len);
}


// %d Prints a decimal (base 10) number and %i Prints an integer in base 10.
int print_dec(int dec)
{
    char *nbr;
    int len;

    nbr = ft_itoa(dec);
    len = print_str(nbr);

    return(len);
}


// %u Prints an unsigned decimal (base 10) number.
int print_unsigned_int(unsigned int ui)
{
    char *nbr;
    int len;

    nbr = ft_uitoa((ui));
    len = print_str(nbr);
    return(len);
}


//%x Prints a number in hexadecimal (base 16) lowercase and uppercase format.
int hex_length(unsigned long int hex)
{
    int len;
    len = 0;
    while (hex != 0)
    {
        hex = hex / 16;
        len++;
    }
    return (len);
}

void convert_hex(unsigned long int hex, char format)
{
    if (hex >= 16)
    {
        convert_hex(hex / 16, format);
        convert_hex(hex % 16, format);
    }
    else
    {
        if(hex < 10)
            ft_putchar(hex + '0');
        else
        {   if(format == 'x' || format =='p')
                ft_putchar(hex - 10 + 'a');
            if(format == 'X')
                 ft_putchar(hex - 10 + 'A');
        }
    }
}

int print_hex(unsigned long int hex, char format)
{
    convert_hex(hex, format);  
    return(hex_length(hex));
}


// %p The void * pointer argument has to be printed in hexadecimal format.
void	ft_put_ptr(unsigned long int ptr,char format)
{
    convert_hex(ptr, format); 
}

int print_ptr(void *ptr, char format)
{
    if(ptr)
    {
        write(1,"0x",2);
        ft_put_ptr((unsigned long int)ptr,format);
    }
    return(hex_length((unsigned long int)ptr));
}


//format identifier
int format_identifier(const char format,va_list args)
{
    int length = 0;
    if (format == 'c' || format == '%')
        length += print_char(va_arg(args ,int),format);
    if(format == 's')
        length += print_str(va_arg(args ,char *));
    if(format == 'x' || format == 'X')
        length+= print_hex(va_arg(args ,unsigned long int),format);
    if(format == 'p')
        length+=print_ptr(va_arg(args ,void *),format);
    if(format == 'd'|| format == 'i')
        length += print_dec(va_arg(args ,int));
    if(format == 'u')
        length += print_unsigned_int(va_arg(args ,unsigned int));

    return(length);
}

int			ft_printf(const char *str, ...)
{
    int print_length;
    va_list args;
    va_start(args, str);

    print_length = 0;
    while(*str)
    {
        if (*str == '%')
        {
            str++;
            if(*str != '%')
                print_length += format_identifier(*str,args);
            if(*str == '%')
                print_length += print_char('%','%');
        }
        else
        {
            ft_putchar(*str);
            print_length++;
        }
        str++;        
    }
    va_end(args);
    //printf("print length is :%d",print_length);
    return(print_length);
}


//test
int main (void)
{
    int c = 49;
    char *str = "ABC";
    int hex = 479;
    void *ptr = &hex;
    unsigned int ui = 4294967295;

    ft_printf("%c %% %s  %x  %X  %p  %d  %d  %i  %u\n",c,str,hex,hex,ptr,*(int*)ptr,c,c,ui);
    printf("%c %% %s  %x  %X  %p  %d  %d  %i  %u\n",c,str,hex,hex,ptr,*(int*)ptr,c,c,ui);
    

    printf("\n hex length is %i",hex_length(hex));
}