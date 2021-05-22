#include <iostream>
#include<stack>
using namespace std;
stack <string> sort(stack <string> names){
    //tmpStack save sorted string
    stack <string> tmpStack;
    while (!names.empty()){
        string tmp = names.top();
        names.pop();
        // tmp save last string in name
        while(!tmpStack.empty()&&tmp < tmpStack.top()){
            //if tmp is smaller than last string saved in tmpStack
            //it will save backward in names
            names.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(tmp);
    }
    return tmpStack;
}
int main(){
    stack <string> names;
    cout << "how much do you want to input?";
    int n;
    cin >> n;
    string junk;
    getline(cin , junk);
    cout << "Pls enter your names to sort"<<endl;
    for(int i=0;i<n;i++){
        string name;
        getline(cin , name);
        names.push(name);
    }
    cout <<"----------------------------"<<endl;
    stack <string> result = sort(names);
    while(!result.empty()){
        cout << result.top()<<endl;
        result.pop();
    }
    return 0;
}
