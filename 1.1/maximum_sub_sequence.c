#include <stdio.h>
#include <stdlib.h>

//KEY: use algorithm--Divide and Conquer;
int *Init_array(int n);
int max(int a, int b, int c);
int divideseq(int *p, int left, int right);
int MaxSub(int *p, int n);

int main()
{
	int n, i = 0;
	scanf("%d",&n);
	int *p = Init_array(n);
    printf("%d\n",MaxSub(p, n));
	free(p);

	return 0;
}

int* Init_array(int n)		//initialize array;
{
	int *pArray = malloc(sizeof(int[n])) ;
	int i = 0;
	while (i < n)
        scanf("%d",&pArray[i++]);

	return pArray;
}

int max(int a, int b, int c)
{
	return (a>b ? (a > c ? a : c) : (b < c ? c : b));
}

int divideseq(int *p, int left, int right)
{
	int i, maxboaderleft, maxboaderright;
	int leftboader = 0, rightboader = 0;

	if (left == right)	//it means only one data, the ending condition;
	{
		if (p[left] > 0)
			return p[left];
		else
			return 0;
	}

	int center = (left + right) / 2;
	int maxleft = divideseq(p, left, center);		// use 'recursion' to get the max left value;
	int maxright = divideseq(p, center + 1, right);

	maxboaderleft = 0;	
	for (i = center; i >= left; i--)		// get left boader max value, and right value, sum them.
	{
		leftboader += p[i];
		if (leftboader > maxboaderleft)		//so we get the value including the left and the right;
			maxboaderleft = leftboader;
	}

	maxboaderright = 0;
	for (i = center + 1; i <= right; i++)
	{
		rightboader += p[i];
		if (rightboader > maxboaderright)
			maxboaderright = rightboader;
	}

	return max(maxleft, maxright, maxboaderleft + maxboaderright);
}

int MaxSub(int *p, int n)
{
	return divideseq(p, 0, n - 1);
}