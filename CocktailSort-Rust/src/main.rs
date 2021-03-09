// cd .\Desktop\Algoritmos\Cases\Caso-3-AnalisisAlgoritmos\CocktailSort-Rust\CocktailSortRust\

extern crate rand;
use rand::Rng;
use std::time::{Instant};

pub fn cocktail_sort(arr: &mut [i32]) {
    let last = arr.len() - 1;
    loop {
        let mut swapped = false;
        for i in 0..last {
            if arr[i] > arr[i + 1] {
                arr.swap(i, i + 1);
                swapped = true;
            }
        }

        if swapped == false {
            return;
        }

        swapped = false;
        for i in (0..last - 1).rev() {
            if arr[i] > arr[i + 1] {
                arr.swap(i, i + 1);
                swapped = true;
            }
        }

        if swapped == false {
            return;
        }
    }
}

 pub fn llenar_lista(arr: &mut [i32]) {
    for indice in 0..arr.len(){
        //print!("indice = {}",indice);
        arr[indice]=rand::thread_rng().gen_range(0,3000000);
    }
 }
fn main() {
    let now = Instant::now();
    let mut numbers:[i32;100000] = [rand::thread_rng().gen_range(0,3000000);100000];
    //llenar_lista(&mut numbers);
    print!("LLeno la lista\n");
    print!("numbers[0]={}\n",numbers[0]);
    print!("numbers[99999]={}\n",numbers[99999]);
    cocktail_sort(&mut numbers);
    let duration = now.elapsed();
    println!("Algoritmo cocktail sort realizado con exito");
    println!("El tiempo es de {:?} \n", duration);
   
}