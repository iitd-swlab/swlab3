#include <iostream>
#include <sstream>
#include <vector> 
#include <string>
#include <unordered_map>
#include <array>
#include <chrono>
#define itos(i) std::to_string(numbers[i])

std::vector<int> numbers;
int k;
std::unordered_map<std::string, long int> results;

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

int main(){
	
	std::string str,num;
	std::cin >> str;
	std::stringstream ss(str);

	while (std::getline(ss, num, ',')){
		numbers.push_back(std::stoi(num));
	}

	k = numbers.back();
	numbers.pop_back();
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	for (auto a = 0u; a < numbers.size(); ++a){
		for (auto b = a+1; b < numbers.size(); ++b){
			for (auto c = b+1; c < numbers.size(); ++c){
				for (auto d = c+1; d < numbers.size(); ++d){
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
	std::cout << "Time taken : " << timeTaken << " us / " << time_span.count()<<" s" << std::endl;
	for (auto &r : results){
		std::cout << r.first << "->" << r.second << std::endl;
	}
	std::cout << "Number of elements: " << results.size();
	return 0;
}

/*
int main(){
std::string numbers,num;
std::cin >> numbers;
std::stringstream ss(numbers);
std::vector<int> values;
std::map<std::array<int,4>, int> results;
while (std::getline(ss, num, ',')){
values.push_back(std::stoi(num));
}

if (values.size() != 5){
std::cout << "\nInvalid inputs";
std::exit(EXIT_FAILURE);
}

results[{values[2], values[3], values[0], values[1]}] = values[0] * values[1] + values[2] + values[3];
results[{values[1], values[3], values[0], values[2]}] = values[0] * values[2] + values[1] + values[3];
results[{values[1], values[2], values[0], values[3]}] = values[0] * values[3] + values[1] + values[2];
results[{values[0], values[3], values[1], values[2]}] = values[0] + values[1] * values[2] + values[3];
results[{values[0], values[2], values[1], values[3]}] = values[0] + values[1] * values[3] + values[2];
results[{values[0], values[1], values[2], values[3]}] = values[0] + values[1] + values[2] * values[3];

for (auto &r : results){
if (r.second <= values[4]){
std::cout << r.second << std::endl;
std::cout << r.first[0] << "," << r.first[1] << "," << r.first[2] << "," << r.first[3] << std::endl;
std::cout << r.first[1] << "," << r.first[0] << "," << r.first[2] << "," << r.first[3] << std::endl;
std::cout << r.first[0] << "," << r.first[1] << "," << r.first[3] << "," << r.first[2] << std::endl;
std::cout << r.first[1] << "," << r.first[0] << "," << r.first[3] << "," << r.first[2] << std::endl;
}
}
fflush(stdin);
std::getchar();
return 0;
};
*/