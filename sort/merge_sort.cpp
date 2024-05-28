#include <iostream>
#include <vector>
#include <algorithm>

void show_info(const std::vector<int>& ivec)
{
    for (auto i : ivec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/*
归并排序:
    时间复杂度:O(NlongN)
    空间复杂度:O(N)

*/
std::vector<int> tmp;
void merge_sort(std::vector<int> ivec, int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort(ivec, left, mid);
    merge_sort(ivec, mid + 1, right);

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (ivec[i] <= ivec[j]) tmp[k++] = ivec[i++];
        else tmp[k++] = ivec[j++]; 
    }
    while (i <= mid) tmp[k++] = ivec[i++];
    while (j <= right) tmp[k++] = ivec[j++];

    for (int i = left, j = 0; i <= right; i++, j++)
        ivec[i] = tmp[j];
}

int main()
{
    std::vector<int> ivec{4, 2, -1, 6, 0, 10, 9, 12};
    show_info(ivec);
    tmp.reserve(ivec.size());
    merge_sort(ivec, 0, ivec.size() - 1);
    show_info(ivec);

    return 0;
}