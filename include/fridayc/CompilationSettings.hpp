#pragma once
#include "Common.hpp"



namespace friday::inline api {
  struct CompilationSettings final {
  private:
    struct CompilationSettingsBuilder final : Builder<CompilationSettings> {
    private:
      FILE* M_stderr { stderr };
      FILE* M_stddbg { stderr };
      FILE* M_stdlog { stdout };
      FILE* M_stdnte { stdout };
      FILE* M_stdwrn { stderr };
      bool M_dgb { false };

      friend struct CompilationSettings;
      
    private:
      constexpr CompilationSettingsBuilder() noexcept = default;
      
    public:
      constexpr ~CompilationSettingsBuilder() override = default;
      
    public:
      auto redirect_errors_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      auto redirect_debugs_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      auto redirect_logs_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      auto redirect_notes_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      auto redirect_warnings_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      auto enable_debug(bool enabled) noexcept -> CompilationSettingsBuilder&;
      auto build() noexcept -> CompilationSettings override;
    };

    friend struct CompilationSettingsBuilder;

  private:
    FILE* M_stderr;
    FILE* M_stddbg;
    FILE* M_stdlog;
    FILE* M_stdnte;
    FILE* M_stdwrn;
    bool M_dgb;

  public:
    static auto defaults() noexcept -> CompilationSettings;
    static auto builder() noexcept -> CompilationSettingsBuilder;

  private:
    CompilationSettings(FILE* err, FILE* dbg, FILE* log, FILE* nte, FILE* wrn, bool dgb_enabled) noexcept;

  public:
    auto get_error_stream() const noexcept -> FILE*;
    auto get_debug_stream() const noexcept -> FILE*;
    auto get_log_stream() const noexcept -> FILE*;
    auto get_note_stream() const noexcept -> FILE*;
    auto get_warning_stream() const noexcept -> FILE*;
    auto is_debug_enabled() const noexcept -> bool;
  };
}
