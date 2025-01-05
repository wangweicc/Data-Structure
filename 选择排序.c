/*
—°‘Ò≈≈–Ú
*/
#include<stdio.h>
void Print(int a[],int length){
	int i;
	for(i = 0; i < length;i++){
		printf("%d\t",a[i]);
	}
	printf("\n");
}

void SelectSort(int a[] ,int length){
	int i,j,min,temp;
	for(i=0;i<length-1;i++){
		min = i;
		for(j=i+1;j<length;j++){
			if (a[min] > a[j])
			min = j;
		}
		if(min!=i){
			temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
		Print(a,length);
	}
	
}
int main(){
	int array[8] = {2,5,8,3,6,9,1,7};
	SelectSort(array,8);
	return 0;
} 
