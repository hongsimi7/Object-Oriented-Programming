#include <iostream>
#include <iomanip>
int main()
{
	using namespace std;
	double x0;				//x0 변수 생성//
	double x;				//x 변수 생성//
	double h;				//h 변수 생성//

	cin >> x0 >> x >> h;	//x0, x, h 세 가지 정보를 입력//

	double exact_value = x * x;															//정확한 값 계산//
	double approx_value = x0 * x0 + ((x0 + h) * (x0 + h) - x0 * x0) / h * (x - x0);		//근사값 계산//
	
	cout << setprecision(5) << "Exact answer is "  << exact_value << endl;				//정확한 값 출력//
	cout << setprecision(5) << "Approximate answer is " << approx_value;				//근사값 출력//
	return 0;
}