/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 10:06:43 by jiyeom            #+#    #+#             */
/*   Updated: 2023/03/01 18:12:58 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		j = i + 1;
		while (base[j] != 0)
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	i = 0;
	if ((base[0] == 0) || (base[1] == 0))
		return (0);
	while (base[i] != '\0')
	{
		if ((((base[i] >= 9) && (base[i] <= 13)) || (base[i] == 32))
			|| ((base[i] == '+') || (base[i] == '-')))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
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

int	check_char(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int			strlen;
	int			baselen;
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	strlen = ft_strlen(str);
	baselen = ft_strlen(base);
	if (check(base) != 1)
		return (0);
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	sign = check_sign(&str[i]);
	while ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (check_char(str[i], base) != -1)
	{
		num *= baselen;
		num += check_char(str[i++], base);
	}
	return (num * sign);
}

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define RED    "\033[1;31m"
#define GREEN  "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE   "\033[1;34m"
#define RESET  "\033[0m"
#define PASS(res) res == 1 ? printf( GREEN " (\xE2\x9C\x93)" RESET ) :\
printf( RED " (x)"  RESET );
#define RET(res, ret) res == 1 ?\
printf( GREEN "%d\n" RESET, ret) : printf( RED "%d\n" RESET, ret);
int main()
{
        int rd  = ft_atoi_base("    +-+-+10", "0123456789");
		int erd = 10;
        int rh  = ft_atoi_base("    +-+-+10", "0123456789abcdef");
		int erh = 16;
        int rb  = ft_atoi_base("    +-+-+10", "01");
		int erb = 2;
        int rp  = ft_atoi_base("    +-+-+10", "poneyvif");
		int erp = 0;

		//min int
        int rd2 = ft_atoi_base("    -2147483648", "0123456789");
		int erd2 = -2147483648;
        int rh2 = ft_atoi_base("    -80000000", "0123456789abcdef");
        int rb2 = ft_atoi_base("    -10000000000000000000000000000000", "01");

		// max int
        int rd3 = ft_atoi_base("    +2147483647", "0123456789");
		int erd3 = 2147483647;
        int rh3 = ft_atoi_base("    +7fffffff", "0123456789abcdef");
        int rb3 = ft_atoi_base("    +1111111111111111111111111111111", "01");

		// 0
        int rd4 = ft_atoi_base("    0", "0123456789");
        int rh4 = ft_atoi_base("    0", "0123456789abcdef");
        int rb4 = ft_atoi_base("    0", "01");
        int rp4 = ft_atoi_base("    0", "poneyvif");
		int er4 = 0;

		// truncated num
        int rd5 = ft_atoi_base("    ---2147o483648", "0123465789");
		int erd5 = -2147;
        int rh5 = ft_atoi_base("    ---2147o483648", "0123465789abcdef");
		int erh5 = -8519;
        int rb5 = ft_atoi_base("    ---2147o483648", "01");
		int erb5 = 0;
        int rp5 = ft_atoi_base("    ---2147o483648", "poneyvif");
		int erp5 = 0;

		// invalid

        int r6 = ft_atoi_base("    -2147o483648", "1");
        int r7 = ft_atoi_base(" o   -2147483648", "0123456789abcdef");
        int r8 = ft_atoi_base("", "0123456789abcdef");
        int r9 = ft_atoi_base(" -aw10", "012345+6789abcdef");
        int r10 = ft_atoi_base("  1001100", "011");


        printf(YELLOW "\nTEST1 number is:" BLUE " \"    +-+-+10\"" RESET);
        PASS(rd == erd && rh == erh && rb == erb && rp == erp)
        printf("\n" );
        printf("-------------------------------\n");
        printf("Decimal:  "); RET(rd == erd, rd)
        printf("Expect:   %d\n\n", erd);

        printf("Hex:      "); RET(rh == erh, rh)
		printf("Expect:   %d\n\n", erh);

        printf("Binary:   "); RET(rb == erb, rb)
		printf("Expect:   %d\n\n", erb);

        printf("octal:    "); RET(rp == erp, rp)
		printf("Expect:   %d\n\n", erp);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST2 number is:" BLUE " MIN_INT" RESET);
        PASS(rd2 == erd2 && rh2 == erd2 && rb2 == erd2)
        printf("\n" );
        printf("-------------------------------\n");
        printf("Decimal:  "); RET(rd2 == erd2, rd2)
        printf("Expect:   %d\n\n", erd2);

        printf("Hex:      "); RET(rh2 == erd2, rh2)
		printf("Expect:   %d\n\n", erd2);

        printf("Binary:   "); RET(rb2 == erd2, rb2)
		printf("Expect:   %d\n\n", erd2);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST3 number is:" BLUE " MAX_INT" RESET);
        PASS(rd3 == erd3 && rh3 == erd3 && rb3 == erd3)
        printf("\n" );
        printf("-------------------------------\n");
        printf("Decimal:  "); RET(rd3 == erd3, rd3)
        printf("Expect:   %d\n\n", erd3);

        printf("Hex:      "); RET(rh3 == erd3, rh3)
		printf("Expect:   %d\n\n", erd3);

        printf("Binary:   "); RET(rb3 == erd3, rb3)
		printf("Expect:   %d\n\n", erd3);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST4 number is: " BLUE "\"    0\"" RESET);
        PASS(rd4 == er4 && rh4 == er4 && rb4 == er4 )
        printf("\n" );
        printf("-------------------------------\n");
        printf("Decimal:  "); RET(rd4 == er4, rd4)
        printf("Expect:   %d\n\n", er4);

        printf("Hex:      "); RET(rh4 == er4, rh4)
		printf("Expect:   %d\n\n", er4);

        printf("Binary:   "); RET(rb4 == er4, rb4)
		printf("Expect:   %d\n\n", er4);

        printf("octal:    "); RET(rp4 == er4, rp4)
		printf("Expect:   %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST5 number is: " BLUE "\"    ---2147o483648\"" RESET);
        PASS(rd5 == erd5 && rh5 == erh5 && rb5 == erb5 && rp5 == erp5)
        printf("\n" );
        printf("-------------------------------\n");
        printf("Decimal:  "); RET(rd5 == erd5, rd5)
        printf("Expect:   %d\n\n", erd5);

        printf("Hex:      "); RET(rh5 == erh5, rh5)
		printf("Expect:   %d\n\n", erh5);

        printf("Binary:   "); RET(rb5 == erb5, rb5)
		printf("Expect:   %d\n\n", erb5);

        printf("octal:    "); RET(rp5 == erp5, rp5)
		printf("Expect:   %d\n\n", erp5);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST6 base is only 1 charactere" RESET);
        PASS(r6 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("output:  "); RET(r6 == 0, r6)
        printf("Expect:   %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST7: input is \" o   -2147483648\"" RESET);
        PASS(r7 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("output:  "); RET(r7 == 0, r7)
        printf("Expect:  %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST8: input is \"\"" RESET);
        PASS(r8 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("output:  "); RET(r8 == 0, r8)
        printf("Expect:  %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST9: base contain a wrong '+' charactere" RESET);
        PASS(r9 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("output:  "); RET(r9 == 0, r9)
        printf("Expect:  %d\n\n", 0);
        printf("-------------------------------\n\n");

        usleep(500000);

		printf(YELLOW "\nTEST10: base has double charactere" RESET);
        PASS(r10 == 0)
        printf("\n" );
        printf("-------------------------------\n");
        printf("output:  "); RET(r10 == 0, r10)
        printf("Expect:  %d\n\n", 0);
        printf("-------------------------------\n\n");
}
