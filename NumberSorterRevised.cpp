#include <iostream>
#include <vector>
#include <sstream>
#include <string>


// function goes through the vector contents, comparing each number starting from the first element to the 
// next element in the vector. if the current element is bigger than the next element, swap function is called
// on the two elements and the current point is reset to the first element in the vector.  function exits if the
// size of the vector is only one element or if the loop reaches the final element in the vector.
void sort_numbers (std::vector <double>& vector1)
{
	if (vector1.size() == 0)
	{
		return;
	}

	int min_endpoint = 0;
	int max_endpoint = vector1.size()-1;
	int current_point = 0;
	while (current_point != max_endpoint)
	{
		if (vector1[current_point] > vector1[current_point + 1])
		{
			std::swap(vector1[current_point], vector1[current_point + 1]);
			current_point = 0;
		}
		else
		{
			++current_point;
		}
	}

}

// takes user input with the getline function and puts each number into a string stream object.
// as long as the string stream is processing valid input it adds the input to a vector using
// the push back method.
void process_user_input(std::vector <double> &vector1)
{
	std::string input;
	double number;
	getline(std::cin, input);
	std::stringstream ss(input);
	while (ss >> number)
	{
		vector1.push_back(number);
	}
}


// prints contents of vector to console using for loop.
void print_vector(std::vector <double>& vector1)
{
	for (int i = 0; i < vector1.size(); ++i)
	{
		std::cout << vector1[i] << " ";
	}
}


int main()
{
	std::vector <double> numbers;
	std::cout << "Enter a set of numbers seperated by spaces: \n";
	process_user_input(numbers);
	sort_numbers(numbers);
	print_vector(numbers);
	


}