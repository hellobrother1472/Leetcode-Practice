#include <bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

// first we store and remove all the elements and during backtracking we are putting them in the write place using sortedInsert.
// Sorted insert means take the element inside the stack until it is greater then the stack.top(), here the reccursion is used for it. And then repeat the process.

void sortedInsert(stack<int> &s, int x)
{
	if(s.empty() or x>s.top())
	{
		s.push(x);
		return;
	}
	int temp = s.top();
	s.pop();
	sortedInsert(s,x);
	s.push(temp);
}

void SortedStack :: sort()
{
	if(!s.empty())
	{
		int x = s.top();
		s.pop();
		sort();
		sortedInsert(s,x);
	}
}

int main(){

    return 0;
}