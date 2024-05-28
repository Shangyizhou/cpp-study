#include <iostream>
#include <vector>
#include <algorithm>

class ObserverInterface {
public:
    virtual void DoSomething() = 0;   // 纯虚函数 
    virtual ~ObserverInterface() {}   // 防止析构函数泄露资源
};

class SubjectInterface {
public:
    virtual void Add(ObserverInterface* observerInterface) = 0;
    virtual void Remove(ObserverInterface* observerInterface) = 0;
    virtual void Notify() = 0;

    virtual ~SubjectInterface() {}
};

class Wife : public ObserverInterface {
public:
    Wife() {}
    void DoSomething() override {
        std::cout << "老公快回家了，开始做饭" << std::endl;
    }
};

class Son : public ObserverInterface {
public:
    void DoSomething() override {
        std::cout << "父亲快会回家了，开始写作业" << std::endl;
    }
};

class Me : public SubjectInterface {
public:
    void Add(ObserverInterface* observerInterface) {
        observers.push_back(observerInterface);
    }

    void Remove(ObserverInterface* observerInterface) {
        auto positon = std::find(observers.begin(), observers.end(), observerInterface);
        if (positon != observers.end()) {
            observers.erase(positon);
        }
    }

    void Notify() {
        for (const auto& ob : observers) {
            ob->DoSomething();
        }
    }

private:
    std::vector<ObserverInterface*> observers;
};

int main() {
    Me me;
    ObserverInterface* wife = new Wife;
    ObserverInterface* son = new Son;

    me.Add(wife);
    me.Add(son);

    me.Notify();

    delete wife;
    delete son;

    return 0;
}