

using friday_byte = char;
using friday_bool = bool;
using friday_int = long long int;
using friday_float = double;

extern "C" {

  inline auto _Z5_add_3int3int(friday_int x, friday_int y) -> friday_int {
    return x + y;
  }
  inline auto _Z5_sub_3int3int(friday_int x, friday_int y) -> friday_int {
    return x - y;
  }
  inline auto _Z5_mul_3int3int(friday_int x, friday_int y) -> friday_int {
    return x * y;
  }
  inline auto _Z5_div_3int3int(friday_int x, friday_int y) -> friday_int {
    return x / y;
  }

  inline auto _Z5_add_5float5float(friday_float x, friday_float y) -> friday_float {
    return x + y;
  }
  inline auto _Z5_sub_5float5float(friday_float x, friday_float y) -> friday_float {
    return x - y;
  }
  inline auto _Z5_mul_5float5float(friday_float x, friday_float y) -> friday_float {
    return x * y;
  }
  inline auto _Z5_div_5float5float(friday_float x, friday_float y) -> friday_float {
    return x / y;
  }

}