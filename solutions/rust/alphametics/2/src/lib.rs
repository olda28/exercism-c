use std::collections::HashMap;

#[derive(Default)]
struct Stats {
    calls: u64,
    attempts: u64,
    occupied: u64,
    forbidden_zero: u64,
    arithmetic_error: u64,
}
fn bruteforce(puzzle: &Alphametic, position: usize, values: &mut [u8; 10], occupied: &mut [bool; 10], stats: &mut Stats) -> bool {
    stats.calls += 1;
    if position == puzzle.alphabet.len() { return true }

    for digit in 0..=9 {
        stats.attempts += 1;
        if occupied[digit as usize] { stats.occupied += 1; continue }
        if digit == 0 && puzzle.forbidden_zero[position] { stats.forbidden_zero += 1; continue }

        values[position] = digit;
        if !puzzle.check(position, values) { stats.arithmetic_error += 1; continue }

        occupied[digit as usize] = true;

        if bruteforce(puzzle, position + 1, values, occupied, stats) {
            return true;
        }

        occupied[digit as usize] = false;
    }
    false
}

struct RawColumn {
    add_digits: Vec<char>,
    result: Option<char>
}
struct Column {
    add_digits: Vec<usize>,
    result: Option<usize>,
    check_at: usize
}

impl Column {
    fn check(&self, carry: u32, values: &[u8; 10]) -> Option<u32> {
        let sum = self.add_digits
            .iter().map(|i| u32::from(values[*i]))
            .sum::<u32>()
            + carry;
        let expected = u32::from(self.result.map_or(0, |i| values[i]));
        if (sum % 10) == expected {
            Some(sum / 10)
        } else {
            None
        }
    }
}

struct Alphametic {
    forbidden_zero: [bool; 10],
    columns: Vec<Column>,
    alphabet: Vec<char>,
}

impl Alphametic {
    fn check(&self, col_idx: usize, values: &[u8; 10]) -> bool {
        let mut carry = 0;
        let mut checked = 0;
        for column in self.columns.iter().take_while(|c| c.check_at <= col_idx ) {
            if let Some(new_carry) = column.check(carry, values){
               carry = new_carry;
            } else {
                return false
            }
            checked += 1;
        }
        checked != self.columns.len() || carry == 0
    }
}

impl<'a> TryFrom<&'a str> for Alphametic {
    type Error = ();

    fn try_from(value: &'a str) -> Result<Self, Self::Error> {
        // Chop up the string
        let (add_words_str, result_str) = value.split_once("==").ok_or(())?;
        let result_str = result_str.trim();
        let add_words_str = add_words_str
            .split('+')
            .map(str::trim)
            .collect::<Vec<_>>();

        let longest_word = add_words_str.iter().map(|w| w.len()).max().unwrap();

        // Transpose rows into right-to-left columns
        let columns: Vec<RawColumn> = (0..longest_word.max(result_str.len())).map(|i| {
            let words = add_words_str.iter()
                .filter_map(|w| w.chars().rev().nth(i))
                .collect::<Vec<_>>();
            let result = result_str.chars().rev().nth(i);
            RawColumn { add_digits: words, result }
        }).collect();

        // Build alphabet of unique letters, in order of appearance RtL
        let mut alphabet = Vec::new();
        for column in &columns {
            for &c in column.add_digits.iter().chain(&column.result) {
                if alphabet.contains(&c) { continue }
                alphabet.push(c);
            }
        }
        if alphabet.iter().any(|c| !c.is_ascii_alphanumeric()) { return Err(()) }

        if alphabet.len() > 10 { return Err(()) }

        // Build map to find a letter's alphabet index
        let indices: HashMap<char, usize> = alphabet
            .iter()
            .enumerate()
            .map(|(i, &c)| (c, i))
            .collect();

        // Convert RawColumns into indexed Columns
        let columns = columns.iter().map(|col| {
            Column {
                add_digits: col.add_digits.iter().map(|c| indices[c]).collect(),
                result: col.result.map(|c| indices[&c]),
                check_at: col.add_digits.iter().map(|c| indices[c]).chain(col.result.map(|c| indices[&c])).max().unwrap()
            }
        }).collect::<Vec<_>>();

        // Check which indices cannot hold a zero (start of word)
        let mut forbidden_zero = [false; 10];
        for word in add_words_str.iter().chain(std::iter::once(&result_str)) {
            if word.len() > 1 {
                forbidden_zero[indices[&word.chars().next().unwrap()]] = true;
            }
        }

        Ok(Self { forbidden_zero, columns, alphabet })
    }
}
#[allow(clippy::cast_precision_loss)]
#[must_use]
pub fn solve(input: &str) -> Option<HashMap<char, u8>> {
    let mut used = [false; 10];
    let mut values = [0_u8; 10];

    let puzzle: Alphametic = input.try_into().ok()?;

    let mut stats = Stats::default();
    bruteforce(&puzzle, 0, &mut values, &mut used, &mut stats)
        .then(|| {
            println!("Recursive calls: {}", stats.calls);
            println!("Candidate attempts: {}", stats.attempts);
            println!("Occupied: {}", stats.occupied);
            println!("Forbidden zero: {}", stats.forbidden_zero);
            println!("Arithmetic errors: {}", stats.arithmetic_error);

            let arithmetic_candidates = stats.attempts - stats.occupied - stats.forbidden_zero;

            println!(
                "Arithmetic rejection rate: {:.2}%",
                100.0 * stats.arithmetic_error as f32 / arithmetic_candidates as f32
            );

            puzzle.alphabet
                .iter()
                .copied()
                .zip(values)
                .collect()
        })
}