class Solution {
  public:
    int rotationCount(int r, int d) {
        // code here
        int ans=0;
        int first,second;
        
        while(r){
            first=r%10;
            second=d%10;
            r/=10;
            d/=10;
            
            ans+=min(abs(first-second), 10-abs(first-second));
        }
        return ans;
    }
};