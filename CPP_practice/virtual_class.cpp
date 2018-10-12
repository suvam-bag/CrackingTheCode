/* Virtual Base Class - Why does a destructor in base class need to be declared virtual */

//To ensure the destructor for the most derived class is called

class Foo {
public:
	void f();
};

class Poo : public Foo{
public:
	void f();
};

Foo *p = new Poo();
p -> f(); //accesses Foo->f() because the pointer is till for Foo, f() not being s virtual
