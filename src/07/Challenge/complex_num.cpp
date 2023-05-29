#include "complex_num.h"

complex_num::complex_num(double r, double i){
    // Write your code here
    real = r;
    imag = i;
}

complex_num complex_num::operator +(complex_num w){
    complex_num z;
    // Write your code here
    z = complex_num(real + w.real, imag + w.imag);

    return z;
}

complex_num complex_num::operator -(complex_num w){
    complex_num z;
    // Write your code here
    z = complex_num(real - w.real, imag - w.imag);

    return z;
}

complex_num complex_num::operator *(complex_num w){
    complex_num z;
    // Write your code here
    z = complex_num(real*w.real - imag*w.imag, real*w.imag + imag*w.real);

    return z;
}

complex_num complex_num::operator /(complex_num w){
    complex_num z;
    // Write your code here
    const int z_real = (real*w.real + imag*w.imag)/(w.real*w.real + w.imag*w.imag);
    const int z_imag = (imag*w.real - real*w.imag)/(w.real*w.real + w.imag*w.imag);

    z = complex_num(z_real, z_imag);

    return z;
}

void complex_num::print(std::ostream &os){
    // Write your code here
    
    os << real << " " << (imag < 0 ? "-" : "+ ") << "i" << abs(imag);
}