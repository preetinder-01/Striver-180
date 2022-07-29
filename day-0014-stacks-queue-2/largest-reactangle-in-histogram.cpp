/**
 * @file largest-reactangle-in-histogram.cpp
 * @author preetinder singh bajaj 
 * @brief 
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*
    intuition : on carrying dry run or just simple calculations we observed that for each heihgt max possible width will be the boundaries made by smaller on each sides 
*/







// this solution is ok but it is having two many iterations of array 
/*
    1.leftsmall     2*O(N)
    2.rightsmall    2*O(N)
    3.stack clear   O(N)
    4.then  last itertaion applying formula O(N)

so it is having O(N) but still it has lot of iterations 
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>s;
        vector<int>leftsmall(heights.size());
        vector<int>rightsmall(heights.size());
        // leftsmaller 
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() and heights[s.top()]>=heights[i])
                s.pop();
            if(!s.empty())
                leftsmall[i]=s.top()+1;
            else
                leftsmall[i]=0;
            s.push(i);
        }
        while(!s.empty())s.pop();
        //rightsmaller
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!s.empty() and heights[s.top()]>=heights[i])
                s.pop();
            if(!s.empty())
                rightsmall[i]=s.top()-1;
            else
                rightsmall[i]=heights.size()-1;
            s.push(i);
        }
        
        int maxrect=0;
        for(int i=0;i<heights.size();i++)
        {
            maxrect=max(maxrect,(rightsmall[i]-leftsmall[i]+1)*heights[i]);
        }
        return maxrect;
    }
};




/*
    to reduce this into one pass solution 
*/

 // APPROACH WITH SINGLE PASS 
        /*
        when calculating left smaller  we calculated at that time only the ls and rs to avoid more passes 
        if stack empty just push
        alsi we need to travel till last_index+1 
        if stack is not empty and (either last index or height at top os stack is greater than height in arr )
        we got height using top element and width using ls and rs 
        is tack empty then width will be rs itself as we need to include both so equalised to rs and rs will be the index at which we are standing
        and is stack not empty then ls will next element of stack (as we already popped after getting height so it will be top element )
        at the end we are left with increasing values in stack instead of using each element we will use only the indexes present in stack to calculate largest rectangle  i.e. at index=size()
        */
        
        stack<int> s;
        int n=heights.size();
        int maxar=0;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() and (i==n or heights[s.top()]>=heights[i]))
            {
                int height=height[s.top()];
                s.pop();
                int width;
                if(s.empty())width=i;
                else width=i-s.top()-1;
                maxar=max(maxar,width*height);
                
            }   
            s.push(i);
            }
        return maxar;