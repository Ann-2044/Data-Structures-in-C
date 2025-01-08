#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int A[MAX],asize=0;
int B[MAX],bsize=0;
int S[MAX],ssize=0;
int bitA[MAX];
int bitB[MAX];
int i,j;
void printbitsets() {
	printf("Bitstring set A:");
	for(i=0; i<ssize; i++)
		printf("%d",bitA[i]);
	printf("\nBitstring set B:");
	for(i=0; i<ssize; i++)
		printf("%d",bitB[i]); 
}
void bitstring() {
	for(i=0; i<ssize; i++) {
		bitA[i]=0;
		bitB[i]=0;
	}
	for(i=0; i<asize; i++) {
		for(j=0; j<ssize; j++)
		{
			if(A[i]==S[j]) {
				bitA[j]=1;
				break;
			}
		}
	}
	for(i=0; i<bsize; i++) {
		for(j=0; j<ssize; j++)
		{
			if(B[i]==S[j]) {
				bitB[j]=1;
				break;
			}
		}
	}
	printbitsets();

}
void setunion() {
	int uni[MAX];
	for(i=0; i<ssize; i++)
	{
		uni[i]=bitA[i] | bitB[i];
	}
	printf("\nUnion of set A and B:");
	for(i=0; i<ssize; i++)
		printf("%d",uni[i]);
}
void intersection() {
	int inter[MAX];
	for(i=0; i<ssize; i++)
		inter[i]=bitA[i] & bitB[i];
	printf("\nintersection of set A and B:");
	for(i=0; i<ssize; i++)
		printf("%d",inter[i]);
}
int main()
{

	//Read universal set
	do {
		printf("Enter the size of universal set(max 20):");
		scanf("%d",&ssize);

		if(ssize>MAX) {
			printf("size limit exceeded!!\n");
		}
	} while(ssize>MAX);
	for(i=0; i<ssize; i++) {
		printf("enter the element %d:",i+1);
		scanf("%d",&S[i]);
	}
	//Read set A
	do {
		printf("enter the size of set A(max %d):",ssize);
		scanf("%d",&asize);
		if(asize>ssize)
			printf("invalid size!! size not exceeded than universal set size\n");
	} while(asize>ssize);
	printf("Enter SET A\n");
	for(i=0; i<asize; i++) {
		printf("enter the element %d:",i+1);
		scanf("%d",&A[i]);
	}
	//Read set B
	do {
		printf("enter the size of set B(max %d):",ssize);
		scanf("%d",&bsize);
		if(bsize>ssize)
			printf("invalid size!! size not exceeded than universal set size\n");
	} while(bsize>ssize);
		printf("Enter SET B\n");
	for(i=0; i<bsize; i++) {
		printf("enter the element %d:",i+1);
		scanf("%d",&B[i]);
	}
	bitstring();
	setunion();
	intersection();
}
