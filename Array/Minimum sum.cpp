//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string add(vector<int> num1, vector<int>num2) {
        // code here
        string result;
        int carry=0;
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0 || j>=0 || carry)
        {
            int sum=carry;
            if(i>=0)sum+=(num1[i--]-'0');
            if(j>=0)sum+=(num2[j--]-'0');
            result.push_back(sum%10+'0');
            carry=sum/10;
        }
        reverse(result.begin(),result.end());
        int start_index=0;
        while(start_index<result.size() && result[start_index]=='0')
        {
            start_index++;
        }
        if(start_index==result.size())
        {
            return "0";
        }
        return result.substr(start_index);
    }
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        string num1="",num2="";
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                num1+=to_string(arr[i]);
            }
            else
            {
                num2+=to_string(arr[i]);
            }
        }
        return add(num1,num2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
