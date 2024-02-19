#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

float Summation1(vector<int> indices);
float Summation2(vector<int> indices);

int main() {
    cout<<"N"<<setw(20)<<"S1"<<setw(20)<<"S2"<<setw(20)<<"△"<<endl;
    /*
    for (int N = 1; N <1000000; N++){
        std::vector<int> indices(N);
        std::iota(indices.begin(), indices.end(), 1);
        float sum1 = Summation1(indices);
        float sum2 = Summation2(indices);
        float delta = abs(1-sum1/sum2);
        if (N%1000 == 0){
            cout<<N<<setw(20)<<sum1<<setw(20)<<sum2<<setw(13)<<delta<<endl;
        }
    }
    */
    int N = 100000000; 
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 1);
    float sum1 = Summation1(indices);
    float sum2 = Summation2(indices);
    float delta = abs(1-sum1/sum2);
    cout<<N<<setw(20)<<sum1<<setw(20)<<sum2<<setw(13)<<delta<<endl;

    return 0;
}

float Summation1(vector<int> indices){
    double sum = std::accumulate(indices.begin(), indices.end(), 0.0,
       [](double partialSum, int i) { return partialSum + 1.0 / i; });
    return sum;
    }

float Summation2(vector<int> indices){
    for (int i = 0; i < indices.size(); i++){
            

    }

    double sum = std::accumulate(indices.rbegin(), indices.rend(), 0.0,
       [](double partialSum, int i) { return partialSum + 1.0 / i; });
    return sum;
    }


