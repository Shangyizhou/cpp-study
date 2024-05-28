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
插入排序:
    像是选择苹果一样,每一次选择一个最大的苹果放入袋中
    首先将首位设为最小标记位,然后在后面的序列中遍历元素与最小标记位元素作比较,如果更小就更新标记位
    最后将交换元素

    稳定性:不稳定   [3 5 3 2] -> [2 5 3 3] (第一个3到了第二个3的后面)
    时间复杂度:O(N2)
*/
void choice_sort(std::vector<int>& ivec)
{
    for (int i = 0; i < ivec.size(); i++) {
        int min_index = i;
        for (int j = i + 1; j < ivec.size(); j++) {
            if (ivec[min_index] > ivec[j]) {
                min_index = j;
            }
        }
        std::swap(ivec[i], ivec[min_index]);
    }
}

int main()
{
    std::vector<int> ivec{4, 2, -1, 6, 0, 10, 9, 12};
    show_info(ivec);
    choice_sort(ivec);
    show_info(ivec);

    return 0;
}