#pragma once
#include <iostream>

using namespace std;

class NativeCat
{
public:
	NativeCat(string name) : m_Name(name)
	{
		cout << m_Name << " constructed" << endl;
	}

	~NativeCat()
	{
		cout << m_Name << " destructed" << endl;
	}

	void Speak(string phrase)
	{
		cout << m_Name << " says: " << phrase << endl;
	}

private:
	string m_Name;
};

