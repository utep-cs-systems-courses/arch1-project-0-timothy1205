#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");

  while (1) { // Infinite while loop

    fputs("Select which shape you want to print (Triangle = t, Square = s, Chars = c, Arrow = a) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      fputs("Please enter a font:\n", stdout);
      printf("\t%c) 11x16\n", FONT_11x16);
      //printf("\t%c) 8x12\n", FONT_8x12); // Disabled due to 8x12 font having different orientation

      printf("\t%c) 5x7\n", FONT_5x7);
      fflush(stdout);	

      while ((c = getchar()) == '\n'); /* ignore newlines */
      if (c == EOF)		     /* terminate on end-of-file */
        goto done;
      
      int failed = 0;
      switch (c) {
        case '0':
          break;
      //case '1':
      //    break;
      case '2':
        break;
      default:
        failed = 1;
      }

      if (failed) {
        printf("Unrecognized option '%c', please try again!\n", c);
        break;
      }

      for (char letter = 'A'; letter < 'D'; letter++)
      print_char(c, letter);
      break;
    case 'a':
      puts ("You selected arrow:");
      print_arrow(5, 5);
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
