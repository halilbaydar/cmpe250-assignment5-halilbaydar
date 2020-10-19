/*
Student Name:halil baydar
Student Number:2017400297
Project Number: 5
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[]){
    int  numberofchocolate=0;
    ofstream outFile(argv[2]);
    ifstream infile(argv[1]);
    string s,tmp;
    getline(infile, s);
    istringstream linestream(s);
    getline(linestream, tmp,' ');
    numberofchocolate=stoi(tmp);
    getline(linestream, tmp,' ');
    int restrictiononchocolate=stoi(tmp);
    vector<long long int> temp(10e5+2,-1);
    vector<long long> costarr;
    vector<long long int>arr(numberofchocolate,0);
    getline(infile, s);
    istringstream linestream2(s);
    for (long long int i = 0; i <numberofchocolate ; ++i) {
        getline(linestream2, tmp,' ');
        arr[i]=stoi(tmp);
    }
    sort(arr.begin(),arr.end());
    long long int a=0;
    long long sum=0;
    for (long long int j = 0; j <numberofchocolate; ++j){
        if(j<restrictiononchocolate){
            sum+=arr[j];
            a=sum;
        }else{
            sum+=arr[j];
            sum-=arr[j-restrictiononchocolate];
            a=sum;
        }
        if((j-(restrictiononchocolate))>-1) {
            long long int t= (j-(restrictiononchocolate*2))>-1 ? costarr[j-(restrictiononchocolate*2)] : 0;
            sum=costarr[j-restrictiononchocolate]*2+(sum-t);
        }
        costarr.push_back(sum);
        outFile<<sum<< " ";
        sum=a;
    }
    outFile.close();
    infile.close();
    return 0;
}