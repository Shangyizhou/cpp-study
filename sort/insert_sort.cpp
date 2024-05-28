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
    [3 2 1]
        [2 3 1]:保存2和前面的比较,前面更大则往后移动,pre_index由0递减成-1,所以pre_index + 1为插入位置
    O(1)的额外空间
    O(N2)

*/
void insert_sort(std::vector<int>& ivec)
{
    int pre_index, current;
    for (int i = 1; i < ivec.size(); i++) {
        pre_index = i - 1;
        //相当于要抽出去放好的牌
        current = ivec[i];
        while (pre_index >= 0 && ivec[pre_index] > current) {
            ivec[pre_index + 1] = ivec[pre_index];
            pre_index--;
        }
        ivec[pre_index + 1] = current;
    }
}

int main()
{
    std::vector<int> ivec{4, 2, -1, 6, 0, 10, 9, 12};
    show_info(ivec);
    insert_sort(ivec);
    show_info(ivec);

    return 0;
}