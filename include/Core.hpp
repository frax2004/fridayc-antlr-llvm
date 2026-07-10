#pragma once

#include <Version.hpp>
#include <bits/stdc++.h>
#include <Pointer.hpp>

using namespace std;
using namespace string_literals;
using namespace string_view_literals;

using byte = char;
using ubyte = unsigned char;
using bit = bool;
using i8 = char;
using i16 = short;
using i32 = int;
using i64 = long long;
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;
using f32 = float;
using f64 = double;

template<class T>
using Predicate = function<bool(T)>;

template<class T>
using rc = shared_ptr<T>;

template<class T>
using weak = weak_ptr<T>;

using string_ref = string_view;

template<class T>
struct FRIDAY_API hash<vector<Pointer<T>>> {
  auto operator()(vector<Pointer<T>> const& vec) const noexcept -> size_t;
};

#include <Core.inl>