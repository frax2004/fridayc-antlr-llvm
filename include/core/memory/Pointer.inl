#ifdef __INTELLISENSE__
#include "Pointer.hpp"
#endif

#include "core/errors/NullPointerError.hpp"

namespace friday::inline core::inline memory {

  constexpr inline Pointer<void>::Pointer(pointer_type pointer) noexcept 
    : M_pointer { pointer }
  {}

  constexpr inline auto Pointer<void>::operator=(pointer_type other) noexcept -> Pointer<void>& {
    this->M_pointer = other;
    return *this;
  }

  constexpr inline auto Pointer<void>::get() const noexcept -> const pointer_type {
    return this->M_pointer;
  }

  constexpr inline auto Pointer<void>::get() noexcept -> pointer_type {
    return this->M_pointer;
  }

  constexpr inline Pointer<void>::operator bool() const noexcept {
    return this->M_pointer != nullptr;
  }

  template<class U>
  constexpr inline Pointer<void>::Pointer(Pointer<U> const& other) noexcept
    : M_pointer { static_cast<void*>(other.M_pointer) }
  {}

  template<class T>
  constexpr inline Pointer<T>::Pointer(pointer_type pointer) noexcept 
    : M_pointer { pointer }
  {}

  template<class T>
  constexpr inline auto Pointer<T>::operator=(pointer_type other) noexcept -> Pointer<T>& {
    this->M_pointer = other;
    return *this;
  }

  template<class T>
  constexpr inline auto Pointer<T>::get() const noexcept -> const pointer_type {
    return this->M_pointer;
  }

  template<class T>
  constexpr inline auto Pointer<T>::get() noexcept -> pointer_type {
    return this->M_pointer;
  }

  template<class T>
  constexpr inline auto Pointer<T>::deref() const -> const reference_type {
    if(this->M_pointer == nullptr) throw NullPointerError{};
    return *this->M_pointer;
  }

  template<class T>
  constexpr inline auto Pointer<T>::deref() -> reference_type {
    if(this->M_pointer == nullptr) throw NullPointerError{};
    return *this->M_pointer;
  }

  template<class T>
  constexpr inline auto Pointer<T>::operator*() const -> const reference_type {
    if(this->M_pointer == nullptr) throw NullPointerError{};
    return *this->M_pointer;
  }

  template<class T>
  constexpr inline auto Pointer<T>::operator*() -> reference_type {
    if(this->M_pointer == nullptr) throw NullPointerError{};
    return *this->M_pointer;
  }

  template<class T>
  constexpr inline auto Pointer<T>::operator->() const -> const pointer_type {
    if(this->M_pointer == nullptr) throw NullPointerError{};
    return this->M_pointer;
  }

  template<class T>
  constexpr inline auto Pointer<T>::operator->() -> pointer_type {
    if(this->M_pointer == nullptr) throw NullPointerError{};
    return this->M_pointer;
  }

  template<class T>
  constexpr inline Pointer<T>::operator bool() const noexcept {
    return this->M_pointer != nullptr;
  }

}
