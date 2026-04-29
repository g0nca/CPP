#include "Serializer.hpp"

void printHeader(const std::string& title) {
    std::cout << "\n============================================\n";
    std::cout << "    TESTE: " << title << "\n";
    std::cout << "============================================\n";
}

int main()
{
    // TESTE 1

    printHeader("Memoria na Stack");
    Data stackData;
    stackData.name = "TesteStack";
    stackData.value = 42;

    uintptr_t rawStack = Serializer::serialize(&stackData);
    Data* ptrStack = Serializer::deserialize(rawStack);

    std::cout << "Ponteiro Original : " << &stackData << "\n";
    std::cout << "Valor Serializado : 0x" << std::hex << rawStack << std::dec << "\n";
    std::cout << "Ponteiro Recuperado: " << ptrStack << "\n";

    if (ptrStack == &stackData && ptrStack->name == "TesteStack" && ptrStack->value == 42)
        std::cout << "SUCESSO: O endereco e os dados mantiveram-se intactos!\n";
    else
        std::cout << "FALHOU!\n";

    // TESTE 2

    printHeader("Memoria na Heap (new)");
    Data* heapData = new Data;
    heapData->name = "TesteHeap";
    heapData->value = 999;

    uintptr_t rawHeap = Serializer::serialize(heapData);
    Data* ptrHeap = Serializer::deserialize(rawHeap);

    std::cout << "Ponteiro Original : " << heapData << "\n";
    std::cout << "Valor Serializado : 0x" << std::hex << rawHeap << std::dec << "\n";
    std::cout << "Ponteiro Recuperado: " << ptrHeap << "\n";

    if (ptrHeap == heapData && ptrHeap->name == "TesteHeap" && ptrHeap->value == 999)
        std::cout << "SUCESSO: O endereco dinâmico manteve-se intacto!\n";
    else
        std::cout << "FALHOU!\n";

    delete heapData;



    // TESTE 3

    printHeader("Ponteiro Nulo (Edge Case)");
    
    Data* nullData = NULL;
    uintptr_t rawNull = Serializer::serialize(nullData);
    Data* ptrNull = Serializer::deserialize(rawNull);

    std::cout << "Ponteiro Original : " << nullData << "\n";
    std::cout << "Valor Serializado : 0x" << std::hex << rawNull << std::dec << "\n";
    std::cout << "Ponteiro Recuperado: " << ptrNull << "\n";

    if (ptrNull == NULL)
        std::cout << "SUCESSO: O programa sobreviveu a um ponteiro nulo!\n\n";
    else
        std::cout << "FALHOU: O ponteiro devia ser NULL (0x0)!\n\n";

    return 0;
}