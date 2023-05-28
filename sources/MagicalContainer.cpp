#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
#include <list>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <set>
#include "MagicalContainer.hpp"

    MagicalContainer::MagicalContainer(){
    }

    MagicalContainer::~MagicalContainer(){
        this->original_order.clear();
        this->sorted.clear();
        this->prime.clear();
        this->cross.clear();
    }

    void MagicalContainer::addElement(int element){
    }

    void MagicalContainer::removeElement(int element){
    }

    int MagicalContainer::size() const{
        return this->original_order.size();
    }

    bool MagicalContainer::contains(int element){
        return false;
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
        int sqroot = std::sqrt(num);
        for (int i = 2; i < sqroot; i++){
            if (num % i == 0){
                return false;
            }
        }
        return true;
    }

    PrimeIterator::PrimeIterator(MagicalContainer &container){
    }

    PrimeIterator& PrimeIterator::operator++(){
        return *this;
    }

    bool PrimeIterator::operator==(const PrimeIterator& other) const{
        return false;
    }

    bool PrimeIterator::operator>(const PrimeIterator& other) const{
        return false;
    }

    bool PrimeIterator::operator<(const PrimeIterator& other) const{
        return false;
    }

    bool PrimeIterator::operator!=(const PrimeIterator& other) const{
        return false;
    }

    int PrimeIterator::operator*() const{
        return 0;
    }

    PrimeIterator PrimeIterator::begin() const{
        return *this;
    }

    PrimeIterator PrimeIterator::end() const{
        MagicalContainer container;
        PrimeIterator ans(container);
        return ans;
    }

    PrimeIterator& PrimeIterator::operator=(const PrimeIterator& other){
        return *this;
    }

    AscendingIterator::AscendingIterator(MagicalContainer &container){
    }

    AscendingIterator& AscendingIterator::operator++(){
        return *this;
    }

    bool AscendingIterator::operator==(const AscendingIterator& other) const{
        return false;
    }

    bool AscendingIterator::operator>(const AscendingIterator& other) const{
        return false;
    }

    bool AscendingIterator::operator<(const AscendingIterator& other) const{
        return false;
    }

    bool AscendingIterator::operator!=(const AscendingIterator& other) const{
        return false;
    }

    int AscendingIterator::operator*() const{
        return 0;
    }

    AscendingIterator AscendingIterator::begin() const{
        return *this;
    }

    AscendingIterator AscendingIterator::end() const{
        MagicalContainer container;
        AscendingIterator ans(container);
        return ans;
    }

    AscendingIterator& AscendingIterator::operator=(const AscendingIterator& other){
        return *this;
    }

    SideCrossIterator::SideCrossIterator(MagicalContainer &container){
    }

    SideCrossIterator& SideCrossIterator::operator++(){
        return *this;
    }

    bool SideCrossIterator::operator==(const SideCrossIterator& other) const{
        return false;
    }

    bool SideCrossIterator::operator>(const SideCrossIterator& other) const{
        return false;
    }

    bool SideCrossIterator::operator<(const SideCrossIterator& other) const{
        return false;
    }

    bool SideCrossIterator::operator!=(const SideCrossIterator& other) const{
        return false;
    }

    int SideCrossIterator::operator*() const{
        return 0;
    }

    SideCrossIterator SideCrossIterator::begin() const{
        return *this;
    }

    SideCrossIterator SideCrossIterator::end() const{
        MagicalContainer container;
        SideCrossIterator ans(container);
        return ans;
    }

    SideCrossIterator& SideCrossIterator::operator=(const SideCrossIterator& other){
        return *this;
    }