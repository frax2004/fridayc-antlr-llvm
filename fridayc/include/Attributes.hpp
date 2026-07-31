#pragma once

//* ////////////////////////////////////////////////////////////////

//* ///////////////////////////
#include <SourceLocation.hpp>
//* ///////////////////////////

//* ///////////////////////////
#include <VisibilityModifier.hpp>
//* ///////////////////////////

//* ////////////////////////////////////////////////////////////////

namespace friday::inline api::inline typesystem {

  /**
   * @brief Attributes for symbols
   */
  struct FRIDAY_API Attributes final {
  public:
    /**
     * @brief the visibility modifier of the symbol
     */
    VisibilityModifier visibility { VisibilityModifier::PUBLIC };

  public:
    /**
     * @brief tells if the symbol is static
     */
    bool isStatic { false };

  public:
    /**
     * @brief tells if the symbol is const
     */
    bool isConst { false };

  public:
    /**
     * @brief tells if the symbol is unused
     */
    bool isUnused { false };

  };

}
