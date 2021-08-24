use std::io;

fn main() {
    let mut input = String::new();

    io::stdin().read_line(&mut input).unwrap();

    let mut s = input.split_whitespace();

    let start: u32 = s.next().unwrap().parse().unwrap();
    let end: u32 = s.next().unwrap().parse().unwrap();
    let time = set(end - start);

    let sec = time % 60;
    let min = ((time - sec) / 60) % 60;
    let hour = (((time - sec) / 60 - min) / 60 ) % 60;

    println!("{:02}:{:02}:{:02}", hour, min, sec);
}

fn set(test: u32) -> u32 {
    let remainder = test % 100;
    if remainder < 50 {
        (test - remainder) / 100 
    } else {
        (test - remainder) / 100 + 1
    }
}
