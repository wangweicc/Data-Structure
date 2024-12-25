#include <stdio.h>
#include <stdlib.h>

// 直接插入排序
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // 将比key大的元素向后移动一位
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// 简单选择排序
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // 遍历所有数组元素
    for (i = 0; i < n-1; i++) {
        // 找到最小元素的索引
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // 交换找到的最小元素与第一个元素
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// 堆排序辅助函数：调整为最大堆
void heapify(int arr[], int n, int i) {
    int largest = i; // 初始化最大值为根
    int left = 2*i + 1; // 左子节点
    int right = 2*i + 2; // 右子节点

    // 如果左子节点大于根
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // 如果右子节点大于当前最大值
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // 如果最大值不是根
    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        // 递归地调整受影响的子树
        heapify(arr, n, largest);
    }
}

// 堆排序
void heapSort(int arr[], int n) {
    // 构建最大堆
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // 一个接一个地从堆中取出元素
    for (i=n-1; i>=0; i--) {
        // 移动当前根到末尾
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整减少后的堆
        heapify(arr, i, 0);
    }
}

// 打印数组
void printArray(int arr[], int size) {
	int i;
   for (i=0; i < size; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

// 测试排序算法
int main() {
    int data[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(data)/sizeof(data[0]);
    int i;
	printf("数组为:\n");
    for(i=0;i<7;i++){
    
    	printf("%d\n",data[i]);
	}

    // 复制数组以用于不同排序方法
    int arrInsertion[n], arrSelection[n], arrHeap[n];
    for ( i = 0; i < n; i++) {
        arrInsertion[i] = arrSelection[i] = arrHeap[i] = data[i];
    }

    // 使用不同的排序方法进行排序并打印结果
    insertionSort(arrInsertion, n);
    printf("插入排序后的数组: \n");
    printArray(arrInsertion, n);

    selectionSort(arrSelection, n);
    printf("选择排序后的数组: \n");
    printArray(arrSelection, n);

    heapSort(arrHeap, n);
    printf("堆排序后的数组: \n");
    printArray(arrHeap, n);

    return 0;
}
