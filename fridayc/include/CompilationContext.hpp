#pragma once


//* ////////////////////////////////////////////////////////////////

//* ///////////////////////////
#include <Common.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <TranslationUnit.hpp>
//* ///////////////////////////

//* ////////////////////////////////////////////////////////////////


namespace friday::inline api::inline pipeline {

  /**
  * @brief Holds data for the entire compilation process
  */
  struct FRIDAY_API CompilationContext final : NonCopyable {

  private:
    /**
    * @brief Represents the llvm context
    */
    llvm::LLVMContext M_llvmContext { };

  private:
    /**
    * @brief All the allocated translation units
    */
    vector<unique_ptr<TranslationUnit>> M_translationUnits { };

  public:
    /**
    * @brief Holds the database for the entire compilation process
    * @param paths the source files to compile
    * @return Instance of the compilation context
    */
    static auto create(vector<string> const& paths) -> unique_ptr<CompilationContext>;

  private:
    /**
    * @brief Construct a compilation context
    * @param paths the source files to compile
    */
    CompilationContext(vector<string> const& paths) noexcept;

  public:
    /**
    * @brief Default destructor
    */
    ~CompilationContext() override = default;

  public:
    /**
    * @brief Get the translation units
    * @return the translation units
    */
    auto get_units() const -> vector<TranslationUnit*>;

  public:
    /**
    * @brief Get the llvm context
    * @return the context instance
    */
    auto get_llvm_context() noexcept -> Pointer<llvm::LLVMContext>;
  };
}