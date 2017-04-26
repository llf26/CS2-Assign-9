/*
   COPYRIGHT (C) 2017 Larry Fritz (llf26) All rights reserved.
   CSII assignment 9
   Author.  Larry Fritz
            llf26@zips.uakron.edu
   Version. 1.01 09.09.2017
   Purpose: This program is the test cases for the assignment
*/
#include <iostream>
#include <iomanip>

// prototypes
void unpackCharacters(char[], unsigned);
void displayBits(unsigned);

int main() {
   char characters[4];
   unsigned packed{1633903975}; // a, c, e, g

   std::cout << "The packed character representation is:\n";
   displayBits(packed);

   // demonstrate unpacking of characters
   unpackCharacters(characters, packed);
   std::cout << "\nThe unpacked characters are: ";
   for (size_t i{0}; i < 4; ++i) {
      std::cout << characters[i] << " ";
   }
   std::cout << std::endl;

   std::cout << "\nThe unpacked characters in bits are:" << std::endl;
   for (size_t i{0}; i < 4; ++i) {
      displayBits(characters[i]);
   }

}

// take apart the characters
void unpackCharacters(char characters[], unsigned pack)
{
int mask[4];
//mask[0] = 4278190080;
//mask[1] = 16711680;
//mask[2] =  65280;
mask[3] = 255;
//unsigned temp = pack;

//Variable to hold shift amount from unsigned value
int sa = 24;

for(int i = 0; i < 4; i++)
    {
    //Set each element of array to the unsigned value shifted by the shift amount
    //combined with the mask
    characters[i] = (pack >> sa) & mask[3];
    //Decrease shift amount by 8 bits
    sa -= 8;
    }

}





// display the bits of value
void displayBits(unsigned value)
{
//Change bits to bytes by multiplying by the size an unsigned requires
const int SHIFT = 8 * sizeof(unsigned) -1;
const unsigned MASK = 1 << SHIFT;

std::cout << std::setw(10) << value << "=";

    for(unsigned i = 1; i <= SHIFT + 1; i++)
    {
    //Combine variable value with mask using AND
    std::cout << (value & MASK ? '1' : '0');
    value <<= 1;
    //Output a space every 8 bits
    if(i % 8 == 0)
        std::cout << ' ';
    }
    std::cout << std::endl;
}

