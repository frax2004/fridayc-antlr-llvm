fn add(x: int, y: int) -> int => x + y;

fn hypot(x: int, y: int) -> int => x*x + y*y;

fn transform_int(x: int, f: fn(int) -> int) -> int => hypot(3, 4)(x);

fn main() -> void {
  print hypot(3, 4) + add(true, 4); 
}
