#include <iostream>
#include <vector>

using namespace std;


int main(){
    string equation;
    vector<double> nums;
    vector<char> operators;
    double result;

    cout << "Enter an equation: ";
    cin >> equation;

    for(int i = 0; i < equation.size(); i++){
        char c = equation[i];
        if(equation[i] == '+' || equation[i] == '-' || equation[i] == '*' || equation[i] == '/'){
            operators.push_back(equation[i]);
        }
        else if(isdigit(equation[i])){
            nums.push_back(equation[i]);
        }
    }

    for(int i = 0; i < nums.size(); i++){
        double temp = 0;
        if(operators[i] == '+'){
            cout << "Adding " << nums[i] << " and " << nums[i+1] << endl;
            temp = nums[i] + nums[i+1];
        }
        else if(operators[i] == '-'){
            cout << "Subtracting " << nums[i] << " and " << nums[i+1] << endl;
            temp = nums[i] - nums[i+1];
        }
        else if(operators[i] == '*'){
            cout << "Multiplying " << nums[i] << " and " << nums[i+1] << endl;
            temp = nums[i] * nums[i+1];
        }
        else if(operators[i] == '/'){
            cout << "Dividing " << nums[i] << " and " << nums[i+1] << endl;
            temp = nums[i] / nums[i+1];
        } 
        result += temp;
    }

    cout << "Answer: " << result << endl;
    return 0;
}