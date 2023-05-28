#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <list>
#include <algorithm>
#include <set>

namespace ariel{
    class MagicalContainer{
        private:
            std::list<int> original_order; // all the values by order of insertion
            std::set<int> sorted; // sorted by value 
            std::list<int> prime; // only prime numbers by order of insertion 
            void updatePrimeContainer();

        public:

            MagicalContainer();
            MagicalContainer(std::vector<int> container);
            ~MagicalContainer();
            void addElement(int element);
            void removeElement(int element);
            int size();
            bool contains(int element);

            class PrimeIterator{
                private:
                    unsigned int curr;
                    std::list<int>* prime_ptr;

                public:
                    PrimeIterator(MagicalContainer &container); // init
                    PrimeIterator& operator++(); // goes to next prime number
                    bool operator>(const PrimeIterator& other) const; // compare indexes 
                    bool operator<(const PrimeIterator& other) const;
                    bool operator==(const PrimeIterator& other) const;
                    bool operator!=(const PrimeIterator& other) const;
                    int operator*() const; // get value
            }
    };
}