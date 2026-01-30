#include "demo/testAll.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;
import employee;

using namespace std;
using namespace Records;

int Test_Employee()
{
    cout << "测试Employee类和Employee结构体" << endl;
    Employee emp { "L", "GW" };  //到栈上，不到堆上不用new
    emp.setFirstName("Larry");
    emp.setLastName("Greenwald");
    emp.setEmployeeNumber(1001);
    emp.setSalary(55000);
    emp.promote();
    emp.promote(5000);
    emp.hire();
    emp.display();

    cin.get();
    return 0;
}