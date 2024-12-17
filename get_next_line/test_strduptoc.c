/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strduptoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfakou <hfakou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:01:06 by hfakou            #+#    #+#             */
/*   Updated: 2024/12/17 20:01:18 by hfakou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// Include your ft_strduptoc implementation here
char *ft_strduptoc(const char *str, char c);

int main(void)
{
    char *result;

    // Test 1: Normal behavior
    printf("Test 1: Normal behavior\n");
    result = ft_strduptoc("Hello, World!", ',');
    if (result)
        printf("Result: \"%s\"\n", result); // Expected: "Hello"
    else
        printf("Result: NULL\n");
    free(result);

    // Test 2: Character 'c' not found
    printf("\nTest 2: Character 'c' not found\n");
    result = ft_strduptoc("Hello, World!", 'z');
    if (result)
        printf("Result: \"%s\"\n", result);
    else
        printf("Result: NULL\n"); // Expected: NULL

    // Test 3: Empty string
    printf("\nTest 3: Empty string\n");
    result = ft_strduptoc("", 'x');
    if (result)
        printf("Result: \"%s\"\n", result);
    else
        printf("Result: NULL\n"); // Expected: NULL


    // Test 5: Character 'c' is the first character
    printf("\nTest 5: Character 'c' is the first character\n");
    result = ft_strduptoc("xHello", 'x');
    if (result)
        printf("Result: \"%s\"\n", result); // Expected: ""
    else
        printf("Result: NULL\n");
    free(result);

    // Test 6: Character 'c' at the end of the string
    printf("\nTest 6: Character 'c' at the end of the string\n");
    result = ft_strduptoc("HelloWorld!", '!');
    if (result)
        printf("Result: \"%s\"\n", result); // Expected: "HelloWorld"
    else
        printf("Result: NULL\n");
    free(result);

    // Test 7: String with consecutive 'c' characters
    printf("\nTest 7: String with consecutive 'c' characters\n");
    result = ft_strduptoc("abc,,def", ',');
    if (result)
        printf("Result: \"%s\"\n", result); // Expected: "abc"
    else
        printf("Result: NULL\n");
    free(result);

    // Test 8: Character 'c' not present, but valid string
    printf("\nTest 8: Character 'c' not present, valid string\n");
    result = ft_strduptoc("OnlyTextHere", 'x');
    if (result)
        printf("Result: \"%s\"\n", result);
    else
        printf("Result: NULL\n"); // Expected: NULL
    free(result);

    // Test 9: Single character string that matches 'c'
    printf("\nTest 9: Single character string with 'c'\n");
    result = ft_strduptoc("x", 'x');
    if (result)
        printf("Result: \"%s\"\n", result); // Expected: ""
    else
        printf("Result: NULL\n");
    free(result);

    // Test 10: Single character string that doesn't match 'c'
    printf("\nTest 10: Single character string without 'c'\n");
    result = ft_strduptoc("y", 'x');
    if (result)
        printf("Result: \"%s\"\n", result);
    else
        printf("Result: NULL\n"); // Expected: NULL


    result = ft_strduptoc("", '\0');
    if (result)
        printf("Result: \"%s\"\n", result);
    else
        printf("Result: NULL\n"); // Expected: NULL
    free(result);

    printf("\nTest 10: Single character string without 'x'\n");
    result = ft_strduptoc("x", '\0');
    if (result)
        printf("Result: \"%s\"\n", result);
    else
        printf("Result: NULL\n"); // Expected: NULL
    free(result);

    printf("\nTest 10: Single character string without 'xx'\n");
    result = ft_strduptoc("x", 'x');
    if (result)
        printf("Result: \"%s\"\n", result);
    else
        printf("Result: NULL\n"); // Expected: NULL
    free(result);

    printf("\nAll tests completed.\n");
    return 0;
}
