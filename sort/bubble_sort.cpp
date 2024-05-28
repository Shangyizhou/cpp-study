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
冒泡排序
    
    优化:如果某次比较完一遍所有元素,并没有发生交换操作,说明数据已经排序完毕,退出循环
    
    稳定性:稳定(因为如果数据相等是不会发生交换操作的,数据的相对位置不改变)
    时间复杂度:O(N2)
*/
void bubble(std::vector<int>& ivec)
{
    //如果元素个数小于等于1,则直接返回
    if (ivec.size() <= 1) return;

    //第一个循环控制趟数,n个数比较n - 1趟
    for (int i = 0; i < ivec.size() - 1; i++) {
        bool flag = true;
        //第二层是控制第 i+1 趟（因为循环中 i 是从 0 开始的）的比较次数，那么 i+1 趟就是比较了 N-1-i 次
        //比如第一趟,第一个数字需要比较四个数字,所以就是 （5 - 0 - 1）次
        for (int j = 0; j < ivec.size() - i - 1; j++) {
            if (ivec[j] > ivec[j + 1]) {
                std::swap(ivec[i], ivec[j]);
                flag = false;
            }
        }
        if (flag == true) break;
    }
}

int main()
{
    std::vector<int> ivec{4, 2, -1, 6, 0, 10, 9, 12};
    show_info(ivec);
    bubble(ivec);
    show_info(ivec);

    return 0;
}