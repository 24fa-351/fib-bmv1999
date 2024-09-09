#include <stdio.h>
#include <stdlib.h>

int fib_recursive(int n);

int main(int argc, char *argv[]) 
{
   if(argc != 4)
   {
      return 1;
   }

   // Convert first argument to an integer
   int input = atoi(argv[1]);

   // Open file
   FILE *file = fopen(argv[3], "r");
   if(file == NULL)
   {
      printf("Unable to open file.\n");
      return 1;
   }

   // Read integer from file
   int file_num;
   fscanf(file, "%d", &file_num);
   fclose(file);

   // Add input to file number to get nth value
   int nth_val = input = file_num;

   // Calculate the nth fibonacci number
   int output;
   if(argv[2][0] == 'r')
   {
      output = fib_recursive(nth_val);
   }

   // Output result
   printf("%d\n", output);
   return 0;
}

// Recursive function that outputs Fibanacci numbers
int fib_recursive(int n)
{
   if(n <= 1)
      return n;
   
   return fib_recursive(n - 1) + fib_recursive(n - 2);
}

