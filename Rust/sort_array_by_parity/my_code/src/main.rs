fn main() {
    println!("Hello, world!");
}

struct Solution {}

impl Solution {
    pub fn sort_array_by_parity(a: Vec<i32>) -> Vec<i32> {
        let mut i: usize = 0;
        let mut j = a.len() - 1;
        let mut result: Vec<i32> = Vec::with_capacity(a.len());
        result.resize(a.len(), 0);
        for n in a.iter() {
            if (n & 1) != 0 {
                result[j] = *n;
                j -= 1;
            } else {
                result[i] = *n;
                i += 1;
            }
        }
        result
    }
}
