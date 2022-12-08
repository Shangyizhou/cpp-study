## extern

```c++
By using 'extern', you are telling the compiler that whatever follows it will be found (non-static) at link time; don't reserve anything for it in the current pass since it will be encountered later. Functions and variables are treated equally in this regard.
```

这大概是说：添加extern声明，可以让编译器把“寻找定义”这件事情推迟到链接阶段，而不会在编译阶段报“没有定义”的错误。

**案例**

```c++
#include <iostream>

int main()
{
    x = 10;

    return 0;
}
```

```c++
g++ main.cpp -c 
main.cpp: In function ‘int main()’:
main.cpp:6:5: error: ‘x’ was not declared in this scope
     x = 10;
```

**增加extern**

```c++
#include <iostream>

extern int x;

int main()
{
    x = 10;

    return 0;
}
```

```c++
g++ main.cpp -c 
ls
head.cpp  head.h  main.cpp  main.o
```

我们可以发现，编译阶段没有报错

一个程序有多个源文件，编译阶段，这些源文件单独编译。得到的文件不能单独运行，因为是单独编译的，有些文件中找不到其他文件的变量和函数，所以还需经过链接阶段才生成可执行文件。

**外部函数：**如果在当前文件中定义的函数**允许**其他文件访问、调用，就称为外部函数。C语言规定，不允许有同名的外部函数。

**内部函数：**如果在当前文件中定义的函数**不允许**其他文件访问、调用，只能在内部使用，就称为内部函数。C语言规定不同的源文件可以有同名的内部函数，并且互不干扰

```c++
//func.c
#include <stdio.h>

//默认情况下,函数自带extern效果(外部函数)
extern void func() {
	printf("调用了func函数\n");
}
```

```c++
//main.c
#include "func.c"


//现在我们想在main.c调用func()函数,我们直接包含了func.c这个文件
int main()
{
	func();
		
	return 0;
}
```

```c++
gcc main.c func.c -o main
/tmp/cc54ZXia.o: In function `func':
func.c:(.text+0x0): multiple definition of `func' //func重定义了
/tmp/cchXg4Zu.o:main.c:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status
```

因为对于`#include`来说，相当与把`func.c`文件的内容又拷贝了一份到`main.c`中，所以`main.c`中有一个`func`函数，而`func.c`中也有一个`func`函数，这两个函数都是全局可见的，所以链接器犯了难题，到底要调用哪个函数呢。

**其实，我们只要在main.c中提前声明func函数即可**

```c++
extern void func()
```

而`extern`又是函数声明和定义默认就有的，所以可以不用加

我们经常喜欢这样子使用，将函数声明放到头文件中，然后要使用该函数的文件包含该头文件，那就相当于函数声明了。

**static**

可以声明内部函数，该函数在其他文件中不可见。所以，其他文件可以相同名称的内部函数

## **C语言中的声明和定义:**

```text
1. 函数和变量的声明不会分配内存, 但是定义会分配相应的内存空间
2. 函数和变量的声明可以有很多次, 但是定义最多只能有一次
3. 函数的声明和定义方式默认都是 extern 的, 即函数默认是全局的
4. 变量的声明和定义方式默认都是局部的, 在当前编译单元或者文件内可用
```

函数的声明和定义默认是`extern`，即全局可见的

 ```c++
 int add(int a, int b);
 ```

在编译器看来, 和下面的代码等价:

```c++
extern int add(int a, int b);
```

如果使用`static`

```c++
static int add(int a, int b);
```

**static**修饰的 **function** 表明这个函数只对于当前文件中的其他函数是可见的, 其他文件中的函数不能够调用.

## 参考

- [C语言中 extern 和 static 总结 - 知乎 (zhihu.com)](https://zhuanlan.zhihu.com/p/27586298)
- [CPlusPlusThings/basic_content/extern at master · Light-City/CPlusPlusThings (github.com)](https://github.com/Light-City/CPlusPlusThings/tree/master/basic_content/extern)
- [(88 封私信 / 83 条消息) extern static - 搜索结果 - 知乎 (zhihu.com)](https://www.zhihu.com/search?type=content&q=extern static)











































