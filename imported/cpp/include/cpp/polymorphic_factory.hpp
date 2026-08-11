#pragma once
#include <vector>
#include <memory>
#include <concepts>
#include <ranges>



namespace cpp {

  /**
   * @brief Unified way to create a pool of objects and manage their allocation and construction
   * @tparam T the type of the object factory
   */
  template<class T>
  struct PolymorphicFactory final {

  public:
    /**
     * @brief the type of the pool: must guarantee pointer stability through the entire lifetime of the objects
     */
    using container_type = std::vector<std::unique_ptr<T>>;

  private:
    /**
     * @brief The product pool
     */
    static container_type S_products;

  private:
    /**
     * @brief Default constructor
     */
    constexpr PolymorphicFactory() noexcept = default;

  public:
    /** 
     * @brief Create a product with guaranteed pointer stability
     * @tparam ...Args the type arguments of the product's constructor
     * @param ...args the arguments
     * @
     * @return instance of the product
    */
    template<std::derived_from<T> U, class... Args>
    requires (std::constructible_from<U, Args...>)
    static auto create(Args&& ...args) -> U*;
    
  public:
    /**
     * @brief Get all the products created by this factory
     * @return the products
    */
    static auto products() -> decltype(auto);
  };
}

#include "polymorphic_factory.inl"