#include <iostream>
// g++ main.cpp -o main && ./main
// 0100 1010 1010 0010 . 1101 0101 0101 0110
const int scale = 16; // 1/2^16

#define DoubleToFixed(x) ((double)x * (double)(1<<scale))
#define FixedToDouble(x) ((double)x / (double)(1<<scale))

int main() {
    std::cout.precision(20);

    float var_f = 5.7;
    double var_d = 5.7;
    std::cout << "just print 5.7  raw = " << 5.7 <<"\n";
    std::cout << "just var_f 5.7  raw = " << var_f <<"\n";
    std::cout << "just var_d 5.7  raw = " << var_d <<"\n";
    std::cout << "----------\n";
    
    int f = DoubleToFixed(var_f);
    std::cout << "Actual Float val of 5.7 with 20P = " << var_f <<"\n";
    std::cout << "DoubleToFixed(var_f) = "  << DoubleToFixed(var_f)<<"\n";
    std::cout << "DoubleToFixed(5.7) = " << DoubleToFixed(5.7) <<"\n";
    std::cout << "It's FXP rep = " << f <<" with scale 2^16\n";
    std::cout << "FixedToDouble(" << f <<") = " << FixedToDouble(f) <<"\n";

    std::cout << "----------\n";

    int ff = DoubleToFixed(5.7);
    std::cout << "Actual Double val of 5.7 with 20P = " << var_d <<"\n";
    std::cout << "DoubleToFixed(5.7) = " << DoubleToFixed(5.7) <<"\n";
    std::cout << "DoubleToFixed(var_d) = " << DoubleToFixed(5.7) <<"\n";
    std::cout << "It's FXP rep = " << ff <<" with scale 2^16\n";
    std::cout << "FixedToDouble(" << ff <<") = " << FixedToDouble(ff) <<"\n";
    std::cout << "Actual Double val of 5.7 with 20P = " << var_d <<"\n";

    



    // int ff = 
    // std::cout<<"Actual Float = " << actual_num <<"\n";
    // std::cout<<"It's FXP rep = " << f <<"\n";
    // std::cout<<"FixedToDouble(" << f <<") = " << FixedToDouble(f) <<"\n";
    return 0;
}


// Follow ups
// 1) does cout round ? by how much ??
