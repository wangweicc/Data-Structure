#include <stdio.h>

// ���ֲ��Һ���
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // ����м�Ԫ���Ƿ���Ŀ��ֵ
        if (arr[mid] == target)
            return mid;

        // ���Ŀ��ֵ�����м�Ԫ�أ������Ұ벿�ּ�������
        if (arr[mid] < target)
            left = mid + 1;
        else
            // ��������벿�ֲ���
            right = mid - 1;
    }

    // ������ǵ����������ôԪ�ز���������
    return -1;
}

int main(void) {
    // ����һ����������
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(data) / sizeof(data[0]);
    int target;
    int i;
    
    printf("����Ϊ��\n");
	for(i = 0;i <10;i++){
		
		printf("%d\n",data[i]);
	}
	printf("������Ҫ���ҵ�����: \n"); 
	scanf("%d", &target);
	

    // ���ö��ֲ��Һ���
    int result = binarySearch(data, n, target);

    // ���ݽ�������Ϣ
    if (result != -1) {
        printf("�ҵ��ˣ����� %d �������е�λ��Ϊ %d\n", target, result);
    } else {
        printf("��Ǹ��û���ҵ����� %d\n", target);
    }

    return 0;
}
