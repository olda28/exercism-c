/// Determines whether the supplied string is a valid ISBN
pub fn is_valid_isbn(isbn: &str) -> bool {
    let mut iter = isbn.chars().rev();
    let Some(check) = iter.next().and_then(|c| match c {
        'X' => Some(10),
        '0'..='9' => c.to_digit(10),
        _ => None
    }) else { return false };

    iter
        .filter(|c| *c != '-')
        .try_fold((check, 2), |(sum, count), c| {
            c.to_digit(10).map(|n| (sum + n * count, count + 1))
        })
        .is_some_and(|(n, count)| n % 11 == 0 && count == 11)
}