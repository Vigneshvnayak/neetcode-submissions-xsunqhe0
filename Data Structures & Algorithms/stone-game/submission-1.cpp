class Solution {
public:
    bool stoneGame(vector<int>& piles) {
       int i = 0; 
       int j = piles.size() - 1;
       int alice = 0, bob = 0, turn = 0;
       while (i < j) {
            if (piles[i] >= piles[j]) {
               if (!turn) {
                    alice += piles[i];
               } else {
                    bob += piles[i];
               }
               i++; 
            } else {
                if (!turn) {
                    alice += piles[j];
                } else {
                    bob += piles[j];
                }
               j--;
            }
       }
       return (alice > bob) ? true : false;
    }
};