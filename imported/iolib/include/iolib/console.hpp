#pragma once

#include <print>
#include <format>
#include <string>

namespace iolib {
  struct Console final {
    enum class Channel : unsigned char {
      LOG, 
      DEBUG, 
      NOTE, 
      WARNING, 
      ERROR,
    };

  private:
    constexpr Console() noexcept = default;

    public:
    struct Color final {

    private:
      constexpr inline Color() noexcept = default;

    public:
      constexpr static auto rgb(unsigned char r, unsigned char g, unsigned char b) noexcept -> std::string;

    public:
      static const std::string BOLD;

    public:
      static const std::string RESET;

    public:
      static const std::string WHITE;

    public:
      static const std::string RED;

    public:
      static const std::string GREEN;

    public:
      static const std::string BLUE;

    public:
      static const std::string PURPLE;

    public:
      static const std::string YELLOW;

    public:
      static const std::string ORANGE;
    };

  public:
    static auto set_debug_enabled(bool enabled) noexcept -> void;

  public:
    static auto set_channel(Channel channel, std::FILE* stream) noexcept -> void;

  public:
    static auto log(std::string message) noexcept -> void;

  public:
    static auto note(std::string message) noexcept -> void;

  public:
    static auto debug(std::string message) noexcept -> void;

  public:
    static auto warning(std::string message) noexcept -> void;

  public:
    static auto error(std::string message) noexcept -> void;

  private:
    static bool S_debugEnabled;

  private:
    static std::FILE* S_stderr;

  private:
    static std::FILE* S_stddbg;

  private:
    static std::FILE* S_stdlog;

  private:
    static std::FILE* S_stdnte;

  private:
    static std::FILE* S_stdwrn;
  };
}

#include "console.inl"