#include <cstdint>
#include <stdfloat>
#include <cmath>
#include <stacktrace>
#include <csignal>
#include <exception>

#define friday_native extern "C"

using friday_int = int64_t;
using friday_float = double;
using friday_byte = int8_t;
using friday_bool = bool;
using friday_void = void;
using friday_voidptr = friday_void*;
using friday_byteptr = friday_byte*;
using std::set_terminate;

friday_native auto _Zpl3int3int(friday_int, friday_int) -> friday_int;
friday_native auto _Zpl5float5float(friday_float, friday_float) -> friday_float;
friday_native auto _Zpl4byte4byte(friday_byte, friday_byte) -> friday_byte;
friday_native auto _ZplP4void3int(friday_voidptr, friday_int) -> friday_voidptr;
friday_native auto _Zpl3int(friday_int) -> friday_int;
friday_native auto _Zpl5float(friday_float) -> friday_float;
friday_native auto _Zpl4byte(friday_byte) -> friday_byte;
friday_native auto _Zmi3int3int(friday_int, friday_int) -> friday_int;
friday_native auto _Zmi5float5float(friday_float, friday_float) -> friday_float;
friday_native auto _Zmi4byte4byte(friday_byte, friday_byte) -> friday_byte;
friday_native auto _ZmiP4void3int(friday_voidptr, friday_int) -> friday_voidptr;
friday_native auto _ZmiP4voidP4void(friday_voidptr, friday_voidptr) -> friday_int;
friday_native auto _Zmi3int(friday_int) -> friday_int;
friday_native auto _Zmi5float(friday_float) -> friday_float;
friday_native auto _Zmi4byte(friday_byte) -> friday_byte;
friday_native auto _Zml3int3int(friday_int, friday_int) -> friday_int;
friday_native auto _Zml5float5float(friday_float, friday_float) -> friday_float;
friday_native auto _Zml4byte4byte(friday_byte, friday_byte) -> friday_byte;
friday_native auto _Zdv3int3int(friday_int, friday_int) -> friday_int;
friday_native auto _Zdv5float5float(friday_float, friday_float) -> friday_float;
friday_native auto _Zdv4byte4byte(friday_byte, friday_byte) -> friday_byte;
friday_native auto _Zrm3int3int(friday_int, friday_int) -> friday_int;
friday_native auto _Zrm5float5float(friday_float, friday_float) -> friday_float;
friday_native auto _Zrm4byte4byte(friday_byte, friday_byte) -> friday_byte;
friday_native auto _Zeq3int3int(friday_int, friday_int) -> friday_bool;
friday_native auto _Zeq5float5float(friday_float, friday_float) -> friday_bool;
friday_native auto _Zeq4byte4byte(friday_byte, friday_byte) -> friday_bool;
friday_native auto _Zeq4bool4bool(friday_bool, friday_bool) -> friday_bool;
friday_native auto _ZeqP4voidP4void(friday_voidptr, friday_voidptr) -> friday_bool;
friday_native auto _Zne3int3int(friday_int, friday_int) -> friday_bool;
friday_native auto _Zne5float5float(friday_float, friday_float) -> friday_bool;
friday_native auto _Zne4byte4byte(friday_byte, friday_byte) -> friday_bool;
friday_native auto _Zne4bool4bool(friday_bool, friday_bool) -> friday_bool;
friday_native auto _ZneP4voidP4void(friday_voidptr, friday_voidptr) -> friday_bool;
friday_native auto _Zlt3int3int(friday_int, friday_int) -> friday_bool;
friday_native auto _Zlt5float5float(friday_float, friday_float) -> friday_bool;
friday_native auto _Zlt4byte4byte(friday_byte, friday_byte) -> friday_bool;
friday_native auto _ZltP4voidP4void(friday_voidptr, friday_voidptr) -> friday_bool;
friday_native auto _Zgt3int3int(friday_int, friday_int) -> friday_bool;
friday_native auto _Zgt5float5float(friday_float, friday_float) -> friday_bool;
friday_native auto _Zgt4byte4byte(friday_byte, friday_byte) -> friday_bool;
friday_native auto _ZgtP4voidP4void(friday_voidptr, friday_voidptr) -> friday_bool;
friday_native auto _Zle3int3int(friday_int, friday_int) -> friday_bool;
friday_native auto _Zle5float5float(friday_float, friday_float) -> friday_bool;
friday_native auto _Zle4byte4byte(friday_byte, friday_byte) -> friday_bool;
friday_native auto _ZleP4voidP4void(friday_voidptr, friday_voidptr) -> friday_bool;
friday_native auto _Zge3int3int(friday_int, friday_int) -> friday_bool;
friday_native auto _Zge5float5float(friday_float, friday_float) -> friday_bool;
friday_native auto _Zge4byte4byte(friday_byte, friday_byte) -> friday_bool;
friday_native auto _ZgeP4voidP4void(friday_voidptr, friday_voidptr) -> friday_bool;
friday_native auto _Zan3int3int(friday_int, friday_int) -> friday_int;
friday_native auto _Zan4byte4byte(friday_byte, friday_byte) -> friday_byte;
friday_native auto _Zan4bool4bool(friday_bool, friday_bool) -> friday_bool;
friday_native auto _Zor3int3int(friday_int, friday_int) -> friday_int;
friday_native auto _Zor4byte4byte(friday_byte, friday_byte) -> friday_byte;
friday_native auto _Zor4bool4bool(friday_bool, friday_bool) -> friday_bool;
friday_native auto _Zco3int(friday_int) -> friday_int;
friday_native auto _Zco4byte(friday_byte) -> friday_byte;
friday_native auto _Zco4bool(friday_bool) -> friday_bool;
friday_native auto _Zpp3int(friday_int) -> friday_int;
friday_native auto _Zpp5float(friday_float) -> friday_float;
friday_native auto _Zmm3int(friday_int) -> friday_int;
friday_native auto _Zmm5float(friday_float) -> friday_float;
friday_native auto _Zaa4bool4bool(friday_bool, friday_bool) -> friday_bool;
friday_native auto _Zoo4bool4bool(friday_bool, friday_bool) -> friday_bool;
friday_native auto _Znt4bool(friday_bool) -> friday_bool;

friday_native auto _Z4main() -> friday_void;

static auto friday_handle_c_terminate() -> void;
static auto friday_handle_c_segmentation_fault(int32_t) -> void;

auto main() -> int {
  std::set_terminate(&friday_handle_c_terminate);
  signal(SIGSEGV, &friday_handle_c_segmentation_fault);

  _Z4main();

  return 0;
}


friday_native auto _Zpl3int3int(friday_int lhs, friday_int rhs) -> friday_int {
  return lhs + rhs;
}

friday_native auto _Zpl5float5float(friday_float lhs, friday_float rhs) -> friday_float {
  return lhs + rhs;
}

friday_native auto _Zpl4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_byte {
  return lhs + rhs;
}

friday_native auto _ZplP4void3int(friday_voidptr lhs, friday_int rhs) -> friday_voidptr {
  return static_cast<friday_voidptr>(static_cast<friday_byteptr>(lhs) + rhs);
}

friday_native auto _Zpl3int(friday_int value) -> friday_int {
  return value;
}

friday_native auto _Zpl5float(friday_float value) -> friday_float {
  return value;
}

friday_native auto _Zpl4byte(friday_byte value) -> friday_byte {
  return value;
}

friday_native auto _Zmi3int3int(friday_int lhs, friday_int rhs) -> friday_int {
  return lhs - rhs;
}

friday_native auto _Zmi5float5float(friday_float lhs, friday_float rhs) -> friday_float {
  return lhs - rhs;
}

friday_native auto _Zmi4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_byte {
  return lhs - rhs;
}

friday_native auto _ZmiP4void3int(friday_voidptr lhs, friday_int rhs) -> friday_voidptr {
  return static_cast<friday_voidptr>(static_cast<friday_byteptr>(lhs) - rhs);
}

friday_native auto _ZmiP4voidP4void(friday_voidptr lhs, friday_voidptr rhs) -> friday_int {
  return static_cast<friday_int>(static_cast<friday_byteptr>(lhs) - static_cast<friday_byteptr>(rhs));
}

friday_native auto _Zmi3int(friday_int value) -> friday_int {
  return value;
}

friday_native auto _Zmi5float(friday_float value) -> friday_float {
  return value;
}

friday_native auto _Zmi4byte(friday_byte value) -> friday_byte {
  return value;
}

friday_native auto _Zml3int3int(friday_int lhs, friday_int rhs) -> friday_int {
  return lhs * rhs;
}

friday_native auto _Zml5float5float(friday_float lhs, friday_float rhs) -> friday_float {
  return lhs * rhs;
}

friday_native auto _Zml4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_byte {
  return lhs * rhs;
}

friday_native auto _Zdv3int3int(friday_int lhs, friday_int rhs) -> friday_int {
  return lhs / rhs;
}

friday_native auto _Zdv5float5float(friday_float lhs, friday_float rhs) -> friday_float {
  return lhs / rhs;
}

friday_native auto _Zdv4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_byte {
  return lhs / rhs;
}

friday_native auto _Zrm3int3int(friday_int lhs, friday_int rhs) -> friday_int {
  return lhs % rhs;
}

friday_native auto _Zrm5float5float(friday_float lhs, friday_float rhs) -> friday_float {
  return static_cast<friday_float>(fmod(lhs, rhs));
}

friday_native auto _Zrm4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_byte {
  return lhs % rhs;
}

friday_native auto _Zeq3int3int(friday_int lhs, friday_int rhs) -> friday_bool {
  return lhs == rhs;
}

friday_native auto _Zeq5float5float(friday_float lhs, friday_float rhs) -> friday_bool {
  return lhs == rhs;
}

friday_native auto _Zeq4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_bool {
  return lhs == rhs;
}

friday_native auto _Zeq4bool4bool(friday_bool lhs, friday_bool rhs) -> friday_bool {
  return lhs == rhs;
}

friday_native auto _ZeqP4voidP4void(friday_voidptr lhs, friday_voidptr rhs) -> friday_bool {
  return lhs == rhs;
}

friday_native auto _Zne3int3int(friday_int lhs, friday_int rhs) -> friday_bool {
  return lhs != rhs;
}

friday_native auto _Zne5float5float(friday_float lhs, friday_float rhs) -> friday_bool {
  return lhs != rhs;
}

friday_native auto _Zne4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_bool {
  return lhs != rhs;
}

friday_native auto _Zne4bool4bool(friday_bool lhs, friday_bool rhs) -> friday_bool {
  return lhs != rhs;
}

friday_native auto _ZneP4voidP4void(friday_voidptr lhs, friday_voidptr rhs) -> friday_bool {
  return lhs != rhs;
}

friday_native auto _Zlt3int3int(friday_int lhs, friday_int rhs) -> friday_bool {
  return lhs < rhs;
}

friday_native auto _Zlt5float5float(friday_float lhs, friday_float rhs) -> friday_bool {
  return lhs < rhs;
}

friday_native auto _Zlt4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_bool {
  return lhs < rhs;
}

friday_native auto _ZltP4voidP4void(friday_voidptr lhs, friday_voidptr rhs) -> friday_bool {
  return lhs < rhs;
}

friday_native auto _Zgt3int3int(friday_int lhs, friday_int rhs) -> friday_bool {
  return lhs > rhs;
}

friday_native auto _Zgt5float5float(friday_float lhs, friday_float rhs) -> friday_bool {
  return lhs > rhs;
}

friday_native auto _Zgt4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_bool {
  return lhs > rhs;
}

friday_native auto _ZgtP4voidP4void(friday_voidptr lhs, friday_voidptr rhs) -> friday_bool {
  return lhs > rhs;
}

friday_native auto _Zle3int3int(friday_int lhs, friday_int rhs) -> friday_bool {
  return lhs <= rhs;
}

friday_native auto _Zle5float5float(friday_float lhs, friday_float rhs) -> friday_bool {
  return lhs <= rhs;
}

friday_native auto _Zle4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_bool {
  return lhs <= rhs;
}

friday_native auto _ZleP4voidP4void(friday_voidptr lhs, friday_voidptr rhs) -> friday_bool {
  return lhs <= rhs;
}

friday_native auto _Zge3int3int(friday_int lhs, friday_int rhs) -> friday_bool {
  return lhs >= rhs;
}

friday_native auto _Zge5float5float(friday_float lhs, friday_float rhs) -> friday_bool {
  return lhs >= rhs;
}

friday_native auto _Zge4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_bool {
  return lhs >= rhs;
}

friday_native auto _ZgeP4voidP4void(friday_voidptr lhs, friday_voidptr rhs) -> friday_bool {
  return lhs >= rhs;
}

friday_native auto _Zan3int3int(friday_int lhs, friday_int rhs) -> friday_int {
  return lhs & rhs;
}

friday_native auto _Zan4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_byte {
  return lhs & rhs;
}

friday_native auto _Zan4bool4bool(friday_bool lhs, friday_bool rhs) -> friday_bool {
  return lhs & rhs;
}

friday_native auto _Zor3int3int(friday_int lhs, friday_int rhs) -> friday_int {
  return lhs | rhs;
}

friday_native auto _Zor4byte4byte(friday_byte lhs, friday_byte rhs) -> friday_byte {
  return lhs | rhs;
}

friday_native auto _Zor4bool4bool(friday_bool lhs, friday_bool rhs) -> friday_bool {
  return lhs | rhs;
}

friday_native auto _Zco3int(friday_int value) -> friday_int {
  return ~value;
}

friday_native auto _Zco4byte(friday_byte value) -> friday_byte {
  return ~value;
}

friday_native auto _Zco4bool(friday_bool value) -> friday_bool {
  return ~value;
}

friday_native auto _Zpp3int(friday_int value) -> friday_int {
  return value++;
}

friday_native auto _Zpp5float(friday_float value) -> friday_float {
  return value++;
}

friday_native auto _Zmm3int(friday_int value) -> friday_int {
  return value--;
}

friday_native auto _Zmm5float(friday_float value) -> friday_float {
  return value--;
}

friday_native auto _Zaa4bool4bool(friday_bool lhs, friday_bool rhs) -> friday_bool {
  return lhs && rhs;
}

friday_native auto _Zoo4bool4bool(friday_bool lhs, friday_bool rhs) -> friday_bool {
  return lhs || rhs;
}

friday_native auto _Znt4bool(friday_bool value) -> friday_bool {
  return !value;
}

auto friday_handle_c_terminate() -> void {
  printf("terminate() called.");
}

auto friday_handle_c_segmentation_fault(int32_t) -> void {
  printf("Segmentation Fault.");
}
