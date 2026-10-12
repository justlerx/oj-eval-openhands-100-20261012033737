#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
using namespace std;

bool isPerfectNumber(uint64_t n) {
    if (n == 1) {
        return false; // 1 has no proper divisors, sum = 0
    }
    
    uint64_t sum = 1; // 1 is always a proper divisor for n > 1
    
    // Check divisors from 2 to sqrt(n)
    uint64_t sqrt_n = static_cast<uint64_t>(sqrt(n));
    
    for (uint64_t i = 2; i <= sqrt_n; i++) {
        if (n % i == 0) {
            uint64_t divisor = i;
            uint64_t complement = n / i;
            
            sum += divisor;
            
            // Add complement divisor if it's different from divisor and not n itself
            if (complement != divisor && complement != n) {
                sum += complement;
            }
        }
    }
    
    return sum == n;
}

int main() {
    int m;
    cin >> m;
    
    vector<uint64_t> numbers(m);
    for (int i = 0; i < m; i++) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < m; i++) {
        cout << (isPerfectNumber(numbers[i]) ? 1 : 0) << endl;
    }
    
    return 0;
}