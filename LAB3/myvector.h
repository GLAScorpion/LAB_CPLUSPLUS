#include <iostream>
class vector{
public:
    vector(int dim);
    int get_size() const;
    double& operator[](int index);
    double operator[](int index) const;
    double safe_get(int index) const;
    void safe_set(int index, double value);
    ~vector();
private:
    const int size;
    double* elem = nullptr;
   
};
