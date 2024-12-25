/*
���ֲ���
��������
С����ͼ��ݽ����鼮��ͼ��ݵ��鼮��ϵͳ�а����˳�����У�С���ڽ��ĺ�����ϵͳ�дӡ��ڹ��鼮�б��н�����ɾ���������С����дһ���������������б�{1, 3, 5, 6, 7, 10, 12, 14, 26, 32, 35, 39, 42, 45, 54, 56, 69, 73, 75, 80, 82, 86, 89, 94, 98, 100, 104, 132, 148, 150}��ʹ�ö��ֲ��ҵķ����ҵ���ͼ����ţ������б��У��������ɾ�������ء�Book borrowing successful�����������б��У���ɾ��ʧ�ܣ����ء�Book borrowing failed����


��������
��һ������һ������n����ʾ�����鼮������
�ڶ�������n�����֣�����Ϊ�����鼮����š�


�������
���ɾ���������Book borrowing successful����Book borrowing failed����


��������
2
54 103
                    

�������
Book borrowing successful
Book borrowing failed
*/


#include <stdio.h>
#define BOOK_COUNT 30
int books[BOOK_COUNT] = {1, 3, 5, 6, 7, 10, 12, 14, 26, 32, 35, 39, 42, 45, 54, 56, 69, 73, 75, 80, 82, 86, 89, 94, 98, 100, 104, 132, 148, 150};
int binary_search(int value, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (books[mid] == value)
            return mid;
        else if (books[mid] < value)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
void remove_book_at_index(int index) {
    for (int i = index; i < BOOK_COUNT - 1; i++) {
        books[i] = books[i + 1];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int new_count = BOOK_COUNT;
    for (int i = 0; i < n; ++i) {
        int book_id;
        scanf("%d", &book_id);
        int index = binary_search(book_id, 0, new_count - 1);
        
        if (index != -1) {
            printf("Book borrowing successful\n");
            remove_book_at_index(index);
            --new_count;
        } else {
            printf("Book borrowing failed\n");
        }
    }
    return 0;
}




/*
��ϣ����
��������
��ɢ�б�a[18]��ɢ�к�����hask(k)=k%p������pȡ17�����ÿ��ŵ�ַ�������ͻhi=( hask(k) di)%m����ͻʱ��ʹ����������di=5i��������������(ֵ>=0)��Ӧ��ɢ�е�ֵַ����Ҫ�����������1-15����С��1�����15���ڱ���Χ�ڣ�������������������Ч����,���������������������ʾ�����������������ϣ��������������


��������
��һ��Ϊ���������p��ֵ��
�ڶ���Ϊ��Ӧ������ֵ���ÿո������


�������
������˳�������ɢ�е�ַ��ÿ�ж�Ӧһ��ֵ����ɢ�е�ַ���м��ÿո��������posǰ�����һ���ո񣩡�


��������
5 17
141 73 95 112 56

                    

�������
141 pos: 5 
73 pos: 10 
95 pos: 15 
112 pos: 2 
56 pos: 7
*/

#include <iostream>
#include <vector>
using namespace std;

int hask(int k, int p) {
    return k % p;
}

int main() {
    int n, p;
    cin >> n >> p;
    if (n < 1 || n > 15) {
        if (n <= 18) {
            cout << "���������Ч��" << endl;
        } else {
            cout << "�������������ϣ��������" << endl;
        }
        return 0;
    }
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }
    for (int i = 0; i < n; ++i) {
        int pos = hask(input[i], p);
        int di = 0;
        while (true) {
            int curPos = (pos + 5 * di) % 18;
            bool flag = false;
            for (int j = 0; j < i; ++j) {
                if ((pos + 5 * di) % 18 == hask(input[j], p)) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                pos = curPos;
                break;
            }
            di++;
        }
        cout << input[i] << " pos: " << pos << endl;
    }
    return 0;
}


