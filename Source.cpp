#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

void changeTextColor(int color)//function to change text color
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

string RemoveSpecialCharacters(string word) //clean the word of special characters, spaces, commas, etc. 
{
	string s = "";
	//treat the string word as a array of characters in order to check if each character is a letter
	for (int i = 0; i < word.length(); i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z' || word[i] >= 'A' && word[i] <= 'Z')
		{
			s = s + word[i];
		}
	}
	return s;
}

char convertWordToUppercase( char c)//convert clean string to uppercase to get rid of case-sensitivity
{
	if (c  < 90)//if char is uppercase, return uppercase char as it is
	{
		return c;
	}
	else// else, if char is lowercase, return lowercase char converted uppercase char
	{
		return c - 32;
	}
}

string convertCharacterToUppercase(string word)
{
	string uppercaseWord = "";
	for (int i = 0; i <=word.length(); i++)
	{
		if (word[i] > 90) //when character is lowercase
		{
			uppercaseWord += word[i]-32 ;
		}
		else //when character is uppercase;
		{
			uppercaseWord += word[i];
		}
	}
	return uppercaseWord;
 }

string flip(string uppercaseWord)//flip string 
{
	string flippedWord="";
	//uppercaseWord = convertCharacterToUppercase(word);
	for (int i = uppercaseWord.length() -1; i >= 0; i--)
	{
		flippedWord += uppercaseWord[i];
	}
	return flippedWord;
}

bool isWordaPalindrome(string uppercaseWord,string word) //function to check if user's word is a palindrome
{
	if (word == uppercaseWord) //check if flipped word = original words
	{
		return true;
	}
	else
	{
		return false;
	}
}

void main()
{
	string word;
	string cleanWord;
	string uppercaseWord;
	string flippedWord; 
	char input;

	do
	{
		cout << "Enter a word: ";
		getline(cin, word); //ask user to input string word
	
		cleanWord = RemoveSpecialCharacters(word);
		flippedWord = flip(cleanWord);
		uppercaseWord = convertCharacterToUppercase(flippedWord);

		cout << "Your clean word is: " << cleanWord << endl;
		cout << "Your flipped word is: " << flippedWord << endl;
		cout << "Your clean word in uppercase is: " << uppercaseWord << endl;
	
		//1. clean original word 2. convert that same word into uppercase 3. compare the word to the reversed word
		word = RemoveSpecialCharacters(word); 
		word = convertCharacterToUppercase(word);

		if (isWordaPalindrome(uppercaseWord, word) ==true)
		{
			changeTextColor(10);
			cout << "Your word is a palindrome!" << endl;
			changeTextColor(15);
		}
		else
		{
			changeTextColor(12);
			cout << "Your word is not a palindrome!" << endl;
			changeTextColor(15);
		}
		
		cout << "Do you want to enter another word? (Y/N) " << endl;
		cin >> input;
		cin.ignore();

	} while (input == 'Y' || input == 'y');
}