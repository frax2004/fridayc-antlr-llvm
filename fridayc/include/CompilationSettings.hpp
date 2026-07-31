#pragma once

#include <Common.hpp>
#include <Builder.hpp>

namespace friday::inline api::inline pipeline {
  struct FRIDAY_API CompilationSettings final {
    private:
    struct FRIDAY_API CompilationSettingsBuilder final : Builder<CompilationSettings> {
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
      ~CompilationSettingsBuilder() override = default;
      
      public:
      constexpr auto redirect_errors_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      constexpr auto redirect_debugs_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      constexpr auto redirect_logs_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      constexpr auto redirect_notes_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      constexpr auto redirect_warnings_to(FILE* stream) noexcept -> CompilationSettingsBuilder&;
      constexpr auto enable_debug(bool enabled) noexcept -> CompilationSettingsBuilder&;
      constexpr auto build() noexcept -> CompilationSettings override;
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
    static constexpr auto defaults() noexcept -> CompilationSettings;
    static constexpr auto builder() noexcept -> CompilationSettingsBuilder;

    private:
    constexpr CompilationSettings(FILE* err, FILE* dbg, FILE* log, FILE* nte, FILE* wrn, bool dgb_enabled) noexcept;

    public:
    constexpr auto get_error_stream() const noexcept -> FILE*;
    constexpr auto get_debug_stream() const noexcept -> FILE*;
    constexpr auto get_log_stream() const noexcept -> FILE*;
    constexpr auto get_note_stream() const noexcept -> FILE*;
    constexpr auto get_warning_stream() const noexcept -> FILE*;
    constexpr auto is_debug_enabled() const noexcept -> bool;
  };
}


#include <CompilationSettings.inl>