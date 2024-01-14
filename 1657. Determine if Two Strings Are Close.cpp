class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
        {
            return false;
        }
        vector<int> wrd1(26,0);
        vector<int> wrd2(26,0);
        int n=word1.size();
        for(int i=0;i<n;i++)
        {
            int index1=word1[i]-'a';
            int index2=word2[i]-'a';
            wrd1[index1]++;
            wrd2[index2]++;
        }
        // check for elements present or not
          for(int i=0;i<26;i++)
          {
              if(wrd1[i]!=0 && wrd2[i]==0)
              return false;
              if(wrd2[i]!=0 && wrd1[i]==0)
              return false;
          }

        for(int i=0;i<26;i++)
        {
            int t1=wrd1[i];
            if(t1==0)
            {
                continue;
            }
            else
            {
                for(int j=0;j<26;j++)
                {
                    int t2=wrd2[j];
                    if(t1==t2)
                    {
                        wrd2[j]=0;
                        wrd1[i]=0;
                        break;
                    }
                }
            }

        }
        for(int i=0;i<26;i++)
        {
            if(wrd1[i]!=0||wrd2[i]!=0)
            return false;
        }
        return true;
    }
};