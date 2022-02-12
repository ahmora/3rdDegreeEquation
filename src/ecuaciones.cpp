#include "../lib/Equation.hpp"

using namespace std;

int main(int argc, char* argv[]){
  if(argc < 5){
    cout << "Usage: ./program a b c d. Where a,b,c and d are real numbers.";
    return -1;
  }

  //Assign values from input to a,b,c,d;
  double a = stod(argv[1]),  b = stod(argv[2]),  c = stod(argv[3]),  d = stod(argv[4]);
  Equation* e = new Equation(a,b,c,d);
  //cout << e->toString() << endl;
  //cout << "Discriminant " << e->discriminant() << endl;
  string sol= e->solve();
  cout << sol << endl;
  
  return 0;
}
