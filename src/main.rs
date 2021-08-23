use std::io::stdin;

fn main() {
    let mut input: String = String::new();

    stdin().read_line(&mut input).expect("read failed");

    let mut s = input.split_whitespace();

    let mut str1: String = s.next().unwrap().parse().unwrap();
    let mut str2: String = s.next().unwrap().parse().unwrap();

    let num1: (i32, i32) = trans(&mut str1);
    let num2: (i32, i32) = trans(&mut str2);
}

fn trans(num_str: &mut String) -> (i32, i32) {
    let mut temp = num_str.split('/');

    let num1: i32 = temp.next().unwrap().parse().unwrap();
    let num2: i32 = temp.next().unwrap().parse().unwrap();

    (num1, num2)
}
