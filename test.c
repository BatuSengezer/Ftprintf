#include "ft_printf.h"
//test
int main (void)
{
    int c = 49;
    char *str = "ABC";
    int hex = 479;
    void *ptr = &hex;
    int percent = '%';
    unsigned int ui = 4294967295;

    ft_printf("%c %% %s  %x  %X  %p  %d  %d  %i  %u\n",c,str,hex,hex,ptr,*(int*)ptr,c,c,ui);
    printf("%c %% %s  %x  %X  %p  %d  %d  %i  %u\n",c,str,hex,hex,ptr,*(int*)ptr,c,c,ui);
    

    printf("\n hex length is %i",hex_length(hex));
}