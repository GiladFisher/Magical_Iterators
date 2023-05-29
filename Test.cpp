#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "doctest.h"
#include "MagicalContainer.hpp"

using namespace ariel;
TEST_CASE("Correct Initialization"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    MagicalContainer::PrimeIterator prime_iter(container);
    CHECK(prime_iter == prime_iter.begin());
    MagicalContainer::AscendingIterator asc_iter(container);
    CHECK(asc_iter == asc_iter.begin());
    MagicalContainer::SideCrossIterator cross_iter(container);
    CHECK(cross_iter == cross_iter.begin());
}

TEST_CASE("Adding and Removing Elements"){
    MagicalContainer container;
    CHECK(container.size() == 0);
    container.addElement(1);
    CHECK(container.size() == 1);
    container.addElement(2);
    CHECK(container.size() == 2);
    container.removeElement(1);
    CHECK(container.size() == 1);
    container.removeElement(2);
    CHECK(container.size() == 0);
}

TEST_CASE("Prime Iterator"){
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);
    container.addElement(6);
    container.addElement(7);
    MagicalContainer::PrimeIterator prime_iter(container);
    CHECK(*prime_iter == 2);
    ++prime_iter;
    CHECK(*prime_iter == 3);
    CHECK(prime_iter != prime_iter.begin());
    ++prime_iter;
    CHECK(*prime_iter == 5);
    ++prime_iter;
    CHECK(*prime_iter == 7);
    ++prime_iter;
    CHECK(prime_iter == prime_iter.end());
}

TEST_CASE("Ascending Iterator"){
    MagicalContainer cont;
    cont.addElement(5);
    cont.addElement(4);
    cont.addElement(3);
    cont.addElement(1);
    cont.addElement(2);
    MagicalContainer::AscendingIterator asc_iter(cont);
    CHECK(*asc_iter == 1);
    ++asc_iter;
    CHECK(asc_iter != asc_iter.begin());
    CHECK(*asc_iter == 2);
    ++asc_iter;
    CHECK(*asc_iter == 3);
    ++asc_iter;
    CHECK(*asc_iter == 4);
    ++asc_iter;
    CHECK(*asc_iter == 5);
    ++asc_iter;
    CHECK(asc_iter == asc_iter.end());    
}

TEST_CASE("Side Cross Iterator"){
    MagicalContainer cont;
    cont.addElement(5);
    cont.addElement(4);
    cont.addElement(3);
    cont.addElement(1);
    cont.addElement(2);
    MagicalContainer::SideCrossIterator cross_iter(cont);
    CHECK(*cross_iter == 5);
    ++cross_iter;
    CHECK(cross_iter != cross_iter.begin());
    CHECK(*cross_iter == 2);
    ++cross_iter;
    CHECK(*cross_iter == 4);
    ++cross_iter;
    CHECK(*cross_iter == 1);
    ++cross_iter;
    CHECK(*cross_iter == 3);
    ++cross_iter;
    CHECK(cross_iter == cross_iter.end());
}

TEST_CASE("Boolean operators -AscendingIterator"){
    MagicalContainer cont;
    cont.addElement(5);
    cont.addElement(4);
    cont.addElement(3);
    cont.addElement(1);
    cont.addElement(2);
    MagicalContainer::AscendingIterator asc_iter(cont);
    MagicalContainer::AscendingIterator asc_iter2(cont);
    CHECK(asc_iter == asc_iter2);
    ++asc_iter;
    CHECK(asc_iter != asc_iter2);
    CHECK(asc_iter > asc_iter2);
    CHECK(!(asc_iter < asc_iter2));
    ++asc_iter2;
    CHECK(asc_iter == asc_iter2);
    ++asc_iter2;
    CHECK(asc_iter < asc_iter2);
    CHECK(!(asc_iter > asc_iter2));
}

TEST_CASE("Boolean operators -SideCrossIterator"){
    MagicalContainer cont;
    cont.addElement(5);
    cont.addElement(4);
    cont.addElement(3);
    cont.addElement(1);
    cont.addElement(2);
    MagicalContainer::SideCrossIterator cross_iter(cont);
    MagicalContainer::SideCrossIterator cross_iter2(cont);
    CHECK(cross_iter == cross_iter2);
    ++cross_iter;
    CHECK(cross_iter != cross_iter2);
    CHECK(cross_iter > cross_iter2);
    CHECK(!(cross_iter < cross_iter2));
    ++cross_iter2;
    CHECK(cross_iter == cross_iter2);
    ++cross_iter2;
    CHECK(cross_iter < cross_iter2);
    CHECK(!(cross_iter > cross_iter2));
}

TEST_CASE("Boolean operators -PrimeIterator"){
    MagicalContainer cont;
    cont.addElement(5);
    cont.addElement(4);
    cont.addElement(3);
    cont.addElement(1);
    cont.addElement(2);
    cont.addElement(7);
    MagicalContainer::PrimeIterator prime_iter(cont);
    MagicalContainer::PrimeIterator prime_iter2(cont);
    CHECK(prime_iter == prime_iter2);
    ++prime_iter;
    CHECK(prime_iter != prime_iter2);
    CHECK(prime_iter > prime_iter2);
    CHECK(!(prime_iter < prime_iter2));
    ++prime_iter2;
    CHECK(prime_iter == prime_iter2);
    ++prime_iter2;
    CHECK(prime_iter < prime_iter2);
    CHECK(!(prime_iter > prime_iter2));
}
