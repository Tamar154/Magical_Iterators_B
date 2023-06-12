#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int element)
{
    if (element < 2)
        return false;

    int squaredElement = sqrt(element);
    for (int i = 2; i <= squaredElement; ++i)
    {
        if (element % i == 0)
            return false;
    }
    return true;
}

namespace ariel
{
    MagicalContainer::MagicalContainer() {}

    void MagicalContainer::addElement(int element)
    {
        if (elements.empty() || element > elements.back())
        {
            elements.push_back(element);
            handleCrossIndexes();
            handlePrimeIndexes();
            return;
        }

        int index = 0;
        for (auto i : elements)
        {
            if (i > element)
            {
                elements.insert(elements.begin() + index, element);
                break;
            }
            ++index;
        }
        handleCrossIndexes();
        handlePrimeIndexes();
    }

    void MagicalContainer::removeElement(int element)
    {
        bool flag = false;
        for (vector<int>::iterator it = elements.begin(); it != elements.end(); ++it)
        {
            if (*it == element)
            {
                elements.erase(it);
                flag = true;
                handleCrossIndexes();
                handlePrimeIndexes();
            }
        }
        if (!flag)
            throw runtime_error("No such element in the container");
    }

    std::size_t MagicalContainer::size() const
    {
        return elements.size();
    }

    bool MagicalContainer::operator==(const MagicalContainer &other) const
    {
        return elements == other.elements;
    }

    void MagicalContainer::handleCrossIndexes()
    {
        crossIndexes.clear();
        size_t i = 0;
        while (i < this->size() / 2)
        {
            crossIndexes.push_back(i);
            crossIndexes.push_back(this->size() - i - 1);
            ++i;
        }

        // odd size
        if (this->size() % 2 != 0)
        {
            crossIndexes.push_back(i);
        }
    }

    void MagicalContainer::handlePrimeIndexes()
    {
        primePointers.clear();
        for (auto &i : elements)
        {
            if (isPrime(i))
            {
                primePointers.push_back(&i);
            }
        }
    }

    //  ======================== AscendingIterator ========================

    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
        : container(container), current(0) {}
    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other)
        : container(other.container), current(other.current) {}

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
    {
        if (!(this->container == other.container))
            throw runtime_error("");
        if (this != &other)
        {
            container = other.container;
            current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
    {
        return current == other.current && container == other.container;
    }

    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
    {
        return current > other.current;
    }

    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
    {
        return current < other.current;
    }

    int MagicalContainer::AscendingIterator::operator*() const
    {
        return container.elements[current];
    }

    MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
    {
        if (current == container.size())
            throw runtime_error("beyond end");

        ++current;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
    {
        current = 0;
        return *this;
    }

    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
    {
        current = container.size();
        return *this;
    }

    //  ======================== SideCrossIterator ========================

    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
        : container(container), current(0), start(true) {}
    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other)
        : container(other.container), current(other.current), start(other.start) {}

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
    {
        if (!(this->container == other.container))
            throw runtime_error("");
        if (this != &other)
        {
            container = other.container;
            current = other.current;
            start = other.start;
        }
        return *this;
    }

    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
    {
        return current == other.current && container == other.container;
    }

    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
    {
        return current > other.current;
    }

    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
    {
        return current < other.current;
    }

    int MagicalContainer::SideCrossIterator::operator*() const
    {
        size_t index = container.crossIndexes[current];
        return container.elements[index];
    }

    MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
    {
        if (current == container.size())
            throw runtime_error("beyond end");

        ++current;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
    {
        current = 0;
        return *this;
    }

    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
    {
        current = container.size();
        return *this;
    }

    //  ======================== PrimeIterator ========================

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
        : container(container), current(0) {}
    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other)
        : container(other.container), current(other.current) {}

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
    {
        if (!(this->container == other.container))
            throw runtime_error("");
        if (this != &other)
        {
            container = other.container;
            current = other.current;
        }
        return *this;
    }

    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
    {
        return current == other.current && container == other.container;
    }

    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
    {
        return !(*this == other);
    }

    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
    {
        return current > other.current;
    }

    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
    {
        return current < other.current;
    }

    int MagicalContainer::PrimeIterator::operator*() const
    {
        return *(container.primePointers[current]);
    }

    MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
    {
        if (current == container.primePointers.size())
            throw runtime_error("beyond end");

        ++current;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
    {
        current = 0;
        return *this;
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
    {
        current = container.primePointers.size();
        return *this;
    }
}