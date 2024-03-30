#pragma once

#include <string>

template <typename T>
class Singleton
{
public:
    static T& instance();

protected:
    Singleton() = default;
    Singleton(Singleton const&) = default;
    Singleton& operator=(Singleton const&) = default;
};

class Logger : public Singleton<Logger>
{
public:
    friend class Singleton<Logger>;

    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

protected:
    Logger() = default;
    Logger(Logger const&) = default;
    Logger& operator=(Logger const&) = default;
};

#include "singleton.hxx"