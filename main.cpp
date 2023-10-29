#include<iostream>

class IPAddress {
protected:
	int* ipAddress;
	int arraySize;
public: 
	IPAddress(int* _array, int sizeArray) { 
		arraySize = sizeArray;
		ipAddress = new int[arraySize];
		for (int i = 0; i < arraySize; i++)
		{
			ipAddress[i] = _array[i];
		}
	}
	virtual void Show() {
		std::cout << "IP ������ : ";
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << ipAddress[i];
			if (i < arraySize - 1)
				std::cout << ".";
		}
	  }
	~IPAddress() {
		delete[] ipAddress;
	}
};

class IPAddressChecked : public IPAddress {
public:
	bool correctIpAddress;
public: 
	IPAddressChecked(int* _array, int sizeArray) : IPAddress(_array,sizeArray) {}
	void SetCorrectIpAddress(bool new_correctIpAddress)
	{
		correctIpAddress = new_correctIpAddress;
	}
	void Show() {
		  if (correctIpAddress == true) {
			  IPAddress::Show();
			  std::cout << " ��������� ����������" << std::endl;
		  }
		  else {
			  IPAddress::Show();
			  std::cout << " �����������" << std::endl;
		  }

	  }
};

bool CheckIPAddress(int *_array, int sizeArray) {
	bool correctIpAddress = false;
	for (int i = 0; i < sizeArray; i++)
	{
		if (_array[i] > 255 || _array[i] < 0) {
			correctIpAddress = false;
			break;
		}
		else
			correctIpAddress = true;
	}
	return correctIpAddress;
}

int main() {
	system("chcp 1251>nul");
	char exitFromCycle = 'z';
	const int arraySize{ 4 };
	int* userIpAddress = new int[arraySize];
	std::cout << "� ������� ��� �쳺 ��������� IP ������ �� �����������" << std::endl;
	std::cout << "����-����� ������ IP ������ (������� �����: 192 ������� Enter 168 ������� Enter 1 ������� Enter 1 ������� Enter)"<<std::endl;
	while (true) {
		for (int i = 0; i < arraySize; i++)
		{
			std::cin >> userIpAddress[i];
		}
		std::cout << "���� IP ������: ";
		for (int i = 0; i < arraySize; i++)
		{
			std::cout << userIpAddress[i];
			if (i < arraySize-1)
				std::cout << ".";
		}
		std::cout << std::endl;
		std::cout << "���� ��� ���� ������ Y, ���� � - ������ N � �������� ��� IP ������: ";
		std::cin >> exitFromCycle;
		if (exitFromCycle == 'Y'|| exitFromCycle == 'y')
			break;
		else
			std::cout << "����-����� ������ IP ������ (������� �����: 192 ������� Enter 168 ������� Enter 1 ������� Enter 1 ������� Enter)" << std::endl;
	}
	bool correctIpAddress = CheckIPAddress(userIpAddress, arraySize);
	IPAddressChecked* ipaddresschek = new IPAddressChecked(userIpAddress,arraySize);
	ipaddresschek->SetCorrectIpAddress(correctIpAddress);
	ipaddresschek->Show();
	delete[] userIpAddress;
	return 0;
}