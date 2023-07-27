#include "main.h"

/**
 * is_printable - entry point
 * @c: Evaluated  char
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}
/**
 * append_hexa_code - Append ascci in hexadecimal
 * @buffer: chars array
 * @i: index at which to start appending
 * @ascii_code: CODE ASSCI
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verifies a char is digit
 * @c: evaluated char
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_size_number - a number casts to a specified size
 * @num: casted number
 * @size: casted number indicating the type
 * Return: casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - a number to be casts to a specified size
 * @num: casted number
 * @size: the number to be casted
 * Return: casted vaue of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	eslse if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

/**
 * write_pointer - memory address
 * @buffer: chars arrays
 * @ind: index number starts in buffer
 * @length: number of length
 * @width: specifier width
 * @flags: specifier flags
 * @padd: padding char representing
 * @extra_c: char extra representing
 * @padd_start: start index padding
 * Return: number of written chars
 */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int
padd_start)
{
	int i,

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & F_MINUS && padd == '')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && padd == '')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')/* etra char to left to padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(i, &buffer[ind], length - (1 - padd_start) -2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
