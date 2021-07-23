#pragma once
#include <iostream>

using namespace std;

// Note the keyword "ref" - this marks this as a managed class
ref class ManagedCat
{
public:
	ManagedCat(System::String^ name) : m_Name(name)
	{
		System::Console::WriteLine(m_Name + " constructed");
	}

	~ManagedCat()
	{
		System::Console::WriteLine(m_Name + " destructed");
	}

	void Speak(System::String^ phrase)
	{
		System::Console::WriteLine(m_Name + " says: " + phrase);
	}

private:
	System::String^ m_Name;
};


