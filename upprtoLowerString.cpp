#include <iostream>
#include<string>
using namespace std;

string convertString(string str) {
	int n = str.size();
	//CONVERT LOWERCASE TO UPPERCASE	
	if(str[0]>= 'a' && str[0]<='z')
		str[0] = str[0] - 'a' + 'A';
	int i=0;
	while(i<n-1){
		if(str[i] == ' ' && str[i+1] >= 'a' && str[i] <= 'z'){
			str[i+1] = str[i+1] + 'A' - 'a';
		}
		i++;
	}
	return str;
}
string removeVowels(string inputString) {
    string str;
    int n = inputString.size();
    for(int i=0; i<n; i++){
        if(inputString[i] == 'a' || inputString[i]=='e' || inputString[i] == 'i' 
                    || inputString[i] == 'o' || inputString[i] == 'u' || inputString[i] == 'A'
                     || inputString[i]=='E' || inputString[i] == 'I' 
                    || inputString[i] == 'O' || inputString[i] == 'U'){
            continue;
        }
        else   
            str.push_back(inputString[i]);
    }
    return str;
}

string removeVowels2(string inputString) {
    string vowel = "aeiouAEIOU";
    for (int i = 0; i < vowel.length(); i++) {
        for (int j = 0; j < inputString.length(); j++) {
            if (vowel[i] == inputString[j]) {
                inputString.erase(j, 1); // Erase 1 character at index j
                j--; // Decrement j to account for the erased character
            }
        }
    }
    return inputString;
}

string leftRotate(string str, int d) {
	int n = str.size();
    d = d%n;
    string ans;
    for(int i=0; i<n; i++){
        if(i<d){
            ans.push_back(str[n+i-d]);
        }
        else
            ans.push_back(str[i-d]);
    }
    return ans;
}

int main(){
    string str = "I love programming";
    //cout << convertString(str);
    string ch = "kmow"; //mowk
    cout << leftRotate(ch, 1) << endl;
}