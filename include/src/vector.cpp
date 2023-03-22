#include "vector.h"
#include <stdexcept> // for std::out_of_range
#include <algorithm> // for std::copy, std::max
#include <iostream>

/*
This constructor creates a new Vector object with a specified size and value
for all its elements. It dynamically allocates memory for the underlying array of integers,
initializes the size and capacity of the Vector object,
and sets all the elements of the array to the specified value.
*/
Vector::Vector(size_t size, int value)
    : m_data(size > 0 ? new int[size] : nullptr)
    , m_size(size)
    , m_capacity(size > 0 ? size : kInitialCapacity)
{
    std::fill(m_data, m_data + m_size, value);
}

//copy constructor
Vector::Vector(const Vector& other)
    : m_data(other.m_size > 0 ? new int[other.m_size] : nullptr)
    , m_size(other.m_size)
    , m_capacity(other.m_size > 0 ? other.m_size : kInitialCapacity)
{
    std::copy(other.m_data, other.m_data + m_size, m_data);
}

//move constructor
Vector::Vector(Vector&& other) noexcept
    : m_data(other.m_data)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
{
    other.m_data = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;
}

//copy operator =
Vector& Vector::operator=(const Vector& other)
{
    // Check if the source object is not the same as the current object.
    if (this != &other)
    {
        Vector temp(other);
        swap(temp);
    }
    return *this;
}

//move operator =
Vector& Vector::operator=(Vector&& other) noexcept
{
    // Check if the source object is not the same as the current object.
    if (this != &other)
    {
        clear(); // Clear the contents of the current object.
        delete[] m_data; // Delete the old `m_data` array of the current object.
        m_data = other.m_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }
    return *this;
}

//d-tor
Vector::~Vector()
{
    clear(); // Clear the contents of the current object.
    delete[] m_data; // Delete the old `m_data` array of the current object.
}

int& Vector::operator[](size_t index)
{
    if (index >= m_size) //check if the index is within range
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

const int& Vector::operator[](size_t index) const
{
    if (index >= m_size) //check if the index is within range
    {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}


int* Vector::data() noexcept
{
    return m_data;
}

const int* Vector::data() const noexcept
{
    return m_data;
}

bool Vector::empty() const noexcept
{
    return m_size == 0;
}

size_t Vector::size() const noexcept
{
    return m_size;
}

size_t Vector::capacity() const noexcept
{
    return m_capacity;
}

//This function reserves memory space for the dynamic array to contain new_capacity elements
void Vector::reserve(size_t new_capacity)
{
    // If new_capacity is not greater than the current capacity, no action is taken
    if (new_capacity > m_capacity)
    {
        // Allocate a new dynamic array of size new_capacity
        int* new_data = new int[new_capacity];

        // Copy the existing elements of the array to the new vector
        std::copy(m_data, m_data + m_size, new_data);

        delete[] m_data; //erase the existing array

        // Update the new vector
        m_data = new_data;
        m_capacity = new_capacity;
    }
}


//This function clears the content of the current vector
void Vector::clear() noexcept {
    delete[] m_data;
    m_data = nullptr;
    m_size = 0;
    m_capacity = 0;
}


//This function resizes the current vector to the new_size, and initializes the added cells to the value.
void Vector::resize(size_t new_size, int value) {
    if (new_size <= m_size) {
        m_size = new_size;
        return;
    }
    reserve(new_size);
    for (size_t i = m_size; i < new_size; ++i) {
        m_data[i] = value;
    }
    m_size = new_size;
}

//This function swaps the contents of the current Vector object with the contents of another Vector object.
void Vector::swap(Vector& other) noexcept {
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
}

//This function adds a new cell to the vector with the value
void Vector::push_back(int value) {
    if (m_size == m_capacity) {
        CapacityMultiplier = (m_capacity >= 128) ? 1.5 : 2;
        reserve(m_capacity * CapacityMultiplier);
    }
    m_data[m_size] = value;
    ++m_size;
}


//This function erases the last cell of the vector.
void Vector::pop_back() {
    if (m_size > 0) {
        --m_size;
    }
}

//This functions inserts a value into the vector in the index cell
void Vector::insert(size_t index, int value) {
    if (index > m_size) { //check if the index is in range
        return;
    }
    if (m_size == m_capacity) {
        CapacityMultiplier = (m_capacity >= 128) ? 1.5 : 2;
        reserve(m_capacity * CapacityMultiplier);
    }
    std::copy_backward(m_data + index, m_data + m_size, m_data + m_size + 1);
    m_data[index] = value;
    ++m_size;
}

//This function erases the cell in the index place
void Vector::erase(size_t index) {
    if (index >= m_size) { //check if the index is in range
        return;
    }
    std::copy(m_data + index + 1, m_data + m_size, m_data + index);
    --m_size;
}


bool operator==(const Vector& lhs, const Vector& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }

    for (size_t i = 0; i < lhs.size(); i++) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }

    return true;
}

bool operator!=(const Vector& lhs, const Vector& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Vector& lhs, const Vector& rhs)
{
    size_t i = 0;
    while (i < lhs.size() && i < rhs.size()) {
        if (lhs[i] < rhs[i]) {
            return true;
        }
        else if (rhs[i] < lhs[i]) {
            return false;
        }
        i++;
    }

    return (i == lhs.size() && i < rhs.size());
}

bool operator<=(const Vector& lhs, const Vector& rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}

bool operator>(const Vector& lhs, const Vector& rhs)
{
    return !(lhs <= rhs);
}

bool operator>=(const Vector& lhs, const Vector& rhs)
{
    return !(lhs < rhs);
}
