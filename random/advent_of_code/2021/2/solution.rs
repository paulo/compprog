use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {
    part1();
    part2();
}

fn part1() {
    let mut x = 0;
    let mut y = 0;

    if let Ok(lines) = read_lines("./input.txt") {
        for line in lines {            
            if let Ok(ip) = line {
                let command = ip.split(" ").collect::<Vec<&str>>();
                let units = command[1].parse::<i32>().unwrap();
                match command[0] {
                    "up" => y-=units,
                    "down" => y+=units,
                    _ => x+=units,
                }
            }
        }
    }

    println!("Result 1: {} x {} = {}", x, y, x*y);
}

fn part2() {
    let mut x = 0;
    let mut y = 0;
    let mut aim = 0;

    if let Ok(lines) = read_lines("./input.txt") {
        for line in lines {            
            if let Ok(ip) = line {
                let command = ip.split(" ").collect::<Vec<&str>>();
                let units = command[1].parse::<i32>().unwrap();
                match command[0] {
                    "up" => aim-=units,
                    "down" => aim+=units,
                    _ => {
                        x+=units;
                        y+=aim*units;
                    }
                }
            }
        }
    }

    println!("Result 2: {} x {} = {}", x, y, x*y);
}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}