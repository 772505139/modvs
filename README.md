# modvs（C++20 Modules / STL Demo）

这是一个面向学习与演示的 C++ 工程，主要在 Visual Studio（MSVC）环境下使用 C++20 特性（含 Modules）与标准库功能，集中在一个“测试集合”里依次运行多个 demo。

## 主要内容
- C++20 Modules：
  - `import std;`
  - 自定义模块：`employee`、`airline_ticket`（以及可能的 `database` 等）
- 语法/标准库演示（示例）：
  - `switch`、三目运算符、三路比较（`<=>`）
  - `vector`、`optional`、`pair`
  - 结构化绑定
  - 循环语句
  - `initializer_list`
  - `string`
  - 引用、指针、`const_cast`
  - `constexpr`/`consteval`
  - 异常处理
  - 类型别名（`using`/`typedef`）
  - `auto`/`decltype`

## 关键入口（按现有源码上下文）
- demo 集合入口：`src/demo/testAll_Demos.cpp` 中的 `RunTestAllDemos()`
  - 调用：`demo::InitConsoleUtf8();`
  - 然后依次执行各类测试函数（如 `test_Array()`、`test_vector()`、`RunTest_Optional()` 等）

## Windows 控制台 UTF-8 输出
提供了一个工具函数用于尽量让控制台以 UTF-8 显示输出：【这是vscode里的实现，vs没用】

- 头文件：`src/console_utf8.h`
- 实现：`src/console_utf8.cpp`
- 函数：`demo::InitConsoleUtf8()`

当前实现会在 Windows 下调用：
- `SetConsoleOutputCP(CP_UTF8);`
- `SetConsoleCP(CP_UTF8);`

### 推荐（VS/MSVC）避免中文乱码的方式
【加这玩意的原因是所有的源码文件.cpp、.cppm、.h等文件的编码字符集不统一，都统一
成utf-8就不用加这条命令了！】【或者你懒得统一，就加上这条命令，也能解决乱码】
在 Visual Studio 项目中添加编译选项：
- `项目属性 > C/C++ > 命令行 > 其他选项`：加入 `/utf-8`

该选项的含义是：**让 MSVC 按 UTF-8 解码源文件**，从而使源码中的 `"中文"` 等窄字符串字面量按 UTF-8 编译生成，避免“源码字面量是 GBK、控制台按 UTF-8 解码”导致的乱码。

## 构建与运行（建议）
- 在 Visual Studio 中打开解决方案并生成（Build）
- 运行方式：
  - `Ctrl + F5`（启动但不调试），或
  - 直接在终端运行生成的 `.exe`

> 说明：本仓库使用模块（Modules）时，请确保已启用 C++20（或更高）标准，并确保 VS/工具集具备模块支持。
>注意把.cppm的常规设置为编译为模块。

## 备注
- 该工程包含大量用于演示的“未使用变量”等代码片段，可能出现编译警告，属于教学/实验用途的正常现象。