# **String Utility**
 

 ## Description
 This string class is for an assessment for uni.
 It is a predominantly a wrapper class for cstring functions.

 The class has an assortment of functions. These include:
 ```
 Length()
 CharacterAt()
 EqualTo()
 Append()
 Prepend()
 CStr()
 ToLower()
 ToUpper()
 Find()
 Replace()
 ReadFromConsole()
 WriteToConsole()
 Wobble()
 ```

 ## Functions

 ### Length()
 The length function returns the length of the string.
 It gets the string length using the strlen() function, returning the result as a size_t value;

 ### CharacterAt()
 The character at function returns a char at the specified index of a string.
 It supports both const and non const char arrays.
 The result is returned as a char.

 ### EqualTo()
 The equal to function determines whether or not two strings are identical.
 It does this using the strcmp() function.
 It returns either true or false.

 ### Append()
 The append function concatenates a string at the end of another string.
 It does this using a combination of strcpy() and strcat().
 It returns a reference of itself.

 ### Prepend()
 The prepend function concatenates a string at the beginning of another string.
 It does this using a combination of strcpy() and strcat().
 It returns a reference of itself.

 ### CStr()
 The cstr function returns a char array for the standary library console out.

 ### ToLower()
 The to lower function transforms all characters of the string to lowercase.
 It does this by looping through each char and using the standard library tolower() function.
 It returns a reference of itself.

 ### ToUpper()
 The to upper function transforms all characters of the string to uppercase.
 It does this by looping through each char and using the standard library toupper() function.
 It returns a reference of itself.

 ### Find()
 The find function searches and finds the location of a substring within a string.
 An index can be supplied to search the string from a specific starting point.
 It returns the location of the substring as a size_t.

 ### Replace()
 The replace function replaces all instances of a substring within a string.
 It returns a reference of itself.

 ### ReadFromConsole()
 The read from console function takes in input from the console and saves it as a string.
 It returns a reference of itself

 ### WriteToConsole()
 The write to console function sends output to the console.
 It returns a reference of itself.

 ### Wobble()
 The wobble function alternates letters in sequence between lowercase and uppercase.
 It returns a reference of itself