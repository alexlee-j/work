#include<stdio.h>
int a, b[10][10], minstep = 0, x[10][10], num = 0, l = 0;

void migong(int m, int n)
{
	if (m == a - 2 && n == a - 2)
	{
		if (l == 0) 
		{
			minstep = num;
		}
		if (num < minstep)
		{
			minstep = num;
		}
		l++;
		return;
	}

	if (b[m][n] == 0 && x[m][n] == 0)//������ 
	{
		num++;
		x[m][n] = 1; 
		migong(m + 1, n);
		
		x[m][n] = 0;
		num--;
	}
	if (b[m][n] == 0 && x[m][n] == 0)//������ 
	{
		num++;
		x[m][n] = 1;
		migong(m - 1, n); 
	
		x[m][n] = 0;
		num--;
	}
	if (b[m][n] == 0 && x[m][n] == 0)//������ 
	{
		num++;
		x[m][n] = 1; 
		migong(m, n + 1);
		
		x[m][n] = 0;
		num--;
	}
	if (b[m][n] == 0 && x[m][n] == 0)//������ 
	{
		num++;
		x[m][n] = 1; 
		migong(m, n - 1);
		
		x[m][n] = 0;
		num--;
	}
}
int main()
{
	scanf("%d", &a);//�����Թ����� 
	for (int c = 0; c < a; c++)
	{
		for (int d = 0; d < a; d++)
		{
			scanf("%d", &b[c][d]);
		}
	}
	migong(1, 1);//��������괫������ 
	if (minstep)  
		printf("%d", minstep);
	else
		printf("No solution");

	return 0;
}

