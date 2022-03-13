## count_if函数

```c++
#include <iostream>
#include <vector>
#include <algorithm>

bool IsLess(const int& i)
{
    return i < 0;
}

int main()
{
    std::vector<int> vec{10, -1, 0, -15, 20};
    int res = std::count_if(vec.cbegin(), vec.cend(), IsLess); //函数指针IsLess
    printf("%d nums < 0\n", res);

    return 0;
}
```

```c++
2 nums < 0
```

> 现在有一个需求，需要求出该数组中小于`len`的元素个数，`len`由人们指定

如果直接传入参数那么是不行的

```c++
#include <iostream>
#include <vector>
#include <algorithm>

bool IsLess(const int& i, const int& len)
{
    return i < len;
}

int main()
{
    int len = 0;
    std::vector<int> vec{10, -1, 0, -15, 20};
    //问题来了,如何把len参数传递进去,count_if要求的是unary function（仅带有一个参数）作为它的最后一个参数。
    int res = std::count_if(vec.cbegin(), vec.cend(), len);
    printf("%d nums < 0\n", res);

    return 0;
}
```

```c++
template< class InputIt, class UnaryPredicate >
typename iterator_traits<InputIt>::difference_type
    count_if( InputIt first, InputIt last, UnaryPredicate p );
```

- `Predicate`：一种特殊的辅助函数，它会返回`Boolean`，常常被用来作为排序或者查找准则。
- `unary`：一元的
- `UnaryPredicate`：单参判断式，该函数指针指向的函数类型只能接收一个参数

**因此，我们不能传入两个参数**

我们可以设置全局变量，然后在`IsLess`内部与该全局变量作比较，不过此举动会比较危险，破坏封装性，没有可拓展性

## 仿函数（早期STL就是使用仿函数）

- `仿函数(functor)`又称为`函数对象(function object)`，它是一个能行使函数功能的类。
- 仿函数的语法几乎和我们普通的函数调用一样，不过作为仿函数的类，都必须重载`()`运算符

那么既然是以类实现，那么自然就会有成员变量，我们可以通过成员变量来获取参数

```c++
#include <iostream>
#include <vector>
#include <algorithm>

//仿函数:一个能行使函数功能的类
class IsLess
{
public:
    //通过有参构造函数获取len,这样在operator()函数内部就可以访问该变量了
    explicit IsLess(const int& compare_number) : size(compare_number) { }
    bool operator()(const int& n) { //重载括号运算符
        return n < size;
    }
private:
    const int size;
};

int main()
{
    //不确定的len值,所以需要传递过去
    int len;
    std::cin >> len;

    std::vector<int> vec{10, -1, 0, -15, 20};
    /*	
    	这里IsLess调用了bool operator()(const int& n),还是一个参数的函数(count_if可以接收)
    	但是可以通过访问其成员变量得到len
    */
    int res = std::count_if(vec.cbegin(), vec.cend(), IsLess(len));
    printf("%d nums < %d\n", res, len);

    return 0;
}
```

```c++
11
4 nums < 11
```

> 第二个例子

```c++
#include <iostream>
#include <vector>
#include <algorithm>

/*
函数对象的出现是为了代替函数指针的，最明显的一个特点是：可以使用内联函数。
而如果使用内联函数的指针，编译器会把它当普通函数对待。
另外，函数对象是类封装的，代码不但看起来简洁，设计也灵活，这样有利于资源的管理
(我们总不能实现一个功能就去定义一个全局函数吧)
*/
class Compare {
private:
    int m_number;

public:
    Compare(int num) : m_number(num) { }

    bool operator()(const int& other) {
        return other < m_number;
    }
};

int main()
{
    std::vector<int> vec = {10, 20, 0, -10, -20};
    int res = std::count_if(vec.begin(), vec.end(), Compare(10));
    std::cout << res << std::endl; // 3(小于10的元素有3个)

    return 0;
}
```

**仿函数优点**

- 利于封装，利于资源管理，通过访问成员变量形式获取额外参数
- 可以被编译器当作内联函数，加快速度；函数指针的话就是函数调用了，会比较慢

## lambda表达式

- `lambda`表达式是在C++11引入的，是C++一种新特性。
- 使用`lambda`可以在向函数传递函数实参的时候，直接写一个`lambda`表达式，用来代替仿函数。
- `lambda`表达式使用更加简洁，不需要再重载`()`运算符。
- 利用`Lambda`表达式，可以方便的定义和创建 **匿名函数**

**Lambda表达式完整的格式声明**

```c++
[capture list] (params list) mutable exception-> return type { function body }
```

- `capture list`：捕获外部变量列表
- `params list`：形参列表
- `mutable`：标明是否可以修改捕获的变量
- `return type`：返回类型
- `function body`：函数体

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int num = 0;
    std::vector<int> vec = {10, 20, 0, -10, -20};
    //num是外部变量捕获,elem是count_if遍历vec容器每个值传递进去的,函数体作比较
    //我们可以省略返回类型,会被自动推导出来
    int res = std::count_if(vec.begin(), vec.end(), [num](int elem){ return elem < num; });
    std::cout << res << std::endl; //2

    return 0;
}
```

**使用mutable**

如果想要在`lambda`表达式内部改变捕获的变量，那么需要添加`mutable`关键字

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int num = 0;
    std::vector<int> vec = {10, 20, 0, -10, -20};
    //num是外部变量捕获,elem是count_if遍历vec容器每个值传递进去的,函数体作比较
    //我们可以省略返回类型,会被自动推导出来
    for_each(vec.begin(), vec.end(), [&num](const int& elem) mutable {
        num = 1; 
        std::cout << elem << " ";
        return true;});
    std::cout << std::endl;
    std::cout << num << std::endl;
    
    return 0;
}
```

注意，我们这里是`&num`，是引用捕获，如果是值捕获，那么改变的是拷贝得来的变量

**变量捕获的多种形式**

> [] 不捕获任何变量,这种情况下lambda表达式内部不能访问外部的变量。
> [&] 以引用方式捕获所有变量
> [=] 用值的方式捕获所有变量（可能被编译器优化为const &)
> [=, &foo] 以引用捕获变量foo, 但其余变量都靠值捕获
> [&, foo] 以值捕获foo, 但其余变量都靠引用捕获
> [bar] 以值方式捕获bar; 不捕获其它变量
> [this] 捕获所在类的this指针 （Qt中使用很多，如此lambda可以通过this访问界面控件的数据）
>
> [(199条消息) C++ lambda表达式入门_混沌的博客-CSDN博客_c++lambda表达式](https://blog.csdn.net/a379039233/article/details/83714770?ops_request_misc=%7B%22request%5Fid%22%3A%22164707992316781683957173%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=164707992316781683957173&biz_id=0&spm=1018.2226.3001.4187)

## 参考

- [(199条消息) C++operator()(重载小括号运算符)_jinzhu1911的专栏-CSDN博客_c++ operator()](https://blog.csdn.net/jinzhu1911/article/details/101317367?spm=1001.2101.3001.6650.1&depth_1-utm_relevant_index=2)
- [C++ 回调函数、仿函数和lambda表达式 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/145598485)
- [11 C++ 仿函数为何而生 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/362323211)
- [(199条消息) C++仿函数和Lambda表达式_bajianxiaofendui的博客-CSDN博客_仿函数和lambda](https://blog.csdn.net/bajianxiaofendui/article/details/86583612?ops_request_misc=%7B%22request%5Fid%22%3A%22164707483116780274190288%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=164707483116780274190288&biz_id=0&spm=1018.2226.3001.4187)