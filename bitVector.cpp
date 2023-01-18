#include "bitVector.h"

bitVector::bitVector() : m_size(1)
{
    m_data = new char[m_size];
    m_data[0] = true;
}

bitVector::~bitVector()
{
    delete[] m_data;
}

void bitVector::set(const std::size_t position, bool value)
{
    if (position < 0 || position >= (m_size * sizeof(char) * 8))
    {
        resize(position);
    }
    int index = position / (sizeof(char) * 8);
    if (value)
    {
        m_data[index] |= (1 << (position - (index * 8 * sizeof(char))));
        std::cout << ((m_data[index] >> (position - (index * 8 * sizeof(char)))) & 1) << std::endl;
    }
    else
    {
        m_data[index] &= ~(1 << (position - (index * 8 * sizeof(char))));
    }
}

bool bitVector::get(std::size_t position)
{
    if (position < 0 || position >= (m_size * sizeof(char) * 8))
    {
        throw std::out_of_range("Out of range!");
    }
    int index = position / (sizeof(char) * 8);
    return ((m_data[index] >> (position - (index * sizeof(char) * 8))) & 1);
}

void bitVector::resize(const std::size_t count)
{
    int newSize = count / (sizeof(char) * 8);
    char* newData = new char[++newSize];
    for (int i = 0; i < m_size; ++i)
    {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
    newData = nullptr;
    m_size = newSize;
}

std::size_t bitVector::size() const
{
    return m_size * sizeof(char) * 8;
}

bool bitVector::operator[](const std::size_t position)
{
    return this->get(position);
}   