#include <iostream>
#include <algorithm>
using namespace std;
void findAverageScore(int N, int contestant[], int &x, int &y, int &z)
{
	int high = 0;
	int low = 99999;
	double sum = 0.0;
	for (int i = 0; i < N; i++)
	{
		if (contestant[i] >= high)
		{
			high = contestant[i];
		}
		if (contestant[i] <= low)
		{
			low = contestant[i];
		}
		sum = sum + contestant[i];
	}
	cout << high << " " << low << endl;
	sum = sum - low - high;
	sum = sum / N;
	if (sum >= y)
	{
		x = z;
	}
	y = sum;
	cout << sum << endl;
}
int main()
{
	int N = 0;
	int x = 0;
	int contestant = 0;
	int scores[99];
	int winner = 0;
	int scorer;
	cout << "Enter the number of judges ";
	cin >> N;
	do {
		cout << "Enter contestant number followed by scores" << endl;
		cin >> contestant;
		if (contestant >= 0)
		{
			for (int i = 0; i < N; i++)
			{
				cin >> scores[i];
			}
			cout << "Contestant " << contestant << " ";
			x = contestant;
			findAverageScore(N, scores, winner, scorer, x);
			cout << endl;
		}
	} while (contestant >= 0);
	cout << "Winner" << winner << endl;
	system("pause");
	return 0;
}