#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <thread>

class ObserverInterface {
public:
    virtual void DoSomething() = 0;   // 纯虚函数 
    virtual ~ObserverInterface() {}   // 防止析构函数泄露资源
};

using ObserverInterfacePtr = std::unique_ptr<ObserverInterface>;
class SubjectInterface {
public:
    virtual void Add(ObserverInterfacePtr observerInterface) = 0;
    virtual void Remove(ObserverInterfacePtr observerInterface) = 0;
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
    void Add(ObserverInterfacePtr observerInterface) override {
        observers.push_back(std::move(observerInterface));
    }

    void Remove(ObserverInterfacePtr observerInterface) override {
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
    std::vector<ObserverInterfacePtr> observers;
};

int main() {
    Me me;
    ObserverInterfacePtr wife(new Wife);
    ObserverInterfacePtr son(new Son);

    me.Add(std::move(wife));
    me.Add(std::move(son));

    me.Notify();

    return 0;
}