#include <stdio.h>
#include <stdlib.h>

// ֱ�Ӳ�������
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // ����key���Ԫ������ƶ�һλ
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ��ѡ������
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // ������������Ԫ��
    for (i = 0; i < n-1; i++) {
        // �ҵ���СԪ�ص�����
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // �����ҵ�����СԪ�����һ��Ԫ��
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// ������������������Ϊ����
void heapify(int arr[], int n, int i) {
    int largest = i; // ��ʼ�����ֵΪ��
    int left = 2*i + 1; // ���ӽڵ�
    int right = 2*i + 2; // ���ӽڵ�

    // ������ӽڵ���ڸ�
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // ������ӽڵ���ڵ�ǰ���ֵ
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // ������ֵ���Ǹ�
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // �ݹ�ص�����Ӱ�������
        heapify(arr, n, largest);
    }
}

// ������
void heapSort(int arr[], int n) {
    // ��������
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // һ����һ���شӶ���ȡ��Ԫ��
    for (i=n-1; i>=0; i--) {
        // �ƶ���ǰ����ĩβ
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // �������ٺ�Ķ�
        heapify(arr, i, 0);
    }
}

// ��ӡ����
void printArray(int arr[], int size) {
	int i;
   for (i=0; i < size; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

// ���������㷨
int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data)/sizeof(data[0]);
    int i;
	printf("����Ϊ:\n");
    for(i=0;i<7;i++){
    
    	printf("%d\n",data[i]);
	}

    // �������������ڲ�ͬ���򷽷�
    int arrInsertion[n], arrSelection[n], arrHeap[n];
    for ( i = 0; i < n; i++) {
        arrInsertion[i] = arrSelection[i] = arrHeap[i] = data[i];
    }

    // ʹ�ò�ͬ�����򷽷��������򲢴�ӡ���
    insertionSort(arrInsertion, n);
    printf("��������������: \n");
    printArray(arrInsertion, n);

    selectionSort(arrSelection, n);
    printf("ѡ������������: \n");
    printArray(arrSelection, n);

    heapSort(arrHeap, n);
    printf("������������: \n");
    printArray(arrHeap, n);

    return 0;
}
