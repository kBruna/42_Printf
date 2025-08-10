# 42_Printf
Project Printf from 42 School

prototype:
	`int	ft_printf(const char *, ...);`


## Main Printf Function

The main `printf` function receives a string and a unknown amount of variables of unknown data types.

The purpose of the `printf` function is to create and initialize the Variadic Function and it's macros/functions (see Notes), and to print the rest of the first string while checking if there is any flag declared on it. If there is, then the `ft_printflags` is called.


## ft_printflags Function

This function main purpose is to define with flag is being used and parse the value to the right auxiliary function.

	`static void ft_putstr(char *s, int *count)` - For the flag `s`
	
	`static void ft_putnbr(long n, int t_char, int *count)` - For the flags `d`, `i` and `u`
	
	`static void ft_puthex(unsigned long nbr, char x, int *count)` - For the flags `x`, `X` and `p`
	

Since the flags `%` and `c` are simple enought to implement in less than 3 lines, they are implemented in this function, without the need for a new function.


## ft_putstr Function

Using the function `write` from the library `unistd.h`, this function prints any string received. If the value is NULL, it will print `(null)`.


## ft_putnbr Function

This function will receive a long `n`, and will print it, from left to right. This function can process the flags `d` for int, `i` also for int (works the same way as `d`), and `u` for unsigned int. 

For the `d`and `i` flags, the function will behave the same way. The function will receive any int value and print it, checking if the value is negative to print the signal `-` (minus) before the number.

For the flag `u` however, for it is just for unsigned int values, it ignores the negative treatment and just print the number without the checks. This ensures that even if a negative number were used in a unsigned int variable, it will behave as a positive number inside this function and flip the value to a positive. (i.e. `unsigned int var = -1` prints `UNSIGNED_INT_MAX`)


## ft_puthex Function

This function will receive an unsigned long `nbr`, and will convert it to hexadecimal and print the converted value. 

If the flag received is `x` (lowercase x) it will print the hex in lowercase. 

If the flag received is `X` (uppercase X) it will print the hex in uppercase. 

If the flag received is `p` it will first print `0x` and then change the flag to `x`, treating the number as this flag would, essencially printing it in lowercase hexadecimal.


## Notes:

### Variadic Functions

The use a Variadic Functions (these three dots -> ...) inside the ft_printf allows the input of several variables/return of functions, bypassing the limitation of 4 variables.


By using the header `stdarg.h` the function has access to the variable arguments:

`va_list`	- Valets - Variable that stores the variadic inputs;

`va_start`	- Macro that initializes the `va_lis` to retrieve arguments from the variable arguments section.
	
`va_arg`	- Macro that returns the next argument from the list. It must be used repeatedly to access all arguments. `va_arg(list, data_type)`;

`va_end`	- Return a copy of the arguments in va_list;

`va_end`	- Used to clean up the `va_list`. This ensures that resources associates with the `va_list` are properly released. `va_end(list)`;


Since `ft_printf` needs to receive different data types, and also, need to receive a `const char *` as a fixed param, it won't receive an `int n`, as it commonly may on others Variadic Functions. The `int n` param would be used to pass the amount of arguments used, since there is no NULL pointer, or such character, at the end of the `va_list`. 

As the function's first parameter is a `const char *`, with the common flags used on the original function `printf`, all flags would be preceded by a `%` character, and that can be used to count the amount of arguments passed.

### Test

	#include <stdio.h>

	int main(void)
	{
	    char    *str = "This is a string";
	    int     org = -123; 
	    int     new = -123;
	    int     hex = 123456;
	    int     hex2 = -123456;
	    char    d   = 'z';
	    unsigned int minus = -5;
	    char    *str1 = "";
	
	    org = printf("\n\tOg function: %d %i %c %u %s %s %x %X %x %X %p %p %q \n", org, org, d, minus, str, str1, hex, hex, hex2, hex2, &org, NULL);
	
	    new = ft_printf("\n\tMy function: %d %i %c %u %s %s %x %X %x %X %p %p %q \n", new, new, d, minus, str, str1, hex, hex, hex2, hex2, &org, NULL);

	    printf("Return :\n\tOriginal %d | My Function %d\n", org, new);

	    return (0);
	}

