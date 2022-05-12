
#include <iostream>
#include <vector>
#include <string>

    using namespace std;


//This function is called by number_sorter function if it has more than one number in the vector already.
//It checks to see if the value being checked is lower than the first number in the vector.
//If true, it inserts the number, if false it compares to the next number in the vector.
//If the number is larger than any other number in the vector it will trigger the pushback statement
//after the for loop, adding it to the end of the vector.

void compare_numbers(double number, vector <double>&vector1)
{
    for (int i = 0; i < vector1.size(); ++i)
    {

        if (number < vector1[i])
        {
            vector1.insert(vector1.begin() + i, number);
            return;
        }

        else
        {
            continue;
        }
    }

    vector1.push_back(number);

}

//This function takes numbers from user input and puts them into a vector.
//If this is the first number in the vector or if its greater than the last number,
//it simply inserts the number at the end of the vector.
//If this is the second number in the vector, it compares it with the number in the vector already
//and places it in the vector according to size.
//If there is more than one number in the vector it calls compare_numbers function.

void number_sorter(double number, vector <double> &vector1)
{
    if (vector1.size() == 0)
    {
        vector1.push_back(number);
    }
    else if (vector1.size() == 1)
    {
        if (number < vector1[0])
        {
            vector1.insert(vector1.begin() + 0, number);
        }
        else
        {
            vector1.insert(vector1.begin() + 1, number);


        }
    }
    else
    {
        compare_numbers(number, vector1);

    }
}

//This is called by the main function at the end to print the contents of the vector.

void print_vector(vector <double>&vector1)
{
    for (int i = 0; i < vector1.size(); ++i)
    {
        cout << vector1[i] << "\t";
    }
}


//Takes user input and calls function to compare against other numbers in vector and insert in numerical order.
//Finally prints vector contents. If user type non numerical input, main exits and prints vector contents.

int main()
{
    double number = 0.0;
    vector <double> numbers;

    while (cin)
    {
        cout << "Enter a number or type quit:\n";
        cin >> number;
        if (cin.fail())
        {
            break;
        }
        else
        {
            number_sorter(number, numbers);
        }
    }

    print_vector(numbers);
}
