#pragma once

#include <vector>

namespace ariel
{
    class MagicalContainer
    {
    private:
        std::vector<int> elements;
        std::vector<int *> primePointers;
        std::vector<int *> crossIndexes;

    public:
        MagicalContainer();

        void addElement(int element);
        void removeElement(int element);
        std::size_t size() const;

        bool operator==(const MagicalContainer &other) const;

        void handleCrossIndexes();
        void handlePrimeIndexes();

        //  ======================== Iterators ========================

        class AscendingIterator
        {
        private:
            MagicalContainer &container;
            size_t current;

            AscendingIterator(AscendingIterator &&other) = delete;
            AscendingIterator &operator=(AscendingIterator &&other) = delete;

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
            MagicalContainer &container;
            size_t current;
            bool start;

            SideCrossIterator(SideCrossIterator &&other) = delete;
            SideCrossIterator &operator=(SideCrossIterator &&other) = delete;

        public:
            SideCrossIterator();
            SideCrossIterator(MagicalContainer &container);
            SideCrossIterator(const SideCrossIterator &other);

            ~SideCrossIterator() = default;

            SideCrossIterator &operator=(const SideCrossIterator &other);

            bool operator==(const SideCrossIterator &other) const;
            bool operator!=(const SideCrossIterator &other) const;
            bool operator>(const SideCrossIterator &other) const;
            bool operator<(const SideCrossIterator &other) const;

            int operator*() const;

            SideCrossIterator &operator++();

            SideCrossIterator begin();
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &container;
            size_t current;

            PrimeIterator(PrimeIterator &&other) = delete;
            PrimeIterator &operator=(PrimeIterator &&other) = delete;

        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer &container);
            PrimeIterator(const PrimeIterator &other);

            ~PrimeIterator() = default;

            PrimeIterator &operator=(const PrimeIterator &other);

            bool operator==(const PrimeIterator &other) const;
            bool operator!=(const PrimeIterator &other) const;
            bool operator>(const PrimeIterator &other) const;
            bool operator<(const PrimeIterator &other) const;

            int operator*() const;

            PrimeIterator &operator++();

            PrimeIterator begin();
            PrimeIterator end();
        };
    };
}