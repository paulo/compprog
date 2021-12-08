use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
    part1();
    part2();
}

fn part1() {
    let mut prev = -1;
    let mut current;
    let mut count = 0;

    if let Ok(lines) = read_lines("./input.txt") {
        for line in lines {            
            if let Ok(ip) = line {
                current = ip.parse::<i32>().unwrap();
                if current > prev && prev != -1 {
                    count+=1;
                } 
                prev = current;
            }
        }
    }

    println!("Count 1: {}", count);
}

fn part2() {
    let mut state = vec![-1, -1, -1];
    let mut current;
    let mut prev = -1;
    let mut count = 0;

    if let Ok(lines) = read_lines("./input.txt") {
        for line in lines {            
            if let Ok(ip) = line {
                current = ip.parse::<i32>().unwrap();
                state[0] = state[1];
                state[1] = state[2];
                state[2] = current;

                if state[0] == -1 {
                   prev = state[0];
                   continue; 
                }

                if prev == -1 {
                    prev = state[0] + state[1] + state[2];
                    continue;
                }

                if state[0] + state[1] + state[2] > prev {
                    count+=1;
                }

                prev = state[0] + state[1] + state[2];
            }
        }
    }

    println!("Count 2: {}", count);
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}