fn main() {
    let mut x:u8 = 255;
    x = wrapping_add(x + 1);
    println!("The value is {x}");
}
