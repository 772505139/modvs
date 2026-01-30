#include "demo/test_Optional.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;


using namespace std;

optional<int> getData(bool giveIt) {
    if (giveIt) {
        return 42;
    } 
    return nullopt;
}

namespace demo {

void RunTest_Optional() 
{
    optional<int> value1 { getData(true) };
    optional<int> value2 { getData(false) };

    cout << "Value1.has_value(): " << value1.has_value() << endl;
    if (value2) {
        cout << "Value2: " << *value2 << endl;
    } else {
        cout << "Value2 is empty." << endl;
    }

    cout << "value1.value(): " << value1.value() << endl;
    cout << "value1解引用: " << *value1 << endl;

    try {
        cout << "value2.value(): " << value2.value() << endl;
    } catch (const bad_optional_access& e) {
        cout << "Caught exception when accessing value2: " << e.what() << endl;
    }

    cout << "value1.value_or(100): " << value1.value_or(100) << endl;
    cout << "value2.value_or(100): " << value2.value_or(100) << endl;
}

void RunTest_Pair() 
{
    pair<string, int> person1 { "Alice", 30 };
    pair<string, int> person2 = make_pair("Bob", 25);

    cout << "Person1: " << person1.first << ", Age: " << person1.second << endl;
    cout << "Person2: " << person2.first << ", Age: " << person2.second << endl;

    // Structured bindings (C++17 and later)
    auto [name, age] = person1;
    cout << "Structured Binding - Name: " << name << ", Age: " << age << endl;

    pair person3 { "a", 99 };
    cout << "Person3: " << person3.first << ", Age: " << person3.second << endl;
}

void Test_StructuredBindings()
{
    struct Point { double m_x, m_y, m_z; };
    Point point;
    point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
    auto [x, y, z] { point };
    cout << "Point coordinates: x=" << x << ", y=" << y << ", z=" << z << endl;
}

void Test_StructuredBindings_fenjie()
{
    pair myPair { "example", 123 };
    auto [strValue, intValue] = myPair;
    cout << "String Value: " << strValue << ", Integer Value: " << intValue << endl;
} //namespace demo

}