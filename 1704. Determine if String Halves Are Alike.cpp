class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        unordered_set<char> vowel;
        char vowels[]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int total_vowels=0;
        int vowel_tillhalf=0;
        vowel.insert(vowels,vowels+10);
        for(int i=0;i<n;i++)
        {
            if(vowel.count(s[i]))
            {
                total_vowels++;
                if(i<n/2)
                vowel_tillhalf++;
            }
        }
        if(total_vowels%2==0)
        {
        if(total_vowels/2==vowel_tillhalf)
        return true;
        }
        return false;
    }
};