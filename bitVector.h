#ifndef BIT_VECTOR
#define BIT_VECTOR
#include <iostream>

class bitVector
{
private:
    char* m_data;
    std::size_t m_size;

public:
    bitVector();
    ~bitVector();

public:
    void set(const std::size_t, bool);
    bool get(const std::size_t);
    void resize (const std::size_t size);
    std::size_t size() const;

public:
    bool operator[](const std::size_t);

};

#endif // BIT_VECTOR