#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// void max_heapify(vector<int>& arr, int start, int end)
// {
//     //建立父节点指标和子节点指标
//     int dad = start;
//     int son = dad * 2 + 1;
//     while (son <= end) { //若子节点指标在范围内才做比较
//         if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
//             son++;
//         if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
//             return;
//         else { //否则交换父子内容再继续子节点和孙节点比较
//             swap(arr[dad], arr[son]);
//             dad = son;
//             son = dad * 2 + 1;
//         }
//     }
// }

// void heap_sort(vector<int>& arr, int len)
// {
//     //初始化，i从最后一个父节点开始调整
//     for (int i = len / 2 - 1; i >= 0; i--)
//         max_heapify(arr, i, len - 1);
//     //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
//     for (int i = len - 1; i > 0; i--) {
//         swap(arr[0], arr[i]);
//         max_heapify(arr, 0, i - 1);
//     }
// }

/**
 * 分为两个过程
 * 1. 建堆，普遍以大顶堆为例子，但是此时只是大顶堆而非是排好序的元素，O(n)时间复杂度，数列求和
 * 2. 维护堆，需要每次将堆顶元素移除（放数组末尾后），然后剩余元素重新排列，相当于每次将最大值放到了数组末尾，有点选择排序的意思
 * 因此，最大堆可以得到最小的K个数字，对N个数字进行排序，每次维护的heapify方法都是logk，因此是 nlog(k)
*/

/**
 * 建立堆
*/
void max_heapify(vector<int>& arr, int start, int end) {
    int left = start * 2 + 1;
    int right = start * 2 + 2;
    int max_flag = start;
    if (left <= end && arr[max_flag] < arr[left]) 
        max_flag = left;
    if (right <= end && arr[max_flag] < arr[right])
        max_flag = right;
    if (max_flag != start) {
        swap(arr[max_flag], arr[start]);
        max_heapify(arr, max_flag, end);
    }
}

/**
 * 建立堆
 * 维护堆
*/
void heap_sort(vector<int>& arr, int len) {
    // O(n)
    for (int i = len / 2 - 1; i >= 0; i--) {
        max_heapify(arr, i, len - 1);
    }
    // O(nlogn) n次循环，每次需要logn
    for (int i = len - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        // O(logn)
        max_heapify(arr, 0, i - 1);
    }
}

int main()
{
    vector<int> arr = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = arr.size();
    heap_sort(arr, len);
    for (const auto& elem : arr)
        cout << elem << " ";
    cout << endl;

    return 0;
}