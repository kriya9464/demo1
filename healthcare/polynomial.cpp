
#include <vector>
#include <climits>
#include <iostream>
using namespace std;


class Polynomial {
    int *degCoeff;   // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    
    public:
    
    Polynomial(){
        degCoeff=new int[5];
        degCoeff={0};
        capacity=5;

    }
    Polynomial(Polynomial const &p){
        this->degCoeff=new int[p.capacity];
        this->capacity=p.capacity;
        for(int i=0;i<capacity;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
        
        
    }
    void operator=(Polynomial const &p){
         this->degCoeff=new int[p.capacity];
        this->capacity=p.capacity;
        for(int i=0;i<capacity;i++){
            this->degCoeff[i]=p.degCoeff[i];
        }
    }
    void setCoefficient(int deg, int coeff){
        if(deg<capacity){
            this->degCoeff[deg]=coeff;
        }
        else{
            if(deg==capacity){
                capacity*=2;
                int *degcoeff=new int[capacity];
                for(int i=0;i<capacity;i++){
                    degcoeff[i]=degCoeff[i];
                }
                for(int i=deg;i<capacity;i++){
                    degcoeff[i]=0;
                }
                delete [] degCoeff;
                degCoeff=degcoeff;
            }
            else{
                int *degcoeff;
                while(deg>capacity){
                   capacity*=2;
                int *degcoeff=new int[capacity];
                    degcoeff={0};
                }
                for(int i=0;i<capacity;i++){
                    degcoeff[i]=degCoeff[i];
                }
                degcoeff[deg]=coeff;
                delete [] degCoeff;
                degCoeff=degcoeff;
                
            }
        }
    }
    Polynomial operator+(Polynomial const &p){
        int m=max(capacity,p.capacity);
        int *degcoeff=new int[m];
        
        for(int i=0;i<m;i++){
            degcoeff[i]=degCoeff[i]+p.degCoeff[i];
        }
        degCoeff=degcoeff;
        return *this;
    }
    Polynomial operator-(Polynomial const &p){
        int m=max(capacity,p.capacity);
        int *degcoeff=new int[m];
        
        for(int i=0;i<m;i++){
         degcoeff[i]=degCoeff[i]-p.degCoeff[i];
        }
        degCoeff=degcoeff;
        return *this;
    }
    Polynomial operator*(Polynomial const &p){
        int m=max(capacity,p.capacity);
        int *degcoeff=new int[m];
        for(int i=0;i<this->capacity;i++){
           for(int j=0;j<p.capacity;j++){
               degcoeff[i+j]=degCoeff[i]*p.degCoeff[j];
           }
        }
        degCoeff=degcoeff;
        return *this;
    }
    void print(){
        //cout<<"x";
        for(int i=0;i<capacity;i++){
            cout<<degCoeff[i]<<"x"<<i<<" ";
        }
    }
};


int main(){
    Polynomial p1;
    p1.setCoefficient(2,3);
    p1.setCoefficient(1,1);
    p1.setCoefficient(0,4);
    Polynomial p2;
    p2.setCoefficient(1,1);
    p2.setCoefficient(0,1);
    p2.print();
    Polynomial p3=p1+p2;
    p3.print();
    return 0;
}