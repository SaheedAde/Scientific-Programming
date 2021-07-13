#include <iostream>

/*______________________________________________________________________________________________________________________________________________
Public, protected and private are ways of declaring the access control of the members of the base class by the derived class.

Below is the format of  declaring access control:

class baseClass
{
.... ... ....
};

class derivedClass : access_specifier baseClass
{
.... ... ....
};

where access_specifier can be one of public, protected and private.

The example below demonstrates the difference between the use of these access specifiers.
_______________________________________________________________________________________________________________________________________________*/

class baseClass
{
	public:
		int x;
	protected:
		int y;
	private:
		int z;
};

class publicDerived: public baseClass
{
	// x is public
	// y is protected
	// z is not accessible from publicDerived
};

class protectedDerived: protected baseClass
{
	// x is protected
	// y is protected
	// z is not accessible from protectedDerived
};

class privateDerived: private baseClass
{
	// x is private
	// y is private
	// z is not accessible from privateDerived
}

/*______________________________________________________________________________________________________________________________________________

In the above example:
   * baseClass has three member variables x, y, z which are declared public, protected and
     private member respectively.

   * the derived class publicDerived inherits variables x and y as public and protected respectively.
     However, z is not inherited as it is a private member variable of the baseClass.

   * the derived class protectedDerived inherits variables x and y, and both variables become protected.
     However, z is not inherited. Even we derive another class from this derived class, variables x and y are
     also inherited to the derived class.

   * the derived class privateDerived inherits variables x and y, and both variables become private. However,
     z is not inherited. Furthermore, if derive a class from privateDerived, variables x and y are not inherited
     due to the fact that they are private variables of privateDerived.
__________________________________________________________________________________________________________________________________________________*/
