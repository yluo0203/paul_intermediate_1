//Integer to English Conversion
/*
Integer to english number conversion
Write a program that takes an integer and displays the English name of that value.
You should support both positive and negative numbers, in the range supported by a 32-bit intege (approximately -2 billion to 2 billion).
 */

#include <iostream>
#include <string>

using namespace std;

string translate(int n);
string ToOnes(int n);
string ToTeens(int n);
string ToTens(int n);

int main() {
    int number = 1;
    //Auto Run
    for (int number = 1; number <=9999; number++) {
        cout << number << " is " << translate(number) << endl << endl;
    }

//        while (number > 0){
//            cout << "Input number: ( 1 ~ 9999 )" << endl;
//            cin >> number;
//            cout << number << " is " << translate(number) << endl << endl;
//        }
    return 0;
}

string translate(int n) {
    string words = "";
    int Ones = n%10;
    int TensNumber = n%100;
    int Tens = 0;
    int Hundreds = ( n%1000 ) / 100;
    int Thousands = n / 1000;

    // 1000
    if ( Thousands > 0 ) {
        if ( Hundreds == 0 && TensNumber == 0 && Ones ==0 ) {
            words = ToOnes(Thousands) + "thousand ";
        }else {
        words = ToOnes(Thousands) + "thousand and ";
        }
    }
    
    // 100
    if ( Hundreds > 0 ) {
        if (Thousands > 0 || (TensNumber ==0  && Ones == 0)) {
            words += ToOnes(Hundreds) + "hundred ";
        }else {
            words += ToOnes(Hundreds) + "hundred and ";
        }
    }
    
    // 10
    if ( TensNumber >0 && TensNumber < 10 ) {
        ;
    }else if ( TensNumber >= 10 && TensNumber <= 19 ) {
        words += ToTeens(TensNumber);
        //
        return words;
        
    }else if (TensNumber >= 20 ) {
        Tens = ( TensNumber - ( n%10 ) )/10;
        words += ToTens(Tens);
    }
    
    // 1
    if ( Ones > 0) {
        words += ToOnes(Ones);
    }
    
    return words;
}


string ToOnes(int n) {
    switch (n) {
        case 0: return "zero ";
        case 1: return "one ";
        case 2: return "two ";
        case 3: return "three ";
        case 4: return "four ";
        case 5: return "five ";
        case 6: return "six ";
        case 7: return "seven ";
        case 8: return "eight ";
        case 9: return "nine ";
    }
    return "Oh! GG! ";
}

string ToTeens(int n) {
    switch (n) {
        case 10: return "ten ";
        case 11: return "eleven ";
        case 12: return "twelve ";
        case 13: return "thirteen ";
        case 14: return "fourteen ";
        case 15: return "fivteen ";
        case 16: return "sixteen ";
        case 17: return "seventeen ";
        case 18: return "eighteen ";
        case 19: return "nineteen ";
    }
    return "Oh! GG!! ";
}

string ToTens(int n) {
    switch (n) {

        case 2: return "twenty ";
        case 3: return "thirty ";
        case 4: return "forty ";
        case 5: return "fifty ";
        case 6: return "sixty ";
        case 7: return "seventy ";
        case 8: return "eighty ";
        case 9: return "ninty ";
    }
    return "Oh! GG!!! ";
}

