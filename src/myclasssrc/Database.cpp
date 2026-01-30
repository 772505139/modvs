module database;
import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

using namespace std;

namespace Records {
    Employee& Database::addEmployee(const string& firstName,
                                  const string& lastName)
    {
        Employee theEmployee { firstName, lastName };   //Employee类的构造函数使用了【初始化列表】
        theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
        theEmployee.hire();
        m_employees.push_back(theEmployee);
        return m_employees.back();
    }

    Employee& Database::getEmployee(int employeeNumber)
    {
        for (auto& emp : m_employees)
        {
            if (emp.getEmployeeNumber() == employeeNumber)
            {
                return emp;//getEmployee()返回的是容器里【元素的引用（Employee&）】，不是【拷贝】，所以是正确的。
            }
        }
        throw runtime_error("Employee not found");
    }

    Employee& Database::getEmployee(const string& firstName,
                                  const string& lastName)
    {
        for (auto& emp : m_employees)
        {
            if (emp.getFirstName() == firstName &&
                emp.getLastName() == lastName)
            {
                return emp;
            }
        }
        throw runtime_error("Employee not found");
    }

    void Database::displayAll() const
    {
        /*
            displayAll()是const成员函数，m_employees在此处被视为const，迭代得到的元素必须是const引用，
            所以写成const auto&才正确。即便写auto&，也会因为const上下文变成const Employee&，但明确写出来更清晰、也避免误修改。
        */
        for (const auto& emp : m_employees)
        {
            emp.display();
        }
    }

    void Database::displayCurrent() const
    {
        for (const auto& emp : m_employees)
        {
            if (emp.isHired())
            {
                emp.display();
            }
        }
    }

    void Database::displayFormer() const
    {
        for (const auto& emp : m_employees)
        {
            if (!emp.isHired())
            {
                emp.display();
            }
        }
    }
}