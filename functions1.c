#include "main.h"

/*************************PRINT UNSIGNED NUMBER*************************/

/**
 * print_unsigned - prints an unsigned number
 * @types: argument list
 * @buffer: print buffer array to handle
 * @flags: flags calculates
 * @width: width
 * @precision: specification precision
 * @size: specifier size
 * Return: number of chars printed
 */
int print_unsigned(val_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/***********************PRINT UNSIGNED NUMBER IN OCTAL***********************/
/**
 * print_octal - prints an unsigned number in octal notation
 * @types: arguments list
 * @buffer: print buffer array to handle
 * @flags: flags calculate
 * @width: width get
 * @precision: specification precision
 * @size: specifier size
 * Return: number of chars printed
 */
int print_octa(val_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - prints an unsigned number in hexadecimal notation
 * @types: arguments list
 * @buffer: print buffer array to handle
 * @flags: flags calculated
 * @width: width get
 * @precision: specification precision
 * @size: specifier size
 * Return: number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x',
		width, precision, size));
}
/**************PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - prints a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: value of array
 * @buffer: print buffer array handle
 * @flags: flags calculates
 * @flag_ch: active flags
 * @width: width get
 * @precision: specification precision
 * @size: specifier size
 * @size: specification size
 * Return: number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[1--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

