#include <iostream>
#include <sstream>
#include <vector> 
#include <string>
#include <unordered_map>
#include <array>
#include <chrono>
#define itos(i) std::to_string(numbers[i])
/**
* Vector of integers to store the input numbers.
*/
std::vector<int> numbers;
/**
* k is the value to be tested against.
*/
int k;
/**
* results is our solution map which stores as key the equation and as value the result of the equation.
*/
std::unordered_map<std::string, long int> results;
/**
* This function checks if the inequality satisfies for tuple (a,b,c,d) and if so, adds it to the solution map along with (a,b,d,c), (b,a,c,d) and (b,a,d,c) as values for all of them will be the same due to commutative property of + and x.
*/
void checkAndInsert(int a, int b, int c, int d){
	long int val = numbers[a] + numbers[b] + numbers[c] * numbers[d];
	if (val <= k){
		std::string result = itos(a) + "+" + itos(b) + "+" + itos(c) + "*" + itos(d);
		results[result] = val;
		result = itos(b) + "+" + itos(a) + "+" + itos(c) + "*" + itos(d);
		results[result] = val;
		result = itos(a) + "+" + itos(b) + "+" + itos(d) + "*" + itos(c);
		results[result] = val;
		result = itos(b) + "+" + itos(a) + "+" + itos(d) + "*" + itos(c);
		results[result] = val;

	}
}
/**
* This function generates all the unique combinations of 4 from the given numbers and for each combination, calls checkAndInsert() for each of 6 permutations that might give different results.
*/
int main(){

	std::string str, num;
	std::cin >> str;
	std::stringstream ss(str);

	while (std::getline(ss, num, ',')){
		numbers.push_back(std::stoi(num));
	}

	k = numbers.back();
	numbers.pop_back();
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for (auto a = 0u; a < numbers.size(); ++a){
		for (auto b = a + 1; b < numbers.size(); ++b){
			for (auto c = b + 1; c < numbers.size(); ++c){
				for (auto d = c + 1; d < numbers.size(); ++d){
					checkAndInsert(a, b, c, d);
					checkAndInsert(a, c, b, d);
					checkAndInsert(a, d, b, c);
					checkAndInsert(b, c, a, d);
					checkAndInsert(b, d, a, c);
					checkAndInsert(c, d, a, b);
				}
			}
		}
	}
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	auto timeTaken = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
	std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
	std::cout << "Time taken : " << timeTaken << " us / " << time_span.count() << " s" << std::endl;
	for (auto &r : results){
		std::cout << r.first << "->" << r.second << std::endl;
	}
	std::cout << "Number of elements: " << results.size();
	return 0;
}