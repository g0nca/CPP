#include "Span.hpp"

int main()
{
    std::cout << "--- TEST 1: Subject ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 2)" << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << " (Expected: 14)" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 2: Exceptions (Maximum Capacity) ---" << std::endl;
    try {
        Span sp = Span(2);
        sp.addNumber(1);
        sp.addNumber(2);
        std::cout << "Trying to add the 3rd element..." << std::endl;
        sp.addNumber(3);
    } catch (std::exception& e) {
        std::cerr << "Exception caught correctly: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 3: Exceptions (Empty or 1 element) ---" << std::endl;
    try {
        Span sp = Span(5);
        sp.addNumber(42);
        std::cout << "Trying to find a span with only 1 number..." << std::endl;
        std::cout << sp.shortestSpan() << std::endl; // Should throw an exception
    } catch (std::exception& e) {
        std::cerr << "Exception caught correctly: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 4: Exceptions (Empty Vector) ---" << std::endl;
    try {
        Span sp = Span(5);
        std::cout << sp.shortestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Exception caught correctly: " << e.what() << std::endl;
    }

        std::cout << "\n--- TEST 5: Exceptions (Without Space on Vector) ---" << std::endl;
    try {
        Span sp = Span(0);
        sp.addNumber(4);
        sp.addNumber(2);
    } catch (std::exception& e) {
        std::cerr << "Exception caught correctly: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 6: Add with Iterator Range (Vector) ---" << std::endl;
    try {
        std::vector<int> vec;
        for (int i = 0; i < 10; ++i)
            vec.push_back(i * 10); // 0, 10, 20... 90

        Span sp = Span(20);
        sp.addNumber(vec.begin(), vec.end());
        std::cout << "Added 10 elements via iterators." << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << " (Expected: 10)" << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << " (Expected: 90)" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n--- TEST 7: At least 10,000 numbers ---" << std::endl;
    try {
        Span sp(15000);
        std::vector<int> bigVec;
        std::srand(std::time(NULL));

        for (int i = 0; i < 15000; i++) {
            bigVec.push_back(std::rand());
        }

        sp.addNumber(bigVec.begin(), bigVec.end());
        std::cout << "15,000 elements added successfully." << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
