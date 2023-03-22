#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef> // for size_t

class Vector {
public:
    explicit Vector(size_t size = 0, int value = 0);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    ~Vector();

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    int* data() noexcept;
    const int* data() const noexcept;

    bool empty() const noexcept;
    size_t size() const noexcept;
    size_t capacity() const noexcept;
    void reserve(size_t new_capacity);
    void clear() noexcept;
    void resize(size_t new_size, int value = 0);
    void swap(Vector& other) noexcept;

    void push_back(int value);
    void pop_back();
    void insert(size_t index, int value);
    void erase(size_t index);

private:
    int* m_data;
    size_t m_size;
    size_t m_capacity;

    static const size_t kInitialCapacity = 8;
    static const size_t kMaxSmallCapacity = 128;
    size_t CapacityMultiplier = 2;
};

#endif // VECTOR_H

bool operator==(const Vector& lhs, const Vector& rhs);
bool operator!=(const Vector& lhs, const Vector& rhs);
bool operator<(const Vector& lhs, const Vector& rhs);
bool operator<=(const Vector& lhs, const Vector& rhs);
bool operator>(const Vector& lhs, const Vector& rhs);
bool operator>=(const Vector& lhs, const Vector& rhs);