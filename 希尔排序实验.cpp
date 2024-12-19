/*
问题描述
随着安庆市经济的蓬勃发展，各县区国内生产总值（GDP）排名新鲜出炉，展现了一幅安庆市经济版图的壮丽画卷。
请根据给出的各县区的GDP数据，采用希尔排序算法进行排序（要求增量大小分别取5，3，1）。

输入描述
第一行输入整数n，表示待排序序列的个数；
第二行为n个待排序的GDP数据（单位为亿元），每个数据之间用空格分隔。

输出描述
分行输出排序每一趟后的GDP序列，数字之间用空格分隔，保留两位小数。

样例输入
10
452.02 344.9 305.6 262.52 253.1 237.2 211.9 210.85 202.49 233.18

样例输出
第1趟排序后：237.20 211.90 210.85 202.49 233.18 452.02 344.90 305.60 262.52 253.10  
第2趟排序后：202.49 211.90 210.85 237.20 233.18 262.52 253.10 305.60 452.02 344.90 
第3趟排序后：202.49 210.85 211.90 233.18 237.20 253.10 262.52 305.60 344.90 452.02
*/

#include <stdio.h>
#include <math.h>

// 希尔排序函数
void shellSort(double arr[], int n) {
    // 定义增量序列
    int gaps[] = {5, 3, 1};
    int size = sizeof(gaps)/sizeof(gaps[0]);

    for (int i = 0; i < size; i++) {
        int gap = gaps[i];
        for (int j = gap; j < n; j++) {
            double temp = arr[j];
            int k;
            for (k = j; k >= gap && arr[k - gap] > temp; k -= gap) {
                arr[k] = arr[k - gap];
            }
            arr[k] = temp;
        }

        // 输出每一趟排序后的结果
        printf("第%d趟排序后：", i + 1);
        for (int l = 0; l < n; l++) {
            printf("%.2f", arr[l]);
            if (l < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    double gdp[n];
    for (int i = 0; i < n; i++) {
        scanf("%lf", &gdp[i]);
    }

    // 调用希尔排序函数
    shellSort(gdp, n);
    
    return 0;
}