class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l = 0, r = 0, n = fruits.size();
        unordered_map<int, int> map;
        int maxfruits = 0;

        while(r<n){
            map[fruits[r]]++;
            r++;

            while(map.size() > 2){
                map[fruits[l]]--;
                if(map[fruits[l]] <= 0){
                    map.erase(fruits[l]);
                }
                l++;
            }
            maxfruits = max(maxfruits, r-l);
        }
        return maxfruits;
    }
};

// 2 3
// 3 1


//         r
// 1 2 3 2 2 
//   l