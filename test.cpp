#include <bits/stdc++.h>
using namespace std;

// C++20 Concepts: 定义一个概念，要求类型T支持加法操作
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};

// 使用 Addable 概念的函数模板
template <Addable T> T add(T a, T b)
{
    return a + b;
}

void solve()
{
    
}

int main()
{
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "C++ 配置及版本检测程序" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "配置成功，程序正在正常运行！" << std::endl;
    std::cout << std::endl;

    // 显示 C++ 标准版本
    std::cout << "C++ 标准版本信息:" << std::endl;
    if (__cplusplus == 202302L)
        std::cout << "  C++23 (ISO/IEC 14882:2023)" << std::endl;
    else if (__cplusplus == 202002L)
        std::cout << "  C++20 (ISO/IEC 14882:2020)" << std::endl;
    else if (__cplusplus == 201703L)
        std::cout << "  C++17 (ISO/IEC 14882:2017)" << std::endl;
    else if (__cplusplus == 201402L)
        std::cout << "  C++14 (ISO/IEC 14882:2014)" << std::endl;
    else if (__cplusplus == 201103L)
        std::cout << "  C++11 (ISO/IEC 14882:2011)" << std::endl;
    else if (__cplusplus == 199711L)
        std::cout << "  C++98 (ISO/IEC 14882:1998)" << std::endl;
    else
        std::cout << "  预定义的 __cplusplus 宏值为: " << __cplusplus << " (一个较旧或未知的C++标准)" << std::endl;
    std::cout << std::endl;

    // --- C++17 特性示例：结构化绑定 (Structured Bindings) ---
    std::cout << "C++17 特性测试：结构化绑定" << std::endl;
    std::map<std::string, int> student_scores = {{"Alice", 90}, {"Bob", 85}};
    bool cxx17_feature_ran = false;
    // 遍历 map 并使用结构化绑定
    for (const auto &[name, score] : student_scores) {
        std::cout << "  学生: " << name << ", 分数: " << score << std::endl;
        cxx17_feature_ran = true;
    }
    if (!cxx17_feature_ran && !student_scores.empty()) {
        std::cout << "  C++17 结构化绑定特性似乎未成功执行（但map非空）。" << std::endl;
    }
    else if (student_scores.empty()) {
        std::cout << "  Map为空，无法演示结构化绑定。" << std::endl;
    }
    std::cout << std::endl;

    // --- C++20 特性示例：Concepts ---
    std::cout << "C++20 特性测试：Concepts" << std::endl;
#if __cplusplus >= 202002L
    int sum_int = add(5, 3);
    std::cout << "  使用 concept 'Addable' 计算整数和: 5 + 3 = " << sum_int << std::endl;

    // 下面这行如果取消注释，并且编译器支持 C++20 Concepts，则会编译错误，
    // 因为 std::string 不直接支持 + 操作符返回 std::string (而是返回新的 std::string)
    // 或者说，我们定义的 Addable 要求 T + T -> T，而 string + string 是一种拼接。
    // 为了简单演示，我们这里仅用能通过编译的例子。
    // std::string s1 = "Hello, ";
    // std::string s2 = "World!";
    // std::cout << "  尝试使用 concept 'Addable' 连接字符串: " << add(s1, s2) << std::endl;
    // 注意：上面的字符串 add 行为可能不符合 Addable 概念中 T + T -> T 的严格定义，
    // 取决于编译器如何解释 std::string 的 operator+。
    // 更安全的做法是使用明确支持此概念的类型，或调整概念。
    // 这里我们主要目的是检查编译器是否认识 `concept` 和 `requires` 关键字。
    std::cout << "  C++20 Concepts 特性关键字已被编译器识别。" << std::endl;
#else
    std::cout << "  编译器似乎不支持 C++20 Concepts (根据 __cplusplus 值判断)。" << std::endl;
    std::cout << "  将跳过 Concepts 功能测试。" << std::endl;
#endif
    std::cout << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "测试结束。" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    return 0;
}