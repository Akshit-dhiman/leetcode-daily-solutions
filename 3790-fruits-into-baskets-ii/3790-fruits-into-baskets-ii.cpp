class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int unplaced = 0;
        for(int i=0; i<n; i++){
            int fruit = fruits[i];
            bool isPlaced = false;
            for(int j=0; j<n; j++){
                if(fruit <= baskets[j]){
                    baskets[j] = INT_MIN;
                    isPlaced = true;
                    break;
                }if(!isPlaced && j == n-1){
                    unplaced++;
                }
            }
        }
        return unplaced;
    }
};