//Ahmed Fakhreddine.... I had a great time learning with you. Hope i did Weell Enough to pass lol !!!! Great teacher!!!!
#include<stdio.h>
#define MAX_SIZE 1000
int getData(char name[], float price[MAX_SIZE], int *, int *,float *);
float determineSurgicalFees(int level, float surgicalPrices[]);
float determineLabFees(int level, float labFees[]);
void printHospitalBill(int level, char name[], float price[], float surgicalPrices[], float labFees[], int days, int meds, float sum);


int main()
{
	char name[50];
	int level;
	int days, meds;
	float sum;
	float price[MAX_SIZE];
	float surgicalPrices[5]={1500.00, 3250.00, 6579.99, 12999.99, 25450.00};
	float labFees[5]={500.00, 1025.00, 2500.99, 5290.00, 9875.99};
	//float sFee;
	
	level=getData(name, price, &days, &meds, &sum);
	
	determineSurgicalFees( level, surgicalPrices);
	
	determineLabFees( level, labFees);
	
	printHospitalBill(level, name, price, surgicalPrices, labFees, days, meds,sum);
	
	return 0;
	
}
int getData(char name[], float price[MAX_SIZE], int *daysP, int *medsP, float *sumP )
{
	
	int days, level, meds, x;
	float sum;
	
	
	printf("\nwhat is your name?");
	gets(name);
	printf("\nhow many days have you stayed in hospital?");
	scanf("%d",&days);
	printf("\nlevel of sugery you had 1-5?");
	scanf("%d",&level);
	
	printf("\nnumber of medications you been on?");
	scanf("%d",&meds);
	
	printf("\nEnter %d medication prices below in order" , meds);
    for(x=0; x<meds; x++)
    {
    	printf("\nEnter price for medication for %d:", x+1);
        scanf("%f", &price[x]);
        sum=sum+price[x];
    }
	
	//this allows the pointers go to num 1 and num 2 to put values in.
	*daysP=days;
	*medsP=meds;
	*sumP=sum;
	return level;
	
}

float determineSurgicalFees(int level, float surgicalPrices[])
{
	int x;

	for(x=0;x<5;++x)	
	{
		printf("\n level %d: surgical price is $%.2f",x+1,surgicalPrices[x]);
		 
	}
	
//	return sFee;
}

float determineLabFees(int level, float labFees[])
{
	int x;
	printf("\n");
	for(x=0;x<5;++x)	
	{
		printf("\n level %d: Lab Fees is $%.2f", x+1, labFees[x]);
		 
	}
//	return 0;
}

void printHospitalBill(int level, char name[], float price[], float surgicalPrices[], float labFees[], int days, int meds, float sum)
{
	int x;
	float total, dailyCharge, totalDue ;
	dailyCharge=350.00;
	total=days*dailyCharge;
	
	totalDue=total+sum+surgicalPrices[level-1]+labFees[level-1];
	
	printf("\n\nBilling statment for level %d surgical Procedure",level);
	printf("\nPatients Name:\t"); puts(name); 
	printf("\nDaily Charge: %.2f",total);
	printf("\nMedication Charges: %.2f",sum);
	printf("\nSurgical charges: %.2f",surgicalPrices[level-1]);
	printf("\nLab Charges: %.2f",labFees[level-1]);
	printf("\nTotal Charges: %.2f", totalDue);
}

