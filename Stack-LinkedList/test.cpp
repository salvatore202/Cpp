/*
 * test.cpp
 *
 *  Created on: 24 set 2023
 *      Author: salva
 */


#include <iostream>
#include "node.h"
#include "stack.h"

using namespace std;

int main()
{
	int x,y,z,t;
	std::string a,b;

	stack<int> integer_stack1;
	stack<int> integer_stack2;
	stack<std::string> string_stack;

	cout<<"\n\n x = ";
	cin>>x;

	cout<<"\n y = ";
	cin>>y;

	cout<<"\n\n z = ";
	cin>>z;

	cout<<"\n t = ";
	cin>>t;

	cout<<"\n prima parola = ";
	cin>>a;

	cout<<"\n seconda parola = ";
	cin>>b;

	cout<<endl<<endl;

	integer_stack1.push(x);
	integer_stack1.push(y);

	integer_stack2.push(z);
	integer_stack2.push(t);

	string_stack.push(a);
	string_stack.push(b);

	cout<<integer_stack1.top()<<endl<<endl;
	cout<<string_stack.top()<<endl<<endl;
	cout<<" Nello stack di interi sono presenti "<<integer_stack1.size()<<" elementi "<<endl;
	cout<<" Nello stack di stringhe sono presenti "<<string_stack.size()<<" elementi "<<endl<<endl;

	cout<<" Operazione di identita' in corso... ..."<<endl<<endl;
	integer_stack1=integer_stack2;

	cout<<integer_stack1.top()<<endl<<endl;
	cout<<string_stack.top()<<endl<<endl;
	cout<<" Nello stack di interi sono presenti "<<integer_stack1.size()<<" elementi "<<endl;
	cout<<" Nello stack di stringhe sono presenti "<<string_stack.size()<<" elementi "<<endl<<endl;

	cout<<" Operazione di Pop in corso... ...";
	integer_stack1.pop();
	string_stack.pop();

	cout<<endl<<endl;
	cout<<integer_stack1.top()<<endl<<endl;
	cout<<string_stack.top()<<endl<<endl;
	cout<<" Nello stack di interi sono presenti "<<integer_stack1.size()<<" elementi "<<endl;
	cout<<" Nello stack di stringhe sono presenti "<<string_stack.size()<<" elementi "<<endl;

}

