#pragma once

#include <print>
#include <stdexcept>

#define CHECK(condition, fmt, ...) __check_impl((condition), (fmt), #condition, __VA_ARGS__)

template <typename... Args>
static void __check_impl(bool condition, const char *condition_str, std::format_string<Args...> fmt, Args &&...args) {
    if (!condition) {
        std::string RED{"\33[31m"};
        std::string BOLD{"\33[1m"};
        std::string RESET{"\33[0m"};

        std::print(stderr, "{}CHECK({}) failed:", BOLD + RED, condition_str);
        std::println(stderr, fmt, std::forward<Args>(args)...);
        std::print(stderr, "{}{} at {}:{} in {}{}\n", RESET, RED, __FILENAME__, __LINE__, __func__, RESET);

        std::exit(EXIT_FAILURE);
    }
}