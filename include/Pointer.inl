#ifdef __INTELLISENSE__
#include <Pointer.hpp>
#endif


#if FRIDAY_API_POINTER_WRAPPER == 1

template<class T>
constexpr Pointer<T>::Pointer(T* pointer) noexcept
  : M_pointer { pointer }
{}

template<class T>
constexpr auto Pointer<T>::operator*(this auto&& self) -> decltype(auto) {
  if constexpr(FRIDAY_API_POINTER_WRAPPER_RUNTIME_SUPPORT) {
    static auto __err = friday::NullPointerError{static_cast<void*>(self.M_pointer)};

    signal(SIGSEGV, [](int signum) { throw __err; });
  } 
  return *self.M_pointer;
}

template<class T>
constexpr auto Pointer<T>::operator->(this auto&& self) -> decltype(auto) {
  if constexpr(FRIDAY_API_POINTER_WRAPPER_RUNTIME_SUPPORT) {
    static auto __err = friday::NullPointerError{static_cast<void*>(self.M_pointer)};

    signal(SIGSEGV, [](int signum) { throw __err; });
  } 
  return self.M_pointer;
}

#endif
