#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class ObserverInterface {
public:
    virtual void DoSomething() = 0;
    virtual ~ObserverInterface() {}
};

using ObserverInterfacePtr = unique_ptr<ObserverInterface>;
class SubjectInterface {
public: 
    virtual void AddObserver(ObserverInterfacePtr observerInterface) = 0;
    virtual void RemoveObserver(ObserverInterfacePtr observerInterface) = 0;
    virtual void Notify() = 0;

    virtual ~SubjectInterface() {}
};


class Son : public ObserverInterface {
public:
    void DoSomething() override {
        cout << "Son Do something" << endl;
    }
    ~Son() {
        cout << "Son 析构" << endl;
    }
};

class Wifi : public ObserverInterface {
public:
    void DoSomething() override {
        cout << "Wifi" << endl;
    }
    ~Wifi() {
        cout << "Wifi 析构" << endl;
    }
};


class Father : public SubjectInterface {
public:
    void AddObserver(ObserverInterfacePtr ob) override {
        observers.push_back(std::move(ob));
    }

    void RemoveObserver(ObserverInterfacePtr ob) override {
        auto position = find(observers.begin(), observers.end(), ob);
        if (position != observers.end()) {
            observers.erase(position);
        }
    }

    void Notify() override {
        for (const auto& observer : observers) {
            observer->DoSomething();
        }
    }

private:
    vector<ObserverInterfacePtr> observers;
};

int main() {
    Father father;
    ObserverInterfacePtr wife(new Wifi);
    ObserverInterfacePtr son(new Son);
    father.AddObserver(move(wife));
    father.AddObserver(move(son));
    father.Notify();
}