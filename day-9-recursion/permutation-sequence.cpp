class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int> numbers;
        // to generate factorial generated factorial without n as we need to divide later so instead dont include in factorial
        for(int i=1;i<n;i++)
        {
            fact*=i;
            numbers.push_back(i);   // created array of numbers 
        }
        numbers.push_back(n);
        k--;    // because of 0-based indexing 
        string res="";
        while(true)
        {
            // as we nknow we need - group so that group starts with (k/fact)th elem of array 
            res+=to_string(numbers[k/fact]);
            // as it is included so erased 
            numbers.erase(numbers.begin()+k/fact);
            // check for stopping case 
            if(numbers.size()==0)
                break;
            // basically  now we have reduced array ans now we know (k%fact)th permutation of new array hence we used while loop
            k=k%fact;
            // in new case we have one number choosen so need to remove from factorial
            fact=fact/numbers.size();
        }
        return res;
        
    }
};