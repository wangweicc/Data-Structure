/*
问题描述
给定一个整数序列，采用简单选择排序算法对整数序列进行从小到大排序，输出排序后的结果。

输入描述
在第一行中给出待排序整数的个数n，第二行中分别给出n个整数，之间用空格隔开。

输出描述
输出排序后的结果，每个数字之间用空格分隔。

样例输入
6
11 29 89 64 53 20

样例输出
11 20 29 53 64 89
*/

#include <stdio.h>

// 选择排序算法
void SelectSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        // 假设当前索引是最小值的索引
        min_idx = i;
        // 查找未排序部分中的最小元素
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 交换找到的最小元素与未排序部分的第一个元素
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 调用选择排序函数
    SelectSort(arr, n);

    // 输出排序后的数组
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n-1) {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}