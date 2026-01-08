#include <iostream>
#include <iomanip> // Para formatação de saída
#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

static void printTest(const std::string& description, bool condition) {
    std::cout << std::left << std::setw(40) << description << ": " << (condition ? "[PASS]" : "[FAIL]") << std::endl;
}

int main(void) {
    Data* originalPtr = new Data;
    originalPtr->name = "Alessandro";
    originalPtr->nickname = "Cabelinho";
    originalPtr->age = 25;

    std::cout << "--- Test initialized ---" << std::endl;

    uintptr_t raw = Serializer::serialize(originalPtr);
    
    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "\nResults:" << std::endl;
    
    printTest("Verifying the adress (Pointer Check)", originalPtr == deserializedPtr);
    
    printTest("Verifying content (name)", originalPtr->name == deserializedPtr->name);
    printTest("Verifying content (nickname)", originalPtr->nickname == deserializedPtr->nickname);
    printTest("Verifying content (age)", originalPtr->age == deserializedPtr->age);

    std::cout << "\nTechnical Details:" << std::endl;
    std::cout << "Original Adress:    " << originalPtr << std::endl;
    std::cout << "Serialized Value:    0x" << std::hex << raw << std::dec << " (hex)" << std::endl;
    std::cout << "Final Adress:       " << deserializedPtr << std::endl;
    std::cout << "\n--- Data Content ---" << std::endl;
    std::cout << *originalPtr;

    delete originalPtr;
    std::cout << "\n--- Test Concluded with Success ---" << std::endl;

    return 0;
}