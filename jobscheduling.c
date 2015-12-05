//---------------------------------------------------------------------------------------------------
//
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Assignment Number : 5.1
// Author(s) : Bhaskar Tejaswi
// Roll Number(s) : A-30
// Date : 01.10.15
//
//---------------------------------------------------------------------------------------------------
#include<stdio.h>
int checker(int slot[], int bookDate, int n) {
	int i, count = 0;

	for(i=0;i<n;i++) {
		if(slot[i] == bookDate)
            count++;
    }
    if(count == 0)
    	return 1;
    else
    	return 0;
}
int jobmain() {
	int n, i, j, temp;

	printf("Enter Number of Jobs : ");
	scanf("%d", &n);

	int dead[n], profit[n], slot[n];

	for (i=0;i<n;i++){
		printf("\nEnter Profit for JOB %d : ", i+1);
		scanf("%d", &profit[i]);
		printf("\nEnter Deadline for JOB %d : ", i+1);
		scanf("%d", &dead[i]);
	}
	for (i=0;i<=n-1;i++) {
		for (j=i+1;j<n;j++) {
			if (profit[i] < profit[j]) {
				temp = profit[i];
				profit[i] = profit[j];
				profit[j] = temp;

				temp = dead[i];
				dead[i] = dead[j];
				dead[j] = temp;
			}
		}
	}

	for (i=0;i<n;i++) {
		slot[i] = 0;
	}
	for (i=0;i<n;i++) {
		for (j=dead[i];j>0;j--) {
			if (checker(slot, j, n) == 1) {
				slot[i] = j;
				break;
			}
		}
	}
    int netProfit = 0;
	printf("\n\nJob  Deadline  Profit  Slot");
	printf("\n---  --------  ------  ----");
	for (i=0;i<n;i++) {
		if (slot[i] > 0){
			printf("\n\n  %d     %d       %d      %d", i+1, dead[i], profit[i], slot[i]);
			netProfit+=profit[i];
			}
		else
			printf("\n\n  %d     %d       %d    Reject", i+1, dead[i], profit[i]);
	}
	printf("\n\nNet Profit = %d",netProfit);
	return 0;
}

