/*
÷±Ω”≤Â»Î≈≈–Ú
*/
#include <stdio.h>
void Print(int a[], int length){
	int i;
	for (i = 0; i <length;i++){
		printf("%d,",a[i]);
	}
	printf("ending!");
}

void Insert(int a[],int length){
	int i,j,t;
	for(i = 1;i < length;i++){
		t =a[i];
		j = i-1;
		while(j>=0 && a[j]>t){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
		Print(a,length);
	}
}

int main(){
	int arr[8]= {2,5,8,3,6,9,1,24};
	Insert(arr,8);
	return 0;
} 
