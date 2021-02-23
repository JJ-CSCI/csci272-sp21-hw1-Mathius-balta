#ifndef Binomial_h
#define Binomial_h
class Binomial {
private:
  float coef[3];
  int pow[3];
public:
  Binomial(float x = 1.0, int a = 1, float y = 1.0, int b = 1);
  
  int GetPower(int i);

  float GetCoefficient(int m);

  int SetPower(int e, int f);

  int Add(Binomial x);

  void Multiply(float x);

  void Multiply(float x, int y);
};
#endif