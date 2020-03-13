#include<stdio.h>

int a[10][10],b[10][10];//b数组记录方格是否被走过 
int x,num = 0,minstep = 0,y = 0;//记录所走的路线 

void migong(int m, int n)
{
	if (m == x - 2 && n == x - 2)//如果函数到达了终点，记录其走过的长度 
	{
		if (y == 0) 
		{
			minstep = num;
		}
		if (num < minstep)
		{
			minstep = num;
		}
		y++;
		return;
	}

	if (a[m][n] == 0 && b[m][n] == 0)//向上走 
	{
		num++;
		b[m][n] = 1; //将走过的方位标记，防止下一次移动重复
		migong(m + 1, n);//运行到这里，说明前面所走的路都不通或者已经走到终点退回来，这时候就将所走的方位标记重置，并且走过的步数减1 
		
		b[m][n] = 0;//将这次方位标记 
		num--;
	}
	if (a[m][n] == 0 && b[m][n] == 0)//向下走 
	{
		num++;
		b[m][n] = 1;
		migong(m - 1, n); 
	
		b[m][n] = 0;
		num--;
	}
	if (a[m][n] == 0 && b[m][n] == 0)//向右走 
	{
		num++;
		b[m][n] = 1; 
		migong(m, n + 1);
		
		b[m][n] = 0;
		num--;
	}
	if (a[m][n] == 0 && b[m][n] == 0)//向左走 
	{
		num++;
		b[m][n] = 1; 
		migong(m, n - 1);
		
		b[m][n] = 0;
		num--;
	}
}
int main()
{
	scanf("%d", &x);//输入迷宫长度 
	for (int c = 0; c < x; c++)
	{
		for (int d = 0; d < x; d++)
		{
			scanf("%d", &b[c][d]);
		}
	}
	migong(1, 1);//将入口坐标传给函数 
	if (minstep) { 
		printf("%d", minstep);
		} 
	else{ 
		printf("No solution");
		} 
	return 0;
}

