use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let test_cases: i64 = input.trim().parse().unwrap();

    for i in 1..test_cases + 1 {
        // Read vector size
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let _n: i64 = input.trim().parse().unwrap();

        // Read vectors
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        // First vector: ordered in desc
        let mut v1: Vec<i64> = input
            .trim()
            .split(" ")
            .map(|x| x.parse::<i64>().unwrap())
            .collect();

        v1.sort();
        v1.reverse();

        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();

        // Second vector, ordered in asc
        let mut v2: Vec<i64> = input
            .trim()
            .split(" ")
            .map(|x| x.parse::<i64>().unwrap())
            .collect();

        v2.sort();

        let dot: i64 = v1.iter().zip(v2.iter()).map(|(x, y)| x * y).sum();

        println!("Case #{}: {}", i, dot);
    }
}
