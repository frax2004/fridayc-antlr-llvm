#pragma once

//* ////////////////////////////////////////////////////////////////

//* ///////////////////////////
#include <Common.hpp>
//* ///////////////////////////

//* ////////////////////////////////////////////////////////////////


namespace friday::inline core::inline IO {

  /**
   * @brief Output channels provider
   */
  struct FRIDAY_API Console final {
    
  public:
    /**
     * @brief Channel code
     */
    enum class Channel : u8 {
      LOG, 
      DEBUG, 
      NOTE, 
      WARNING, 
      ERROR,
    };

  private:
    /**
     * @brief Default constructor
     */
    constexpr Console() noexcept = default;

    public:
    /**
     * @brief Represents a text color for the command line
     */
    struct FRIDAY_API Color final {

    private:
      /**
       * @brief Default constructor
       */
      constexpr inline Color() noexcept = default;

    public:
      /**
       * @brief Get a color string from (r, g, b) triplet
       * @param r red channel
       * @param g green channel
       * @param b blue channel
       * @return formatted string representing the text color
       */
      constexpr static auto rgb(u8 r, u8 g, u8 b) noexcept -> string;

    public:
      /**
       * @brief Turn the text style bold on
       */
      static const string BOLD;

    public:
      /**
       * @brief Reset all text styles to default
       */
      static const string RESET;

    public:
      /**
       * @brief White text color
       */
      static const string WHITE;

    public:
      /**
       * @brief Red text color
       */
      static const string RED;

    public:
      /**
       * @brief Green text color
       */
      static const string GREEN;

    public:
      /**
       * @brief Blue text color
       */
      static const string BLUE;

    public:
      /**
       * @brief Purple text color
       */
      static const string PURPLE;

    public:
      /**
       * @brief Yellow text color
       */
      static const string YELLOW;

    public:
      /**
       * @brief Orange text color
       */
      static const string ORANGE;
    };

  public:
    /**
     * @brief Enabled or disables the debug channel
     * @param enabled the state
     */
    static auto set_debug_enabled(bool enabled) noexcept -> void;

  public:
    /**
     * @brief Redirect the channel
     * @param channel the channel code
     * @param stream the stream to redirect the channel to
     */
    static auto set_channel(Channel channel, FILE* stream) noexcept -> void;

  public:
    /**
     * @brief Prints a message into the log channel
     * @param message the message to write into the channel
     */
    static auto log(string message) noexcept -> void;

  public:
    /**
     * @brief Prints a message into the note channel
     * @param message the message to write into the channel
     */
    static auto note(string message) noexcept -> void;

  public:
    /**
     * @brief Prints a message into the debug channel
     * @param message the message to write into the channel
     */
    static auto debug(string message) noexcept -> void;

  public:
    /**
     * @brief Prints a message into the warning channel
     * @param message the message to write into the channel
     */
    static auto warning(string message) noexcept -> void;

  public:
    /**
     * @brief Prints a message into the error channel
     * @param message the message to write into the channel
     */
    static auto error(string message) noexcept -> void;

  private:
    /**
     * @brief tells if the debug mode is enabled
     */
    static bool S_debugEnabled;

  private:
    /**
     * @brief Error channel
     */
    static FILE* S_stderr;

  private:
    /**
     * @brief Debug channel
     */
    static FILE* S_stddbg;

  private:
    /**
     * @brief Log channel
     */
    static FILE* S_stdlog;

  private:
    /**
     * @brief Note channel
     */
    static FILE* S_stdnte;

  private:
    /**
     * @brief Warning channel
     */
    static FILE* S_stdwrn;
  };
}

#include <Console.inl>