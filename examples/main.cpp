#include "demo/testAll.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

using namespace std;

int main()
{



    //运行所有【第一章】演示测试
    RunTestAllDemos();

    //测试Employee类和Employee结构体
    Test_Employee();

    //测试Database类
    Test_Database();


    //测试DLL调用
    runTestDLL();


    //测试用户界面（控制台版）
    Test_UserUI_Console();



    return 0;
}
