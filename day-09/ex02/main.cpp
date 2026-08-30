#include "Utils.hpp"
#include "iostream"
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "not enough arguement." << std::endl;
        return 0;
    }
    std::vector<int> args;
    try
    {
         args = validateArguement(argv, argc);
    }
    catch (const NotValid &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Before: " << std::endl << std::endl;
    for (std::vector<int>::iterator it = args.begin(); it != args.end();++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl << std::endl;
    
    
    {
        
        PmergeMeVector pmergeMeVector(args);
        
        long seconds = pmergeMeVector.end.tv_sec - pmergeMeVector.start.tv_sec;
        long microseconds = pmergeMeVector.end.tv_usec - pmergeMeVector.start.tv_usec;
        long total =seconds * 1000000 + microseconds;
        
        int numbersCount = pmergeMeVector.sortedVector.size();
        std::cout << "after: " << std::endl << std::endl;
        for (std::vector<int>::iterator it = pmergeMeVector.sortedVector.begin(); it != pmergeMeVector.sortedVector.end();++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl << std::endl;
        std::cout << "using std::vector container" << std::endl;
        std::cout << "Time to process a range of " << numbersCount << " elements with std::vector : " << total << " us" << std::endl;
    }
    
    {
        std::cout << "using std::list container" << std::endl;
        PmergeMeList pmergeMeList(args);
        long seconds = pmergeMeList.end.tv_sec - pmergeMeList.start.tv_sec;
        long microseconds = pmergeMeList.end.tv_usec - pmergeMeList.start.tv_usec;
        long total = seconds * 1000000 + microseconds;
        
        int numbersCount = pmergeMeList.sortedList.size();
        std::cout << "Time to process a range of " << numbersCount << " elements with std::list : " << total << " us" << std::endl;
    }

}