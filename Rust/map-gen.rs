extern crate rand;
const MAP_SIZE: usize = 25;
struct Map {r: u8, m: [[u8; MAP_SIZE]; MAP_SIZE]}
impl Map {
  fn generate(&mut self) {
    for y in 0..MAP_SIZE {
      for x in 0..MAP_SIZE {
        self.m[y][x] = rand::random::<u8>() % self.r;
      }
    }
  }
  fn smooth(&mut self) {
    for y in 0..MAP_SIZE {
      for x in 0..MAP_SIZE {
        if x > 0 && self.m[y][x - 1] > self.m[y][x] {
          self.m[y][x] = self.m[y][x - 1] - (self.m[y][x] / 2);
        }
        if x < MAP_SIZE - 1 && self.m[y][x + 1] > self.m[y][x] {
          self.m[y][x] = self.m[y][x + 1] - (self.m[y][x] / 2);
        }
        if y > 0 && self.m[y - 1][x] > self.m[y][x] {
          self.m[y][x] = self.m[y - 1][x] - (self.m[y][x] / 2);
        }
        if y < MAP_SIZE - 1 && self.m[y + 1][x] > self.m[y][x] {
          self.m[y][x] = self.m[y + 1][x] - (self.m[y][x] / 2);
        }
      }
    }
    for y in 0..MAP_SIZE {
      for x in 0..MAP_SIZE {
        if x > 0 && self.m[y][x - 1] < self.m[y][x] {
          self.m[y][x] = self.m[y][x - 1] + (self.m[y][x] / 5);
        }
        if x < MAP_SIZE - 1 && self.m[y][x + 1] < self.m[y][x] {
          self.m[y][x] = self.m[y][x + 1] + (self.m[y][x] / 5);
        }
        if y > 0 && self.m[y - 1][x] < self.m[y][x] {
          self.m[y][x] = self.m[y - 1][x] + (self.m[y][x] / 5);
        }
        if y < MAP_SIZE - 1 && self.m[y + 1][x] < self.m[y][x] {
          self.m[y][x] = self.m[y + 1][x] + (self.m[y][x] / 5);
        }
      }
    }
  }
  fn print(&self) {
    for y in 0..MAP_SIZE {
      for x in 0..MAP_SIZE {
        print!("{} ", self.m[y][x]);
      }
      println!("");
    }
  }
}
fn main() {
  let mut map_1: Map = Map {r: 10, m: [[0; MAP_SIZE]; MAP_SIZE]};
  map_1.generate();
  map_1.smooth();
  map_1.print();
}
