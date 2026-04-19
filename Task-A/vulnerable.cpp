#include <iostream>
#include <cstring>

void login() {
    char password_buffer[8]; // Very small fixed buffer
    
    std::cout << "Enter password: ";
    
    // VULNERABILITY: cin >> into a char array has no bounds checking.
    // If the user enters more than 8 characters, it will overflow the stack.
    std::cin >> password_buffer; 

    if (strcmp(password_buffer, "admin") == 0) {
        std::cout << "Access granted!\n";
    } else {
        std::cout << "Access denied.\n";
    }
}

int main() {
    login();
    return 0;
}