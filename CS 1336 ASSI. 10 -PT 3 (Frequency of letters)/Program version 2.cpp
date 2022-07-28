/*

    This program will calculate the frequency of occurrence of each type of character in a given text file.


1. Declare and initialize an array that stores each upper and lower case letter in order.
2. Open the input text file.
3. If the file does not open, display an error message to the user and quit the program.
4. while (Store the each character gotten from the file)
    {
        Update the number of characters that are in the file.
        for (Process each array element)
        {
            if (Check if the character that was gotten from the file is equal to the current array element (is an alphabet))
            {
                Update the number of alphabets that are in the file.
                Update the frequency of occurrences for that letter (array element).
                If the alphabet is a lower case letter, update the number of lower case alphabets that are in the file.
                If the alphabet is an upper case letter, update the number of upper case alphabets that are in the file.
            }
        }
    }
5. Calculate the number of non alphabets that are in the text file.
6. Display the frequency of the occurrence of each character category to the user.
7. for (Process each upper case letter array element)
    {
        Display the letter, its index, and the number of times it occurred, if it occurred at least once in the text file.
    }
8. Display the number of upper case letters in the text file.
9. for (Process each lower case letter array element)
    {
        Display the letter, its index, and the number of times it occurred, if it occurred at least once in the text file.
    }
10. Display the number of lower case letters in the text file.
11. Close the input file.

*/


// This program will calculate the frequency of occurrence of each type of character in a given text file.

#include <iostream>
#include <fstream>

using namespace std;

    // Main function.
int main()
{
        // Declare constants.
    const int NUM_CHARACTERS = 52;  // To hold the number of upper and lower case alphabets.

    // Declare variables.

        // Array that stores each upper and lower case letter.
    char charArr[NUM_CHARACTERS] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                                    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    int occurrences[NUM_CHARACTERS] = {0};  // Array that stores the frequency of occurrences of each letter.

    int numChars = 0;  // To hold the number of characters that are in the file.
    int numAlphabets = 0;  // To hold the number of alphabets that are in the file.
    int numLowerCaseLetter = 0;  // To hold the number of lower case alphabets that are in the file.
    int numUpperCaseLetter = 0;  // To hold the number of upper case alphabets that are in the file.
    int numNonAlphabets = 0;  // To hold the number of non alphabets that are in the file.
    char fileContent;  // To hold each character that will be gotten from the text file.

    ifstream inputFile;  // To hold the input file.

        // Open the input file.
    inputFile.open ( "Ass10_fileread.txt" );

    // If the file does not open, display an error message to the user and quit the program.
    if (!inputFile)
    {
        cout << "File \"Ass10_fileread.txt\" could not be opened." << endl;
        exit(0);
    }

    // If the file opens, process it's content.

        // Store the each character gotten from the file.
    while (inputFile >> fileContent)
    {
            // Update the number of characters that are in the file.
        numChars++;

            // Process each array element.
        for (int i = 0; i < NUM_CHARACTERS; i++)
        {
                // Check if the character that was gotten from the file is equal to the current array element (is an alphabet).
            if (fileContent == charArr[i])
            {
                    // Update the number of alphabets that are in the file.
                numAlphabets++;

                    // Update the frequency of occurrences for that letter (array element).
                occurrences[i]++;

                    // If the alphabet is a lower case letter, update the number of lower case alphabets that are in the file.
                if ( i <= 26 )
                    numLowerCaseLetter++;

                    // If the alphabet is an upper case letter, update the number of upper case alphabets that are in the file.
                else
                    numUpperCaseLetter++;
            }
        }
    }

        // Calculate the number of non alphabets that are in the text file.
    numNonAlphabets = numChars - numAlphabets;

        // Display the frequency of the occurrence of each character category to the user.
    cout << "The number of non alphabets is " << numNonAlphabets << endl;
    cout << "The number of upper case alphabets is " << numUpperCaseLetter << endl;
    cout << "The number of lower case alphabets alphabets is " << numLowerCaseLetter << endl;
    cout << "The number of  alphabets is " << numAlphabets << endl;
    cout << "The number of characters is " << numChars << endl << endl;

        // Process each upper case letter array element.
    for (int i = 26; i < NUM_CHARACTERS; i++)
    {
            // Display the letter, its index, and the number of times it occurred, if it occurred at least once in the text file.
        if (occurrences[i] > 0)
            cout << "The letter " << charArr[i] << " in index " << i - 26 << " occurs " << occurrences[i] << " times" << endl;
    }

        // Display the number of upper case letters in the text file.
    cout << "The total number of uppercase letters are " << numUpperCaseLetter << endl << endl;

        // Process each lower case letter array element.
    for (int i = 0; i < 26; i++)
    {
            // Display the letter, its index, and the number of times it occurred, if it occurred at least once in the text file.
        if (occurrences[i] > 0)
            cout << "The letter " << charArr[i] << " in index " << i << " occurs " << occurrences[i] << " times" << endl;
    }

        // Display the number of lowercase case letters in the text file.
    cout << "The total number of lowercase letters are " << numLowerCaseLetter << endl;

        // Close the input file.
    inputFile.close();

    return 0;
}

/*

    RUN 1:

The number of non alphabets is 22
The number of upper case alphabets is 8
The number of lower case alphabets alphabets is 700
The number of  alphabets is 708
The number of characters is 730

The letter E in index 4 occurs 1 times
The letter M in index 12 occurs 1 times
The letter R in index 17 occurs 1 times
The letter T in index 19 occurs 5 times
The total number of uppercase letters are 8

The letter a in index 0 occurs 55 times
The letter b in index 1 occurs 8 times
The letter c in index 2 occurs 25 times
The letter d in index 3 occurs 15 times
The letter e in index 4 occurs 97 times
The letter f in index 5 occurs 8 times
The letter g in index 6 occurs 13 times
The letter h in index 7 occurs 43 times
The letter i in index 8 occurs 53 times
The letter k in index 10 occurs 7 times
The letter l in index 11 occurs 33 times
The letter m in index 12 occurs 9 times
The letter n in index 13 occurs 48 times
The letter o in index 14 occurs 48 times
The letter p in index 15 occurs 21 times
The letter r in index 17 occurs 52 times
The letter s in index 18 occurs 57 times
The letter t in index 19 occurs 61 times
The letter u in index 20 occurs 17 times
The letter v in index 21 occurs 8 times
The letter w in index 22 occurs 13 times
The letter x in index 23 occurs 3 times
The letter y in index 24 occurs 6 times
The total number of lowercase letters are 700

    -------------------------------------------------

    RUN 2:

File "Ass10_fileread.txt" could not be opened.

*/
