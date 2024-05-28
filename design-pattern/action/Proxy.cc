//携程买票
#include <iostream>
#include <string>
using namespace std;
/*
    1.提供一个抽象主题角色：真实主题与代理主题的共同接口
    2.提供一个真实主题角色：定义了代理角色所代表的真实对象
    3.提供一个代理主题角色：含有对真实主题角色的引用
*/
class AbstractSubject 
{
public:
    virtual void BuyTicket() = 0;
};

// 实际买票行为
class User : public AbstractSubject
{
public:
    void BuyTicket() 
    {
        cout << "用户购票" << endl;
    }
};

// 代理买票
class Ctrip :public AbstractSubject 
{
public:
    Ctrip(AbstractSubject* pBase)
    {
        this->pBase = pBase;
    }
    void BuyTicket() 
    {
        cout << "携程购票" << endl;
    }

private:
    AbstractSubject* pBase;
};

int main() 
{
    AbstractSubject* pBase = new User;
    pBase->BuyTicket();
    // 这里是使理类进行买票操作
    Ctrip* proxy = new Ctrip(pBase);
    proxy->BuyTicket();

    return 0;
}