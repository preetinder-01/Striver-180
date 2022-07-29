void insert(stack<int> &stack,int temp)
{
 if(stack.size()==0 or stack.top()<=temp)
 {
     stack.push(temp);
     return;
 }
    int val=stack.top();
    stack.pop();
    insert(stack,temp);
    stack.push(val);
    return;
}

void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.size()==1)
        return;
    
    int temp=stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack,temp);
    return;
}