#include "demo/test_String.h"

import std;  // 导入整个标准库模块
//•	注释掉 import std.core; 是正确的做法，因为目前 Visual Studio 只支持 import std; 作为标准库模块的入口。
//•	保持 import std; ，不要使用 import std.core; ，否则会出现找不到模块接口的错误。
//•	如果你确实需要模块功能，请确保你的 Visual Studio 已安装 C++20 模块支持
//import std.core;  // 导入标准库的核心模块
//import std.iostream;
//import std.vector;

using namespace std;


class KeyValue
{
    public:
        KeyValue(string_view key, int value) :m_key{ key }, m_value{ value } {};

        const string& getKey() const { return m_key; }
        int getValue() const { return m_value; }
    private:
        string m_key;
        int m_value;
};


template<>
class formatter<KeyValue>
{
    public:
        constexpr auto parse(auto& context)
        {
            auto iter{ context.begin() };
            const auto end{ context.end() };

            if (iter == end || *iter == '}') {
                m_outputType = OutputType::KeyAndValue;
                return iter;
            }

            switch (*iter) {
                case 'a' :     //{:a} format specifier
                    m_outputType = OutputType::KeyOnly;
			        break;
                case 'b' :     //{:b} format specifier 
			        m_outputType = OutputType::ValueOnly;
			        break;
		        case 'c':     //{:c} format specifier
			        m_outputType = OutputType::KeyAndValue;
                    break;
                default:
			        throw format_error{ "Invalid format specifier for KeyValue. Use 'a' for key only, 'b' for value only, 'c' for key and value." };
            }

		    ++iter; // Move past the format specifier
            if (iter != end && *iter != '}') {
                throw format_error{ "Unexpected characters in format specifier for KeyValue." };
            }
		    return iter;
        }

        auto format(const KeyValue& kv, auto& context) const
        {
            switch (m_outputType) {
                using enum OutputType;
                case KeyOnly:
					return format_to(context.out(), "{}", kv.getKey());//转发到 format_to()实际执行格式化，并使用适当的格式字符串来输出键或值
                case ValueOnly:
                    return format_to(context.out(), "{}", kv.getValue());
                default:
				    return format_to(context.out(), "{}: {}", kv.getKey(), kv.getValue());
            }
	    }

    private:
       enum class OutputType { KeyAndValue, KeyOnly, ValueOnly };
       OutputType m_outputType{ OutputType::KeyAndValue };

};

namespace demo {


static string_view extractExtension(string_view filename)
{
    //return filename.substr(filename.rfind('.'));  //运行时出错，过不了边际检查
    /*
        当FileName里**没有.**时，rfind('.')会返回nPos（一个很大的无符号值）。
•	    把nPos传给substr()会触发标准库的边界检查，从而抛出std::out_of_range: "invalid string_view position"（你 callstack 里正是这个）。
    */
    const auto dotPos = filename.rfind('.');
    if (dotPos == string_view::npos) {
        return {}; // 没有扩展名：返回空的 string_view，避免 substr(npos) 抛 out_of_range
    }

    return filename.substr(dotPos);
}

static void handleExtension(const string& extension) { /*... */ }









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

    char text1[]{ "abcdef" };
    size_t s1{ sizeof(text1) };
    size_t s2{ strlen(text1) };

    const char* text2{ "ghijkl" };
    size_t s3{ sizeof(text2) };
    size_t s4{ strlen(text2) };

    cout << format("text1: {}, sizeof: {}, strlen: {}", text1, s1, s2) << endl;
    cout << format("text2: {}, sizeof: {}, strlen: {}", text2, s3, s4) << endl;

    const char* ptr1{ "hello" };
    // 错误修复：不能直接对 const char* 使用基于范围的 for 循环
    // 替换为传统指针遍历方式
    for (const char* i = ptr1; *i != '\0'; ++i) {
        cout << *i << endl;
    }
    for (int i = 0; i < strlen(ptr1) + 1; i++){
        cout << ptr1[i] << endl;
	}

	const char* str_literal{ "This is a \"string literal.\" " };// 使用转义字符
	const char* raw_str_literal{ R"( This is a "string literal." )" };// 原始字符串字面值


    const char* str_literal_ex{ R"-(Embedded )" characters)-" };
    cout << "扩展的 原始 字符串 字面量：" << str_literal_ex << endl;


    string myString { "hello" };
    myString += ",there";
    string myAnotherString{ myString };
    if (myString == myAnotherString) {
        myAnotherString[0] = 'H'; //【我操】注意这里要用字符''去赋值,不能用""去赋值，这玩意是【const char】！
    }
    cout << format("myString是：{}", myString) << endl;
    cout << format("myAnotherString是：{}", myAnotherString) << endl;


    auto string_s_1{ "test"s }; 


	vector names_constcharx{ "张三", "李四", "王五" }; // 自动推类型导为 const char*
	vector names_string{ "张三"s, "李四"s, "王五"s }; // 自动推类型导为 std::string


    const string toParse{ " 123USD" };
    size_t index{ 0 };
	int value{ stoi(toParse, &index) }; //函数执行以后，index 会被【更新】为第一个未被解析的字符的位置
    cout << format("Parsed value: {}", value) << endl;
    cout << format("First non-parsed character: '{}'", toParse[index]) << endl;


    const size_t BufferSize{ 50 };

    string out1(BufferSize, ' '); // A string of BufferSize space characters.是 std::string 的构造函数调用语法（直接初始化），意思是：用指定数量的同一个字符来生成一个字符串。
    auto result{ to_chars(out1.data(), out1.data() + out1.size(), 12345) };
    if (result.ec == errc{}) { cout << "out1:"s << out1 << endl; /* Conversion successful. */ }

    string out2(BufferSize, ' '); // A string of BufferSize space characters.
    auto [ptr, error] { to_chars(out2.data(), out2.data() + out2.size(), 12345) };
    if (error == errc{}) { cout << "out2:"s << out2 << endl; /* Conversion successful. */ }


    //完美往返特性：
    double value_testTochar { 0.314 };
    string out3(BufferSize, ' '); // A string of BufferSize space characters.
    auto [ptr2, error2] { to_chars(out3.data(), out3.data() + out3.size(), value_testTochar) };
    if (error == errc{}) { cout << "out3:"s << out3 << endl; /* Conversion successful. */ }

	double parsedValue{ 0.0 };
	auto [ptr4, error4] { from_chars(out3.data(), out3.data() + out3.size(), parsedValue) };
    if (error4 == errc{}) {
        if (value_testTochar == parsedValue) {
            cout << "完美往返特性测试通过，parsedValue="s << parsedValue << endl;
        } else {
			cout << "完美往返特性测试失败，parsedValue="s << parsedValue << endl;
        }
    }


    string filename { R"( c:\temp\my file.ext )" };
    cout << format("C++ string: {}", extractExtension(filename)) << endl;

    const char* cString{ R"( c:\temp\my file.ext )" };
    cout << format("C string: {}", extractExtension(cString)) << endl;

    cout << format("Literal: {}", extractExtension(R"(c:\temp\my file.ext)")) << endl;


	//使用string_view的构造函数，他接收一个const char*【或者说是字符串缓冲区】和一个长度参数
    static const char* raw{ /*... */ };
    static size_t length_stringview{ /*... */ };
    cout << format("Raw: {}", extractExtension({ raw, length_stringview })) << endl;
    cout << format("Raw: {}", extractExtension(string_view{ raw, length_stringview })) << endl;


    handleExtension(extractExtension("my file.ext").data());// data() method
    handleExtension(string{ extractExtension("my file.ext") }); //显式构造


    string str_teststringview{ "Hello" };
	string_view sv_teststringview{ " world"};
    auto result_combine1{ str_teststringview + sv_teststringview.data() };
	string result_combine2{ str_teststringview };
	result_combine2.append(sv_teststringview.data(), sv_teststringview.size());
	cout << format("Combined String1: {}", result_combine1) << endl;
	cout << format("Combined String2: {}", result_combine2) << endl;


	string str_testNullptr{ "Hello" };
	string_view sv_testNullptr{ str_testNullptr + " world" };  //生成临时字符串，然后用这个临时字符串去初始化 string_view
	cout << "测试悬空指针sv：" << sv_testNullptr << endl;


    int i{ 42 };
    cout << format("|{:5}|)", i) << endl;    //|   42|
    cout << format("|{:{}}|", i, 7) << endl;//|     42|

	cout << format("|{:7}|", i) << endl;   //|42   |
    cout << format("|{:<7}|", i) << endl;
    cout << format("|{:_>7}|", i) << endl;
    cout << format("|{:_^7}|", i) << endl;

    cout << format("|{:<5}|", i) << endl;
    cout << format("|{:<+5}|", i) << endl;
    cout << format("|{:< 5}|", i) << endl;
    cout << format("|{:< 5}|", -i) << endl;

	cout << format("|{:10d}|", i) << endl;
    cout << format("|{:10b}|", i) << endl;
    cout << format("|{:#10b}|", i) << endl;
    cout << format("|{:10X}|", i) << endl;
    cout << format("|{:#10X}|", i) << endl;

	string str_testFormat{ "ProCpp" };
    cout << format("String: {:_^10}", str_testFormat) << endl; // 居中对齐

	double d_testFormat{ 3.14159 / 2.3 };
    cout << format("Default: {}", d_testFormat) << endl; // 默认格式
	cout << format("Fixed: {:12g}", d_testFormat) << endl; // 定点格式，自动选择合适的精度
	cout << format("Fixed: {:12.2}", d_testFormat) << endl; // 定点格式，保留两位小数
	cout << format("Scientific: {:12e}", d_testFormat) << endl; // 科学计数法格式，保留六位小数

	int width_testFormat{ 12 };
	int precision_testFormat{ 3 };
	cout << format("Width and Precision: {2:{0}.{1}f}", width_testFormat, precision_testFormat, d_testFormat) << endl; // 宽度和精度，使用位置参数指定宽度和精度值


	cout << format("|{:06d}|", i) << endl; //|000042|
	cout << format("|{:+06d}|", i) << endl; //|+00042|
	cout << format("|{:06X}|", i) << endl; //|00002A|
	cout << format("|{:#06d}|", i) << endl; //|000042|  
    //对于十进制整数，#标志没有效果，所以输出和没有#标志的结果一样。对于其他进制（如八进制或十六进制），
    //#标志会添加相应的前缀（0、0x、0X）。但对于十进制整数，#标志被忽略，因此输出仍然是|000042|。


    try {
        cout << format("An integer:{:.2f}", 5.0);
    }
    catch (const format_error& e) {
		cout << "Caught format_error: " << e.what() << endl;
    }


	KeyValue keyValue1{ "Key1", 42 };
    cout << format("Default (key and value): {}", keyValue1) << endl; // 默认输出键和值
    cout << format("Key only: {:a}", keyValue1) << endl; // 只输出键
    cout << format("Value only: {:b}", keyValue1) << endl; // 只输出值
	cout << format("Key and Value: {:c}", keyValue1) << endl; // 输出键和值，使用不同的格式
    //try { cout << format("{:cd}", keyValue1) << endl; }
    //catch (const format_error& e) { cout << "Caught format_error for KeyValue: " << e.what() << endl; }
	//上面这段代码测试了我们为 KeyValue 定义的自定义格式化器的错误处理机制。当我们尝试使用无效的格式说明符（如 "d"）时，formatter 的 parse() 方法会抛出一个 format_error 异常。
    // 我们在 main() 函数中捕获这个异常，并输出错误信息，验证了我们的错误处理逻辑是否正确工作。
	//【但是】由于我们在 formatter<KeyValue>::parse() 方法中已经抛出了异常，所以这段代码实际上是无法编译通过的，因为编译器会在【编译阶段】检测到无效的格式说明符并报错。
	//根本就不会进入到运行时的异常处理逻辑，因为编译器在编译阶段就会拒绝编译这段代码。要测试这个错误处理机制，我们需要在运行时动态地构造格式字符串，而不是在编译时直接使用无效的格式说明符。


} // Runtest_String

} // namespace demo