use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).unwrap();

    let mut s = input.split_whitespace();

    let num: u32 = s.next().expect("failed to read number...").parse().expect("too...");
    let ch: &str = s.next().expect("failed to read String...");
    
    let max = get(num);
    let remainder = num + 1 - 2 * max * max;
    print(max, ch);
    println!("{}", remainder);
}

fn get(num: u32) -> u32 {
    let mut ans = 1;
    while 2 * ans * ans - 1 < num {
        ans += 1;
    }

    if ans == 1 { ans } else { ans - 1 }
}

fn print(max: u32, ch: &str) {
    let mut count = 0;
    let u_max: usize = max as usize;
    let mut u_count: usize = 0;

    while count < 2 * max - 1 {
        if count < max {
            println!("{}{}", " ".repeat(u_count),
                            ch.repeat(2 * u_max - 2 * u_count - 1));
        } else {
            println!("{}{}", " ".repeat(2 * u_max - u_count - 2),
                            ch.repeat(2 * u_count - 2 * u_max + 3));
        }
        count += 1;
        u_count += 1;
    }
}
