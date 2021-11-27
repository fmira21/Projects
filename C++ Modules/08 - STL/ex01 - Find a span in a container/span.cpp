#include "span.hpp"

Span::Span(void) : _size(0)
{
    this->_storage.push_back(0);
}

Span::Span(unsigned int sz) : _size(sz)
{
    this->_storage.reserve(sz);
}

Span::~Span(void)
{

}

Span& Span::operator=( const Span& from )
{
    if (this != &from) {
		this->_size = from._size;
		for (unsigned int i = 0; i < this->_size; i++)
        {
			this->_storage[i] = from._storage[i];
		}
	}
	return *this;
}

int& Span::operator[](const unsigned int index)
{
    if (index >= this->_size)
        throw outOfBoundsException();

    return(this->_storage[index]);
};

unsigned int Span::getSize(void)
{
    return(_size);
}

std::vector<int> Span::getStorage(void)
{
    return(_storage);
}

void Span::addNumber(int nbr)
{
    if (this->_storage.size() < this->_size)
        this->_storage.push_back(nbr);
    else throw noMoreSpaceException();
}

int Span::shortestSpan(void)
{
    int sSpan;
    if(this->_storage.size() < 2)
        throw noSpanException();
    std::sort(this->_storage.begin(), this->_storage.end());
    sSpan = this->_storage[1] - this->_storage[0];

    return(sSpan);
}

int Span::longestSpan(void)
{
    int lSpan;
    if(this->_storage.size() < 2)
        throw noSpanException();    
    lSpan = *std::max_element(this->_storage.begin(), this->_storage.end()) - *std::min_element(this->_storage.begin(), this->_storage.end());

    return lSpan;
}