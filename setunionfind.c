#include<stdio.h>
//---------------------------------------------------------------------------------------------------
//
// Course : Design & Analysis of Algorithm Lab
// Code : CS591
// Assignment Number : 5.0
// Author(s) : Bhaskar Tejaswi
// Roll Number(s) : A-30
//
//---------------------------------------------------------------------------------------------------
void Build_Disjoint(int p[], int s1[], int s2[], int s3[], int n1, int n2, int n3) {
	int i;

	for (i=1;i<=n1;i++) {
		p[s1[i]] = s1[1];
		p[s1[1]] = -1;
	}

	for (i=1;i<=n2;i++) {
		p[s2[i]] = s2[1];
		p[s2[1]] = -1;
	}

	for (i=1;i<=n3;i++) {
		p[s3[i]] = s3[1];
		p[s3[1]] = -1;
	}
}

														//Build_Disjoint_For_Weighted_Union Function...
void Build_Disjoint_For_Weighted_Union(int p[], int s1[], int s2[], int s3[], int n1, int n2, int n3) {
	int i;

	for (i=1;i<=n1;i++) {
		p[s1[i]] = s1[1];
		p[s1[1]] = -n1;
	}

	for (i=1;i<=n2;i++) {
		p[s2[i]] = s2[1];
		p[s2[1]] = -n2;
	}

	for (i=1;i<=n3;i++) {
		p[s3[i]] = s3[1];
		p[s3[1]] = -n3;
	}
}

void Union(int p[], int s1[], int s2[]) { 				//Union Function...
	p[s2[1]] = s1[1];
}

void Find(int key, int p[]) {							//Find Function...
	int root = key;

	while (p[key] >= 0) {
		key = p[key];
	}
	printf("\nRoot of %d Element is %d...\n", root, key);
}

void WeightedUnion(int p[], int s1[], int s2[]) { 		//Weighted Union Function...
	if (p[s1[1]] > p[s2[1]]) {
		p[s2[1]] = p[s1[1]] + p[s2[1]];
		p[s1[1]] = s2[1];
	}
	else {
		p[s1[1]] = p[s1[1]] + p[s2[1]];
		p[s2[1]] = s1[1];
	}
}

int CompressedFind(int key, int p[]) {					//CompressedFind Function...
	int root = key;

	if (p[key] < 0) {
		return key;
	}

	p[key] = CompressedFind(p[key], p);
	return p[key];
}


int setunionfindmain() {
	int n1, n2, n3, i, p[100];
	printf("\n\n......The FIRST Elements of the Sets will be their corresponding ROOTS......\n\n");

	printf("\nEnter Number of Elements in Set S1 : \n");
	scanf("%d", &n1);
	int s1[n1];

	for (i=1;i<=n1;i++) {
		printf("\nS1[%d] = ", i);
		scanf("%d", &s1[i]);
	}

	printf("\nEnter Number of Elements in Set S2 : \n");
	scanf("%d", &n2);
	int s2[n2];

	for (i=1;i<=n2;i++) {
		printf("\nS2[%d] = ", i);
		scanf("%d", &s2[i]);
	}

	printf("\nEnter Number of Elements in Set S3 : \n");
	scanf("%d", &n3);
	int s3[n3];

	for (i=1;i<=n3;i++) {
		printf("\nS3[%d] = ", i);
		scanf("%d", &s3[i]);
	}

	Build_Disjoint(p, s1, s2, s3, n1, n2, n3); 			//Building the Disjoint Set...

	printf("\n\n......The Disjoint Array......\n");
	for (i=1;i<=(n1+n2+n3);i++) {
		printf("\nP[%d] = %d",i, p[i]);
	}

	Union(p, s1, s2); 					  				//Union of S1 and S2...
	printf("\n\n......Union of S1 and S2......\n");
	for (i=1;i<=(n1+n2+n3);i++) {
		printf("\nP[%d] = %d",i, p[i]);
	}

	printf("\n\n......Find......");
	printf("\nEnter Element to be found : ");			//Find...
	int key;
	scanf("%d", &key);
	Find(key, p);


	Build_Disjoint_For_Weighted_Union(p, s1, s2, s3, n1, n2, n3);
	WeightedUnion(p, s1, s2);
	printf("\n\n......Weighted Union of S1 and S2......\n");
	for (i=1;i<=(n1+n2+n3);i++) {
		printf("\nP[%d] = %d",i, p[i]);
	}

	printf("\n\n......Compressed Find......\n");
	printf("Enter Element to be found : ");
	scanf("%d", &key);
	int key_backup = key;
	int root = CompressedFind(key, p);
	printf("\nRoot of %d Element is %d...\n", key_backup, root);

	printf("\n");
	return 0;
}
