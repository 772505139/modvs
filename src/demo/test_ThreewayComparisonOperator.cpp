#include "demo/test_ThreewayComparisonOperator.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

namespace demo {
void RunThreewayComparisonOperatorDemo(int i)
{
    using namespace std;
    cout << format("三向比较运算符输出，与0比较: {}\n", (i <=> 0) == strong_ordering::less ? "less" : (i <=> 0) == strong_ordering::greater ? "greater" : "equal");
    strong_ordering result { i <=> 0 };
    if ( result == strong_ordering::less ) { cout << "less" << endl; }
    if ( result == strong_ordering::greater ) { cout << "greater" << endl; }
    if ( result == strong_ordering::equal ) { cout << "equal" << endl; }
    if (is_lt(result)) { cout << "is less" << endl; }
    if (is_gt(result)) { cout << "is greater" << endl; }
    if (is_eq(result)) { cout << "is equal" << endl; }
}
} // namespace demo