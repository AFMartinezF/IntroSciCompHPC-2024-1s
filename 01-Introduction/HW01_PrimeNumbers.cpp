//Codigo para encontrar los numeros primos entre 10 y 30 Escrito por Angel Martínez
#include<iostream>
#include<vector>
using namespace std;

int main(){
    std::vector<int> primeNumbers;
    for (int i = 10;i < 31;i++){
        if (i % 2 == 0){
            continue;
            }
        else{
            for (int j=3;j < i;j=j+2){
                if (i % j == 0){
                    break;
                    }
                else if (j == i-2){
                primeNumbers.push_back(i);
                    }
            }                   
                
        }               
    }
    cout << "Prime Numbers between 10 and 30 are: ";
    for (int i = 0;i < primeNumbers.size();i++){
        cout << primeNumbers[i] << " ";
        }    
    return 0;
    }

