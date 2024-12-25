#include <stdio.h>

// 二分查找函数
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // 检查中间元素是否是目标值
        if (arr[mid] == target)
            return mid;

        // 如果目标值大于中间元素，则在右半部分继续查找
        if (arr[mid] < target)
            left = mid + 1;
        else
            // 否则，在左半部分查找
            right = mid - 1;
    }

    // 如果我们到达了这里，那么元素不在数组中
    return -1;
}

int main(void) {
    // 定义一个有序数组
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(data) / sizeof(data[0]);
    int target;
    int i;
    
    printf("数组为：\n");
	for(i = 0;i <10;i++){
		
		printf("%d\n",data[i]);
	}
	printf("请输入要查找的数字: \n"); 
	scanf("%d", &target);
	

    // 调用二分查找函数
    int result = binarySearch(data, n, target);

    // 根据结果输出信息
    if (result != -1) {
        printf("找到了！数字 %d 在数组中的位置为 %d\n", target, result);
    } else {
        printf("抱歉，没有找到数字 %d\n", target);
    }

    return 0;
}
