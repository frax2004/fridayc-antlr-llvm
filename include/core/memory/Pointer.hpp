#pragma once



namespace friday::inline core::inline memory {

  template<class T>
  struct Pointer;

  /// @brief Raw void pointer wrapper
  template<>
  struct Pointer<void> final {

    public:
    /// @brief Value type
    using value_type = void;
    /// @brief Pointer type
    using pointer_type = void*;

    /// @brief Default empty constructor
    constexpr inline Pointer() noexcept = default;
    /// @brief Default copy constructor
    /// @param other 
    constexpr inline Pointer(Pointer<void> const& other) noexcept = default;
    /// @brief Default move constructor
    /// @param other 
    constexpr inline Pointer(Pointer<void> && other) noexcept = default;
    /// @brief Construct an instance from a raw pointer
    /// @param pointer raw pointer
    constexpr inline Pointer(pointer_type pointer) noexcept;
    
    /// @brief Constructd a void pointer from another generic pointer
    /// @tparam U the target type
    template<class U>
    constexpr inline Pointer(Pointer<U> const& other) noexcept;
    
    /// @brief Checks if the contained pointer is null
    /// @return `true`if the contained pointer is null
    constexpr inline operator bool() const noexcept;

    /// @brief Default copy assignment operator
    /// @param other 
    /// @return `*this`
    constexpr inline auto operator=(Pointer<void> const& other) noexcept -> Pointer<void>& = default;
    /// @brief Default move assignment operator
    /// @param other 
    /// @return `*this`
    constexpr inline auto operator=(Pointer<void> && other) noexcept -> Pointer<void>& = default;
    /// @brief Copy assignment operator
    /// @param other raw pointer
    /// @return `*this`
    constexpr inline auto operator=(pointer_type other) noexcept -> Pointer<void>&;

    /// @brief Default equality operator
    /// @param other
    /// @return `true` if the underlying pointers are the same
    constexpr inline auto operator==(Pointer<void> const& other) const noexcept -> bool = default;

    /// @brief Default inequality operator
    /// @param other
    /// @return `true` if the underlying pointers are the different
    constexpr inline auto operator!=(Pointer<void> const& other) const noexcept -> bool = default;

    /// @brief Default comparison operator
    /// @param other 
    /// @return comparison result
    constexpr inline auto operator<=>(Pointer<void> const& other) const noexcept -> std::strong_ordering = default;

    /// @brief Get the contained pointer (const version)
    /// @return the raw pointer
    constexpr inline auto get() const noexcept -> const pointer_type;

    /// @brief Get che contained pointer
    /// @return the raw pointer
    constexpr inline auto get() noexcept -> pointer_type;

    private:
    /// @brief Contained pointer
    void* M_pointer { nullptr };
  }; // struct Pointer<void>

  /// @brief Raw pointer wrapper
  /// @tparam T underlying value type
  template<class T>
  struct Pointer final {

    public:
    /// @brief Value type
    using value_type = T;
    /// @brief Reference type
    using reference_type = T&;
    /// @brief Pointer type
    using pointer_type = T*;

    /// @brief Default empty constructor
    constexpr inline Pointer() noexcept = default;
    /// @brief Default copy constructor
    /// @param other 
    constexpr inline Pointer(Pointer<T> const& other) noexcept = default;
    /// @brief Default move constructor
    /// @param other 
    constexpr inline Pointer(Pointer<T> && other) noexcept = default;
    /// @brief Construct an instance from a raw pointer
    /// @param pointer raw pointer
    constexpr inline Pointer(pointer_type pointer) noexcept;

    /// @brief Checks if the contained pointer is null
    /// @return `true`if the contained pointer is null
    constexpr inline operator bool() const noexcept;

    /// @brief Default copy assignment operator
    /// @param other 
    /// @return `*this`
    constexpr inline auto operator=(Pointer<T> const& other) noexcept -> Pointer<T>& = default;
    /// @brief Default move assignment operator
    /// @param other 
    /// @return `*this`
    constexpr inline auto operator=(Pointer<T> && other) noexcept -> Pointer<T>& = default;
    /// @brief Copy assignment operator
    /// @param other raw pointer
    /// @return `*this`
    constexpr inline auto operator=(pointer_type other) noexcept -> Pointer<T>&;

    /// @brief Default equality operator
    /// @param other
    /// @return `true` if the underlying pointers are the same
    constexpr inline auto operator==(Pointer<T> const& other) const noexcept -> bool = default;

    /// @brief Default inequality operator
    /// @param other
    /// @return `true` if the underlying pointers are the different
    constexpr inline auto operator!=(Pointer<T> const& other) const noexcept -> bool = default;

    /// @brief Default comparison operator
    /// @param other 
    /// @return comparison result
    constexpr inline auto operator<=>(Pointer<T> const& other) const noexcept -> std::strong_ordering = default;

    /// @brief Get the contained pointer (const version)
    /// @return the raw pointer
    constexpr inline auto get() const noexcept -> const pointer_type;

    /// @brief Get che contained pointer
    /// @return the raw pointer
    constexpr inline auto get() noexcept -> pointer_type;

    /// @brief Dereference the contained pointer (const version)
    /// @return const value reference
    /// @throws `NullPointerError` instance if the contained pointer is `nullptr`
    constexpr inline auto deref() const -> const reference_type;

    /// @brief Dereference the contained pointer
    /// @return value reference
    /// @throws `NullPointerError` instance if the contained pointer is `nullptr`
    constexpr inline auto deref() -> reference_type;

    /// @brief Dereference member access operator (const version)
    /// @return const value reference
    /// @throws `NullPointerError` instance if the contained pointer is `nullptr`
    constexpr inline auto operator->() const -> const pointer_type;

    /// @brief Dereference member access operator
    /// @return value reference
    /// @throws `NullPointerError` instance if the contained pointer is `nullptr`
    constexpr inline auto operator->() -> pointer_type;

    /// @brief Dereference operator (const version)
    /// @return const value reference
    /// @throws `NullPointerError` instance if the contained pointer is `nullptr`
    constexpr inline auto operator*() const -> reference_type;

    /// @brief Dereference operator
    /// @return value reference
    /// @throws `NullPointerError` instance if the contained pointer is `nullptr`
    constexpr inline auto operator*() -> reference_type;

    private:
    /// @brief Contained pointer
    T* M_pointer { nullptr };
  }; // struct Pointer<T>
} // namespace friday::core::memory

#include "Pointer.inl"