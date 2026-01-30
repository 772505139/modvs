#include "demo/test_Loop.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

namespace demo {
void RunTest_Loop()
{
    using namespace std;
    int i {0};
    while ( i < 5 ) {
        cout << "while循环。重复执行5次" << endl;
        ++i;
    }

    int j { 100 };
    do {
        cout << "do...while循环。错也要执行1次：" << endl;
        ++j;
    } while ( j < 5 );

    for (int i { 0 }; i < 5; ++i) {
     cout << "for循环。重复执行5次" << endl;
    }

    array <int,5> arr = {1,2,3,4,5};
    for ( int i : arr ) { cout << format("范围for循环，当前元素值为：{}",i) << endl; }

    cout << "给予范围的for循环的初始化器：" << endl;
    for (array myarr {1,2,3,4,5}; int i : myarr ) { cout << format("当前元素值为：{}",i) << endl; }
}

} // namespace demo

