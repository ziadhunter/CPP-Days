#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <exception>
#include <cfloat>
#include <cstdlib>

std::string to_string(int number);

class BitcoinExchange {
    private:
        std::map<std::string, double> exchangeRates;
        std::string inputFile;
        BitcoinExchange();
        int validateDate(const std::string& date);
        int ValidatePrice(const std::string& price, double *value);
        double validateValue(std::string const &valueStr);
        void printResult(const std::string& date, double priceValue);

        public:
        BitcoinExchange(const std::string& database, const std::string& InputFile);
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
        
        void execute();

        class CouldntOpenFile : public std::exception
        {
            private:
            std::string _message;
            
            public:
            CouldntOpenFile(const std::string& filename);
            ~CouldntOpenFile() throw();
            const char* what() const throw();
        };
        
        class invalidStartingLine : public std::exception
        {
            private:
            std::string _message;
            
            public:
            invalidStartingLine(const std::string& expectition);
            ~invalidStartingLine() throw();
            const char* what() const throw();
        };
        
        class invalidDate : public std::exception
        {
            private:
            std::string _message;
            
            public:
            invalidDate(const std::string& date, int lineNumber);
            ~invalidDate() throw();
            const char* what() const throw();
        };
        
        class invalidPrice : public std::exception
        {
            private:
            std::string _message;
            
            public:
            invalidPrice(const std::string& price, int lineNumber);
            ~invalidPrice() throw() ;
            const char* what() const throw();
        };
    };

#endif