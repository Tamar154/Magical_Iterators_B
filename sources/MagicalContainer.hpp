#pragma once

#include <vector>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;

        std::vector<size_t> ascIndexes;
        std::vector<size_t> crossIndexes;
        std::vector<size_t> primeIndexes;


    public:
        MagicalContainer();

        void addElement(int element);
        void removeElement(int element);
        std::size_t size() const;

        bool operator==(const MagicalContainer &other) const;

        void print(std::vector<int> vec); // delete

        //  ======================== Iterators ========================

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t current;

            // AscendingIterator(AscendingIterator &&other) = default;
            // AscendingIterator &operator=(AscendingIterator &&other) = default;

        public:
            AscendingIterator();
            AscendingIterator(MagicalContainer &container);
            AscendingIterator(const AscendingIterator &other);

            ~AscendingIterator() = default;

            AscendingIterator &operator=(const AscendingIterator &other);

            bool operator==(const AscendingIterator &other) const;
            bool operator!=(const AscendingIterator &other) const;
            bool operator>(const AscendingIterator &other) const;
            bool operator<(const AscendingIterator &other) const;

            int operator*() const;

            AscendingIterator &operator++();

            AscendingIterator begin();
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        private:
            const MagicalContainer *container;
            std::vector<int>::const_iterator current;

        public:
            SideCrossIterator() : container(nullptr) {}
            SideCrossIterator(const MagicalContainer &container) : container(&container), current(container.elements.begin()) {}
            SideCrossIterator(const SideCrossIterator &other) : container(other.container), current(other.current) {}
            SideCrossIterator(SideCrossIterator &&other) = default;
            ~SideCrossIterator() = default;

            SideCrossIterator &operator=(SideCrossIterator &&other) = default;
            SideCrossIterator &operator=(const SideCrossIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    current = other.current;
                }
                return *this;
            }

            bool operator==(const SideCrossIterator &other) const { return false; };
            bool operator!=(const SideCrossIterator &other) const { return false; };
            bool operator>(const SideCrossIterator &other) const { return false; };
            bool operator<(const SideCrossIterator &other) const { return false; };

            const int &operator*() const { return *current; }

            SideCrossIterator &operator++()
            {
                ++current;
                return *this;
            }

            SideCrossIterator begin() { return *this; }
            SideCrossIterator end() { return *this; }
        };

        class PrimeIterator
        {
        private:
            const MagicalContainer *container;
            std::vector<int>::const_iterator current;

        public:
            PrimeIterator() : container(nullptr) {}
            PrimeIterator(const MagicalContainer &container) : container(&container), current(container.elements.begin()) {}
            PrimeIterator(const PrimeIterator &other) : container(other.container), current(other.current) {}
            PrimeIterator(PrimeIterator &&other) = default;
            ~PrimeIterator() = default;

            PrimeIterator &operator=(PrimeIterator &&other) = default;
            PrimeIterator &operator=(const PrimeIterator &other)
            {
                if (this != &other)
                {
                    container = other.container;
                    current = other.current;
                }
                return *this;
            }

            bool operator==(const PrimeIterator &other) const { return false; };
            bool operator!=(const PrimeIterator &other) const { return false; };
            bool operator>(const PrimeIterator &other) const { return false; };
            bool operator<(const PrimeIterator &other) const { return false; };

            const int &operator*() const { return *current; }

            PrimeIterator &operator++()
            {
                ++current;
                return *this;
            }

            PrimeIterator begin() { return *this; }
            PrimeIterator end() { return *this; }
        };
    };
}