#include "demo/test_String.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

using namespace std;

namespace demo {

void Runtest_String() {
    string str1 = "Hello, ";
    string str2 = "World!";
    string str3 = str1 + str2;
    cout << format("Concatenated String: {}", str3) << endl;

    size_t length = str3.length();
    cout << format("Length of String: {}", length) << endl;

    string substring = str3.substr(7, 5);
    cout << format("Substring: {}", substring) << endl;

    size_t pos = str3.find("World");
    if (pos != string::npos) {
        cout << format("'World' found at position: {}", pos) << endl;
    } else {
        cout << "'World' not found" << endl;
    }

    cout << str3[1] << endl; // Output character at index 1
}

} // namespace demo