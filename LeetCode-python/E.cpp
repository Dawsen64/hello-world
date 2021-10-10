#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s, result;
	
	getline(cin, s);
	

	int i = 0;
	int k = 5;
	int j = 0;
	for (i = 5; i < s.size(); i++)
	{
		if (s[i] == '-')
		{
			result += "-"; //处理负号
			k = 6;
		}
		else
		{
			if (s[i] == '+' || s[i] == '-')
			{
				string oneder = s.substr(k, i - k);
				j = k;
				k = i + 1;

				long long A = 0, E = 0;
				int xsite = oneder.find("x");

				if (xsite == oneder.npos)
				{
					if (result.size() == 0)
					{
						result += "0";
					}
				}
				else
				{
					//获得系数A
					if (xsite == 0)
					{
						A = 1;
					}
					else A = atoll(oneder.substr(j, xsite - j).c_str());

					if (oneder.find("^") != oneder.npos)
					{
						E = atol(oneder.substr(xsite + 2).c_str());
						A = A * E;
						E -= 1;
					}
					else E = 0;

					if (E == 0)
					{
						result = result + to_string(A) + s[i];
					}
					else if (E == 1)
					{
						result = result + to_string(A) + "x" + s[i];
					}
					else if (E > 1)
					{
						result = result + to_string(A) + "x^" + to_string(E) + s[i];
					}
				}
			}


		}
	}
	string oneder = s.substr(k);
	j = k;
	k = i + 1;

	long long A = 0, E = 0;
	int xsite = oneder.find("x");

	if (xsite == oneder.npos)
	{
		if (result.size() <= 1)
		{
			result += "0";
		}
	}
	else
	{
		//获得系数A
		if (xsite == 0)
		{
			A = 1;
		}
		else A = atoll(oneder.substr(j, xsite - j).c_str());

		if (oneder.find("^") != oneder.npos)
		{
			E = atol(oneder.substr(xsite + 2).c_str());
			A = A * E;
			E -= 1;
		}
		else E = 0;

		if (E == 0)
		{
			result = result + to_string(A) + s[i];
		}
		else if (E == 1)
		{
			result = result + to_string(A) + "x" + s[i];
		}
		else if (E > 1)
		{
			result = result + to_string(A) + "x^" + to_string(E) + s[i];
		}
	}
	if ((result[0] == '+' || result[0] == '-') && result[1] == '0')
	{
		result = result.substr(1);
	}
	if ((result[result.size() - 1] == '+' || result[result.size() - 1] == '-'))
	{
		result = result.substr(0, result.size() - 1);
	}
	result = "f'(x)=" + result;
	cout << result << endl;
	return 0;
}