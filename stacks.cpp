
void printNGE(int arr[], int n)
{
	stack<int> s;
  
  for (int i=n-1; i>=0; i--)
  {
    if (s.empty()) {
      cout <<-1<<endl;
    } else if (arr[i] > s.top()) {
        while(!s.empty() && arr[i] > s.top()) {
            s.pop();
        }
        if (s.empty()) 
          cout<<-1<<endl;
        else
          cout<<s.top()<<endl;
    } else if( arr[i] < s.top()) {
        cout<<s.top()<<endl;
	  }
     s.push(arr[i]);
  }
}
