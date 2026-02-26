// DLL：COMMONSM4.dll
// 导出名：encryptData_ECB / decryptData_ECB
// 调用约定：__cdecl
// 字符集：ANSI（与厂商 C# 示例 Encoding.Default 对齐）
//
// 重要语义：
// - encrypt 入参/ decrypt 入参虽然类型是 byte*，但实际按“C 字符串”处理。
// - decrypt 的入参必须是 “Base64 文本(ANSI) + '\0'”。
// - 返回值为 const char*（疑似指向 DLL 内部缓冲区），读取时要做“有界”拷贝，避免尾部残留导致乱码。

#include "demo/testAll.h"

#include <windows.h>

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using Sm4EncryptFn = const char* (__cdecl*)(const unsigned char* content);
using Sm4DecryptFn = const char* (__cdecl*)(const unsigned char* content);

namespace
{
    constexpr size_t kMaxReturnBytes = 4096;

    void PrintWin32Error(const char* title)
    {
        const DWORD err = ::GetLastError();

        LPSTR msg = nullptr;
        const DWORD flags = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
                            FORMAT_MESSAGE_IGNORE_INSERTS;
        const DWORD langId = MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT);

        ::FormatMessageA(flags, nullptr, err, langId, reinterpret_cast<LPSTR>(&msg), 0, nullptr);

        std::cerr << title << " err=" << err;
        if (msg) std::cerr << ", msg=" << msg;
        std::cerr << "\n";

        if (msg) ::LocalFree(msg);
    }

    // 从 DLL 返回的 char* 做“有界 C 字符串”拷贝，避免读到缓冲区残留垃圾数据
    std::string CopyAnsiZBounded(const char* p, size_t maxBytes)
    {
        if (!p) return {};
        const size_t n = strnlen(p, maxBytes);
        return std::string(p, n);
    }

    // 将 std::string 按“ANSI 文本 + '\0'”打包成 byte[]（满足 DLL 以 C 字符串方式读取的假设）
    std::vector<unsigned char> ToAnsiZBytes(const std::string& s)
    {
        std::vector<unsigned char> v(s.begin(), s.end());
        v.push_back('\0');
        return v;
    }
}

int runTestDLL()
{
    std::cout << "[SM4] begin\n";

    const HMODULE dll = ::LoadLibraryW(L"COMMONSM4.dll");
    if (!dll)
    {
        PrintWin32Error("[SM4] LoadLibraryW(COMMONSM4.dll) failed.");
        return 1;
    }

    const auto encrypt = reinterpret_cast<Sm4EncryptFn>(::GetProcAddress(dll, "encryptData_ECB"));
    const auto decrypt = reinterpret_cast<Sm4DecryptFn>(::GetProcAddress(dll, "decryptData_ECB"));
    if (!encrypt || !decrypt)
    {
        PrintWin32Error("[SM4] GetProcAddress(encryptData_ECB/decryptData_ECB) failed.");
        ::FreeLibrary(dll);
        return 2;
    }

    // 演示明文（ANSI）；入参按 C 字符串传入更稳妥
    const std::string plainAnsi = "test";
    const auto plainZ = ToAnsiZBytes(plainAnsi);

    // 1) encrypt：返回 Base64 文本（ANSI）
    const char* encPtr = encrypt(plainZ.data());
    const std::string encBase64 = CopyAnsiZBounded(encPtr, kMaxReturnBytes);
    std::cout << "加密后(Base64)=" << encBase64 << "\n";

    // 2) decrypt：入参必须传 Base64 文本 + '\0'
    const auto encZ = ToAnsiZBytes(encBase64);
    const char* decPtr = decrypt(encZ.data());
    const std::string decrypted = CopyAnsiZBounded(decPtr, kMaxReturnBytes);
    std::cout << "解密还原=" << decrypted << "\n";

    ::FreeLibrary(dll);
    std::cout << "[SM4] end\n";
    return 0;
}