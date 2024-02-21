#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

float Summation1(int N);
float Summation2(int N);

int main() {
    cout<<"N,S1,S2,△"<<endl;
    vector<int> N;
    for (int i = 10000; i <= 9000000; i += 10000) {
        N.push_back(i);
    }
    vector<float> delta(N.size());
    int i = 0;

     for (auto n : N) {
        float sum1 = Summation1(n);
        float sum2 = Summation2(n);
        delta[i] = abs(1-sum1/sum2);
        cout << n <<','<<sum1<<','<<sum2<<','<<delta[i]<< endl;
        i = i + 1;
    } 
    return 0;
}

float Summation1(int N){
    float sum1 = 0.0;
    for (float i = 1;i<=N; i++){
        sum1 = sum1 + 1/i;
        //cout<<"i: "<<i<<" S1: "<<sum1<<endl;
        //if (N%10 == 0){
            //cout<<i<<setw(20)<<sum1<<setw(20);
        //}
    }
    return sum1;
}

float Summation2(int N){
    float sum2 = 0.0;
    for (float i = N;i>=1; i--){
        //cout<<"i: "<<i<<" S2: "<<sum2<<endl;
        sum2 =sum2 + 1/i;
        //if (N%10 == 0){
        //    cout<<" S2: "<<sum2<<endl;
        //}
    }
    return sum2;
}

/*float Summation2(int N){
    double sum = std::accumulate(indices.rbegin(), indices.rend(), 0.0,
       [](double partialSum, int i) { return partialSum + 1.0 / i; });
    return sum;
    }*/


