#include "binomial.h"
#include "catch.hpp"

Binomial::Binomial() {
    coef[1] = 1.0;
    coef[2] = 1.0;
    pow[1] = 1;
    pow[2] = 1;
  }
Binomial::Binomial(float x) {
    coef[1] = x;
    coef[2] = 1.0;
    pow[1] = 1;
    pow[2] = 1;
  }

Binomial::Binomial(float x, int y) {
    coef[2] = 1.0;
    pow[2] = 1;
    coef[1] = x;

    if (y < 1){
      pow[1] = 1;
    }
    else
    pow[1] = y;
  }

Binomial::Binomial(float x, int y, float a) {
  pow[2] = 1;
  coef[1] = x;
  coef[2] =a;

  if (y < 1){
    pow[1] = 1;
    }
    else
    pow[1] = y;
  }

Binomial::Binomial(float x, int a, float y, int b) {
  coef[1] = x;
  coef[2] =y;

  if((a < 1) && (b < 1)){
    pow[1] = 1;
    pow[2] = 1;
  }
  else if ((a < 1) && (b >= 1)){
    pow[1] = 1;
    pow[2] = b;
  }
  else if ((a >= 1) && (b < 1)){
    pow[1] = a;
    pow[2] = 1;
  }
  else{
  pow[1] = a;
  pow[2] = b;
  }
  }

int Binomial::GetPower(int i) {
    if (pow[i] == pow[1])
    return pow[1];
    if (pow[i] == pow[2])
    return pow[2];
    else
    return -1;
  }

  float Binomial::GetCoefficient(int m) {
    if (coef[m] == coef[1])
    return coef[1];
    if (coef[m] == coef[2])
    return coef[2];
    else
    return -1;
  }

  int Binomial::SetPower(int e, int f){

    if (((e == 1) || (e == 2)) && (f >= 0)){
      pow[e] = f;
      return 0;
    }
    else if ((f < 0) && ((e == 1) || (e == 2))){
      pow[e] = 1;
      return 0;
    }
    else if (((e != 1) || (e != 2)) && (f >= 0)){
      pow[1] = pow[1];
      pow[2] = pow[2];
      return -1;
    }
    else if (((e != 1) || (e != 2)) && (f < 0)){
      pow[1] = pow[1];
      pow[2] = pow[2];
      return -1;
    }
    else
    return -1;
  }

  int Binomial::Add(Binomial x) {

    if (pow[1] != x.pow[1]){
      return -1;
    }
    else if ((pow[1] == x.pow[1]) && (pow[2] != x.pow[2])){
      coef[1] = coef[1] + x.coef[1];
      return 0;
    }
    else if ((pow[1] == x.pow[1]) && (pow[2] == x.pow[2])){
      coef[1] = coef[1] + x.coef[1];
      coef[2] = coef[2] + x.coef[2];
      return 0;
    }
    else 
    return -1;
  }

  void Binomial::Multiply(float x) {
    coef[1] = coef[1] * x;
    pow[1] = pow[1];
    coef[2] = coef[2] * x;
    pow[2] = pow[2];
  }
  void Binomial::Multiply(float x, int y) {
    coef[1] = coef[1] * x;
    pow[1] = pow[1] + y;
    coef[2] = coef[2] * x;
    pow[2] = pow[2] + y;
  }