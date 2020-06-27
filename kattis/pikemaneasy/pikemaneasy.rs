use std::io;

fn main() {
    // Read input
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let l: Vec<i128> = input
        .trim()
        .split(" ")
        .map(|x| x.parse::<i128>().unwrap())
        .collect();

    let n_problems: i128 = *l.get(0).unwrap();
    let c_length: i128 = *l.get(1).unwrap();

    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();

    let l: Vec<i128> = input
        .trim()
        .split(" ")
        .map(|x| x.parse::<i128>().unwrap())
        .collect();

    let a: i128 = *l.get(0).unwrap();
    let b: i128 = *l.get(1).unwrap();
    let c: i128 = *l.get(2).unwrap();
    let t0: i128 = *l.get(3).unwrap();

    let mut p_times = Vec::with_capacity(n_problems as usize);
    p_times.push(t0);

    let mut t_minus_one: i128 = t0;

    for _ in 1..n_problems {
        let t: i128 = (a * t_minus_one + b).rem_euclid(c) + 1;
        p_times.push(t);
        t_minus_one = t;
    }

    p_times.sort();

    let mut total_time: i128 = 0;
    let mut total_problems: i128 = 0;
    let mut s: i128 = 0;

    for p_time in &p_times {
        if (s + p_time) > c_length {
            break;
        }
        s += p_time;

        total_time = (total_time + s).rem_euclid(1000000007);
        total_problems += 1;
    }

    println!("{} {}", total_problems, total_time);
}
