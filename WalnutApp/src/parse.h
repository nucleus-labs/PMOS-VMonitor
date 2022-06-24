#pragma once

#include <iostream>
#include <sstream>
#include <bitset>
#include <regex>
#include <string>

/**
 * @brief Parse a string into a tokenized list of strings supporting quoted strings.
 * 
 * @param input_string 
 * @return uint8_t* 
 */
uint8_t* parse_input(std::string* input_string)
{
    // separate input into tokens split by spaces unless encapsulated by quotes
    std::regex token_regex("(\"[^\"]*\"|[^\\s]+)");

    // split input string into tokens
    std::sregex_token_iterator token_iter(input_string->begin(), input_string->end(), token_regex, 0);

    // create a vector of tokens
    std::vector<std::string> tokens;

    // iterate over tokens and add to vector
    while (token_iter != std::sregex_token_iterator())
    {
        tokens.push_back(*token_iter);
        ++token_iter;
    }
}