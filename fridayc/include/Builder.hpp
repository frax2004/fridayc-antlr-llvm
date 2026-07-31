#pragma once


namespace friday::inline core {

  /**
   * @brief Interface for builder classes
   * @tparam T the type of the object built
   */
  template<class T>
  struct FRIDAY_API Builder {

  public:
    /**
     * @brief Default destructor
     */
    virtual ~Builder() = default;

  public:
    /**
     * @brief Builds the object
     * @return the built object instance
     */
    virtual auto build() -> T = 0;
  };
}