#include<cstdio>
#include<vector>
using namespace std;

int ternary_search(vector<int>& arr, int l, int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(arr[mid1] == x)
            return mid1;
        if(arr[mid2] == x)
            return mid2;
        if(x<arr[mid1])
            return ternary_search(arr, l,mid1-1,x);
        else if(x>arr[mid2])
            return ternary_search(arr, mid2+1,r,x);
        else
            return ternary_search(arr, mid1+1,mid2-1,x);
    }
    return -1;
}

int main()
{
    vector<int> sample{10,20,25,35,50,55,70,95};
    
    int elem, pos, low=0, high=sample.size()-1;
    
    elem=100; 
    pos = ternary_search(sample,0,7,elem);
    if(pos==-1) 
        printf("%d not found\n",elem);
    else 
        printf("%d found at %d index \n",elem,pos);
    
    elem=35; 
    pos = ternary_search(sample,0,7,elem);
    if(pos==-1) 
        printf("%d not found\n",elem);
    else 
        printf("%d found at index %d\n",elem,pos);
    
    return 0;
}
