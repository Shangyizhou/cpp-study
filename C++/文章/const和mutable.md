## 案例

```c++
#include <iostream>
#include <string>

class Student
{
public:
    Student() { }
    Student(const std::string& name) : name_(name) { }
    Student(const Student& rhs) : name_(rhs.name_) { }

    //后一个const表示该成员函数不会修改任何成员变量的值
    const std::string GetName() const { return name_; }

    const std::string GetName2() { return name_; }

private:
    std::string name_;
};

//非成员函数上不允许使用类型限定符(出错)
Student func() const
{
    return Student();
}

int main(int argc, char* argv[])
{
    Student s("last_week");
    std::cout << s.GetName() << std::endl;   //last_week
    std::cout << s.GetName2() << std::endl;  //last_week

    const Student s2("last_week_2");
    std::cout << s2.GetName() << std::endl;  //last_week
    std::cout << s2.GetName2() << std::endl; //对象含有与成员 函数 "Student::GetName2" 不兼容的类型限定符
    
    return 0;
}
```

- `常量对象`只可以调用`常量成员函数`
- 非`const`对象，都可以调用`常量成员函数`或是`普通函数`
- `普通函数`末尾是不能加`const`的，编译无法通过，因为`const`在函数末尾的意思是成员函数不会修改该对象里面任何成员变量值，但普通函数根本就没有对象的概念

## mutable

`mutable` 表示不稳定的，容易改变的意思，正好和`const`是相反的意思。引入`mutable`也是为了突破`const`的限制

在末尾有`const`修饰的函数中，我们无法改变类成员对象的值，但有时候我们又需要改变，并且我们不能把末尾的`const`去掉，比如这个成员函数从`const`变成非`const`了，那么就不能被`const`对象调用了

> `const`意思是：“这个函数不修改对象内部状态”。
>
> 为了保证这一点，编译器也会主动替你检查，确保你没有修改对象成员变量——否则内部状态就变了。
>
> `mutable`意思是“这个成员变量不算对象内部状态”。比如，你搞了个变量，用来统计某个对象的访问次数（比如供`debug`用）。它变成什么显然并不影响对象功用，但编译器并不知道：它仍然会阻止一个声明为`const`的函数修改这个变量。
>
> 把这个计数变量声明为`mutable`，编译器就明白了：这个变量不算对象内部状态，修改它并不影响`const`语义，所以就不需要禁止`const`函数修改它了。
> ————————————————
> 版权声明：本文为CSDN博主「zedjay_」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
> 原文链接：https://blog.csdn.net/luke_sanjayzzzhong/article/details/104362340

## 多线程的案例

举个例子：你写了一个基于`mutex`的线程安全的队列。

对外接口应该如下：

```C++
class Queue
{
    public:
    	void push(int x);
    	void pop(int& x);
    	bool empty() const;
}
```

但你使用`empty`这个常量成员函数时肯定也要先获得内部的一个`mutex`，也就是说在`const`函数内部也会改变对象状态，于是要把`mutex`声明成`mutable`的

```C++
class Queue
{
    mutable std::mutex mutex_;
    public:
    	bool empty() const
        {
            std::lock_guard<std::mutex> lk(mutex_);
            //...
        }
}
```

**参考**

- (56 封私信 / 84 条消息) C++中mutable关键字存在的必要性是什么？ - 知乎 (zhihu.com)