mod bindings;

type clock_t = i64;

extern "C" {
    pub fn clock() -> clock_t;
}

impl std::ops::Add<bindings::V3d> for bindings::V3d {
    type Output = Self;

    fn add(self, rhs: bindings::V3d) -> Self::Output {
        Self::Output {
            x: self.x + rhs.x,
            y: self.y + rhs.y,
            z: self.z + rhs.z,
        }
    }
}

fn method_a(count: usize) {
    let mut t = unsafe { clock() };
    let mut c = unsafe { bindings::v3d_create(0.0, 0.0, 0.0) };
    let mut d = unsafe { bindings::v3d_create(0.0, 0.0, 0.0) };

    for _ in 0..count {
        let a = unsafe { bindings::v3d_create(1.0, 2.0, 3.0) };
        let b = unsafe { bindings::v3d_create(1.0, 2.0, 3.0) };
        c = unsafe { bindings::v3d_add_a(a, b) };
        d.x += c.x;
        d.y += c.y;
        d.z += c.z;
    }

    t = unsafe { clock() } - t;

    println!("{}", t);
    println!("{} {} {}", d.x, d.y, d.z);
}

fn method_b(count: usize) {
    let mut t = unsafe { clock() };
    let mut c = unsafe { bindings::v3d_create(0.0, 0.0, 0.0) };
    let mut d = unsafe { bindings::v3d_create(0.0, 0.0, 0.0) };

    for _ in 0..count {
        let a = unsafe { bindings::v3d_create(1.0, 2.0, 3.0) };
        let b = unsafe { bindings::v3d_create(1.0, 2.0, 3.0) };
        c = unsafe { bindings::v3d_add_b(a, b) };
        d.x += c.x;
        d.y += c.y;
        d.z += c.z;
    }

    t = unsafe { clock() } - t;

    println!("{}", t);
    println!("{} {} {}", d.x, d.y, d.z);
}

fn method_c(count: usize) {
    let mut t = unsafe { clock() };
    let mut c = unsafe { bindings::v3d_create(0.0, 0.0, 0.0) };
    let mut d = unsafe { bindings::v3d_create(0.0, 0.0, 0.0) };

    for _ in 0..count {
        let a = unsafe { bindings::v3d_create(1.0, 2.0, 3.0) };
        let b = unsafe { bindings::v3d_create(1.0, 2.0, 3.0) };
        c = a + b;
        d.x += c.x;
        d.y += c.y;
        d.z += c.z;
    }

    t = unsafe { clock() } - t;

    println!("{}", t);
    println!("{} {} {}", d.x, d.y, d.z);
}

fn main() -> Result<(), ()> {
    let args: Vec<String> = std::env::args().into_iter().collect();

    if args.len() < 2 {
        return Err(());
    }

    let count: usize = args[1].parse().unwrap();

    method_a(count);
    method_b(count);
    method_c(count);

    Ok(())
}
