#include <iostream>
#include "vector.h"

int main() {
    // create a vector with size 5 and initial value 1
    Vector v(5, 1);

    // print the vector size and capacity
    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;

    // print the vector contents
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // resize the vector to size 10, with initial value 2
    v.resize(10, 2);

    // print the vector size and capacity
    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;

    // print the vector contents
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // change the value of the first element to 3
    v[0] = 3;

    // print the vector contents
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // add an element with value 4 to the end of the vector
    v.push_back(4);

    // print the vector size and capacity
    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;

    // print the vector contents
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // remove the last element from the vector
    v.pop_back();

    // print the vector size and capacity
    std::cout << "Size: " << v.size() << std::endl;
    std::cout << "Capacity: " << v.capacity() << std::endl;

    // print the vector contents
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    // Create a vector of size 5 with all elements initialized to 0
    Vector v1(5, 0);

    // Access an element of the vector
    std::cout << v1[0] << '\n';

    // Modify an element of the vector
    v1[0] = 42;

    // Get a pointer to the underlying data array
    int* data = v1.data();

    // Resize the vector to a larger size and fill the new elements with a value
    v1.resize(10, 99);

    // Check the size and capacity of the vector
    std::cout << "Size: " << v1.size() << '\n';
    std::cout << "Capacity: " << v1.capacity() << '\n';

    // Reserve space for more elements
    v1.reserve(100);

    // Add elements to the end of the vector
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    // Copy the vector
    Vector v2 = v1;

    // Move the vector
    Vector v3 = std::move(v2);

    // Swap two vectors
    v1.swap(v3);

    // Clear the contents of a vector
    v3.clear();

    Vector v4(3,0);
    v4[0] = 1;
    v4[1] = 2;
    v4[2] = 3;
    Vector v5(3, 0);
    v5[0] = 1;
    v5[1] = 2;
    v5[2] = 3;
    Vector v6(3, 0);
    v6[0] = 4;
    v6[1] = 5;
    v6[2] = 6;

    // Test the equality operator
    if (v4 == v5) {
        std::cout << "v4 and v5 are equal" << std::endl;
    }
    else {
        std::cout << "v4 and v5 are not equal" << std::endl;
    }

    if (v4 == v6) {
        std::cout << "v4 and v6 are equal" << std::endl;
    }
    else {
        std::cout << "v4 and v6 are not equal" << std::endl;
    }

    // Test the inequality operator
    if (v4 != v5) {
        std::cout << "v4 and v5 are not equal" << std::endl;
    }
    else {
        std::cout << "v4 and v5 are equal" << std::endl;
    }

    if (v4 != v6) {
        std::cout << "v4 and v6 are not equal" << std::endl;
    }
    else {
        std::cout << "v4 and v6 are equal" << std::endl;
    }

    // Test the less than operator
    if (v4 < v6) {
        std::cout << "v4 is less than v6" << std::endl;
    }
    else {
        std::cout << "v4 is not less than v6" << std::endl;
    }

    if (v6 < v4) {
        std::cout << "v6 is less than v4" << std::endl;
    }
    else {
        std::cout << "v6 is not less than v4" << std::endl;
    }

    // Test the less than or equal to operator
    if (v4 <= v6) {
        std::cout << "v4 is less than or equal to v6" << std::endl;
    }
    else {
        std::cout << "v4 is not less than or equal to v6" << std::endl;
    }

    if (v6 <= v4) {
        std::cout << "v6 is less than or equal to v4" << std::endl;
    }
    else {
        std::cout << "v6 is not less than or equal to v4" << std::endl;
    }

    // Test the greater than operator
    if (v4 > v6) {
        std::cout << "v4 is greater than v6" << std::endl;
    }
    else {
        std::cout << "v4 is not greater than v6" << std::endl;
    }

    return 0;
}
