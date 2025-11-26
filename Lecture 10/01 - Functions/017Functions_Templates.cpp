#include<iostream>

// int max(int a, int b) {
// 	return a < b ? b : a;
// }

// double max(double a, double b) {
// 	return a < b ? b : a;
// }

// std::string max(std::string a, std::string b) {
// 	return a < b ? b : a;
// }

template <typename T>
T mx(T a, T b) {
	return a < b ? b : a;
}


int main() {

	std::cout << mx<int>(2, 3) << std::endl;
	std::cout << mx<double>(2.71, 3.14) << std::endl;
	std::cout << mx<std::string>("abc", "xyz") << std::endl;

	// std::cout << mx<>(2, 3) << std::endl;
	// std::cout << mx<>(2.71, 3.14) << std::endl;
	// std::cout << mx<std::string>("abc", "xyz") << std::endl;

	// std::cout << mx(2, 3) << std::endl;
	// std::cout << mx(2.71, 3.14) << std::endl;
	// std::cout << mx("abc", "xyz") << std::endl;


	return 0;

}