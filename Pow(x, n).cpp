class Solution {
public:
    double pow(double x, int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        double half_result = 0.0;
        
        if (n == 0) return 1.0;
            
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        
        if (n == 1)
            return x;
        
        half_result = pow(x, n / 2);
        
        return half_result * half_result * pow(x, n % 2);
    }
};
