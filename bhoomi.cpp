int distinctStrings(vector<string> &arr, int n)
{
    //  Counter variable to store the number of distinct strings.
    int count = 0;

    //  Iterate through the given set.
    for (int i = 0; i < n; i = i + 1)
    {
        //  Create two vectors to store frequencies of characters at even or odd indexes.
        vector<int> even1(26, 0), odd1(26, 0);

        //  Iterate through the string.
        for (int j = 0; j < arr[i].length(); j = j + 1)
        {
            //  For odd index, increment frequency in odd1 vector.
            if (j & 1)
            {
                odd1[arr[i][j] - 'a'] = odd1[arr[i][j] - 'a'] + 1;
            }

            //  For even index, increment frequency in even1 vector.
            else
            {
                even1[arr[i][j] - 'a'] = even1[arr[i][j] - 'a'] + 1;
            }
        }

        int h;

        //  Again, increment through the set.
        for (h = i + 1; h < n; h = h + 1)
        {
            //  Create two vectors to store frequencies of characters at even or odd indexes.
            vector<int> even2(26, 0), odd2(26, 0);

            for (int j = 0; j < arr[h].length(); j = j + 1)
            {
                if (j & 1)
                {
                    odd2[arr[h][j] - 'a'] = odd2[arr[h][j] - 'a'] + 1;
                }
                else
                {
                    even2[arr[h][j] - 'a'] = even2[arr[h][j] - 'a'] + 1;
                }
            }

            int k;

            //  Check, If both vectors are equal or not.
            for (k = 0; k < 26; k = k + 1)
            {
                if (even1[k] != even2[k] || odd1[k] != odd2[k])
                {
                    break;
                }
            }

            if (k == 26)
            {
                break;
            }
        }

        //  Increment counter if string at 'i' is not equivalent to any other string.
        if (h == n)
        {
            count = count + 1;
        }
    }

    return count;
}

#include <vector>
#include <string>

bool isInterleave(string a, string b, string c){

    // We want to reduce the space complexity to O(min(N,M)). 
    // We swap the two strings if b.length() > a.length(), so that we can make a dp array of size b.length()+1.
    if(b.length() > a.length()){
        swap(a,b);
    }

    int n1 = a.length(), n2 = b.length(), n3 = c.length();

    // Create a dp array of size n2 and initialise it to false.
    vector<bool> dp(n2 + 1, false);

    // If the length of "c" is not equal to the sum of the length of "a" and "b", then return false.
    if(n1 + n2 != n3) {
        return false;
    }

    int i,j;

    for(i = 0; i <= n1; i++){

        for(j = 0; j <= n2; j++){

            // Mark dp[j] as true, if the values of i and j are both zeroes.
            if(i == 0 && j == 0){
                dp[j] = true;
            }

            // Check for the case when i = 0.
            else if(i == 0){
                dp[j] = dp[j - 1] && (b[j - 1] == c[j - 1]);
            }

            // Check for the case when j = 0.
            else if(j == 0){
                dp[j] = dp[j] && (a[i - 1] == c[i - 1]);
            }

            //Check for both the cases.
            else{
                dp[j] = (dp[j] && a[i - 1] == c[i + j - 1]) || (dp[j - 1] && b[j - 1] == c[i + j - 1]);
            }
        }
    }

    return dp[n2];
}

/*

	Time complexity: O(N^2) 
	Space complexity: O(1)
	
	where ‘N’ is the length of the given string ‘s’.


*/

bool checkUnique(string &s)
{
    //  Iterate through the given string 's'.
    for (int i = 0; i < s.length(); i++)
    {
        //  Again, Iterate through the given string.
        for (int j = i + 1; j < s.length(); j++)
        {
            //  If, found same character at different indexed then return false.
            if (s[i] == s[j])
            {
                return false;
            }
        }
    }

    return true;
}
