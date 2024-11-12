#include <stdio.h>
#define MAXEXP 4


int main() {
 int workspace = 1;
     for (int i = 1; i <= MAXEXP; i++){
        workspace *= 10;        //make [1,10^maxexp +9] <-- workspace
    }
 workspace += 9;
 // [1, 10^MAXEXP + 9] segment
 
 int minK = 1;
 int maxK = 1;
  for (int k=1; k <= MAXEXP; k++){
     minK *= 10;
     maxK *= 10; 
 }
 minK -= 9;
 maxK += 9;
 // [10^k -9, 10^k + 9] segment
 
 int ZP = 0;
 int Mertens = 0;
 int mobius, n, FlagForNonET;

 printf("Printing the Mertens values in the space [%d,%d]\n", minK, maxK);
 for (n = 1; n <= workspace; n++){
    FlagForNonET = 0;
    int numOfDivisors = 0;
        if (n == 1) // 1 is a special case
        {       
            int mobius = 1;
        } 
        else if (n % 4 == 0 || n % 9 == 0) // around 30% of numbers are divided with 4 or 9 so non ET
        {       
          FlagForNonET = 1;                   
        } 
        else 
        {          // else for the rest of the cases
           for (int current_divisor = 2; current_divisor <= n; current_divisor++){      // find the divisors of n
            int temporaryN = n;

            if (temporaryN % current_divisor == 0)
            {
             temporaryN /= current_divisor;
             // if n is divided twice with the same number the number is not ET
             if (temporaryN % current_divisor == 0)
             {
               FlagForNonET = 1;
               break;
              }
              else // check if the divisor is prime
              {     
                int flag = 0;
                for (int i = 2; i < current_divisor; i++) {     
                  if (current_divisor % i == 0) 
                  {
                    temporaryN *= current_divisor;  //the square of current divisor must be cancelled 
                    flag = 1;
                    break;
                  }
                }
                
                if (flag == 0) {
                    numOfDivisors++;
                }
                }
            }
           }
        }
  if (n == 1) {     //determine the mobius value
    mobius = 1;
  }
  else if (FlagForNonET == 1) {
    mobius = 0;
  }
  else if (numOfDivisors % 2 == 0 || numOfDivisors == 0) {
    mobius = 1;
  }
  else {
    mobius = -1;
  }
 
  Mertens += mobius;
  if (Mertens == 0) {
    ZP++;
  }
  if (n >= minK && n <= maxK) 
  {
  printf("M(%d) = %d\n", n, Mertens);
   }

  }
  printf("Found %d zero points of the Mertens\n", ZP);

  //First 2 objectives segment done


  printf("Checking numbers in the range of [2,%d]\n", ZP*1000);


  int NumOfdeficient = 0;
  int NumOfAbudant = 0;
  for (int i = 2; i <= 1000 * ZP; i++) {
    int divisorsum = 0;
    for (int potdivisor = 1; potdivisor < i; potdivisor++){     //potdivisor = potential divisor of i
      if (i % potdivisor == 0) {
        divisorsum += potdivisor;
      }
      if (divisorsum > i) {       //cut operating time by stopping when an abudant is located (we dont need the exact number)
        break;
      }
    }
    if (divisorsum == i){         // Check for Perfect numbers
      printf ("Found Perfect Number: %d\n", i);
    } else if (divisorsum < i) {      //else find deficient and abudant
      NumOfdeficient++;
    } else {
      NumOfAbudant++;
    }
  }
  printf("Found %d deficient numbers\n", NumOfdeficient);
  printf("Found %d abudant numbers\n", NumOfAbudant);

  // Last 2 objectives segment
  return 0;
}
