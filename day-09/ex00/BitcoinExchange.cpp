#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

int BitcoinExchange::validateDate(const std::string& date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return 0;

	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (isdigit(date[i]) == 0)
			return 0;
	}

	if (date[5] == '0' && date[6] == '0') 
		return 0;
	if ((date[5] == '1' && date[6] > '2') || date[5] > '1')
		return 0;


	if (date[8] == '0' && date[9] == '0')
		return 0;
	if ((date[8] == '3' && date[9] > '1') || date[8] > '3')
		return 0;

    return 1;
}

int BitcoinExchange::ValidatePrice(const std::string& price, double *value)
{
    char *end;
    double result = strtod(price.c_str(), &end);

    if (result < 0 || result > FLT_MAX || end[0] != '\0')
    {
        return 0;
    }
    *value = result;
    return 1;
}

void printExchangeRates(const std::map<std::string, double>& exchangeRates) {
    std::map<std::string, double>::const_iterator it = exchangeRates.begin();
    for (; it != exchangeRates.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(const std::string& database, const std::string& InputFile) {
    inputFile = InputFile; 
    std::ifstream file(database.c_str());
    if (!file.is_open()) {
        throw CouldntOpenFile(database);
    }
    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        throw invalidStartingLine("date,exchange_rate");
    }

    int lineNumber = 1;
    while (std::getline(file, line)) {
        std::stringstream s(line);
        std::string date;
        std::string rate;

        std::getline(s, date, ',');
        if (!validateDate(date))
            throw invalidDate(date, lineNumber);
        s >> rate;
        double valide = 0;
        if (!ValidatePrice(rate, &valide))
            throw invalidPrice(rate, lineNumber);
        lineNumber++;
        exchangeRates.insert(std::make_pair(date, valide));
    }
    // printExchangeRates(exchangeRates);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    exchangeRates = other.exchangeRates;
    inputFile = other.inputFile;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
        inputFile = other.inputFile;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {
}

std::string to_string(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}


double BitcoinExchange::validateValue(std::string const &valueStr)
{
    if (valueStr.empty())
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return -1;
    }

    if (valueStr[0] == '-')
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return -1;
    }

    int dot = 0;

    for (size_t i = 0; i < valueStr.length(); ++i)
    {
        if (valueStr[i] == '.')
        {
            dot++;
            if (dot > 1)
            {
                std::cerr << "Error: bad input => " << valueStr << std::endl;
                return -1;
            }
            continue;
        }

        if (!std::isdigit(static_cast<unsigned char>(valueStr[i])))
        {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
            return -1;
        }
    }

    double val = std::strtod(valueStr.c_str(), NULL);

    if (val > 1000.0)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return -1;
    }

    return val;
}

void BitcoinExchange::printResult(const std::string& date, double priceValue)
{
    std::map<std::string, double>::iterator it = exchangeRates.find(date);
	if (it != exchangeRates.end())
		std::cout << date << " => " << priceValue << " = " << priceValue * it->second << std::endl;
	else
	{
		it = exchangeRates.lower_bound(date);
		if (it == exchangeRates.begin())
			std::cout << date << " => " << priceValue << " = " << priceValue * it->second << std::endl;
		else
		{
            if (exchangeRates.empty())
            {
                std::cerr << "Error: exchange rates data is empty." << std::endl;
                return;
            }
            else
            {
                it--;
                std::cout << date << " => " << priceValue << " = " << priceValue * it->second << std::endl;
            }
		}
	}
}

void BitcoinExchange::execute()
{
    std::ifstream file(inputFile.c_str());
    if (!file)
    {
        throw CouldntOpenFile(inputFile);
    }

    std::string line;
    std::getline(file, line);
    if (line != "date | value")
    {
        throw invalidStartingLine("date | value");
    }

    while (std::getline(file, line))
    {
    	std::string date;
		std::string valueStr;
		double priceValue;
		std::istringstream s(line);
		std::getline(s, date, '|');
		s >> valueStr;

		if (!date.empty())
			date = date.erase(date.length() -1);
		if (!validateDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		priceValue = validateValue(valueStr);
		if (priceValue != -1)
			printResult(date, priceValue);
    }
}

BitcoinExchange::CouldntOpenFile::CouldntOpenFile(const std::string& filename)
{
    _message = "Could not open file: " + filename;
}

BitcoinExchange::CouldntOpenFile::~CouldntOpenFile() throw() {}

const char* BitcoinExchange::CouldntOpenFile::what() const throw()
{
    return _message.c_str();
}



BitcoinExchange::invalidStartingLine::invalidStartingLine(const std::string& expectition)
{
    _message = "invalid starting line, expect: " + expectition;
}

BitcoinExchange::invalidStartingLine::~invalidStartingLine() throw() {}

const char* BitcoinExchange::invalidStartingLine::what() const throw()
{
    return _message.c_str();
}



BitcoinExchange::invalidDate::invalidDate(const std::string& date, int lineNumber)
{
    _message = "invalid date: " + date + " at line: " + to_string(lineNumber);
}

BitcoinExchange::invalidDate::~invalidDate() throw() {}

const char* BitcoinExchange::invalidDate::what() const throw()
{
    return _message.c_str();
}


BitcoinExchange::invalidPrice::invalidPrice(const std::string& price, int lineNumber)
{
    _message = "invalid price: " + price + " at line: " + to_string(lineNumber);
}

BitcoinExchange::invalidPrice::~invalidPrice() throw() {}

const char* BitcoinExchange::invalidPrice::what() const throw()
{
    return _message.c_str();
}