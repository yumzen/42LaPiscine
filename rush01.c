/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyeom <jiyeom@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:10:48 by jiyeom            #+#    #+#             */
/*   Updated: 2023/02/20 00:11:18 by jiyeom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int    row_count_visible(int annexe[4][4], int row, int left_right)
{
    int    i;
    int    max;
    int    count;
    i = 0;
    count = 1;
    max = annexe[row][left_right];
    while (left_right + i < 4 && left_right + i >= 0)
    {
        if (annexe[row][left_right + i] > max)
        {
            count ++;
            max = annexe[row][left_right + i];
        }
        if (left_right == 0)
            i ++;
        else if (left_right == 3)
            i --;
    }
    return (count);
}

int	col_count_visible(int annexe[4][4], int col, int up_down)
{
	int	i;
	int	max;
	int	count;
	i = 0;
	count = 1;
	max = annexe[up_down][col];
	while (up_down + i < 4 && up_down + i >= 0)
	{
		if (annexe[up_down + i][col] > max)
		{
			count ++;
			max = annexe[up_down + i][col];
		}
		if (up_down == 0)
			i ++;
		else if (up_down == 3)
			i --;
	}
	return (count);
}

int    doublecheck(int i, int j, int n, int arr[4][4])
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y < 4)
    {
        if(arr[y][j] == n)
            return 0;
        y++;
    }
    while(x < 4)
    {
        if(arr[i][x] == n)
            return 0;
        x++;
    }
    return 1;
}

void one_more_rev_need(int count[4][4][4], int arr[4][4], int i, int j)
{
    int t;
    int p;
    t = j;
    while(t < 4)
    {
        p = 0;
        arr[i][t] = 0;
        while(p < 4)
        {
            count[i][t][p] = 0;
            p ++;
        }
        t++;
    }
}

int    reverse(int count[4][4][4], int arr[4][4], int i, int j)
{
    int p;
	p = 0;
	arr[i][j] = 0;
	while (p<4)
	{
    	count[i][j][p] = 0;
		p++;
	}
    j--;
    int a;

    int suc = 0;
    while(j > 0)
    {
        a = 0;
        while (a < 4)
        {
            if(doublecheck(i, j, a+1, arr) == 1)
            {
                if (count[i][j][a] == 0)
                {
                    arr[i][j]=a+1;
                    count[i][j][a] =1;
                    suc =1;
                    break;
                }
            }
            a++;
        }
        if(suc == 1)
            break;
        if(a == 4)
        {
            one_more_rev_need(count, arr, i, j);
            j--;
            arr[i][j] = 0;
        }
    }
    return (j);
}

void print(int arr[4][4])
{
    for(int i= 0;i <4;i++)
    {
        for (int j=0;j<4;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
}

void    rush(int views[16])
{
    int i;
    int j;
    int k;
    int arr[4][4] = {0,};
    int count[4][4][4]= {0,};
    int rev;

    int ip;
    int jp;
    ip = 0;
    while (ip < 16)
    {
        if (views[ip] == 1)
        {
            if (ip < 4)
                arr[0][ip] = 4;
            else if (ip < 8)
                arr[3][ip % 4] = 4;
            else if (ip < 12)
                arr[ip % 4][0] = 4;
            else if (ip < 16)
                arr[ip % 4][3] = 4;
        }
        else if (views[ip] == 4)
        {
            jp = 0;
            if (ip < 4)
            {
                while(jp < 4)
                {
                    arr[jp][ip % 4] = jp + 1;
                    jp ++;
                }
            }
            else if (ip <8)
            {
                while (jp <4)
                {
                    arr[4 - jp][ip % 4] = jp + 1;
                    jp ++;
                }
            }
            else if (ip < 12)
            {
                while (jp < 4)
                {
                    arr[ip % 4][jp] = jp +1;
                    jp ++;
                }
            }
            else if (ip < 16)
            {
                while (jp <4)
                {
                    arr[ip % 4][4 - jp] = jp +1;
                    jp ++;
                }
            }
        }
        ip++;
    }

    i = 0;
    rev = 0;
    while(i < 4)
    {
        j = 0;
        while(j < 4)
        {
            if(arr[i][j] == 0)
            {
                k = 0;
                int doublecount;
                doublecount = 0;
                while(k < 4)
                {
                    if (doublecheck(i, j, k+1, arr) == 1)
                    {
                        if (count[i][j][k] == 0)
                        {
                            arr[i][j] = k+1;
                            count[i][j][k] = 1;
                            break;
                        }
                    }
                    else
                        doublecount++;
                    k++;
                }
                if (doublecount == 4)
                    rev = 1;
            }
            j++;
            if ((j == 4)&&(arr[i][j-1]!=0))
            {
                if (row_count_visible(arr,i,0) == views[8+i])
                {
                    if (row_count_visible(arr, i, 3) == views[12+i])
                        break;
                }
                rev = 1;
            }
            if(rev == 1)
            {
                j = reverse(count, arr, i, j-1);
                rev = 0;
            }
        }
        i++;
    }
    int c;
    c=0;
    while (c < 4)
    {
        if (col_count_visible(arr,c,0)==views[c])
        {
            if (col_count_visible(arr,c,3)==views[4 + c])
            {
                print(arr);
                return;
            }
        }
        write(2, "Error\n", 6);
    }
}

int main()
{
  int view [16] = {2,1,4,2,2,3,1,3,2,3,1,2,2,1,3,2};
  rush(view);
  return 0;
}
