# 42_Printf
Project Printf from 42 School

prototype:
	`int	ft_printf(const char *, ...);`

## Notes:

### Variadic Functions
The use o Variadic Functions (these three dots -> ...) inside the ft_printf allows the input of several variables/return of functions, bypassing the limitation of 4 variables.


By using the header `stdarg.h` the function has access to the variable arguments:

	`va_list`	- Valets - Variable that stores the variadic inputs;

	`va_start`	- Macro that initializes the `va_lis` to retrieve arguments from the variable arguments section.
	
	`va_arg`	- Macro that returns the next argument from the list. It must be used repeatedly to access all arguments. `va_arg(list, data_type)`;

	`va_end`	- Used to clean up the `va_list`. This ensures that resources associates with the `va_list` are properly released. `va_end(list)`;


Since `ft_printf` needs to receive different data types, and also, need to receive a `const char *` as a fixed param, it won't receive an `int n`, as it commonly may on others Variadic Functions. The `int n` param would be used to pass the amount of arguments used, since there is no NULL pointer, or such character, at the end of the `va_list`. 

As the function's first parameter is a `const char *`, with the common flags used on the original function `printf`, all flags would be preceded by a `%` character, and that can be used to count the amount of arguments passed.


### Bitwise

Bitwise operators are used to perform directly on the binary. These operators work by manipulating individual bits (0s and 1s) in a number.

Allow precise manipulation of bits, giving you control over hardware operations.

	`&`	- AND operator - Does AND operation on every two bit of two numbers. Return 1 only if both bits are 1.
	
	`|`	- OR operator - Does OR operation on every two bit of two numbers. Return 1 if any of the two bits is 1.
	
	`^`	- XOR operator - Does XOR operation on every two bit of two numbers. Return 1 if the two bits are different.
	
	`~`	- NOT operator - Does a NOT operation. Return an invertion of all the bits received.
	
	`<<`	- LEFT SHIFT operator - Takes two numbers, the one on the right side of the operator is the number of digits to shift. The left one is the number that is shifted. This operation 'pushes the number to the left', adding a zero at the end of the number.
	
	`>>`	- RIGHT SHIFT operaton - Takes two numbers, the one on the right side of the operator is the number of digits to shift. The left one is the numer that is shifted. This operation 'pushes the number to the right', 'cutting' wherever number is at the last digit, or wherever amount is shifted.
	

Considerations:

- Bitwise operations should NOT be used in place of logical operators. While logical operators (&&, || and !) return either 0 or 1, Bitwise operators return an integer value. Also, the logical operators consider any non-zero operand as 1.

- The LEFT-SHIFT and the RIGHT-SHIFT only work for positive numbers. If a zero (0) is passed as a amount to shift, NO shift operation is performed.

- The LEFT-SHIFT and the RIGHT-SHIFT are equivalent to multiplication and division by 2 respectively.

- The `&` operator can be used to quickly check if a number is odd or even.

- The `~` operator should be used carefully, as a small number can turn into a big number if the variable that store the result is unsigned.
