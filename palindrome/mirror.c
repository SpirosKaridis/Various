#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int checkifdecimal(long double n)
{
    if (ceil(n) == floor(n)){
        return 0;
    } else {
        return 1;
    }
}

int isPrime(unsigned long long int rt){
    for (unsigned long long int i = 2; i * i <= rt / 2; i++){
        if (rt % i == 0){
            return 1; // if it is not prime we skip it
        } 
    }
    return 0;
}

int fastPalindomic(unsigned long long int x){ //check if first and last digit are the same if not the number is not palindromic
    unsigned long long int last = x % 10;
    while (x >= 10) {
        x /= 10;
    } 
    if (x == last) {
        return 1;
    } else {
        return 0;
    }
} 


unsigned long long int isPalindromic(long long int x){
    long long int reversed = 0, temp_mover = x;

        while(temp_mover != 0) {    //we create the mirrored version of the number
            long long int rem = temp_mover % 10;
            reversed = reversed * 10 + rem;
            temp_mover /= 10;
        }
        
        if (x == reversed) { // if it palindromic is we skip it
            return 1;
        } else {
            return reversed;
        }
}


int main(int argc, char* argv[]) {
    long double square;
    unsigned long long int temp, sum = 0;

    if(argc != 3) { // we check whether enough info has been provided
        printf("Error, please provide sufficient data.\n");
        exit(1);
    }

    temp = strlen(argv[2]); //we make sure there is no number given bigger than 10^15
    if(temp >= 16) {
        printf("Invalid upper border\n");
        exit(1);
    }

    unsigned long long int start = strtoull((argv[1]), NULL, 10), end = strtoull((argv[2]), NULL, 10); // we use start as low border and end as high border accordinngly
    if (start > end || end > 1e15 || start <= 0) {  //we check the integrity of the border given
        printf("Invalid borders given.\n");
        exit(1);
    }

    for (unsigned long long int i = start; i <= end; i++) {    //we traverse the total of values

        temp = isPalindromic(i);// we check whether i is palindromic
        if(temp == 1){
            continue;
        } else {
            square = sqrt((double)temp); // we check if the reverse form is perfect square
            if (checkifdecimal(square)) continue;
        }

        if (isPrime((unsigned long long int)square)) // if the mirrored form is not a perfect square of a prime number we skip it 
        {
            continue;
        }

        square = sqrt((double)i);
        if (checkifdecimal(square)) continue;

        if (isPrime((unsigned long long int)square)) { // we check whether i is a perfect square of a prime
            continue;  
        }
       
        sum = sum + i;
    }
    printf("%llu\n", sum);
    return 0;
}
