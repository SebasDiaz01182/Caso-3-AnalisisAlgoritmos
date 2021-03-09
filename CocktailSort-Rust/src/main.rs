// cd .\Desktop\Algoritmos\Cases\Caso-3-AnalisisAlgoritmos\CocktailSort-Rust\CocktailSortRust\

extern crate rand;
use rand::Rng;

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

pub fn cocktail_sort2<T: PartialOrd>(s: &mut [T]) {
    let len = s.len();
    // Check if slice is shorter than 2, because if it's empty we get
    // substraction with overflow.
    if len < 2 {
        return;
    }

    let mut begin = 0;
    let mut end = len - 1;
    while begin < end {
        let range = begin..end;
        end = begin;
        for i in range {
            if s[i] > s[i + 1] {
                s.swap(i, i + 1);
                end = i;
            }
        }

        let range = (begin..end).rev();
        begin = end;
        for i in range {
            if s[i] > s[i + 1] {
                s.swap(i, i + 1);
                begin = i;
            }
        }
    }
}

 pub fn llenar_lista(arr: &mut [i32]) {
    for indice in 0..100000{
        //print!("indice = {}",indice);
        arr[indice]= rand::thread_rng().gen_range(0,3000000);
    }
 }
fn main() {
    let mut numbers:[i32;100000] = [5;100000];
    llenar_lista(&mut numbers);
    print!("LLeno la lista\n");
    print!("numbers[0]={}\n",numbers[0]);
    print!("numbers[99999]={}\n",numbers[99999]);
    //cocktail_sort(&mut numbers);
    cocktail_sort2(&mut numbers);
    println!("Algoritmo cocktail sort realizado con exito");
   


}