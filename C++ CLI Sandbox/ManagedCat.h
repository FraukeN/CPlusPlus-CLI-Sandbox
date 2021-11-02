#pragma once
#include <iostream>

using namespace std;

// Note the keyword "ref" - this marks this as a managed class
ref class ManagedCat
{
public:
	ManagedCat(System::String^ name) : m_Name(name)
	{
		System::Console::WriteLine(m_Name + " Constructor called");
	}

	~ManagedCat()
	{
		System::Console::WriteLine(m_Name + " Destructor called");

		// the finalizer of a class is not called when the destructor is called.
		// It's a good idea to call the finalizer from here, like so:
		// this->!ManagedCat();
		// Go on, uncomment the line above and try it - you know you want to!
	}

	!ManagedCat()
	{
		// This is where you'd typically do the cleanup

		System::Console::WriteLine(m_Name + " Finalizer called");
	}

	void Speak(System::String^ phrase)
	{
		System::Console::WriteLine(m_Name + " says: " + phrase);
	}

private:
	System::String^ m_Name;
}


