#ifdef __INTELLISENSE__
#include <CompilationSettings.hpp>
#endif

namespace friday::inline api::inline pipeline {
  constexpr auto CompilationSettings::CompilationSettingsBuilder::redirect_errors_to(FILE* stream) noexcept -> CompilationSettingsBuilder& {
    this->M_stderr = stream;
    return *this;
  }

  constexpr auto CompilationSettings::CompilationSettingsBuilder::redirect_debugs_to(FILE* stream) noexcept -> CompilationSettingsBuilder& {
    this->M_stddbg = stream;
    return *this;
  }

  constexpr auto CompilationSettings::CompilationSettingsBuilder::redirect_logs_to(FILE* stream) noexcept -> CompilationSettingsBuilder& {
    this->M_stdlog = stream;
    return *this;
  }

  constexpr auto CompilationSettings::CompilationSettingsBuilder::redirect_notes_to(FILE* stream) noexcept -> CompilationSettingsBuilder& {
    this->M_stdnte = stream;
    return *this;
  }

  constexpr auto CompilationSettings::CompilationSettingsBuilder::redirect_warnings_to(FILE* stream) noexcept -> CompilationSettingsBuilder& {
    this->M_stdwrn = stream;
    return *this;
  }

  constexpr auto CompilationSettings::CompilationSettingsBuilder::enable_debug(bool enabled) noexcept -> CompilationSettingsBuilder& {
    this->M_dgb = enabled;
    return *this;
  }

  constexpr auto CompilationSettings::CompilationSettingsBuilder::build() noexcept -> CompilationSettings {
    return CompilationSettings{
      this->M_stderr,
      this->M_stddbg,
      this->M_stdlog,
      this->M_stdnte,
      this->M_stdwrn,
      this->M_dgb
    };
  }

  
  constexpr auto CompilationSettings::defaults() noexcept -> CompilationSettings {
    return CompilationSettings::builder().build();
  }

  constexpr auto CompilationSettings::builder() noexcept -> CompilationSettingsBuilder {
    return {};
  }

  constexpr CompilationSettings::CompilationSettings(FILE* err, FILE* dbg, FILE* log, FILE* nte, FILE* wrn, bool dgb_enabled) noexcept
    : M_stderr { err }
    , M_stddbg { dbg }
    , M_stdlog { log }
    , M_stdnte { nte }
    , M_stdwrn { wrn }
    , M_dgb { dgb_enabled }
  {}
    
  constexpr auto CompilationSettings::get_error_stream() const noexcept -> FILE* {
    return this->M_stderr;
  }

  constexpr auto CompilationSettings::get_debug_stream() const noexcept -> FILE* {
    return this->M_stddbg;
  }

  constexpr auto CompilationSettings::get_log_stream() const noexcept -> FILE* {
    return this->M_stdlog;
  }

  constexpr auto CompilationSettings::get_note_stream() const noexcept -> FILE* {
    return this->M_stdnte;
  }

  constexpr auto CompilationSettings::get_warning_stream() const noexcept -> FILE* {
    return this->M_stdwrn;
  }

  constexpr auto CompilationSettings::is_debug_enabled() const noexcept -> bool {
    return this->M_dgb;
  }
}