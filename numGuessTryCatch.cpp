// Copyright (c) 2025. Joseph Wondimagnehu. All rights reserved.
//
// Created by: Joseph Wondimagnehu
// Date: Mar. 27, 2025
/* This program creates a guessing game with a number range of 0-9.
It uses exception handling with a try-catch statement to
prevent erroneous user input from crashing the program. */

/* Include the iostream library for
input and output functionalities. */
#include <iostream>
// Include the random libary for random number generators.
#include <random>
/* Include the string library because it 
adheres to the style guidelines. */
#include <string>

// Runs the main function.
int main() {
    // Declare the correct number as an integer.
    int correctNum;
    // Creates the seed.
    std::random_device rseed;
    // Generates the seed using the mersenne twister.
    std::mt19937 rgen(rseed());
    // Distributes the possible integers over a distance of 0-9.
    std::uniform_int_distribution<int> idist(0, 9);
    // Sets the correct number to the generated integer.
    correctNum = idist(rgen);

    // Declare the variable for the chosen number as a string.
    std::string chosenNumberStr;

    /* Additionally, declare the variable for the chosen nummber
    as an integer. */
    int chosenNumberInt;

    // Ask for the user to enter an integer between 0 and 9.
    std::cout << "Enter an integer between 0 and 9.\n";

    // Store the user's input in the string type of the chosen number.
    std::cin >> chosenNumberStr;

    // Try to check the validity of the user's input.
    try {
        // Convert the user's input into an integer.
        chosenNumberInt = std::stoi(chosenNumberStr);

        // Checks if the chosen number is equal to the correct number.
        if (correctNum == chosenNumberInt) {
            // Display that the user guessed correctly.
            std::cout << "You guessed correctly!";
        } else {
            // Otherwise, the user did not guess correctly.
            /* Display that the user guessed incorrectly, 
            showing the correct answer. */
            std::cout << "You guessed incorrectly! The correct answer was "
            << correctNum << ".";
        }
    } catch (std::invalid_argument) {
        /* Run if std::stoi could not convert the
        user's input value to an integer. */
        // Display that the user did not enter a valid integer.
        std::cout << chosenNumberStr << " is not an integer.";
    }
}
