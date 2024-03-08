fn is_prime(n: i32) -> bool {
    if n == 2 || n == 3 { return true; }
    if n <= 1 || n % 2 == 0 || n % 3 == 0 { return false; }

    let mut i = 5;
    while i * i <= n {
        if n % i == 0 || n % (i + 2) == 0 { return false; }
        i += 6
    }

    return true;
}

fn main() {
    let mut primes = 0;
    let mut diagonales = 1;
    let mut odd_number = 1;

    loop {
        odd_number += 2;
        let odd_square = odd_number * odd_number;
        diagonales += 4;

        if is_prime(odd_square - odd_number + 1) { primes += 1 }
        if is_prime(odd_square - 2 * odd_number + 2) { primes += 1 }
        if is_prime(odd_square - 3 * odd_number + 3) { primes += 1 }

        if (primes * 10) / diagonales < 1 { break; }
    }

    println!("{}", odd_number);
}
