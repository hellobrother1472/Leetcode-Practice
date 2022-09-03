#include <iostream>

using namespace std;

class Solution
{
public:
    // long long printDivisorsOptimal(long long n){
    //     long long sum = 0;
	   // for(int i = 1; i <= sqrt(n); i++)
	   // 	if(n % i == 0){
	   // 		sum+=i;
	   // 		if(i != n/i) sum+=n/i ;
	   // 	}
	   // return sum;
    // }

    long long sumOfDivisors(int N)
    {
        long long sum = 0;
       for(int i = 1; i <= N; i++){
           sum += (N/i)*i;
       }
       return sum;
    }
};
int main(){
    

    return 0;
}