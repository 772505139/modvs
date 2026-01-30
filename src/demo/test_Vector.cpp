#include "demo/test_Vector.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;
namespace demo {

void test_vector()
{
    using namespace std;
    //Create a vector of integers.
    vector<int> myVector1 {11, 22};
    //Add some more integers to the vector using push back().
    myVector1.push_back(33);
    myVector1.push_back(44);
    //Access elements.
    cout << format("lst element:{}",myVector1[0])<< endl;

    //Create and initialize a vector using an initializer list.
    vector myVector2 {100, 200, 300, 400};
    cout << format("2nd element:{}",myVector2[1])<< endl;
}

}