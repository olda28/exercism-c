use std::cmp::Ordering;
use crate::Comparison::{Equal, Sublist, Superlist, Unequal};

#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    let (smaller, bigger) = if first_list.len() < second_list.len() {
        (first_list, second_list)
    } else {
        (second_list, first_list)
    };

    let found = smaller.is_empty() || bigger.windows(smaller.len()).any(|window| window == smaller);


    if !found { return Unequal }
    match first_list.len().cmp(&second_list.len()) {
        Ordering::Less => Sublist,
        Ordering::Equal => Equal,
        Ordering::Greater => Superlist
    }
}