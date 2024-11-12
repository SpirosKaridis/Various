#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ERROR -1


void WrongInput()
{
    printf("\nInput Error");
    exit(0);
}


int turngrayscale(unsigned int R,unsigned int G,unsigned int B) {   //function to turn ppm to pgm in binary
    unsigned int GS;
    GS = ((299 * R) & (587 * G) & (114 * B)) % 1000;
    return GS;
}

int getinteger(unsigned int base,unsigned int pixel)
{
    unsigned int ch = pixel;               // No need to declare ch as int - no EOF handling
    unsigned int value = 0;                // Initialize return value
        if (ch >= '0' && ch <= '0' + base - 1)      // Legal character?
            value = base * value + (ch - '0');     // Update return value
        else
            return ERROR;               // Illegal character read
    return value;                       // Everything OK - Return value of number read
}


int main ()
{
    int edit_case, flag, width, height, i, bytegetter, value1, value2, value3, j;
    unsigned int photoEntry, temppixel, horizontalcounter, R, B, G, GS, max, digits, black_and_white;

    photoEntry = getchar();

    if (photoEntry != 'P')   //check for P
    {
        WrongInput();
    } else 
    {
        putchar(photoEntry);
    }
    
    photoEntry = getchar(); //check in which P case we are
    if (photoEntry < '1' || photoEntry > '6')
    {
        WrongInput();
    } else 
        edit_case = photoEntry;

    switch (edit_case) {
    case '1' :
        exit(0); //we don't change B&W photos
        break;
    case '2' :    //we make P2  -> P1
        edit_case = '1';
        photoEntry = edit_case;
        putchar(photoEntry);
        break;
    case '3' :    // we make P3 -> P2
        edit_case = '2';
        photoEntry = edit_case;
        putchar(photoEntry);
        break;
    case '4' :
        exit(0);    // same as before for B&W
        break;
    case '5' :  //we make P5 -> P4
        edit_case = '4';
        photoEntry = edit_case;
        putchar(photoEntry);
        break;
    case '6' : //we make P6 -> P5
        edit_case = '5';
        photoEntry = edit_case;
        putchar(photoEntry);
        break;
    }

    photoEntry = getchar(); // we check all ascii info until the pixel segment manually
    if (isspace(photoEntry) == 0) {
        WrongInput();
    } else if (photoEntry == '#' || isspace(photoEntry) != 0) { // we skip both spaces and comments
        while (photoEntry != '\n')
        {
            photoEntry = getchar();
        }
        putchar(photoEntry);
    }

    photoEntry = getchar(); // we skip white space
    while (isspace(photoEntry) != 0 && photoEntry != '#')   // we skip the white space only
    {
        putchar(photoEntry);
    }

    if (photoEntry == 35) //35 = # so we skip the comments
    {
        while(photoEntry != '\n')  
        {
            photoEntry = getchar();
        }
        photoEntry = getchar();
    }

    /////////// PHOTO DIMENSIONS SEGMENT //////////////////
    width = 0;
    while (isspace(photoEntry) == 0)   // we get the width
    {
        width *= 10;
        width += getinteger(10, photoEntry);
        putchar(photoEntry);    
        photoEntry = getchar(); 
    }

    while (isspace(photoEntry) != 0) // white space after width
    { 
        putchar(photoEntry);
        photoEntry = getchar();
    }

    height = 0;
    while (isspace(photoEntry) == 0) // we get the height
    {
        height *= 10;
        height += getinteger(10, photoEntry);
        putchar(photoEntry);   
        photoEntry = getchar();
    }

    while (isspace(photoEntry) != 0)    //white space after height
    {
        putchar(photoEntry);
        photoEntry = getchar();
    }

    switch (edit_case)    // we check the integrity, we set a max of 255 to make sure its 1 byte data
    {
     case '1' :
     case '4' : //we have to create a MAX value, if we make a P4 or P1 photo, we dont print it
            if (photoEntry > '2')
                WrongInput();
        max = 0;
        max += getinteger(10, photoEntry);
        max *= 10;
        photoEntry = getchar();
        max += getinteger(10, photoEntry);
        max *= 10;
        photoEntry = getchar();
        max += getinteger(10, photoEntry);
        break;
     case '2' :
     case '5' :    //we simply print the values it for P5 and P2 photos
            if (photoEntry > '2')
                WrongInput();
        putchar(photoEntry);
        photoEntry = getchar();
        putchar(photoEntry);
        photoEntry = getchar();
        putchar(photoEntry);
        break;
    }

    if (edit_case <= '3')        // for text format we proceed to the white space
    {
       photoEntry = getchar();
       if (isspace(photoEntry) != 0)
       {
        // putchar(photoEntry);
        photoEntry = getchar();
       }
    } else  // for binary we just use a single white character
    {
        photoEntry = getchar();
        putchar(photoEntry);
    }


    ///////////////// PIXEL ENCODING ///////////////////

  switch (edit_case) {
    
        case '4' : // binary format grayscale to B&W
        for (j = 0; j < height; j++)
        {
            for (horizontalcounter = 0; horizontalcounter < width; horizontalcounter++) {
            temppixel = 0;
            for (i = 0; i < 8; i++) {   // process 8 pixels at a time
                photoEntry = getchar();
                temppixel <<= 1;
                if (photoEntry < (max + 1) / 2) {
                    temppixel |= 1;             // raise the bit for a dark pixel
                }
            }
            putchar(temppixel);
        }
      }
    break;
   case '5' : //binary format colored to grayscale
    for ( ; ; )
    {
            R = getchar();
            if (R == EOF)
                break;
            G = getchar();
            if (G == EOF)
                break;
            B = getchar();
            if (B == EOF)
                break;
            GS = turngrayscale(R,B,G);
            putchar(GS);
     }
     break;
  case '2' :        //ascii format of colored pixels
    for (i = 0; i < height; i++)
    {
        for (horizontalcounter = 0; horizontalcounter < width - 1; horizontalcounter++)
        {
            photoEntry = getchar();
            if (photoEntry == EOF)
                break;
            if (photoEntry > '0' && photoEntry <= '9') {
                R = getinteger(10, photoEntry) * 100;
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                R += getinteger(10, photoEntry) * 10;
                    photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                R += getinteger(10, photoEntry);
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                putchar(photoEntry);
            } else 
            {
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                if (photoEntry >= '0' && photoEntry <= '9')
                {
                    R = getinteger(10, photoEntry) * 10;
                        photoEntry = getchar();
                    if (photoEntry == EOF)
                        break;
                    R += getinteger(10, photoEntry);
                    photoEntry = getchar();
                    if (photoEntry == EOF)
                        break;
                }
            }
            photoEntry = getchar();
            putchar(' ');
            if (photoEntry > '0' && photoEntry <= '9') {
                G = getinteger(10, photoEntry) * 100;
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                G += getinteger(10, photoEntry) * 10;
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                G += getinteger(10, photoEntry);
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
            } else {
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                if (photoEntry >= '0' && photoEntry <= '9')
                {
                    G = getinteger(10, photoEntry) * 10;
                    photoEntry = getchar();
                    if (photoEntry == EOF)
                        break;
                    G += getinteger(10, photoEntry);
                    photoEntry = getchar();
                    if (photoEntry == EOF)
                        break;
                }
            }
            photoEntry = getchar();
            putchar(' ');
            if (photoEntry > '0' && photoEntry <= '9') {
                B = getinteger(10, photoEntry) * 100;
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                B += getinteger(10, photoEntry) * 10;
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                B += getinteger(10, photoEntry);
                if (photoEntry == EOF)
                    break;
            } else {
                photoEntry = getchar();
                if (photoEntry == EOF)
                    break;
                if (photoEntry >= '0' && photoEntry <= '9')
                {
                    B = getinteger(10, photoEntry) * 10;
                    photoEntry = getchar();
                    if (photoEntry == EOF)
                        break;
                    B += getinteger(10 , photoEntry);
                }
            }
            GS = (((299 * R) & (587 * G) & (114 * B)) % 1000);
            temppixel = GS;
            digits = 1;  //we count the digits of GS
            while (temppixel /= 10)
            {
                    digits ++;
            }

            switch (digits) {   // depending on the amount of digits of the value we print the appropriate ascii value

                case 1 :
                    putchar(GS + '0');
                    putchar(' ');
                    break;
                    
                case 2 :
                    value1 = GS / 10;   // for 2+ digits we need to get the specific digits
                    value2 = GS % 10;
                    putchar(value1 + '0');
                    putchar(value2 + '0');
                    putchar(' ');
                    break;

                case 3 :
                    value1 = GS / 100;
                    value2 = (GS / 10) % 10;
                    value3 = GS % 10;
                    putchar(value1 + '0');
                    putchar(value2 + '0');
                    putchar(value3 + '0');
                    putchar(' ');
                    break;

            }
        }
      }
       break;   // this break is for the switch - case
   case '1' :
    for (i = 0; i < height; i++) 
    {
        for (horizontalcounter = 0; horizontalcounter < width - 1; horizontalcounter++)
        {
            temppixel += getinteger(10, photoEntry);
            photoEntry = getchar();
            if (photoEntry == ' ')
            {
                black_and_white = (temppixel > ((max + 1) / 2)) ? 0 : 1;
                // value1 = black_and_white / 10;
                // value2 = black_and_white % 10;
                // putchar(value1 + '0');
                // putchar(value2 + '0');
                putchar(black_and_white + '0');
                putchar(photoEntry);
            } else
            {
                value1 = temppixel * 10;
                value2 = getinteger(10, photoEntry);
                photoEntry = getchar();
                if (photoEntry == ' ')
                {
                    temppixel = value1 + value2;
                    black_and_white = (temppixel > ((max + 1) / 2)) ? 0 : 1;
                    // value1 = black_and_white / 10;
                    // value2 = black_and_white % 10;
                    // putchar(value1 + '0');
                    // putchar(value2 + '0');
                    putchar(black_and_white + '0');
                    putchar(photoEntry);
                } else
                {
                    value1 *= 10;
                    value2 *= 10;
                    value3 = getinteger(10, photoEntry);
                    temppixel = value1 + value2 + value3;
                    black_and_white - (temppixel > ((max +1) / 2)) ? 0 : 1;
                    // value1 = black_and_white / 10;
                    // value2 = black_and_white % 10;
                    // putchar(value1 + '0');
                    // putchar(value2 + '0');
                    putchar(black_and_white + '0');
                    putchar(photoEntry);
                }
            }
        }
        putchar('\n');
    }
  }
return 0;
}
