#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <deque>
#include "Utils.hpp"
#include <sys/time.h>


class PmergeMeList
{
    private:
    typedef std::list<std::pair<int, int> > PairList;
    PairList pairList;
    int stragler;
    PmergeMeList();
    
    public:
    std::list<int> sortedList;
    struct timeval start;
    struct timeval end;
    PmergeMeList(std::vector<int>& vec);
    PmergeMeList(const PmergeMeList &other);
    PmergeMeList &operator=(const PmergeMeList &other);
    ~PmergeMeList();
    void MakePair(std::vector<int>& vec);
    void SortInsidePair();
    void MergeSort(PairList::iterator start, PairList::iterator end);
    void createSortedList();
    void jacobsthalInsertion();
};



class PmergeMeVector
{
    private:
        typedef std::vector<std::pair<int, int> > PairVector;

        PairVector pairVector;
        int stragler;

        PmergeMeVector();

    public:
        std::vector<int> sortedVector;
        struct timeval start;
        struct timeval end;

        PmergeMeVector(std::vector<int>& vec);
        PmergeMeVector(const PmergeMeVector &other);
        PmergeMeVector &operator=(const PmergeMeVector &other);
        ~PmergeMeVector();

        void MakePair(std::vector<int>& vec);
        void SortInsidePair();
        void MergeSort(PairVector::iterator start, PairVector::iterator end);
        void createSortedVector();
        void jacobsthalInsertion();
        void simpleInsertion();

};


#endif