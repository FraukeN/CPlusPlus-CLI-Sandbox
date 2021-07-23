#include "NativeCat.h"
#include "ManagedCat.h"

void create_cats()
{
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
}

int main()
{
	create_cats();

	return 0;
}
