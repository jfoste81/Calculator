#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    string equation;
    vector<double> nums;
    vector<char> operators;
    double result;
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

    for(int i : nums){ // REMOVE THIS SECTION LATER
        cout << i << endl;
    }
    for(char i : operators){ // REMOVE THIS SECTION LATER
        cout << i << endl;
    }

    int size = nums.size();
    for(int i = 0; i <= size; i++){
        // double temp = 0;
        if(operators[i] == '+'){
            i++;
            cout << "Adding " << nums[0] << " and " << nums[i] << endl;
            nums[0] += nums[i];
        }
        else if(operators[i] == '-'){
            i++;
            cout << "Subtracting " << nums[0] << " and " << nums[i] << endl;
            nums[0] -= nums[i];
        }
        else if(operators[i] == '*'){
            i++;
            cout << "Multiplying " << nums[0] << " and " << nums[i] << endl;
            nums[0] *= nums[i];
        }
        else if(operators[i] == '/'){
            i++;
            cout << "Dividing " << nums[0] << " and " << nums[i] << endl;
            nums[0] /= nums[i];
        } else {
            cout << "No operator found." << endl;
        }    
    }
    result += nums[0];
    cout << "Answer: " << result << endl;
    return 0;
}