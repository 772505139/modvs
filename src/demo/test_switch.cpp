#include <demo/test_switch.h>

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

namespace demo {

void RunTestSwitch()
{
    using namespace std;

    enum class Mode { Default, Custom, Standard };
    int value{ 42 };
    Mode mode{ Mode::Custom };

    switch (mode) {
        using enum Mode;
        case Custom:
            value = 84;
            cout << format("Custom mode: value={}\n", value);
            [[fallthrough]];
        case Standard:
            value = 21;
            cout << format("Standard mode: value={}\n", value);
            [[fallthrough]];
        case Default:
            value = 42;
            cout << format("Default mode: value={}\n", value);
            break;
    }
}

} // namespace demo
