#include <iostream>
#include <iomanip>
int main()
{
	using namespace std;
	double x0;				//x0 ���� ����//
	double x;				//x ���� ����//
	double h;				//h ���� ����//

	cin >> x0 >> x >> h;	//x0, x, h �� ���� ������ �Է�//

	double exact_value = x * x;															//��Ȯ�� �� ���//
	double approx_value = x0 * x0 + ((x0 + h) * (x0 + h) - x0 * x0) / h * (x - x0);		//�ٻ簪 ���//
	
	cout << setprecision(5) << "Exact answer is "  << exact_value << endl;				//��Ȯ�� �� ���//
	cout << setprecision(5) << "Approximate answer is " << approx_value;				//�ٻ簪 ���//
	return 0;
}