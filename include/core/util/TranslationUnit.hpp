#pragma once

#include "core/Common.hpp"
#include "api/parser/FridayParser.h"

namespace ant = antlr4;

namespace friday::inline core::inline util {

  /// @brief Represents a tranlation unit with the source path and llvm module
  struct TranslationUnit final {

    /// @brief Construct a translation unit
    /// @param path the source path
    /// @param ctx the llvm context
    TranslationUnit(std::filesystem::path path, llvm::LLVMContext& ctx) noexcept;

    /// @brief Get the source path
    /// @return the path of the source file
    auto getPath() const noexcept -> std::filesystem::path const&;

    /// @brief Get the associated llvm module instance
    /// @return pointer to the module instance
    auto getModule() const noexcept -> llvm::Module*;

    /// @brief Sets the parse tree for this translation unit
    /// @param tree the parse tree
    auto setParseTree(FridayParser::ProgramContext* tree) noexcept -> void;

    /// @brief Get the associated parse tree for this translation unit
    /// @return the parse tree (if set before)
    auto getParseTree() const noexcept -> FridayParser::ProgramContext*;

    private:
    /// @brief The parse tree
    FridayParser::ProgramContext* M_parseTree { nullptr };
    /// @brief The source path
    std::filesystem::path M_sourcePath { };
    /// @brief The associated llvm module
    Box<llvm::Module> M_module { nullptr };
  }; // struct TranslationUnit
} // namespace friday::core::util