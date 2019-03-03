/*Obstacle avoider----You have to drive a car and try to avoid the obstacles*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char drive(int car[1][2],char ch1);
void delete_el(int xy[50],int yd[50],int a,int b,int n);
void Merge(int *a, int Low, int Mid, int High,int *x,int *yx);
void MergeSort(int *a, int Low, int High,int *x,int *yx);
//void positionxy(int *xy,int *x,int *y,int *yd,int n);
int main(void)
{
	int i,n,x[50],y[50],car[1][2],yd[50],x1[50],y1[50],xd[50],xy[50],yx[50],k,l,j;//xd and yd is for the copy of the original array
	//car is for the position of the car you are driving
	char g='n',ch,ch1='w';
	system("clear");
	printf("\tNAME:- SIDDHANT ANAND\n");
	printf("\tREG.NO:- 1641012106\n");
	printf("\tCLASS:- CSE 'A'\n");
	printf("\t\t\t\t\t\t\t--------------------OBSTACLE AVOIDER--------------------\n");
	printf("\t\t\t\t\t				  WELCOME TO THE GAME\n");
	printf("\t\t\t\tINSTRUCTIONS:-\n");
	printf("\t\t\t\t   Control the car using W,S,A,D keys to move the car forward,backward,left,right\n");
	printf("\t\t\t\tThe display will show the your initial position and will increase or decrease according to\n");
	printf("\t\t\t\t the keys you press and will also show the distance from the car to the nearest obstacle\n");
	printf("\t\t----------------------------------------------------------------------------------------------------------------------------\n");
	printf("Press y to continue: ");
	while(g!='y')
	{
		scanf("%c",&g);
	}
	system("clear");
	printf("Number of obstacles should be less than 20\nEnter the no.of obstacles: ");
	scanf("%d",&n);
	x[0]=(rand()%40)+1;
	y[0]=(rand()%40)+1;
	for(i=1;i<n;i++)
	{
		int real_num=0,real_num2=0;
		while(real_num==0&&real_num2==0)
		{
			for(j=0;j<=i;j++)
			{
				real_num=(rand()%35)+1;
				real_num2=(rand()%35)+1;
				if(real_num==x[j])
				{
					real_num=0;
				}
				if(real_num2==y[j])
				{
					real_num2=0;
				}
			}
		}
		x[i]=real_num;
		y[i]=real_num2;
	}
	printf("Your obstacles are at:\n");
	for(i=0;i<n;i++)
	{
		xd[i]=x[i];
		yd[i]=y[i];
		x1[i]=x[i];
		y1[i]=y[i];
	}
	printf("\n");
	//MergeSort(xd,0,n-1,y1,yx);
	//MergeSort(yd,0,n-1,x1,xy);
	for(i=0;i<n;i++)
	{
		printf("(%d,%d)\t",x[i],y[i]);
	}
	printf("\nEnter the starting point of the car: ");
	printf("\nx: ");
	scanf("%d",&car[0][0]);
	printf("y: ");
	scanf("%d",&car[0][1]);
	printf("\nPress y to continue: ");
	g='n';
	while(g!='y')
	{
		scanf("%c",&g);
	}
	scanf("%c",&ch);
	system("clear");
	printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tLoding....\n\t\t\t\t\t");
    for(k=1;k<=20;k++)
    {
    	for(l=0;l<=100000000;l++);//to display the character slowly
	printf("%c",177);
    }
	printf("\n\n\n\n");
	system("clear");
	int dam=4;
	x:  for(i=0;i<n;i++)
		{
			xd[i]=x[i];
			yd[i]=y[i];
			x1[i]=x[i];
			y1[i]=y[i];
		}		
		xd[n]=car[0][0];
		yd[n]=car[0][1];
		x1[n]=car[0][0];
		y1[n]=car[0][1];
		n++;
		MergeSort(xd,0,n-1,y1,yx);
		MergeSort(yd,0,n-1,x1,xy);
		printf("\n   ");
		if(xd[n-1]>=36||xd[0]<=0)
		{
			dam--;
		}
		if(yd[n-1]>=36||yd[0]<=0)
		{
			dam--;
		}
		for(k=0;k<=35;k++)
		{
			printf("_ "	);
		}
		int count=n,freq=1,temp=0,s[50];
	for (i = 40; i > 0; i--)
	{
		if(i<=35)
		{
			printf("\n%2d|",i);
		}
		if (i==yd[count-1])
		{
				while(yd[count-1]==yd[count-2])
				{
					if(xy[count-1]==xy[count-2])
					{
						dam--;
					}
					freq++;
					count--;
					temp++;
				}
					count=count+temp;

					for(j=0;j<freq;j++)
					{
						s[j]=xy[count-1-j];
					}
					MergeSort(s,0,freq-1,y1,yx);
					int lev=0;//lev is for getting the position of s[]
					
					for(j=1;j<=s[freq-1];j++)
					{
						if(j==s[lev])
						{
							if(s[lev]==car[0][0]&&yd[count-1]==car[0][1])
							{
								printf("X ");
							}
							else
							{
								printf("O ");
							}
							lev++;
						}
						else
						{
							printf("  ");
						}

					}
					count=count-freq;
				
				freq=1;
				temp=0;
		}
	}
	printf("\n   ");
	for(k=0;k<=35;k++)
	{
		printf("_ "	);
	}
	printf("\nLIFE = %d",dam);
	int a=car[0][0];
	int b=car[0][1];
	    if(dam<=0)
		{
			system("clear");
			printf("\nGAME OVER!!!\nBETTER LUCK NEXT TIME!!!");	
		}
		else
		{
			delete_el(xy,yd,a,b,n);
			n--;
			ch1=drive(car,ch1);
			scanf("%c",&ch);
			system("clear");
			goto x;	
		}
}
char drive(int car[1][2],char ch1)
{
	char ch;
	x:printf("\nEnter the direction you wanna drive: ");
	scanf("%c",&ch);
	ch=tolower(ch);
	switch (ch)
	{
		case 'w':
		{
			car[0][1]++;
			break;		
		}
		case 'a':
		{
			car[0][0]--;
			break;		
		}
		case 'd':
		{
			car[0][0]++;
			break;		
		}
		case 's':
		{
			car[0][1]--;
			break;		
		}
		default:
		{
			printf("\nPlease enter either w,a,s or d ");
			goto x;
		}
	}
	return ch;
}
void delete_el(int xy[50],int yd[50],int a,int b,int n)
{
	int i,found = 0,pos = 0;
	for (i = 0; i < n; i++)
        {
            if (xy[i] == a && yd[i] == b)
            {
                found = 1;
                pos = i;
                break;
            }
        }
 
        if (found == 1)
        {
            for (i = pos; i <  n - 1; i++)
            {
                xy[i] = xy[i + 1];
                yd[i] = yd[i + 1];
            }
        }
        xy[n-1]=0;
        yd[n-1]=0;
}
void Merge(int *a, int Low, int Mid, int High,int *x,int *xy)
{
	int b[20];
	int i = Low, j = Mid + 1, k = Low, l;
	while (i <= Mid && j <= High)
	{
		if (a[i] < a[j])
		{
			b[k] = a[i];
			xy[k] = x[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			xy[k] = x[j];
			j++;
		}
		k++;
	}
	if (j > High)
	{
		for (l = i; l <= Mid; l++)
		{
			b[k] = a[l];
			xy[k] = x[l];
			k++;
		}
	}
	else
	{
		for (l = j; l <= High; l++)
		{
			b[k] = a[l];
			xy[k] = x[l];
			k++;
		}
	}
	for (k = Low; k <= High; k++)
	{
		a[k] = b[k];
		x[k] = xy[k];
	}
}

void MergeSort(int *a, int Low, int High,int *x,int *yx)
{
	int Mid;
	if (Low < High)
	{
		Mid = ((Low + High) / 2);
		MergeSort(a, Low, Mid,x,yx);
		MergeSort(a, Mid + 1, High,x,yx);
		Merge(a, Low, Mid, High,x,yx);
	}	
}
