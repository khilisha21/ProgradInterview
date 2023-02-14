/******************************************************************************

Program to encrypt a particular password

*******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int checkStrong(string s) {
    
    int sum = 0;
    int a = 0, b = 0, c = 0, d = 0;
    if(s.length() <= 8)
        return 0;
        
    for(int i = 0; i < s.length(); i++) {
        // cout << s[i];
        if(s[i] == '@' || s[i] == '$' || s[i] == '%' || s[i] == '*' || s[i] == '&'|| s[i] == '#')
            a = 1;
        else if(s[i] >= 48 && s[i] <= 57)
            b = 1;
        else if(s[i] >= 65 && s[i] <= 90)
            c = 1;
        else if(s[i] >= 97 && s[i] <= 122)
            d = 1;
        
    }
    
    
    sum = a + b + c + d;
    // cout << sum;
    if(sum == 4) 
        return 1;
    return 0;
    
}

void encrpyt(string s) {
    
    string s1;
    
   for(int i = 0; i < s.length(); i++) {
       
    //   if(s[i] == '@' || s[i] == '$' || s[i] == '%' || s[i] == '*' || s[i] == '&'|| s[i] == '#'){
            if(s[i] == '@')
                s1 += "at";
            else if(s[i] == '$')
                s1 += "dollar";
            else if(s[i] == '%')
                s1 += "modulo";
            else if(s[i] == '*')
                s1 += "asterisk";
            else if(s[i] == '&')
                s1 += "ampersand";
            else if(s[i] == '#')
                s1 += "hash";
        else if(s[i] >= 48 && s[i] <= 57){
            int t = s[i] - 48;
            t = pow(t, t + 1);
            s1 += to_string(t);
        }
        else if(s[i] >= 65 && s[i] <= 90){
            
            s1 += s[i] + 32;
            
        }
        else if(s[i] >= 97 && s[i] <= 122){
            s1 += s[i] - 32;
        }
    }
    cout << s1;
}



int main()
{
    string s;
    cin >> s;
    
    if(checkStrong(s) == 1) {
        cout << "\nEncrypted: ";
        encrpyt(s);
        return 0;
    }
    cout << "Password is not strong";
}

