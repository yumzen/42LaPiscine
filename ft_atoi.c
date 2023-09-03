/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:21:12 by jiyeom            #+#    #+#             */
/*   Updated: 2023/03/01 18:21:43 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	whitespace(char *str, int i)
{
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		return (1);
	return (0);
}

int	put_result(char *str, int i, long long result)
{
	if (result > 0)
		result *= 10;
	result += (str[i] - '0');
	return (result);
}

int	check_sign(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (sign);
}

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (whitespace(str, i) == 1)
		i++;
	sign = check_sign(&str[i]);
	while ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = put_result(str, i, result);
		i++;
	}
	return (result * sign);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define RESET  "\033[0m"
#define PASS(res) res == 1 ? printf( GREEN " (\xE2\x9C\x93)" RESET ) : printf( RED " (x)"  RESET );
#define RET(res, ret) res == 1 ? printf( GREEN "%d\n" RESET, ret) : printf( RED "%d\n" RESET, ret);
int main()
{
		char number[] = "    --+--+--  2147483647";
		int r = ft_atoi(number);

		char number2[] = "  f  -+-++--2147483648";
		int r2 = ft_atoi(number2);

		char number3[] = "    -+-++--21474-83648";
		int r3 = ft_atoi(number3);

		char number4[] = "     ++2147483647";
		int r4 = ft_atoi(number4);

		char number40[] = "    -2147483648";
		int r40 = ft_atoi(number40);

		char number5[] = " ---+--+1234ab567";
		int r5 = ft_atoi(number5);

		char number6[] = " 5  ---+--+1234ab567";
		int r6 = ft_atoi(number6);

		char number7[] = "   --+--+1234ab567";
		int r7 = ft_atoi(number7);

		char number8[] = "";
		int r8 = ft_atoi(number8);

		char number9[] = "0000000000000000";
		int r9 = ft_atoi(number9);

        printf(YELLOW "\nTEST1 number is: " BLUE "\"%s\"" RESET, number);
        PASS(r == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r == 0, r)
        printf("Expected:   %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST2 number is: " BLUE "\"%s\"" RESET, number2);
        PASS(r2 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r2 == 0, r2)
        printf("Expected:   %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST3 number is: " BLUE "\"%s\"" RESET, number3);
        PASS(r3 == 21474)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r3 == 21474, r3)
        printf("Expected:   %d\n\n", 21474);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST4 number is: " BLUE "\"%s\"" RESET, number4);
        PASS(r4 == 2147483647)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r4 == 2147483647, r4)
        printf("Expected:   %d\n\n", 2147483647);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST40 number is: " BLUE "\"%s\"" RESET, number40);
        PASS(r40 == -2147483648)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r40 == -2147483648, r40)
        printf("Expected:   %ld\n\n", -2147483648);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST5 number is: " BLUE "\"%s\"" RESET, number5);
        PASS(r5 == -1234)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r5 == -1234, r5)
        printf("Expected:   %d\n\n", -1234);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST6 number is: " BLUE "\"%s\"" RESET, number6);
        PASS(r6 == 5)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r6 == 5, r6)
        printf("Expected:   %d\n\n", 5);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST7 number is: " BLUE "\"%s\"" RESET, number7);
        PASS(r7 == 1234)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r7 == 1234, r7)
        printf("Expected:   %d\n\n", 1234);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST8 number is: " BLUE "\"%s\"" RESET, number8);
        PASS(r8 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r8 == 0, r8)
        printf("Expected:   %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

        printf(YELLOW "\nTEST9 number is: " BLUE "\"%s\"" RESET, number9);
        PASS(r9 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("My atoi:    "); RET(r9 == 0, r9)
        printf("Expected:   %d\n\n", 0);
        printf("-------------------------------\n\n");

}
