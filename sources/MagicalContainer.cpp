#include "MagicalContainer.hpp"
#include <iostream>
#include <vector>

using namespace std;

namespace ariel
{
    MagicalContainer::MagicalContainer() {}

    void MagicalContainer::addElement(int element)
    {

        if (elements.empty())
        {
            elements.push_back(element);
            ascIndexes.push_back(0);
            // cout << "elements: " << endl;
            // print(elements);
            // cout << "asc: " << endl;
            // print(ascIndexes);
            return;
        }

        elements.push_back(element);
        int counter = 0;
        // Improve insertion ??
        for (auto &i : elements)
        {
            if (element > i)
                counter++;
        }
        ascIndexes.insert(ascIndexes.begin() + counter, elements.size() - 1);

        // cout << "elements: " << endl;
        // print(elements);
        // cout << "asc: " << endl;
        // print(ascIndexes);
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

    void MagicalContainer::print(std::vector<int> vec) // delete
    {
        for (auto i : vec)
            cout << i << " ";
        cout << endl;
    }

    //  ======================== AscendingIterator ========================

    // MagicalContainer::AscendingIterator::AscendingIterator() : container(nullptr) {}
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
        // cout << "current : " << current << endl;
        size_t index = container.ascIndexes[current];
        cout << "\nindex of operator*: " << index << endl;
        return container.elements[index];
        // return 0;
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

}