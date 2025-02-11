vector<int> lcmAndGcd(int A, int B) {
        long long gcd = 1, lcm = 1, a = A, b = B;

        while(a && b){
            if(a > b)
                a = a % b;
            else
                b =  b % a;
        }
        if(a == 0) gcd = b;
        else gcd = a;
        
        lcm = (A*B)/gcd;
        return {lcm, gcd};
    }

// The Euclidean Algorithm is a method for finding the greatest common divisor of two numbers. It operates on the principle that the GCD of two numbers remains the same even if the smaller number is subtracted from the larger number.

// To find the GCD of n1 and n2 where n1 > n2:

// Repeatedly subtract the smaller number from the larger number until one of them becomes 0.
// Once one of them becomes 0, the other number is the GCD of the original numbers.
// Eg, n1 = 20, n2 = 15:

// gcd(20, 15) = gcd(20-15, 15) = gcd(5, 15)

// gcd(5, 15) = gcd(15-5, 5) = gcd(10, 5)

// gcd(10, 5) = gcd(10-5, 5) = gcd(5, 5)

// gcd(5, 5) = gcd(5-5, 5) = gcd(0, 5)

// Hence, return 5 as the gcd.
