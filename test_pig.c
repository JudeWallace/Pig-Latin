#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "pig.h"

void test(char *word, char *expected);

/**
 * test - A set of tests to check the pig latin conversion is as supposed to be
 *
 * @word: Pointer to the word to be converted
 * @expected: Pointer to the expected word in pig latin
 *
 * Return: None
 */
void test(char *word, char *expected)
{
    char result[10];
    // compare if the result is the expected pig latin output
    strcpy(result, pig(word));
    printf("%s => %s\n", word, result);
    // if does not match, display what should be expected in pig latin
    if (strcmp(result, expected) != 0)
    {
        printf("Expected: %s\n", expected);
    }
}

/**
 * main - the starting point of the program to run test cases
 */
int main()
{
    // run the test data through pig.c
    test("happy", "appyhay");
    test("duck", "uckday");
    test("glove", "oveglay");
    test("evil", "evilway");
    test("eight", "eightway");
    test("yowler", "owleryay");
    test("crystal", "ystalcray");
    return 0;
}
