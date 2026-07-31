#pragma once

//* ////////////////////////////////////////////////////////////////

//* ///////////////////////////
#include <CompilationSettings.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <CompilationContext.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <Pipeline.hpp>
//* ///////////////////////////

//* ////////////////////////////////////////////////////////////////


namespace friday::inline api {

  /**
   * @brief Represents the compiler
   */
  struct FRIDAY_API Compiler final {
  private:
    /**
     * @brief The context
     */
    CompilationContext* M_ctx { nullptr };

  private:
    /**
     * @brief The settings
     */
    CompilationSettings M_settings;

  private:
    /**
     * @brief Constructs a compiler
     * @param ctx the context
     * @param the settings
     */
    Compiler(CompilationContext& ctx, CompilationSettings settings);

  private:
    /**
     * @brief Default copy constructor (deleted)
     */
    Compiler(Compiler const&) = delete;

  private:
    /**
     * @brief Default move constructor
     */
    Compiler(Compiler &&) = default;

  private:
    /**
     * @brief Default destructor
     */
    ~Compiler() = default;

  private:
    /**
     * @brief Default copy assignment operator (deleted)
     */
    auto operator=(Compiler const&) -> Compiler& = delete;

  private:
    /**
     * @brief Default move assignment operator
     */
    auto operator=(Compiler &&) -> Compiler& = default;

  public:
    /**
     * @brief Creates a compiler instance
     * @param ctx the context
     * @param settings the settings
     * @return the instance of the compiler
     */
    static auto create(CompilationContext& ctx, CompilationSettings settings) noexcept -> unique_ptr<Compiler>;

  public:
    /**
     * @brief Run the compilation pipeline process
     */
    auto compile() -> void;

  };

}