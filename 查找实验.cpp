/*
二分查找
问题描述
小明在图书馆借阅书籍，图书馆的书籍在系统中按序号顺次排列，小明在借阅后，需在系统中从“在馆书籍列表”中将该书删除。请帮助小明编写一个函数，在现有列表{1, 3, 5, 6, 7, 10, 12, 14, 26, 32, 35, 39, 42, 45, 54, 56, 69, 73, 75, 80, 82, 86, 89, 94, 98, 100, 104, 132, 148, 150}中使用二分查找的方法找到该图书序号，若在列表中，将该序号删除，返回“Book borrowing successful”；若不在列表中，则删除失败，返回“Book borrowing failed”。


输入描述
第一行输入一个整数n，表示借阅书籍本数。
第二行输入n个数字，依次为借阅书籍的序号。


输出描述
输出删除结果，“Book borrowing successful”或“Book borrowing failed”。


样例输入
2
54 103
                    

样例输出
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
哈希查找
问题描述
设散列表a[18]，散列函数是hask(k)=k%p（其中p取17），用开放地址法解决冲突hi=( hask(k) di)%m。冲突时，使用增量序列di=5i。计算输入序列(值>=0)对应的散列地址值。（要求输入个数在1-15，如小于1或大于15且在表长范围内，则输出：“输入个数无效！”,如输入个数超过表长，则提示：“输入个数超过哈希表容量。”）。


输入描述
第一行为输入个数和p的值；
第二行为对应的输入值，用空格隔开。


输出描述
按输入顺序输出其散列地址，每行对应一个值及其散列地址，中间用空格隔开（即pos前后均有一个空格）。


样例输入
5 17
141 73 95 112 56

                    

样例输出
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
            cout << "输入个数无效！" << endl;
        } else {
            cout << "输入个数超过哈希表容量。" << endl;
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









