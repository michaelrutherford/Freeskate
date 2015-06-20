use std::io;
const MAX: i32 = 99999999;
const MIN: i32 = -99999999;
struct Point {x: i32, y: i32,}
struct Line {h: Point, i: Point,}
impl Line {
  fn length(&self, a: i32, b: i32) -> f64 {
    let c = (a * a) + (b * b);
    if c > MAX || c < MIN {panic!("overload.");}
    (c as f64).sqrt()
  }
  fn midpoint(&self, a: i32, b: i32, c: i32, d: i32) -> Point {
    let mp: Point = Point {x: (a + b) / 2, y: (c + d) / 2};
    if mp.x > MAX || mp.x < MIN {panic!("overload");}
    if mp.y > MAX || mp.y < MIN {panic!("overload");}
    mp
  }
}
fn main() {
  let mut numbox = vec![0, 0, 0, 0];
  for i in 0..4 {
    match i {
      0 => println!("point 1 x-value: "),
      1 => println!("point 1 y-value: "),
      2 => println!("point 2 x-value: "),
      3 => println!("point 2 y-value: "),
      _ => panic!("error"),
    }
    let mut osin = io::stdin();
    let mut entry = String::new();
    osin.read_line(&mut entry).ok().expect("error.");
    let gen: Option<i32> = entry.trim().parse::<i32>().ok();
    let num = match gen {Some(num) => num, None => {return;}};
    if num > MAX || num < MIN {panic!("overload");}
    numbox[i] = num;
  }
  let p1: Point = Point {x: numbox[0], y: numbox[1]};
  let p2: Point = Point {x: numbox[2], y: numbox[3]};
  let l1: Line = Line {h: p1, i: p2};
  println!("point 1: ({}, {})", l1.h.x, l1.h.y);
  println!("point 2: ({}, {})", l1.i.x, l1.i.y);
  if l1.h.x > l1.i.x {println! ("domain: {} <= x <= {}", l1.i.x, l1.h.x);}
  if l1.i.x > l1.h.x {println! ("domain: {} <= x <= {}", l1.h.x, l1.i.x);}
  if l1.h.x == l1.i.x {println! ("domain: {} <= x <= {}", l1.i.x, l1.h.x);}
  if l1.h.y > l1.i.y {println! ("range: {} <= y <= {}", l1.i.y, l1.h.y);}
  if l1.i.y > l1.h.y {println! ("range: {} <= y <= {}", l1.h.y, l1.i.y);}
  if l1.h.y == l1.i.y {println! ("range: {} <= y <= {}", l1.i.y, l1.h.y);}
  let s1: i32 = if l1.h.x > l1.i.x {l1.h.x - l1.i.x} else {l1.i.x - l1.h.x};
  if s1 > MAX || s1 < MIN {panic!("overload");}
  let s2: i32 = if l1.h.y > l1.i.y {l1.h.y - l1.i.y} else {l1.i.y - l1.h.y};
  if s2 > MAX || s2 < MIN {panic!("overload");}
  let len = l1.length (s1, s2);
  println!("length: {}", len);
  let mid = l1.midpoint(l1.h.x, l1.i.x, l1.h.y, l1.i.y);
  println!("midpoint ≈ ({}, {})", mid.x, mid.y);
}
