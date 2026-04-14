#include "Version.hpp"




namespace friday {

  auto getHelpPage() noexcept -> String {
    constexpr StringRef helpPage = R"(Usage: fridayc [<option>...] build <file> | run <file>
  
  {} Sub-Commands:
    {} run                      Launch the friday interpreter
                                with the specified input file
    {} build                    Compile the source  file  and
                                generate the executable
  
  {} Options:
    {} -H, --help               Display this information page
    {} -V, --version            Display the compiler  version
                                information
    {} -O, --output             Specify the output  directory
                                or directory  and  filename (
                                only supported on compilation
                                mode)
    {} -W[all|restricted|none]  all:   enables  all  warnings
                                restricted:  enables  limited
                                warnings
                                none: disables  every warning
  )";
  
    return std::format(helpPage, "📝", "🚀", "🛠️", "🔧", "🆘", "✅", "📁", "⚠️");
  }
  
  auto getVersionPage() noexcept -> String {
    auto now = std::chrono::system_clock::now();
  
    return "friday compiler version " FRIDAYC_VERSION " built on "s 
    + "{:%A %d %B %Y %T}"_f.format(std::chrono::floor<std::chrono::seconds>(now))
    + " by " FRIDAY_BUILD_AUTHOR;
  }
}
