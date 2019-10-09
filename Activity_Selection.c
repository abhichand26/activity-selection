#include<stdio.h>
#include<malloc.h>

/*
** Program to find non overlapping activities using Activity Selection algorithm
** Made by - Abhishek Chand
*/

typedef struct ACTIVITY
{
	int actno,st,fin,dur;
}Activity;


void asort(Activity A[],int n)
{
	int i,j;
	Activity t;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(((A+j)->fin)<((A+i)->fin))
			{
				t=*(A+j);
				*(A+j)=*(A+i);
				*(A+i)=t;		
			}
		}
	}
}

void ActivitySelection(Activity A[],int n)
{
	int i,p;
	printf("\n\nActivity number: %d",A[1].actno);
	printf("\nStart: %d",A[1].st);
	printf("\nFinish: %d",A[1].fin);
	printf("\nDuration: %d",A[1].dur);
	p=1;
	
	for(i=2;i<n;i++)
	{
		if(A[i].st>=A[p].fin)
		{
			printf("\n\nActivity number: %d",A[i].actno);
			printf("\nStart: %d",A[i].st);
			printf("\nFinish: %d",A[i].fin);
			printf("\nDuration: %d",A[i].dur);
			p=i;
		}
	}
}

int main()
{
	int i,n,j,t,k=1;
	Activity *A;
	printf("Enter the no. of activities:");
	scanf("%d",&n);
	n++;
	A=(Activity *)malloc(n*sizeof(Activity));
	
	for(i=1;i<n;i++)
	{
		printf("Enter the activity number:");
		scanf("%d",&(A[i].actno));
		printf("Enter the Starting date:");
		scanf("%d",&(A[i].st));
		printf("Enter the Duration:");
		scanf("%d",&(A[i].dur));
		(A[i].fin)=(A[i].st)+(A[i].dur)-1;
	}
	
	asort(A,n);
	ActivitySelection(A,n);
	
	return 0;
}
