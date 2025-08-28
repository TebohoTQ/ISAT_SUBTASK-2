#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        cout << "Binary: 0" << endl;
        return;
    }
    string binary = "";
    while (decimal > 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal /= 2;
    }
    cout << "Binary: " << binary << endl;
}

// Function to convert binary to decimal
int binaryToDecimal(const string& binary) {
    int decimal = 0;
    for (int i = 0; i < binary.length(); ++i) {
        if (binary[i] == '1') {
            decimal += pow(2, binary.length() - 1 - i);
        }
    }
    return decimal;
}

// Function to convert decimal to hexadecimal
void decimalToHexadecimal(int decimal) {
    if (decimal == 0) {
        cout << "Hexadecimal: 0" << endl;
        return;
    }
    string hex = "";
    string hex_chars = "0123456789ABCDEF";
    while (decimal > 0) {
        hex = hex_chars[decimal % 16] + hex;
        decimal /= 16;
    }
    cout << "Hexadecimal: " << hex << endl;
}

// Function to convert hexadecimal to decimal
int hexadecimalToDecimal(const string& hex) {
    int decimal = 0;
    int power = 0;
    for (int i = hex.length() - 1; i >= 0; --i) {
        char c = toupper(hex[i]);
        if (c >= '0' && c <= '9') {
            decimal += (c - '0') * pow(16, power);
        } else if (c >= 'A' && c <= 'F') {
            decimal += (c - 'A' + 10) * pow(16, power);
        }
        power++;
    }
    return decimal;
}

// Function for the demo option
void demo() {
    srand(time(0));
    int randomDecimal = rand() % 1000 + 1; // Random decimal number from 1 to 1000
    
    cout << "--- Demo Mode ---" << endl;
    
    cout << "Random Decimal: " << randomDecimal << endl;
    decimalToBinary(randomDecimal);
    decimalToHexadecimal(randomDecimal);
    
    // Generate a random binary number for the demo
    string randomBinary = "";
    int binaryLength = rand() % 8 + 4; // Random binary length between 4 and 11
    for (int i = 0; i < binaryLength; ++i) {
        randomBinary += to_string(rand() % 2);
    }

    cout << "\nRandom Binary: " << randomBinary << endl;
    cout << "Decimal: " << binaryToDecimal(randomBinary) << endl;

    // Generate a random hexadecimal number for the demo
    string randomHex = "";
    int hexLength = rand() % 4 + 1; // Random hex length between 1 and 4
    string hex_chars = "0123456789ABCDEF";
    for (int i = 0; i < hexLength; ++i) {
        randomHex += hex_chars[rand() % 16];
    }
    
    cout << "\nRandom Hexadecimal: " << randomHex << endl;
    cout << "Decimal: " << hexadecimalToDecimal(randomHex) << endl;
    
    cout << "--- End of Demo ---" << endl;
}

int main() {
    int choice;
    cout << "Choose conversion type:" << endl;
    cout << "1. Decimal to Binary" << endl;
    cout << "2. Binary to Decimal" << endl;
    cout << "3. Decimal to Hexadecimal" << endl;
    cout << "4. Hexadecimal to Decimal" << endl;
    cout << "5. Demo" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        decimalToBinary(decimal);
    } else if (choice == 2) {
        string binary;
        cout << "Enter a binary number: ";
        cin >> binary;
        cout << "Decimal: " << binaryToDecimal(binary) << endl;
    } else if (choice == 3) {
        int decimal;
        cout << "Enter a decimal number: ";
        cin >> decimal;
        decimalToHexadecimal(decimal);
    } else if (choice == 4) {
        string hex;
        cout << "Enter a hexadecimal number: ";
        cin >> hex;
        cout << "Decimal: " << hexadecimalToDecimal(hex) << endl;
    } else if (choice == 5) {
        demo();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
   
