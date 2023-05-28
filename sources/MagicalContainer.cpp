#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <list>
#include <algorithm>
#include <iterator>
#include <set>
#include "MagicalContainer.hpp"

namespace ariel{
    MagicalContainer::MagicalContainer(){
    }
    
    MagicalContainer::~MagicalContainer(){
        this->original_order.clear();
        this->sorted.clear();
        this->prime.clear();
        this->cross.clear();
    }

    void MagicalContainer::addElement(int element){
        this->original_order.push_back(element);
        this->sorted.insert(element);
        this->cross.push_back(element);
        this->updatePrimeContainer();
    }

    void MagicalContainer::removeElement(int element){
        this->original_order.remove(element);
        this->sorted.erase(element);
        this->cross.remove(element);
        this->updatePrimeContainer();
    }

    int MagicalContainer::size(){
        return this->original_order.size();
    }

    bool MagicalContainer::contains(int element){
        return (std::find(this->original_order.begin(), this->original_order.end(), element) != this->original_order.end());
    }

    void MagicalContainer::updatePrimeContainer(){
        this->prime.clear();
        for (auto it = this->original_order.begin(); it != this->original_order.end(); ++it){
            if (isPrime(*it)){
                this->prime.push_back(*it);
            }
        }
    }

    bool MagicalContainer::isPrime(int num){
        if (num <= 1){
            return false;
        }
        for (int i = 2; i < num; i++){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }

    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container){
        this->curr = 0;
        this->prime_ptr = &(container.prime);
    }

    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
        this->curr++;
        return *this;
    }
}