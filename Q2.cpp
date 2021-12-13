#include <iostream>

using namespace std;

int main()
{
	int n, m;

	cout << "Enter the size of message: ";
	cin >> n;

	int arr[n], temp[10];

	cout << "\n\nEnter the message (in binary): ";

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
		temp[i] = arr[i];

	cout << "\nMessage entered is: ";
	for (int i = 0; i < n; i++)
		cout << arr[i];

	cout << "\n\nEnter the size of generator: ";
	cin >> m;

	int arr1[m];

	cout << "\n\nEnter the message generator(in binary): ";
	for (int i = 0; i < m; i++)
		cin >> arr1[i];

	cout << "\nMessage after reduntant bits is: ";
	for (int i = n; i < (n + m - 1); i++)
		arr[i] = 0;

	for (int i = 0; i < (n + m - 1); i++)
		cout << arr[i];

	for (int i = 0; i < n; i++)
	{
		if (arr1[0] == arr[i])
		{
			for (int j = 0, k = i; j < m; j++, k++)
			{
				if (!(arr[k] ^ arr1[j]))
					arr[k] = 0;
				else
					arr[k] = 1;
			}
		}
	}

	cout << "\n\nCRC bits at sender's side are: ";
	for (int i = n; i < (n + m - 1); i++)
		cout << arr[i];

	int arr2[n + m];
	cout << "\nEnter the message(with CRC's bits) at reciever's end: ";

	for (int i = 0; i < (n + m - 1); i++)
		cin >> arr2[i];

	cout << "\nMessage recieved is: ";
	for (int i = 0; i < (n + m - 1); i++)
		cout << arr2[i];

	for (int i = 0; i < n; i++)
	{
		if (arr1[0] == arr2[i])
		{
			for (int j = 0, k = i; j < m; j++, k++)
			{
				if (!(arr2[k] ^ arr1[j]))
					arr2[k] = 0;
				else
					arr2[k] = 1;
			}
		}
	}

	cout << "\n\nCRC bits at reciever's side are: ";
	for (int i = n; i < (n + m - 1); i++)
		cout << arr2[i];

	return 0;
}
