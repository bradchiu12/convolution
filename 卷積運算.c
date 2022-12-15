#include <stdio.h>
void x_arr(int x[20][20],int x_cols[],int x_rows[],int count);
void w_arr(int w[10][10],int count,int w_size[]);
int main(void)
{
	int count=0,times,sum=0;
	printf("輸入運算次數:");
	scanf("%d",&times);//次數 
	printf("\n");
	int x_cols[10],x_rows[10],w_size[10];
	int x[20][20],i,j,w[10][10],k=0,l=0;	
	int h[20][20]={0};
	for(;count<times;count++)
	{
		printf("輸入x矩陣大小:");
		scanf("%d%d",&x_cols[count],&x_rows[count]);
		x_arr(x,x_cols,x_rows,count);
		printf("\n輸入w矩陣大小:"); 
		scanf("%d",&w_size[count]);
		if(w_size[count]%2==0)
		{
			for(;;)
			{
				scanf("%d",&w_size[count]);
				if(w_size[count]%2==1)
					break;
			}
		}
		w_arr(w,count,w_size);
		k=0,l=0;
		for(;;)
		{
			for(i=0;i<w_size[count];i++)
			{
				for(j=0;j<w_size[count];j++)
				{
					sum+=w[i][j]*x[i+k][j+l];
				}
			}
			h[k][l]=sum;
			sum=0;
			
			l++;
			if(l>x_rows[count])
			{
				l=0;
				k++;
			}
			if(k > x_cols[count] && l == 0)
				break;
		}
		printf("\n輸出為:\n");
		for(i=0;i<x_cols[count]-w_size[count]+1;i++)
		{
			for(j=0;j<x_rows[count]-w_size[count]+1;j++)
			{
				printf("%d\t",h[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

void x_arr(int x[20][20],int x_cols[],int x_rows[],int count)
{
	int i,j;
	printf("\n輸入矩陣內容:\n");
	for(i=0;i<x_cols[count];i++)
		{
			for(j=0;j<x_rows[count];j++)
				scanf("%d",&x[i][j]);
		}
	return;
}
void w_arr(int w[10][10],int count,int w_size[])
{
	int i,j;
	printf("\n輸入矩陣內容:\n");
	for(i=0;i<w_size[count];i++)
	{
		for(j=0;j<w_size[count];j++)
			scanf("%d",&w[i][j]);
	}
	return;
}
