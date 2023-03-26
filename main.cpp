#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    string equation;
    vector<double> nums;
    vector<char> operators;
    // double result;
    string willBeANumber = "";

    cout << "Enter an equation: ";
    getline(cin, equation);

    for(int i = 0; i < equation.length(); i++){
        if(isdigit(equation[i])){
            willBeANumber += equation[i];
        } else if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/'){
            operators.push_back(equation[i]);
        } 
        if((!isdigit(equation[i]) && willBeANumber.size() > 0) || i == equation.length() - 1){
            nums.push_back(stod(willBeANumber));
            willBeANumber = "";
        }
    }

    for(int i = 0; i < operators.size(); i++){
        if(operators[i] == '*'){
            nums[i] *= nums[i + 1];
            nums.erase(nums.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        }
        else if(operators[i] == '/'){
            nums[i] /= nums[i + 1];
            nums.erase(nums.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        } else if(operators[i] == '+'){
            nums[i] += nums[i + 1];
            nums.erase(nums.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        } else if(operators[i] == '-'){
            nums[i] -= nums[i + 1];
            nums.erase(nums.begin() + i + 1);
            operators.erase(operators.begin() + i);
            i--;
        }
    }

    cout << "Answer: " << nums[0] << endl;
    return 0;
}