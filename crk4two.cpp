#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>

// This function simulates checking if a password is correct
// In a real scenario, this would be replaced with actual authentication logic
bool checkPassword(const std::string& password, const std::string& correctPassword) {
    // Simulate some processing time to make the brute force feel more realistic
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
    return password == correctPassword;
}

int main() {
    // This is for demonstration purposes. In a real scenario, the cracker
    // wouldn't know the correct password - it would be attempting to crack
    // an actual authentication system.
    std::string correctPassword;
    
    std::cout << "===== Two-Digit Password Cracker Demo =====" << std::endl;
    std::cout << "Enter a 2-digit number (00-99) to 'protect': ";
    std::cin >> correctPassword;
    
    // Simple validation to ensure it's a 2-digit number
    while (correctPassword.length() != 2 || !std::isdigit(correctPassword[0]) || !std::isdigit(correctPassword[1])) {
        std::cout << "Please enter exactly 2 digits (00-99): ";
        std::cin >> correctPassword;
    }
    
    std::cout << "\nStarting brute force attack to crack the password..." << std::endl;
    
    // Record start time
    auto startTime = std::chrono::high_resolution_clock::now();
    
    // Try all possible combinations from 00 to 99
    for (int i = 0; i <= 99; i++) {
        // Format the number with leading zero if needed
        std::string attempt = (i < 10) ? "0" + std::to_string(i) : std::to_string(i);
        
        std::cout << "Trying: " << attempt << "\r" << std::flush;
        
        // Check if this is the correct password
        if (checkPassword(attempt, correctPassword)) {
            // Calculate elapsed time
            auto endTime = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
            
            std::cout << std::endl;
            std::cout << "=====================================" << std::endl;
            std::cout << "Password cracked! The password is: " << attempt << std::endl;
            std::cout << "Attempts required: " << i + 1 << std::endl;
            std::cout << "Time taken: " << duration / 1000.0 << " seconds" << std::endl;
            std::cout << "=====================================" << std::endl;
            
            return 0;
        }
    }
    
    // Should never reach here for a 2-digit password
    std::cout << "Failed to crack the password. Something went wrong." << std::endl;
    
    return 0;
}
