#include "PmergeMe.hpp"

// PmergeMeVector class implementation

PmergeMeVector::PmergeMeVector()
{
}

PmergeMeVector::PmergeMeVector(const PmergeMeVector &other)
{
    pairVector = other.pairVector;
    sortedVector = other.sortedVector;
    stragler = other.stragler;
}

PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector &other)
{
    if (this != &other)
    {
        pairVector = other.pairVector;
        sortedVector = other.sortedVector;
        stragler = other.stragler;
    }
    return *this;
}

PmergeMeVector::~PmergeMeVector()
{
}

PmergeMeVector::PmergeMeVector(std::vector<int>& vec): stragler(-1)
{
    gettimeofday(&start, NULL);

    MakePair(vec);
    SortInsidePair();
    MergeSort(pairVector.begin(), pairVector.end());
    createSortedVector();
    // jacobsthalInsertion();
    //just a demonstration why jacobstha squence is better than simple insertion
    simpleInsertion();


    gettimeofday(&end, NULL);
}

void PmergeMeVector::createSortedVector()
{
    for (PairVector::iterator it = pairVector.begin();
         it != pairVector.end();
         ++it)
    {
        sortedVector.push_back(it->second);
    }

    if (pairVector.size() > 0)
    {
        sortedVector.insert(sortedVector.begin(), pairVector.begin()->first);
    }
}

void PmergeMeVector::simpleInsertion()
{
    for (size_t i = 1; i < pairVector.size(); ++i)
    {
        int value = pairVector[i].first;
        int upperBound = pairVector[i].second;

        std::vector<int>::iterator end = sortedVector.end();

        for (std::vector<int>::iterator it = sortedVector.begin();
             it != sortedVector.end();
             ++it)
        {
            if (*it == upperBound)
            {
                end = it;
                break;
            }
        }

        std::vector<int>::iterator pos =
            std::lower_bound(sortedVector.begin(), end, value);

        sortedVector.insert(pos, value);
    }

    if (stragler != -1)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(sortedVector.begin(),
                             sortedVector.end(),
                             stragler);

        sortedVector.insert(pos, stragler);
    }
}

void PmergeMeVector::jacobsthalInsertion()
{
    size_t Jacobsthal[] = {
        1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
        1365, 2731, 5461, 10923, 21845, 43691,
        87381, 174763, 349525, 699051, 1398101,
        2796203, 5592405, 11184811, 22369621,
        44739243, 89478485, 178956971, 357913941,
        715827883, 1431655765
    };

    size_t pairCount = pairVector.size();

    if (pairCount == 0)
        return;

    size_t previous = 1;

    for (size_t j = 1;
         j < sizeof(Jacobsthal) / sizeof(Jacobsthal[0]);
         ++j)
    {
        size_t current = Jacobsthal[j];

        if (previous >= pairCount)
            break;

        if (current > pairCount)
            current = pairCount;

        size_t i = current;

        while (i > previous)
        {
            --i;

            PairVector::iterator pairIt = pairVector.begin() + i;

            int value = pairIt->first;
            int upperBound = pairIt->second;

            std::vector<int>::iterator end = sortedVector.end();

            for (std::vector<int>::iterator it = sortedVector.begin();
                 it != sortedVector.end();
                 ++it)
            {
                if (*it == upperBound)
                {
                    end = it;
                    break;
                }
            }

            std::vector<int>::iterator pos =
                std::lower_bound(sortedVector.begin(), end, value);

            sortedVector.insert(pos, value);
        }

        previous = current;
    }

    if (stragler != -1)
    {
        std::vector<int>::iterator pos = std::lower_bound(sortedVector.begin(), sortedVector.end(), stragler);
        sortedVector.insert(pos, stragler);
    }
}

void PmergeMeVector::MergeSort(PairVector::iterator start, PairVector::iterator end)
{
    if (std::distance(start, end) > 1)
    {
        PairVector::iterator mid =
            start + std::distance(start, end) / 2;

        MergeSort(start, mid);
        MergeSort(mid, end);

        std::inplace_merge(start, mid, end, &CompareFunction);
    }
}

void PmergeMeVector::SortInsidePair()
{
    for (PairVector::iterator it = pairVector.begin();
         it != pairVector.end();
         ++it)
    {
        if (it->first > it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
}

void PmergeMeVector::MakePair(std::vector<int>& vec)
{
    std::vector<int>::iterator it = vec.begin();

    while (it != vec.end())
    {
        std::vector<int>::iterator tmpIt = it;
        ++tmpIt;

        if (tmpIt != vec.end())
        {
            std::pair<int, int> pair_temp(*it, *tmpIt);
            pairVector.push_back(pair_temp);

            it = tmpIt;
            ++it;
        }
        else
        {
            stragler = *it;
            ++it;
        }
    }
}


// PmergeMeList class implementation

PmergeMeList::PmergeMeList()
{
}

PmergeMeList::PmergeMeList(const PmergeMeList &other)
{
    pairList = other.pairList;
    sortedList = other.sortedList;
    stragler = other.stragler;
}

PmergeMeList& PmergeMeList::operator=(const PmergeMeList &other)
{
    if (this != &other)
    {
        pairList = other.pairList;
        sortedList = other.sortedList;
        stragler = other.stragler;
    }
    return *this;
}

PmergeMeList::~PmergeMeList()
{
}

PmergeMeList::PmergeMeList(std::vector<int>& vec): stragler(-1)
{
    gettimeofday(&start, NULL);
    
    
    MakePair(vec);
    SortInsidePair();
    MergeSort(pairList.begin(), pairList.end());
    // for (std::list<std::pair<int, int> >::iterator it = pairList.begin(); it != pairList.end(); ++it)
    // {
    //     std::cout << "pair : (" << it->first << ", " << it->second << ")" << std::endl;
    // }
    // if (stragler != -1)
    // {
    //     std::cout << "stragler : " << stragler << std::endl;
    // }
    createSortedList();
    
    jacobsthalInsertion();
    // for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
    gettimeofday(&end, NULL);
}

void PmergeMeList::createSortedList()
{
    //make the sorted list from the second of each pair and then insert the first of the first pair at the beging because it will be always the small one
    
    // for (std::list<int>::iterator it = sortedList.begin(); it != sortedList.end(); ++it)
    // {
    //     std::cout << *it << " ";
    // }
    for (PairList::iterator it = pairList.begin(); it != pairList.end(); ++it)
    {
        sortedList.push_back(it->second);
    }
    if (pairList.size() > 0)
    {
        sortedList.push_front(pairList.begin()->first);
    }
}

void PmergeMeList::jacobsthalInsertion()
{
    size_t Jacobsthal[] = {
        1, 3, 5, 11, 21, 43, 85, 171, 341, 683,
        1365, 2731, 5461, 10923, 21845, 43691,
        87381, 174763, 349525, 699051, 1398101,
        2796203, 5592405, 11184811, 22369621,
        44739243, 89478485, 178956971, 357913941,
        715827883, 1431655765
    };

    size_t pairCount = pairList.size();

    if (pairCount == 0)
        return;

    size_t previous = 1;

    for (size_t j = 1; j < sizeof(Jacobsthal) / sizeof(Jacobsthal[0]); ++j)
    {
        size_t current = Jacobsthal[j];

        if (previous >= pairCount)
            break;

        if (current > pairCount)
            current = pairCount;

        size_t i = current;

        while (i > previous)
        {
            --i;

            PairList::iterator pairIt = pairList.begin();
            std::advance(pairIt, i);

            int value = pairIt->first;
            int upperBound = pairIt->second;

            //Find the position of upperBound in sortedList, We only need to search before the matching 'second' element because:
            //first < second
            std::list<int>::iterator end = sortedList.end();

            for (std::list<int>::iterator it = sortedList.begin();
                 it != sortedList.end();
                 ++it)
            {
                if (*it == upperBound)
                {
                    end = it;
                    break;
                }
            }

            //moment of realilzation that the time complexity of std::lower_bound is O(log n)if i was working with random access container like vector
            // but since we are working with list which is a bidirectional container the time complexity of std::lower_bound is O(n),
            //but anyway the subject is about the Ford-Johnson algorithm and not about the time complexity of std::lower_bound hehehehehehehehe
            //but its good to know that std::lower_bound is O(log n) for random access containers and O(n) for bidirectional containers
            std::list<int>::iterator pos =
                std::lower_bound(sortedList.begin(), end, value);

            sortedList.insert(pos, value);
        }

        previous = current;
    }

    
    // Insert the final odd element, if the original input contained an odd number of elements.
    if (stragler != -1)
    {
        std::list<int>::iterator pos =
            std::lower_bound(sortedList.begin(), sortedList.end(), stragler);

        sortedList.insert(pos, stragler);
    }
}

void PmergeMeList::MergeSort(PairList::iterator start, PairList::iterator end)
{
    if (std::distance(start, end) > 1)
    {
        PairList::iterator mid = start;
        std::advance(mid, std::distance(start, end) / 2);
        MergeSort(start, mid);
        MergeSort(mid, end);
        std::inplace_merge(start, mid, end, &CompareFunction);
    }
}

void PmergeMeList::SortInsidePair()
{
    for (PairList::iterator it = pairList.begin(); it != pairList.end(); ++it)
    {
        if (it->first > it->second)
        {
            int temp = it->first;
            it->first = it->second;
            it->second = temp;
        }
    }
}

void PmergeMeList::MakePair(std::vector<int>& vec)
{
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
	{
        std::vector<int>::iterator tmpIt = it;
        ++tmpIt;
		if (tmpIt != vec.end())
		{
			std::pair<int, int> pair_temp(*it, *tmpIt);
			pairList.push_back(pair_temp);
			it = tmpIt;
            it++;
		}
		else
		{
			stragler = *it;
            it++;
		}
	}
}