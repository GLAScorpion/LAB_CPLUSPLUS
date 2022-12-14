#include <iostream>
class vector{
public:
    explicit vector(int dim);
    int size() const;
    double& operator[](int index);
    double operator[](int index) const;
    double safe_get(int index) const;
    void safe_set(int index, double value);
    vector(const vector& vec);//costruttore di copia
    vector(vector&& vec);//costruttore di spostamento
    vector& operator=(const vector& vec); //assegnamento per copia
    vector& operator=(vector&& vec); //assegnamento per spostamento
    ~vector();
    vector(std::initializer_list<double> lst);
private:
    const int dim;
    double* elem = nullptr;
   
};
std::ostream& operator<<(std::ostream& os, vector& vec);
