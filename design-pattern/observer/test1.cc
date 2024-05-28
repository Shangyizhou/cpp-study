#include <iostream>

class Son {
public: 
    void DoSomething() {
        std::cout << "爸爸回来了，赶紧写作业" << std::endl;
    }
};

class Wife {
public:
    void DoSomething() {
        std::cout << "老公回来了，做饭" << std::endl;
    }
};

class Me {
public:
    void GoHome() {
        wife.DoSomething();
        son.DoSomething();
    }

private:
    Son son;
    Wife wife;
};

int main() {
    Me me;
    me.GoHome();

    return 0;
}

// https://zhuanlan.zhihu.com/p/119308881
// 这其实就有着观察者模式的样子
// 观察到父亲回来时，然后观察者调用不同的处理方式
// 不过还不够抽象，可以将观察者抽象为一个接口/虚函数，然后每个类重写自己的DoSomething方法
// 被观察者同样也需要抽象，比如某个实例就是父亲作为被观察者，也可以是用另一个爷爷类当作被观察者
// 被观察者要拥有可以数据结构可以保存注册的观察者，提供注册观察者的方法以及移除观察者的方法，还需要有触动事件发生的方法