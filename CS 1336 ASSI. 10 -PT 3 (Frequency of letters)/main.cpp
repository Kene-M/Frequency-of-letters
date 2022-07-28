/*

    This program will calculate the frequency of occurrence of each type of character in a given text file.


1. Declare two arrays that store the occurrences of upper and lower case letters.
2. Open the input text file.
3. If the file does not open, display an error message to the user and quit the program.
4. while (Store the each character gotten from the file)
    {
        Update the number of characters that are in the file.

        if the character that was gotten from the file is an alphabet:
        {
            Update the number of alphabets that are in the file.
            If the alphabet is a lower case letter:
            {
                Update the number of lower case alphabets that are in the file.
                Update the frequency of occurrences for that letter (array element) by accessing it,s index.
            }
            If the alphabet is an upper case letter:
            {
                Update the number of upper case alphabets that are in the file.
                Update the frequency of occurrences for that letter (array element) by accessing it,s index.
            }
        }
    }
5. Calculate the number of non alphabets that are in the text file.
6. Display the frequency of the occurrence of each character category to the user.
7. for (Process each array element for upper and lower case letters)
    {
        Display the letter, its index, and the number of times it occurred, if it occurred at least once in the text file.
    }
8. Close the input file.

*/


// This program will calculate the frequency of occurrence of each type of character in a given text file.

#include <iostream>
#include <fstream>

using namespace std;

    // Main function.
int main()
{
        // Declare constants.
    const int NUM_CHARACTERS = 26;  // To hold the number of alphabets.

        // Declare variables.
    int upperCaseArr[NUM_CHARACTERS] = {0};  // Array that stores the occurrences of upper case letters.
    int lowerCaseArr[NUM_CHARACTERS] = {0};  // Array that stores the occurrences of lower case letters.

    int numChars = 0;  // To hold the number of characters that are in the file.
    int numAlphabets = 0;  // To hold the number of alphabets that are in the file.
    int numLowerCaseLetter = 0;  // To hold the number of lower case alphabets that are in the file.
    int numUpperCaseLetter = 0;  // To hold the number of upper case alphabets that are in the file.
    int numNonAlphabets = 0;  // To hold the number of non alphabets that are in the file.
    char fileContent;  // To hold each character that will be gotten from the text file.
    int index;  // Array subscript/Counter variable.

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

            // Check if the character that was gotten from the file is an alphabet.
        if ((fileContent >= 'a' && fileContent <= 'z') || (fileContent >= 'A' && fileContent <= 'Z'))
        {
                // Update the number of alphabets that are in the file.
            numAlphabets++;

                // If the alphabet is a lower case letter:
            if ( fileContent >= 'a' && fileContent <= 'z' )
            {
                    // Update the number of lower case alphabets that are in the file.
                numLowerCaseLetter++;

                    // Update the frequency of occurrences for that letter (array element) by accessing it,s index.
                lowerCaseArr[fileContent -'a']++;
            }

                // If the alphabet is an upper case letter:
            else if ( fileContent >= 'A' && fileContent <= 'Z' )
            {
                    // Update the number of upper case alphabets that are in the file.
                numUpperCaseLetter++;

                    // Update the frequency of occurrences for that letter (array element) by accessing it,s index.
                upperCaseArr[fileContent -'A']++;
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

        // Process each array element for upper case letters.
    for (index = 0; (index < NUM_CHARACTERS); index++)
    {
            // Display the letter, it's index, and the number of times it occurred, if it occurred at least once in the text file.
        if (upperCaseArr[index] > 0)
            cout << "The letter " << char(index + 'A') << " in index " << index << " occurs " << upperCaseArr[index] << " times" << endl;
    }

        // Display the number of upper case letters in the text file.
    cout << "The total number of uppercase letters are " << numUpperCaseLetter << endl << endl;

        // Process each array element for lower case letters.
    for (index = 0; (index < NUM_CHARACTERS) ; index++)
    {
            // Display the letter, it's index, and the number of times it occurred, if it occurred at least once in the text file.
        if (lowerCaseArr[index] > 0)
            cout << "The letter " << char(index + 'a') << " in index " << index << " occurs " << lowerCaseArr[index] << " times" << endl;
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
