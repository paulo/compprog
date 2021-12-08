use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
    part1();
}

fn part1() {
    let mut v = vec![0,0,0,0,0,0,0,0,0,0,0,0];
    let mut gamma = 0;
    let mut eps = 0;

    if let Ok(lines) = read_lines("./input.txt") {
        for line in lines {            
            if let Ok(ip) = line {
                for (i,c) in ip.chars().enumerate() {
                    if c == '1' {
                        v[i]+=1;
                    } else {
                        v[i]-=1;
                    }
                }
            }
        }
    }

    println!("{:?}", v);

    let mut i = 12;
    for c in v.iter() {
        if c > &0 {
            gamma += i32::pow(2, i-1);
        } else {
            eps += i32::pow(2, i-1);
        }

        i-=1;
    } 

    println!("Result 1: {} x {} = {}", gamma, eps, gamma*eps);
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}