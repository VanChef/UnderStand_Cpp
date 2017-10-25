

#include <iostream>
#include <string>

using namespace std;

/*
编译命令：
g++ -std=c++11 shared_ptr.cpp -o shared_ptr

希望对shared_ptr有更深入的理解

*/

int main() {

    //传递给make_shared函数的参数必须和shared_ptr所指向类型的某个构造函数相匹配
    shared_ptr<string> pStr = make_shared<string>(10, 'a'); //表示构造一个将‘a’重复10遍的string
    cout << *pStr << endl;  //  aaaaaaaaaa

    cout << "use count " << pStr.use_count() << endl;  //  1

    shared_ptr<string> pStr2(pStr);

    /*
     * 《c++ primer》上的介绍：
       每个shared_ptr都有一个关联的计数值，通常称为引用计数。无论何时我们拷贝一个shared_ptr，计数器都会递增。
       例如，当用一个shared_ptr初始化另一个shred_ptr，或将它当做参数传递给一个函数以及作为函数的返回值时，它
       所关联的计数器就会递增。当我们给shared_ptr赋予一个新值或是shared_ptr被销毁（例如一个局部的
       shared_ptr离开其作用域）时，计数器就会递减。一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理
       的对象。
    */
    cout << "use count " << pStr.use_count() << endl;  // 2
    cout << "use count " << pStr2.use_count() << endl;  // 2

    int *p = new int(5);
    shared_ptr<int> pInt(p);
    cout << *pInt << endl;  // 5

    return 0;
}

