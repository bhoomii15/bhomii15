/*

	Time complexity: O(N^2) 
	Space complexity: O(1)
	
	where āNā is the length of the given string āsā.


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
