#ifndef Binomial_h
#define Binomial_h
class Binomial {
private:
  float coef[3] {0, 1.0, 1.0};
  int pow[3] {0, 1, 1};
public:
  Binomial();

  Binomial(float x);
  
  Binomial(float x, int y);

  Binomial(float x, int y, float a);
  
  Binomial(float x, int a, float y, int b);
  
  int GetPower(int i);

  float GetCoefficient(int m);

  int SetPower(int e, int f);

  int Add(Binomial x);

  void Multiply(float x);

  void Multiply(float x, int y);
};
#endif