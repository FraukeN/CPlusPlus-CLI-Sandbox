#include "NativeCat.h"
#include "ManagedCat.h"

void create_cats()
{
	System::Console::WriteLine("************** Native vs.managed classes construction example ***************");
	// Create NativeCat on the stack. This is what we want to do in Selector.
	NativeCat stack_cat("StackCat");
	stack_cat.Speak("This stack of pillows is comfortable. Meow.");

	
	// Create NativeCat on the heap. this can lead to memory leaks.
	// We don't want to do this if we can avoid it.
	NativeCat* heap_cat = new NativeCat("HeapCat");
	heap_cat->Speak("I don't want to be on this heap of junk. Hiss.");
	delete heap_cat;
	// If you forget to delete the object, the memory will never be released.

	
	// Create ManagedCat. Managed classes are always created on the heap.
	// This is OK, though, they are garbage collected, so no memory leaks.
	ManagedCat^ managed_cat = gcnew ManagedCat("ManagedCat");
	managed_cat->Speak("This heap of freshly washed shirts is comfy. Purr");
	// Managed classes use nullptr, not null.
	managed_cat = nullptr;
	// Now the garbage collector will release the memory at some point
	System::Console::WriteLine("\n\n\n");
}

void destroy_managed_cats()
{
	System::Console::WriteLine("************** Native vs.managed classes destruction example ***************");
	// If nothing in particular is done to destruct a managed class,
	// only the finalizer is called
	ManagedCat^ managed_cat = gcnew ManagedCat("ManagedCat that will be nullpointered");
	managed_cat->Speak("I'm indestructible! Muahahahaha!");
	managed_cat = nullptr; // <- Here Visual Studio should give you a helpful hint that only the finalizer for managed_cat will be called.

	managed_cat = gcnew ManagedCat("ManagedCat that will not be explicitly destroyed at all");
	managed_cat->Speak("I'm also indestructible! Muahahahaha!");

	// Only if the managed class is explicitly deleted will the destructor be called
	// Note that here the finalizer is NOT called!
	// One way of making sure that the finalizer is always called is to explicitly call it from the destructor
	managed_cat = gcnew ManagedCat("ManagedCat that will be deleted");
	managed_cat->Speak("Oh, no! Cybermen!!!");
	delete managed_cat;
}

int main()
{
	create_cats();

	destroy_managed_cats();

	return 0;
}
