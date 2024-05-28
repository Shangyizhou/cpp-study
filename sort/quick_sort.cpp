#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//使用的是双指针法
//闭区间
/*
双指针法:
    闭区间
    为什么定左边为基数,就要先走右边
        比如 [ 1 2 3 ]
        如果先走左边,那么i走到2,j走到2与i相遇,然后交换位置得到 [2 1 3]
        i先停下的,那么i得到的就是一个大于基数的值,j找到i,他们在i原来这个位置相遇,经过交换之后,基数左边的值大于了基数,这是不符合定义的
*/
void QuickSort(vector<int>& vec, int left, int right)
{
    if (left > right) return;
    int i = left, j = right;
    int temp = vec[left];
    while (i != j) {
        //左边作为基数,先走右边
        while (vec[j] >= temp && j > i) j--;
        while (vec[i] <= temp && j > i) i++;
        //倘若相等则直接跳出
        if (j > i)
            swap(vec[i], vec[j]);
    }
    //相遇位置与基数位置交换值
    //自此,基数左边的值小于它,基数右边的值大于它
    swap(vec[left], vec[i]);
    //递归处理
    //发现没有,我们的参数不包含中间的i,即相遇的值,因为它的位置已经确定,不需要改变(左边值都小于它,右边值都大于它)
    QuickSort(vec, left, i - 1);
    QuickSort(vec, i + 1, right);
}

int main()
{
    vector<int> vec = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    QuickSort(vec, 0, vec.size() - 1);
    for (const auto& elem : vec)
        cout << elem << " ";
    cout << endl;

    return 0;
}