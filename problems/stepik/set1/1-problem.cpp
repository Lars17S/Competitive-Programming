#include <iostream> 
#include <vector>
#include <string>
using namespace std; 

vector<string> sub_s[2];

void SubSeqRec(string str, int n, int string_num,
           int index = -1, string curr = "")  {

    // base case 
    if (index == n)  
        return; 
    
    // Store the string
    if (curr != "")
        sub_s[string_num].push_back(curr);

    for (int i = index + 1; i < n; i++) { 
        curr += str[i]; 
        SubSeqRec(str, n, string_num, i, curr); 

        // backtracking 
        curr.pop_back();  
    } 
    return; 
} 
   
void SubSeq(string str, int string_num) { 
    SubSeqRec(str, str.size(), string_num); 
} 
   
int main() 
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    SubSeq(str1, 0);
    SubSeq(str2, 1);
    int max = -1;

    // For each subsequence generated in str2, find the max length for each
    // subsequence in str1
    for (string str1 : sub_s[0])
        for (string str2 : sub_s[1])
            if (str1 == str2 && max < int(str2.length()))
                max = int(str2.length());
    cout << max << endl;

    return 0; 
} 