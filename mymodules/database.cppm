export module database;
import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;
import employee;

namespace Records {
    const int FirstEmployeeNumber { 1'000 };

    export class Database
    {
        public:
            Employee& addEmployee(const std::string& firstName,
                                  const std::string& lastName);
            Employee& getEmployee(int employeeNumber);
            Employee& getEmployee(const std::string& firstName,
                                  const std::string& lastName);
            
            void displayAll() const;
            void displayCurrent() const;
            void displayFormer() const;

        private:
            std::vector<Employee> m_employees;    
            int m_nextEmployeeNumber { FirstEmployeeNumber };

    }; //

} // namespace Records