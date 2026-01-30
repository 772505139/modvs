#include "demo/test_InitializerList.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

using namespace std;

namespace demo {
int makeSum(initializer_list<int> list) {
    int sum = 0;
    for (int value : list) {
        sum += value;
    }
    return sum;
}

void Runtest_InitializerList() {
    int a { makeSum({1, 2, 3, 4, 5}) };
    int b { makeSum({10, 20, 30}) };
    //int c { makeSum({1, 2, 3.0}) };   // 编译错误：窄化。Error: narrowing conversion from 'double' to 'int'
    cout << format("a = {}, b = {}", a, b) << endl;
}

} // namespace demo