/*	Since there are common requirements for many Project Euler problems I
	decided to start this common tools library	*/
/*	Todo: Fix duplicate entries of sumOfDivisors, pollardRho equations etc...	*/
// V3.8

#ifndef __PROJECTEULERTOOLS__
#define __PROJECTEULERTOOLS__

#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <time.h>
#include <assert.h>
#include <map>

// Math Functions
/// bool isPerfectSquare(T n)
/// T power(T base, T exponent)
/// T toBase(T input, T base)
/// vector<pair<T, T> > primeFactors(T input)
/// vector<pair<T, T> > primeFactors(T input, vector<U> &primes)
/// T binomialCoefficient(T n, T k)
/// T numberOfDivisors(T input, vector<U> &primes)
/// T sumOfDivisors(T input, vector<U> &primes)
/// T sumOfProperDivisors(T input, vector<U> &primes)
/// T fundamentalSolutionOfPellsEquationForSqrt(int D)
/// void generateNextSuperCatalan(vector<T> &superCatalans)
/// T PollardRho(T n, T c)
/// T PollardRho(T n, T c, vector<U> &primes)
//// [Miller Rabin Primality Test]
/// T millerRabinPowerTest(T a, T n, T mod)
/// bool primeWitness(T n, T s, T d, T a)
/// bool isPrime(T n)
/// vector<T> primesInRange_MillerRabin(T min, T max)
/// vector<T> primesUpTo_MillerRabin(T max)
//// [/Miller Rabin Primality Test]
/// vector<T> primesUpTo(T max)
/// T sum(vector<T> &data)
/// size_t digitSum(T input)
/// T digitCount(T input)
/// T digitCount(T base, T exponent)
/// bool isPandigital(T number, string pandigitalString)
/// T factorial(T n)
/// T swapDigit(T input, int index, T value)
/// vector<T> firstTriangleNumbers(T max)
/// T pentagonalNumber(T input)
/// vector<T> firstPentagonalNumbers(T max)
/// bool isPentagonal(T input)
/// vector<T> firstHexagonalNumbers(T max)
/// T GCD(T x, T y)
/// T GCD(T x, T y, T z)
/// bool isCoprime(T x, T y)
/// bool isEven(T input)
/// bool isOdd(T input)
// Vector Functions
/// void log(vector<T> &data)
/// void logPair(pair<T, U> pair)
/// void logPairs(vector<pair<T, U> > pairs)
/// bool existsIn(T item, vector<U> &values)
/// unsigned existCount(T item, vector<T> &values)
/// size_t commonCount(vector<T> &left, vector<T> &right)
/// void removeFromVector(T input, vector<T> &vect)
/// void removeRepeats(vector<T> &input)
//// [Set Theory]
/// bool isSubset(vector<T> &left, vector<T> &right)
/// bool areDistinct(vector<T> &left, vector<T> &right)
//// [/Set Theory]
// File Functions
/// vector<string> fileLines(string fileName)
// String Functions
/// vector<string> split(const string &s, char delim)
/// vector<string> &split(const string &s, char delim, vector<string> &elems)
/// void stripPrefixZeros(string &input)
/// void removeCharacter(string &input, char character)
/// string toString(T input)
/// T fromString(string input)
/// vector<T> fromStrings(vector<string> inputs)
/// void permute(string permutation, int startIndex, vector<string> &permutations)
/// vector<string> permutationsOf(string input)
/// bool isPermutationOf(T a, T b)
/// vector<string> circularValues(string input)
// Misc Functions
/// int diceRoll(int diceSize)
/// class Timer
/// void swap(T &x, T &y)
/// class ContinuedFraction
/// ContinuedFraction *continuedFractionOfSquareRoot(int n)

namespace PET {

template<class T>
bool isPerfectSquare(T n) {
	if (n < 0)return false;
	T root(round(sqrt(n)));
	return n == root * root;
}

// Good up to larger values, then mean gets skewed
int diceRoll(int diceSize) {
	// I'm not sure how much slower this makes the code
	static bool seeded = false;
	if(!seeded) {srand(time(NULL));seeded=true;}

	int divisor = RAND_MAX/(diceSize), retVal;
	do {retVal = rand() / divisor;} while (retVal > diceSize);
	return retVal+1;
}

// Found that this is significantly faster than: return log10(input)+1;
template<class T>
T digitCount(T input) {
	T count = T();
	while(input != 0) {
		input /= 10;
		count++;
	}
	return count;
}

template<class T>
T digitCount(T base, T exponent) {
	T digits = ceil(exponent*log10(base));
	return digits;
}

// Calculates a^n%mod
template<class T>
T millerRabinPowerTest(T a, T n, T mod) {
	T power = a, result = 1;

	while(n) {
		if(n & 1)result = (result * power) % mod;
		power = (power * power) % mod;
		n >>= 1;

		T value = result*power;
		T count = digitCount(value);
	}
	return result;
}

// n−1 = 2^s * d with d odd by factoring powers of 2 from n−1
template<class T>
bool primeWitness(T n, T s, T d, T a) {
	T x = millerRabinPowerTest(a, d, n), y;

	while(s) {
		y = (x * x) % n;
		if(y == 1 && x != 1 && x != n-1)return false;
		x = y;
		s--;
	}
	if(y != 1)return false;
	return true;
}

// Supposed to be Deterministic up to 341,550,071,728,321
/*	Miller Rabin Primality Test Citation:
		http://www.wikihow.com/Check-if-a-Number-Is-Prime
		http://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
		http://stackoverflow.com/questions/2586596/fastest-algorithm-for-primality-test
		http://rosettacode.org/wiki/Miller-Rabin_primality_test#Deterministic_up_to_341.2C550.2C071.2C728.2C321		*/
// Because of how the power test algorithm works the precision of this test is ~sqrt(input max precision)
// This means even if you use uint64_t your precision will only be around uint32_t
// Memoization will impact performance if primes aren't checked more than once
template<class T>
bool isPrime(T n) {
	if(((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))return false;
	if(n <= 3)return true;

#if PRIME_MEMOIZATION
	static std::map<T, bool> memo;
	if(memo.count(n) > 0)return memo[n];
#endif

	T d = n>>1, s = 1;
	while(!(d & 1)) {
		d >>= 1;
		s++;
	}

	bool retVal;
	if(n < 1373653u)retVal = primeWitness<T>(n, s, d, 2) && primeWitness<T>(n, s, d, 3);
	else if(n < 9080191u)retVal = primeWitness<T>(n, s, d, 31) && primeWitness<T>(n, s, d, 73);
	else if(n < 4759123141u)retVal = primeWitness<T>(n, s, d, 2) && primeWitness<T>(n, s, d, 7) && primeWitness<T>(n, s, d, 61);
	else if(n < 1122004669633u)retVal = primeWitness<T>(n, s, d, 2) && primeWitness<T>(n, s, d, 13) && primeWitness<T>(n, s, d, 23) && primeWitness<T>(n, s, d, 1662803);
	else if(n < 2152302898747u)retVal = primeWitness<T>(n, s, d, 2) && primeWitness<T>(n, s, d, 3) && primeWitness<T>(n, s, d, 5) && primeWitness<T>(n, s, d, 7) && primeWitness<T>(n, s, d, 11);
	else if(n < 3474749660383u)retVal = primeWitness<T>(n, s, d, 2) && primeWitness<T>(n, s, d, 3) && primeWitness<T>(n, s, d, 5) && primeWitness<T>(n, s, d, 7) && primeWitness<T>(n, s, d, 11) && primeWitness<T>(n, s, d, 13);
	else retVal = primeWitness<T>(n, s, d, 2) && primeWitness<T>(n, s, d, 3) && primeWitness<T>(n, s, d, 5) && primeWitness<T>(n, s, d, 7) && primeWitness<T>(n, s, d, 11) && primeWitness<T>(n, s, d, 13) && primeWitness<T>(n, s, d, 17);

#if PRIME_MEMOIZATION
	memo[n] = retVal;
#endif
	return retVal;
}

template<class T>
T toBase(T input, T base) {
	T count = input/base;
	T mod = input%base;
	if(count > 0)mod += 10*toBase(count, base);
	return mod;
}

// http://oeis.org/A001003
// http://mathworld.wolfram.com/SuperCatalanNumber.html
/*	I found this tying to find how many ways you can order
	parenthesis in an equation with n terms. I don't know
	if the sequence starts with two 1s though...	*/
template<class T>
void generateNextSuperCatalan(std::vector<T> &superCatalans) {
	if(superCatalans.size() < 2) {
		superCatalans.empty();
		superCatalans.push_back(1);
		superCatalans.push_back(1);
	}
	T n = superCatalans.size()+1;
	T n1 = superCatalans[n-1-1];
	T n2 = superCatalans[n-2-1];
	superCatalans.push_back((3*(2*n-3)*n1 - (n-3)*n2)/n);
}

template<class T>
T factorial(T n) {
	if(n == 0 || n == 1)return 1;
	else return factorial<T>(n - 1) * n;
}

// http://blog.plover.com/math/choose.html
template<class T>
T binomialCoefficient(T n, T k) {
	T r = 1;
	if(k > n)return 0;
	for(T d=1;d<=k;d++) {
		r *= n--;
		r /= d;
	}
	return r;
}

// I would really like to test this against Lehmer's GCD algorithm
// Also I would like to add memoization to this and test that out too
template<class T>
T GCD(T x, T y) {
	while(x && y) {
		if(x >= y)x %= y;
		else y %= x;
	}
	return x + y;
}

template<class T>
T GCD(T x, T y, T z) {
	return GCD(x, GCD(y, z));
}

// There might be a problem with searching for type T in vector of type U
// To test floats/doubles you must either have exact value searches, or fudge it with an epsilon
// Epsilon testing should be implemented in another function using std::numeric_limits<double>::epsilon();
template<class T, class U>
bool existsIn(T item, std::vector<U> &values) {
	typename std::vector<T>::iterator location = std::find(values.begin(), values.end(), item);
	if(location != values.end())return true;
	return false;
}

template<class T>
unsigned existCount(T item, std::vector<T> &values) {
	unsigned count = 0;
	for(unsigned d=0;d<values.size();d++) {
		if(values[d] == item)count++;
	}
	return count;
}

// I don't think this is very fast
template<class T>
size_t commonCount(std::vector<T> &left, std::vector<T> &right) {
	size_t count = 0;
	for(size_t d=0;d<left.size();d++) {
		if(existsIn(left[d], right))count++;
	}
	return count;
}

// Can be sped up I think
template<class T>
bool areDistinct(std::vector<T> &left, std::vector<T> &right) {
	if(commonCount(left, right) == 0)return true;
	return false;
}

// Is left subset of right
template<class T>
bool isSubset(std::vector<T> &left, std::vector<T> &right) {
	for(size_t d=0;d<left.size();d++) {
		if(!existsIn(left[d], right))return false;
	}
	return true;
}

template<class T>
void log(std::vector<T> &data) {
	for(size_t d=0;d<data.size();d++)
		std::cout << data[d] << std::endl;
}

template<class T, class U>
void logPair(std::pair<T, U> pair) {
	std::cout << pair.first << ":" << pair.second << std::endl;
}

template<class T, class U>
void logPairs(std::vector<std::pair<T, U> > pairs) {
	for(int d=0;d<pairs.size();d++)logPair(pairs[d]);
}

template<class T, class U>
T PollardRho(T n, T c, std::vector<U> &primes) {
	if(existsIn(n, primes))return n;
	if(n == 4)return 2;	// For some reason 4 crashes this algorithm...
	T x = 2, y = 2, d = 1;

	while(d == 1) {
		x = (x * x + c) % n;
		y = (y * y + c) % n;
		y = (y * y + c) % n;
		d = GCD((T)abs(x - y), n);
	}

	if(d == n)return PollardRho(n, (T)(c + 1), primes);
	return d;
}

// duplicate since I don't know how to handle data overflow checking...
template<class T>
T PollardRho(T n, T c) {
	if(isPrime(n))return n;
	if(n == 4)return 2;	// For some reason 4 crashes this algorithm...
	T x = 2, y = 2, d = 1;

	while(d == 1) {
		x = (x * x + c) % n;
		y = (y * y + c) % n;
		y = (y * y + c) % n;
		d = GCD((T)abs(x - y), n);
	}

	if(d == n)return PollardRho(n, (T)(c + 1));
	return d;
}

// I don't like how I don't know exactly how this works
template<class T>
void removeRepeats(std::vector<T> &input) {
	std::sort(input.begin(), input.end());
	typename std::vector<T>::iterator it = std::unique(input.begin(), input.end());
	input.resize(std::distance(input.begin(), it));
}

template<class T>
void removeFromVector(T input, std::vector<T> &vect) {
	typename std::vector<T>::iterator location = std::find(vect.begin(), vect.end(), input);
	while(location != vect.end()) {
		vect.erase(location);
		location = std::find(vect.begin(), vect.end(), input);
	}
}

// Will only work on integer exponents...
// Found at http://www.programminglogic.com/fast-exponentiation-algorithms/
template<class T>
T power(T base, T exponent) {
	T result = 1;
	while(exponent) {
		if(exponent & 1)result *= base;
		exponent >>= 1;
		base *= base;
	}
	return result;
}

template<class T, class U>
std::vector<std::pair<T, T> > primeFactors(T input, std::vector<U> &primes) {
	static std::map<T, std::vector<std::pair<T, T> > > memo;
	if(memo.count(input) > 0)return memo[input];
	// I actually don't know how large the prime database needs to be...
	// I think it's input/2 since the largest possible divisor could be
	// half the input right? I just don't know...
	if(primes.back() < input/2)std::cout << "It's possible that app will crash due to insufficient primes" << std::endl;
	if(input > primes.back())std::cout << "You've tried factoring without sufficient primes.\n\tInput: " << input << ", maxPrime: " << primes.back() << std::endl;
	std::map<T, T> currentDivisors;
	T value = input;
	while(value != 1) {
		T divisor = PollardRho<T>(value, 1, primes);
		if(existsIn(divisor, primes))
			currentDivisors[divisor]++;
		else {
			std::vector<std::pair<T, T> >divisors = primeFactors(divisor, primes);
			for(int d=0;d<divisors.size();d++)
				currentDivisors[divisors[d].first] += divisors[d].second;
		}
		value /= divisor;
	}
	std::vector<std::pair<T, T> > retVal;
	typedef typename std::map<T, T>::iterator it_type;
	for(it_type iterator = currentDivisors.begin();iterator != currentDivisors.end();iterator++)
		retVal.push_back(std::pair<T, T>(iterator->first, iterator->second));
	memo[input] = retVal;
	return retVal;
}

// duplicate since I don't know how to handle data overflow checking...
template<class T>
std::vector<std::pair<T, T> > primeFactors(T input) {
	static std::map<T, std::vector<std::pair<T, T> > > memo;
	if(memo.count(input) > 0)return memo[input];
	std::map<T, T> currentDivisors;
	T value = input;
	while(value != 1) {
		T divisor = PollardRho<T>(value, 1);
		if(isPrime(divisor))
			currentDivisors[divisor]++;
		else {
			std::vector<std::pair<T, T> >divisors = primeFactors(divisor);
			for(int d=0;d<divisors.size();d++)
				currentDivisors[divisors[d].first] += divisors[d].second;
		}
		value /= divisor;
	}
	std::vector<std::pair<T, T> > retVal;
	typedef typename std::map<T, T>::iterator it_type;
	for(it_type iterator = currentDivisors.begin();iterator != currentDivisors.end();iterator++)
		retVal.push_back(std::pair<T, T>(iterator->first, iterator->second));
	memo[input] = retVal;
	return retVal;
}

// http://www.wikihow.com/Determine-the-Number-of-Divisors-of-an-Integer
template<class T, class U>
T numberOfDivisors(T input, std::vector<U> &primes) {
	std::vector<std::pair<T, T> > factors = primeFactors(input, primes);
	T retVal = 1;
	for(int d=0;d<factors.size();d++)
		retVal *= factors[d].second+1;
	return retVal;
}

// http://sage.colorado.edu/home/pub/40/
template<class T, class U>
T sumOfDivisors(T input, std::vector<U> &primes) {
	static std::map<T, T> memo;
	if(memo.count(input) > 0)return memo[input];

	std::vector<std::pair<T, T> > factors = primeFactors(input, primes);
	T retVal = 1;
	for(int d=0;d<factors.size();d++)
		retVal *= (power<T>(factors[d].first, factors[d].second+1)-1) / (factors[d].first-1);
	memo[input] = retVal;
	return retVal;
}

template<class T, class U>
T sumOfProperDivisors(T input, std::vector<U> &primes) {
	return sumOfDivisors(input, primes) - input;
}

template<class T>
bool isCoprime(T x, T y) {
	if(GCD(x, y) == 1)return true;
	return false;	
}

template<class T>bool isEven(T input) {if(input%2 == 0)return true;return false;}
template<class T>bool isOdd(T input) {return !isEven(input);}

class Timer {
	clock_t begin, end;
public:
	Timer() {}
	void start() {begin = clock();}
	void stop() {end = clock();}
	void log(std::string message) {std::cout << message << delta() << " seconds" << std::endl;}
	void log() {log("Took: ");}
	void stopLog() {stop();log();}
	void stopLog(std::string message) {stop();log(message);}
	double delta() {return (end-begin) / (float)CLOCKS_PER_SEC;}
};

template<class T>void swap(T &x, T &y) {T tmp = x;x = y;y = tmp;}

void permute(std::string permutation, int startIndex, std::vector<std::string> &permutations) {
	if(startIndex == permutation.size()-1)permutations.push_back(permutation);
	else {
		for(int d=startIndex;d<permutation.size();d++) {
			swap(permutation[startIndex], permutation[d]);
			permute(permutation, startIndex+1, permutations);
			swap(permutation[d], permutation[startIndex]);
		}
	}
}

std::vector<std::string> permutationsOf(std::string input) {
	std::vector<std::string>retVal;
	permute(input, 0, retVal);
	return retVal;
}

template<class T>
T sum(std::vector<T> &data) {
	T retVal = T();
	for(int d=0;d<data.size();d++)retVal += data[d];
	return retVal;
}

// Miller-Rabin requires a large multiplication which I think will max at the square of the requested value to check
// This means your data type must be capable of supporting the square of the value to search for
// Thus you have to use large data types! Not a problem for arbitrary types but not good for int or size_t etc...
// If you use this method use a data type of uint64_t or something
template<class T>
std::vector<T> primesInRange_MillerRabin(T min, T max) {
	std::vector<T> retVal;
	for(T d=min;d<=max;d++)if(isPrime(d))retVal.push_back(d);
	return retVal;
}

template<class T>
std::vector<T> primesUpTo_MillerRabin(T max) {
	return primesInRange_MillerRabin<T>(1, max);
}

// Included along with Miller Rabin because Miller Rabin can only calculate up to sqrt(dataMaxSize)
// and this can calculate up to dataMaxSize. Much faster at calculating concurrent primes as well
template<class T>
std::vector<T> primesUpTo(T max) {
	std::vector<T>exceptedPrimes;
	std::vector<T>testPrimes;
	std::vector<T>skipSet;
	T potentialPrime = 2;
	exceptedPrimes.push_back(potentialPrime);
	potentialPrime++;
	testPrimes.push_back(potentialPrime);
	skipSet.push_back(2);
	while(potentialPrime <= max) {
		bool isPrime = true;
		potentialPrime += skipSet[0];
		T sqrtPotentialPrime = sqrt(potentialPrime);
		for(int d=0;d<testPrimes.size();d++) {
			if(testPrimes[d] > sqrtPotentialPrime)break;
			if(potentialPrime%testPrimes[d] == 0) {isPrime = false;break;}
		}
		if(isPrime && potentialPrime <= max)testPrimes.push_back(potentialPrime);
	}
	for(int d=0;d<testPrimes.size();d++)exceptedPrimes.push_back(testPrimes[d]);
	return exceptedPrimes;
}

template<class T>
std::vector<T> firstTriangleNumbers(T max) {
	std::vector<T>retVal;
	for(T n=T()+1;n<=max;n++)retVal.push_back(n*(n+1)/2);
	return retVal;
}

template<class T>
T pentagonalNumber(T input) {
	return input*(3*input-1)/2;		// can >>1 the /2?
}

template<class T>
std::vector<T> firstPentagonalNumbers(T max) {
	std::vector<T>retVal;
	for(T n=T()+1;n<=max;n++)retVal.push_back(pentagonalNumber(n));
	return retVal;
}

// I don't like casting to double
// Resources: http://www.divye.in/2012/07/how-do-you-determine-if-number-n-is.html
template<class T>
bool isPentagonal(T input) {
	double x = (double)input;
	double test = (sqrt(24*x+1)+1)/6;
	if(test == (int)test)return true;
	return false;
}

template<class T>
std::vector<T> firstHexagonalNumbers(T max) {
	std::vector<T>retVal;
	for(T n=T()+1;n<=max;n++)retVal.push_back(n*(2*n-1));		// can <<1 the *2?
	return retVal;
}

// boost's lexical_cast seems to be just as fast as this
// Have to do more testing because it seems like #inclue <string>'s .to_string() is MUCH faster than this
template<class T>
std::string toString(T input) {
	std::stringstream ss;
	ss << input;
	return ss.str();
}

template<class T>
T fromString(std::string input) {
	T retVal = T();
	std::istringstream(input) >> retVal;
	return retVal;
}

template<class T>
std::vector<T> fromStrings(std::vector<std::string> inputs) {
	std::vector<T>retVal;
	for(size_t d=0;d<inputs.size();d++) {
		T value = T();
		std::istringstream(inputs[d]) >> value;
		retVal.push_back(value);
	}
	return retVal;
}

template<class T>
bool isPermutationOf(T a, T b) {
	std::string aString = toString(a);
	std::string bString = toString(b);
	sort(aString.begin(), aString.end());
	sort(bString.begin(), bString.end());
	if(aString == bString)return true;
	return false;
}

// Can handle strings, cpp_int, and regular numbers
template<class T>
size_t digitSum(T input) {
	std::string inputString = toString(input);
	size_t retVal = 0;
	for(size_t d=0;d<inputString.size();d++)
		retVal += inputString[d] - '0';
	return retVal;
}

std::vector<std::string> circularValues(std::string input) {
	std::vector<std::string>retVal;
	retVal.push_back(input);
	for(int d=0;d<input.size()-1;d++) {
		std::string value = retVal.back();
		char temp = value[0];
		for(int index=0;index<value.size()-1;index++)
			value[index] = value[index+1];
		value[value.size()-1] = temp;
		retVal.push_back(value);
	}
	return retVal;
}

std::vector<std::string> fileLines(std::string fileName) {
	std::ifstream fileIn;
	fileIn.open(fileName.c_str());

	std::vector<std::string>lines;
	if(fileIn.is_open()) {
		while(fileIn.good()) {
			std::string currentLine;
			getline(fileIn, currentLine);
			if(currentLine != "")
				lines.push_back(currentLine);
		}
		fileIn.close();
		return lines;
	}
	else std::cout << "Unable to open input file" << std::endl;
}

void stripPrefixZeros(std::string &input) {while(input[0] == '0')input.erase(input.begin());}

void removeCharacter(std::string &input, char character) {
	std::string::iterator end_pos = std::remove(input.begin(), input.end(), character);
	input.erase(end_pos, input.end());
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))elems.push_back(item);
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

// I don't really like how this is done
template<class T>
T swapDigit(T input, int index, T value) {
	std::string inputString = toString(input);
	assert(index < inputString.size());
	inputString[inputString.size()-1-index] = toString(value)[0];
	return fromString<T>(inputString);
}

// To improve this I'd like to add a pandigital map that is built during execution
// That way I won't have to pass pandigitalString to this function
// as the pandigital value will only have to be calculated once
template<class T>
bool isPandigital(T number, std::string pandigitalString) {
	std::string test = toString(number);
	sort(test.begin(), test.end());
	if(test == pandigitalString)return true;
	return false;
}

class ContinuedFraction {
public:
	ContinuedFraction() {}
	void log() {
		if(digits.size() == 0 && period.size() == 0)std::cout << first << std::endl;
		else {
			std::cout << "[" << first << ";";
			for(int d=0;d<digits.size();d++) {
				std::cout << digits[d];
				if(d+1 != digits.size() || period.size() > 0)std::cout << ",";
			}
			if(period.size() > 0)std::cout << "(";
			for(int d=0;d<period.size();d++) {
				std::cout << period[d];
				if(d+1 != period.size())std::cout << ",";
			}
			if(period.size() > 0)std::cout << ")";
			std::cout << "]" << std::endl;
		}
	}
	int first;
	std::vector<int> digits, period;
};

// http://www.maths.surrey.ac.uk/hosted-sites/R.Knott/Fibonacci/cfINTRO.html
ContinuedFraction *continuedFractionOfSquareRoot(int n) {
	std::vector<int> periodValues;
	int numerator = 0;
	int denominator = 1;
	for(;;) {
		if(denominator == 0) {	// Will always catch after first iteration
			assert(periodValues.size() > 0);
			periodValues[0] = sqrt(n);
			break;
		}

		// Step 1
		int m = (sqrt(n) + numerator) / denominator;
		periodValues.push_back(m);

		// Step 2 requires algebra
		int xNumerator = denominator;
		int xDenominator = numerator - (m * denominator);

		// Step 3, multiply numerator and denominator by sqrt(n)+m, requires algebra
		numerator = -xDenominator;
		denominator = (n - xDenominator*xDenominator) / xNumerator;
		if(denominator == 1) {
			int m = (sqrt(n) + numerator) / denominator;
			periodValues.push_back(m);
			break;
		}
	}
	ContinuedFraction *retVal = new ContinuedFraction();
	retVal->first = periodValues[0];
	for(int d=1;d<periodValues.size();d++)
		retVal->period.push_back(periodValues[d]);
	return retVal;
}

// Pell's Equation:
//	http://en.wikipedia.org/wiki/Pell%27s_equation
// Equations for convergent calculations:
//	http://www.math.uiuc.edu/~hildebr/453.spring11/nt-notes6.pdf
// Convergent equation examples:
//	http://www.mathisfunforum.com/viewtopic.php?id=12436
template<class T>
std::vector<T> fundamentalSolutionOfPellsEquationForSqrt(int D) {
	// Pell's Equation: x^2 - Dy^2 = 1
	// a = period values of continued fraction of sqrt(D)
	// p_i = a_i*p_i-1 + p_i-2
	// q_i = a_i*q_i-1 + q_i-2
	// p_0 = 1, p_1 = a_0
	// q_0 = 0, q_1 = 1
	// After calculating next fraction it will check if those values satisfy Pell's Equation
	ContinuedFraction *a = continuedFractionOfSquareRoot(D);
	std::vector<T> p, q;
	p.push_back(1);
	p.push_back(a->first);
	q.push_back(0);
	q.push_back(1);
	int d = 0;
	while(true) {
		int i = d%a->period.size();
		int ai = a->period[i];
		int lastIndex = p.size()-1;
		T pi = ai*p[lastIndex] + p[lastIndex-1];
		T qi = ai*q[lastIndex] + q[lastIndex-1];
		p.push_back(pi);
		q.push_back(qi);

		if(d > 0) {
			T value = p[d]*p[d] - D*q[d]*q[d];
			if(value == 1) {
				std::vector<T> retVal;
				retVal.push_back(p[d]);
				retVal.push_back(q[d]);
				return retVal;
			}
		}
		d++;
	}
}

} // End of PET namespace

#endif
